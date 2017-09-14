/* LibTomCrypt, modular cryptographic library -- Tom St Denis
 *
 * LibTomCrypt is a library that provides various cryptographic
 * algorithms in a highly modular and flexible manner.
 *
 * The library is free for all purposes without any express
 * guarantee it works.
 *
 * Tom St Denis, tomstdenis@gmail.com, http://libtom.org
 */
#include "tomcrypt.h"

/**
  @file xcbc_test.c
  XCBC Support, Test XCBC-MAC mode
*/

#ifdef LTC_XCBC

/** Test XCBC-MAC mode
  Return CRYPT_OK on succes
*/
int xcbc_test(void)
{
#ifdef LTC_NO_TEST
   return CRYPT_NOP;
#else
   static const struct {
       int msglen;
       unsigned char K[16], M[34], T[16];
   } tests[] = {
{
   0,
   { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f },

   { 0 },

   { 0x75, 0xf0, 0x25, 0x1d, 0x52, 0x8a, 0xc0, 0x1c,
     0x45, 0x73, 0xdf, 0xd5, 0x84, 0xd7, 0x9f, 0x29 }
},

{
   3,
   { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f },

   { 0x00, 0x01, 0x02 },

   { 0x5b, 0x37, 0x65, 0x80, 0xae, 0x2f, 0x19, 0xaf,
     0xe7, 0x21, 0x9c, 0xee, 0xf1, 0x72, 0x75, 0x6f }
},

{
   16,
   { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f },

   { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f },

   { 0xd2, 0xa2, 0x46, 0xfa, 0x34, 0x9b, 0x68, 0xa7,
     0x99, 0x98, 0xa4, 0x39, 0x4f, 0xf7, 0xa2, 0x63 }
},

{
   32,
   { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f },

   { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f },

   { 0xf5, 0x4f, 0x0e, 0xc8, 0xd2, 0xb9, 0xf3, 0xd3,
     0x68, 0x07, 0x73, 0x4b, 0xd5, 0x28, 0x3f, 0xd4 }
},

{
   34,
   { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f },

   { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
     0x20, 0x21 },

   { 0xbe, 0xcb, 0xb3, 0xbc, 0xcd, 0xb5, 0x18, 0xa3,
     0x06, 0x77, 0xd5, 0x48, 0x1f, 0xb6, 0xb4, 0xd8 },
},



};
  unsigned char T[16];
  unsigned long taglen;
  int err, x, idx;

  /* AES can be under rijndael or aes... try to find it */
  if ((idx = find_cipher("aes")) == -1) {
     if ((idx = find_cipher("rijndael")) == -1) {
        return CRYPT_NOP;
     }
  }

  for (x = 0; x < (int)(sizeof(tests)/sizeof(tests[0])); x++) {
     taglen = 16;
     if ((err = xcbc_memory(idx, tests[x].K, 16, tests[x].M, tests[x].msglen, T, &taglen)) != CRYPT_OK) {
        return err;
     }
     if (taglen != 16 || XMEMCMP(T, tests[x].T, 16)) {
        return CRYPT_FAIL_TESTVECTOR;
     }
  }

  return CRYPT_OK;
#endif
}

#endif

/* $Source$ */
/* $Revision$ */
/* $Date$ */


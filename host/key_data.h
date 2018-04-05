#ifndef KEY_DATA_H
#define KEY_DATA_H

/* It was too much work to read IETF RPCs to parse PEM and ASN.1 
 * formated RSA keys. Instead,0x we just use openssl to parse the 
 * key into its components in the form of octets. We store the key 
 * in octet form here for the keys under capsule_gen/keys folder. 
 * This is a very manual process,0x but should do for bootstrapping 
 * a prototype.
 *
 * An enterprising individual might use system() to make this 
 * process more automatic.
 *
 * An ambitious individual might write his own PEM and ASN.1 parser 
 * after reading the RPCs
 */

#include <tee_client_api.h>
#include <tee_api_types.h>
#include <capsule.h>
#include <util.h>

struct tee_attr_packed {
	uint32_t attr_id;
	uint32_t a;
	uint32_t b;
};

struct rsa_key {
	const uint8_t *modulus;
	size_t modulus_len;

	const uint8_t *pub_exp;
	size_t pub_exp_len;

	const uint8_t *priv_exp;
	size_t priv_exp_len;

	const uint8_t *prime1;     /* q */
	size_t prime1_len;         

	const uint8_t *prime2;     /* p */
	size_t prime2_len;

	const uint8_t *exp1;
	size_t exp1_len;

	const uint8_t *exp2;
	size_t exp2_len;

	const uint8_t *coeff;
	size_t coeff_len;
};

static const uint8_t modulus[] = {
    0xd1,0x8c,0x17,0x2e,0x41,0xc8,0x85,0x1b,0x97,0x63,0xcd,0xd9,0xf8,
	0x6a,0x48,0x3a,0xf9,0x9a,0x0e,0xbb,0xf3,0x3f,0xd6,0x36,0xa3,0x4c,
	0x18,0xd6,0xeb,0x9a,0x96,0xb8,0xb2,0x0c,0x41,0x78,0x02,0x27,0xbf,
	0x8d,0xe1,0x3a,0xc1,0xd8,0xe8,0x48,0x4c,0x4b,0x33,0x3b,0xe6,0x9e,
	0xd0,0xfd,0x03,0x41,0xa7,0x04,0xa7,0xd0,0x48,0xb2,0xf1,0xf5,0x51,
	0xca,0x11,0xd7,0xb0,0x4a,0x33,0xb9,0x86,0xdc,0xa7,0x79,0x58,0x23,
	0xe3,0x53,0x1a,0xd2,0xba,0x5c,0xaa,0xfd,0x1d,0x07,0x6a,0x48,0xa2,
	0x3f,0xb2,0xd8,0x9e,0x61,0x68,0xd1,0x70,0x19,0x4f,0x11,0x11,0xcd,
	0x36,0x80,0x39,0x1b,0xa6,0x7d,0x58,0x7c,0x41,0xf1,0x18,0x5f,0x76,
	0x93,0x94,0xcd,0x13,0xf0,0x56,0x51,0x60,0xc1,0x0a,0x4d,0x08,0xe0,
	0x40,0x85,0x1f,0x39,0x56,0x07,0xc5,0xf4,0xe1,0x7c,0xc0,0x97,0x23,
	0x5d,0x05,0x4e,0x82,0xd4,0x37,0x84,0xae,0x20,0x93,0x00,0xc4,0x63,
	0x7c,0x0e,0xe1,0xe8,0xe5,0x3f,0x76,0xdd,0xe6,0x89,0x8b,0x34,0x9b,
	0x04,0xf8,0x12,0x59,0x01,0xcf,0x34,0xe0,0xac,0x6a,0xd7,0xec,0xad,
	0x77,0xb6,0xcc,0xfa,0xa7,0x99,0x57,0x78,0xc4,0xdf,0x82,0xb4,0xa5,
	0x62,0x98,0x3f,0xc9,0x4d,0x35,0x3d,0x18,0xdd,0x44,0xe9,0xaf,0x77,
	0xfc,0x80,0xd2,0x23,0x77,0xa8,0x83,0x59,0x00,0xd3,0xad,0x87,0xe1,
	0x22,0x3e,0xf9,0x6e,0xfa,0x21,0xdc,0x75,0xa3,0x96,0x54,0xe4,0xf4,
	0x6d,0xc3,0x55,0x19,0x62,0x3e,0x01,0x19,0x7f,0xf3,0x87,0x7f,0xae,
	0x02,0x6b,0xc7,0x3c,0x33,0x06,0x65,0xb8,0x87
};

static const uint8_t pub_exp[] = {
	0x01,0x00,0x01
};

static const uint8_t priv_exp[] = {
    0x24,0x74,0xe5,0x0b,0x8d,0x32,0x5f,0xc6,0x1f,0x1e,0xa4,0x0f,0xca,
	0x22,0x63,0x92,0xaf,0x1e,0x58,0x75,0xe6,0xaa,0x32,0x90,0xaa,0xf4,
	0x70,0x55,0xe4,0x03,0xaf,0x39,0x4e,0xf0,0xc6,0xeb,0x24,0x24,0xda,
	0x34,0xca,0xfc,0xb8,0x01,0x0e,0xd8,0x95,0x3d,0x78,0x1a,0x71,0xd3,
	0x2b,0xb4,0xf9,0x3e,0x10,0xda,0xc4,0x7f,0x7e,0x46,0x73,0xc6,0x24,
	0x86,0xad,0x78,0x03,0x19,0xc5,0xc9,0xff,0x66,0xa0,0x54,0x82,0x3b,
	0x2c,0x2f,0xa7,0x39,0x06,0x67,0x5c,0xf0,0x50,0x7e,0x9b,0xc5,0x2b,
	0x45,0x3d,0xce,0x66,0x2f,0xb8,0x56,0xc7,0xd3,0xff,0x67,0x8e,0xdb,
	0x4f,0x22,0x1b,0xcd,0x6d,0xb7,0xdd,0x0f,0x31,0x41,0xca,0xe5,0xc0,
	0xf1,0x88,0x2f,0xed,0xca,0x20,0x9a,0x63,0xe4,0xf1,0xef,0x88,0x6c,
	0x5b,0x1e,0xef,0x13,0x51,0x69,0x03,0x6e,0xba,0xdd,0x67,0x35,0xec,
	0x56,0xa9,0xff,0x68,0xb6,0xb5,0x10,0x7e,0xa3,0x84,0x0e,0x88,0x6d,
	0x5a,0xb8,0xd7,0xb3,0x1b,0xb1,0xb3,0x3b,0xd1,0x00,0x69,0xd3,0xbc,
	0x90,0xc8,0x9c,0xc0,0x1c,0xf3,0x81,0xce,0x45,0x80,0x28,0x7c,0x86,
	0xa7,0x04,0xd2,0x97,0xf3,0xe5,0xc7,0xc7,0x9f,0x75,0xc7,0x08,0x7a,
	0xd2,0x79,0xe9,0x0e,0xc9,0xd8,0x06,0xd4,0x8d,0xf8,0x93,0x56,0xda,
	0x3c,0x05,0x1d,0x59,0xb1,0x91,0xa6,0x38,0x99,0xcd,0xea,0x8a,0x87,
	0x9b,0x10,0xe0,0x69,0xa8,0x08,0x7b,0x70,0xa9,0x4e,0xa6,0x15,0x80,
	0x52,0x18,0x6b,0x39,0x44,0x49,0x56,0x02,0x98,0xe7,0x4a,0x34,0x72,
	0xa5,0x93,0xc5,0x0d,0xac,0x4c,0x40,0x59,0x61
};

static const uint8_t prime1[] = {
    0xf3,0x81,0xe9,0x03,0x0e,0x9c,0x96,0xda,0xcf,0x51,0xa1,0x7a,0x36,
	0x13,0xeb,0x14,0x27,0x38,0x83,0xc7,0x19,0x81,0x89,0x0a,0x91,0xd4,
	0xb0,0xa0,0xf8,0xa0,0xab,0x00,0xe7,0x55,0x28,0x27,0x33,0x1b,0x8e,
	0x07,0x12,0xc6,0xb4,0xa0,0xd8,0xcb,0x4d,0xcf,0xe7,0x86,0x30,0x90,
	0xf1,0xd3,0xd0,0xa6,0xc1,0x57,0xfd,0xe3,0x1b,0x77,0x85,0x43,0x4e,
	0x6b,0xe1,0x8b,0xb9,0x09,0x3a,0x6b,0x20,0x1c,0x6f,0xbc,0x8c,0xcb,
	0xd2,0x81,0x9b,0x8d,0xef,0x76,0xf2,0x3b,0x44,0x0f,0x07,0xee,0xc4,
	0xbe,0xde,0x5d,0x0b,0x9f,0xd9,0x2b,0x9c,0x40,0x27,0x78,0xed,0x26,
	0xbc,0xbc,0x2e,0xdf,0xa5,0x83,0x0f,0xdd,0xa7,0xa9,0xcc,0x3a,0x56,
	0x60,0xd1,0x07,0x4c,0x4f,0x3e,0x9d,0xc7,0x54,0x12,0xc9
};

static const uint8_t prime2[] = {
    0xdc,0x4c,0x2a,0x70,0xa3,0x38,0x31,0xe6,0x21,0x58,0xf8,0xb2,0xe1,
	0x03,0x7a,0x19,0xef,0x53,0xdb,0xcc,0x75,0xba,0x7f,0x07,0x7c,0x1e,
	0x8c,0xd3,0x1a,0x2b,0x91,0x1e,0xc9,0xf1,0x56,0x2d,0xbc,0xb8,0x3e,
	0x04,0x36,0x19,0xf4,0x49,0x90,0x85,0x18,0xc0,0x0b,0x59,0xe7,0x28,
	0xd5,0x6b,0x55,0x2b,0x38,0xa8,0x38,0x55,0x8f,0xfd,0x50,0x5f,0x7b,
	0x7f,0x31,0x3f,0xfa,0x08,0x10,0xfe,0xf0,0x10,0xf9,0xd9,0x12,0x41,
	0x59,0xb7,0x67,0x34,0x81,0x42,0x13,0xbe,0x59,0x6a,0xee,0x76,0xf9,
	0xbf,0xc1,0xd8,0xfe,0x1a,0xe2,0xfc,0xc5,0x34,0xff,0xe1,0xa9,0x6b,
	0x22,0x48,0x82,0x96,0xb0,0xac,0x05,0x88,0x09,0xc7,0x05,0x45,0xb7,
	0xbf,0xf6,0x09,0x7b,0xa4,0xae,0xd5,0xd2,0x12,0x48,0xcf
};

static const uint8_t exp1[] = {
    0x92,0x60,0xf1,0x95,0x68,0xdf,0x30,0xbf,0xf0,0x08,0x7e,0x2d,0x5c,
	0xfc,0xb4,0x3f,0xb5,0x23,0xff,0xf3,0x5b,0x9d,0xc6,0xa7,0x97,0xea,
	0x67,0x13,0x1c,0xe2,0x58,0x69,0x7e,0xa6,0x6e,0x30,0xc2,0x44,0x3a,
	0x28,0x7e,0x5c,0xfc,0x90,0x04,0x42,0x92,0x4f,0xfc,0x39,0x6a,0x50,
	0x77,0x4e,0x81,0x0a,0xfd,0x06,0xcc,0x14,0x0d,0x9a,0xd7,0x7d,0x12,
	0x53,0x3f,0x8e,0x22,0x79,0x2d,0xa8,0xdf,0xf0,0xb8,0x2a,0x7b,0xe8,
	0xba,0x6e,0x36,0xf8,0x27,0x8f,0x35,0x25,0xf3,0x4f,0xa5,0xd1,0x1e,
	0x6c,0x2e,0x77,0x78,0x59,0x6a,0xcf,0x10,0x6a,0x70,0x4f,0xfd,0x1f,
	0x60,0x2d,0x2f,0x70,0x39,0xaa,0x83,0x8b,0x17,0x12,0xb7,0x36,0x0a,
	0x5e,0xc0,0xc8,0xc6,0x52,0x8c,0xad,0x83,0xf9,0x42,0x21
};

static const uint8_t exp2[] = {
    0x07,0xd6,0xbd,0xfb,0xdc,0x12,0xf7,0xd3,0x94,0x84,0x31,0xf5,0x4b,
	0x84,0x70,0x27,0xd4,0x18,0x4b,0xcd,0xee,0xb2,0x80,0x2a,0xa8,0x03,
	0xfe,0x46,0xd4,0xbb,0x90,0x22,0x64,0x55,0x2e,0x17,0xda,0x8b,0x43,
	0xc9,0xaa,0x93,0x29,0xda,0x24,0x46,0x58,0x27,0x1d,0x40,0x49,0xb5,
	0x6e,0x42,0xaf,0x79,0x26,0x3e,0xf6,0x22,0x35,0x49,0x72,0x3e,0xb3,
	0x8a,0x47,0x1a,0x5b,0xaf,0x45,0xcb,0x8c,0x87,0x4e,0x1c,0xa7,0x45,
	0xa4,0x07,0x9e,0xa8,0x83,0xa0,0xf2,0x4a,0xe7,0xab,0xa2,0x68,0xa1,
	0x62,0x6d,0x67,0x67,0x43,0x55,0xa8,0x60,0xec,0x0d,0xde,0xdd,0xc4,
	0x6e,0x27,0xde,0x5d,0xb6,0x53,0xa8,0xae,0xba,0x8a,0x56,0x69,0xb0,
	0xac,0x27,0xf9,0x16,0x69,0x39,0xbf,0x6a,0x06,0x34,0x89
};

static const uint8_t coeff[] = {
    0x6e,0xf3,0x85,0xb6,0x2f,0x76,0x3d,0x30,0x14,0xae,0xc8,0x79,0xa5,
	0x4d,0xe1,0x4b,0x43,0x4e,0x65,0x07,0x4e,0x3a,0xe0,0xe7,0x22,0xcf,
	0x7b,0x5b,0x80,0xd2,0xf2,0x3f,0x8d,0x2c,0xf1,0x1c,0x09,0xe0,0xa5,
	0xe2,0x4f,0x4f,0xbd,0x37,0xea,0x58,0xd4,0x36,0xe0,0x97,0xea,0xd3,
	0xc3,0xcb,0x6d,0x70,0xb9,0x03,0x30,0x48,0x35,0x80,0xdd,0xb5,0xa6,
	0xba,0x87,0xac,0xf5,0x7b,0xb5,0x1a,0x82,0xfd,0x74,0x74,0x9f,0x23,
	0x11,0xc1,0x03,0xed,0x42,0x56,0x83,0x5a,0x50,0xc8,0xba,0xb2,0xc0,
	0x6a,0xe8,0xa8,0xd4,0xcb,0x2e,0x46,0x9b,0x9c,0x51,0xd3,0x08,0xc3,
	0xde,0x07,0xef,0x1c,0x84,0x21,0x1a,0x91,0x57,0xf5,0xad,0xe7,0xb0,
	0xfe,0xf8,0x88,0x37,0xb3,0x33,0xe2,0xfb,0xd1,0x80,0x0d
};

void unused_func();
void add_attr( size_t attr_count, TEE_Attribute *attrs, 
			   uint32_t attr_id, const void *buf, size_t len );
TEEC_Result pack_attrs( const TEE_Attribute *attrs, uint32_t attr_count,
						uint8_t *buf, size_t *blen, size_t max_size );

void create_rsa_key( TEEC_Operation *op, uint32_t max_key_size, 
				     uint32_t key_type, TEE_Attribute *attrs, 
					 size_t num_attrs, TEEC_SharedMemory* in );

void create_aes_key( TEEC_Operation *op, uint32_t max_key_size, 
				     uint32_t key_type, unsigned char* id, 
					 TEE_Attribute *attrs, size_t num_attrs,
					 uint8_t* iv, size_t iv_len, 
					 TEEC_SharedMemory* in );
#endif /*KEY_DATA*/

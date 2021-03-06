#ifndef CAPSULE_UTIL_H
#define CAPSULE_UTIL_H

#include <tomcrypt.h>
#include <capsule.h>

#ifdef DEBUG
	#define DIAGNOSTIC(...) printf( __VA_ARGS__ )
#else
	#define DIAGNOSTIC(...) 
#endif

#define PRINT_INFO(...) printf( __VA_ARGS__ )
#define PRINT_ERR(...) fprintf( stderr, __VA_ARGS__ )

#define CHECK_CRYPT_OK(err, name) do { \
	if ((err != CRYPT_OK)) { \
		printf("%s: %s\n", name, error_to_string(err)); \
		return -1; \
	} \
} while(0)

typedef enum {
	false,
	true,
} bool;

struct range {
	int start;
	int end;
};

typedef int (*process_func)( const unsigned char *in, 
							 unsigned char *out, unsigned long len, 
							 symmetric_CTR *ctr );

void parse_kvstore( unsigned char* store, size_t inlen );

char* filename_concat( const char* name, const char* extension, 
					   const char* delimiter );

int process_ctr_aes( const unsigned char *in, unsigned char *out, 
				     size_t len, unsigned char *key, size_t keylen, 
					 unsigned int ctr, unsigned char *iv, 
					 unsigned int iv_len, process_func func );

int aes_encrypt( const unsigned char *in, unsigned char *out, 
				 size_t len, unsigned char *key, size_t keylen, 
				 unsigned int ctr, unsigned char *iv, 
				 unsigned int iv_len );

int aes_decrypt( const unsigned char *in, unsigned char *out, 
				 size_t len, unsigned char *key, size_t keylen, 
				 unsigned int ctr, unsigned char *iv, 
				 unsigned int iv_len );

void print_header( struct TrustedCap* header, unsigned int hlen, 
				   unsigned char* key, unsigned int key_len, 
				   unsigned char* iv, unsigned int iv_len );

void fill_header( struct TrustedCap* header, size_t fsize, 
				  unsigned char* key, unsigned int key_len, 
				  unsigned char* iv, unsigned int iv_len, 
				  unsigned char* id, unsigned char* hash,
			   	  unsigned int hashlen );

void encrypt_content( unsigned char* buffer, size_t buflen, 
					  //unsigned char* hash, size_t hashlen, 
					  unsigned char* key, unsigned int key_len, 
					  unsigned char* iv, unsigned int iv_len );

void decrypt_content( unsigned char* buffer, size_t buflen,
					  //unsigned char* hash, size_t hashlen, 
					  unsigned char* key, unsigned int key_len, 
					  unsigned char* iv, unsigned int iv_len );

void find_delimiter( unsigned char* buf, size_t blen, int* dstart, 
					 int* dend, int* state, bool *matched, 
					 unsigned char* delim, size_t dlen );

void populate_parts( unsigned char* buffer, int len, 
					 struct range parts[4] );

void print_parts( unsigned char * buf, struct range parts[4] );

void set_capsule( char* keyname, unsigned int* key_len, 
				  unsigned char** key, unsigned int* iv_len, 
				  unsigned char** iv, unsigned char** id );

#endif

#ifndef CAPSULE_TA_H
#define CAPSULE_TA_H

#define POLICY_FUNC      "policy"
#define TZ_CRED          "cred"
#define POLICY_MAX_SIZE  2048

#define ASSERT_PARAM_TYPE( pt ) \
			do {                \
				if ( (pt) != param_type ) \
					return TEE_ERROR_BAD_PARAMETERS;  \
			} while( 0 )	

/* UNUSED - RSA key parameters */
extern TEE_ObjectHandle curr_pub;
extern TEE_ObjectHandle curr_priv;

/* AES key parameters */
extern TEE_OperationHandle  decrypt_op;
extern TEE_OperationHandle  encrypt_op;
extern TEE_OperationHandle  hash_op;
extern char                *capsule_name;
extern uint32_t 			symm_id;
extern uint8_t         	   *symm_iv;
extern uint32_t         	symm_iv_len;
extern uint32_t         	symm_key_len;
extern uint32_t             symm_chunk_size;
extern bool                 aes_key_setup;
extern struct HashList      hash_head;

/* Trusted Capsule file index information */
extern struct capsule_text  cap_head;

/* Secure storage objects */
extern TEE_ObjectHandle keyFile;                                   
extern char             keyID[];
extern TEE_ObjectHandle stateFile;

/* Lua interpreter */
extern lua_State *Lstate;
extern int        curr_tgid;
extern int        curr_fd;
extern int        curr_len;
extern char       curr_declassify_dest[128];
extern int        curr_cred;

#endif /* CAPSULE_TA_H */

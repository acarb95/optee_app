#ifndef FAKEOPTEE_H
#define FAKEOPTEE_H

#define HASHLEN             32
#define POLICY_MAX_SIZE 	2048
#define DEVICE_ID_LEN 		32

typedef unsigned int 		uint32_t;
typedef unsigned short		uint16_t;
typedef unsigned char  		uint8_t;

static unsigned char keyDefault[] = { 0x00, 0x01, 0x02, 0x03, 
							  		  0x04, 0x05, 0x06, 0x07, 
								   	  0x08, 0x09, 0x0A, 0x0B, 
								   	  0x0C, 0x0D, 0x0E, 0x0F };

static unsigned char ivDefault[16] = { 0x00 };

typedef struct capsuleManifestEntry {
	const char			        name[45];
	unsigned const char           id[4];
} capsuleManifestEntry;

/* capsule name, capsule ID, device ID */
static capsuleManifestEntry manifest[] = {
 { "bio", { 0x12,0x31,0x2b,0xf1 } },
};

typedef enum {
	ECHO = 0,
	GET_STATE,
	SET_STATE,
	POLICY_UPDATE,
	LOG_ENTRY,
} SERVER_REQ;

typedef enum {
	SUCCESS = 0,
	FAILURE,
} SERVER_REPLY;

typedef struct msgReqHeader {
	uint32_t 				capsuleID;
	char	 				deviceID[DEVICE_ID_LEN];
	int						req;
	int						nonce;
	unsigned char			hash[HASHLEN];
	// ECHO 	 		-   0
	// GET_STATE 		-   length of key
	// SET_STATE 		-   length of key:value
	// POLICY_UPDATE 	- 	length of int version
	// LOG_ENTRY		-   length of []char
	size_t					payloadLen;
} msgReqHeader;

typedef struct msgReplyHeader {
	uint32_t 		capsuleID;
	int				response;
	int				nonce;
	unsigned char	hash[HASHLEN];
	// This is the length of msgPayload->payload
	// ECHO 	 		-   0
	// GET_STATE 		-   len of value
	// SET_STATE 		-   0
	// POLICY_UPDATE 	- 	payloadLen = 0 if no upload OR 
	//                      size of policy file
	// LOG_ENTRY		-  	0
	int				payloadLen;
} msgReplyHeader;

typedef struct msgPayload {
	int 			nonce;
	unsigned char	hash[HASHLEN];
	char			payload[0];
} msgPayload;

#endif

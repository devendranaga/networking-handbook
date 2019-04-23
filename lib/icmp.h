#ifndef __NH_ICMP_H__
#define __NH_ICMP_H__

// icmp types
typedef enum {
   DESTINATION_UNREACHABLE = 3,
   TIME_EXCEEDED = 11,
   PARAMETER_PROBLEM = 12,
   SOURCE_QUENCH = 4,
   REDIRECT_MESSAGE = 5,
   ECHO_REQUEST = 8,
   ECHO_REPLY = 0,
   TIMESTAMP_REQUEST = 13,
   TIMESTAMP_REPLY = 14,
   INFORMATION_REQ = 15,
   INFORMATION_REP = 16,
} icmp_type_t;


// code values for destination field
typedef enum {
   DESTINATION_NET_UNREACHABLE = 0,  // from gateway
   DESTINATION_HOST_UNREACHABLE = 1, // from gateway
   DESTINATION_PROTOCOL_UNREACHABLE = 2, // from host
   DESTINATION_PORT_UNREACHABLE = 3, // from host
   DESTINATION_FRAGMENT_IS_NEEDED_AND_DF_SET = 4, // from gateway
   DESTINATION_SOURCE_ROUTE_FAILED = 5, // from gateway
} icmp_dest_code_t;

// code values for time exceeded
typedef enum {
   TTL_EXCEEDED_IN_TRANSIT = 0,
   TTL_FRAGMENT_REASSEMBLY_EXCEEDED = 1,
} icmp_time_exceeded_code_t;

typedef enum {
   REDIRECT_FOR_NETWORK = 0,
   REDIRECT_FOR_HOST,
   REDIRECT_FOR_TOS_NW,
   REDIRECT_FOR_TOS_HOST,
} icmp_rediect_code_t;

typedef enum {
    POINTER_INDICATION = 0,
} icmp_parameter_problem_t;

typedef enum {
    ECHO_CODE_NUM = 0,
} icmp_echo_code_t;

typedef enum {
    TIMESTAMP_CODE_NUM = 0,
} icmp_timestamp_code_t;

typedef enum {
    INFORMATION_CODE_NUM = 0,
} icmp_information_code_t;

typedef unsigned int icmp_code_t;

struct icmp_protocol {
    icmp_type_t type;
    icmp_code_t code;
    unsigned short checksum;
    union {
        unsigned char pointer;
        unsigned int gateway_internet_addr;
        struct echo_req_reply {
            unsigned short int identifier;
            unsigned short int sequence_number;
        } e_req_rep;
        
        struct timestamp_req_reply {
            unsigned short int identifier;
            unsigned short int sequence_number;
            unsigned int originating_timestamp;
            unsigned int receive_timestamp;
            unsigned int transmit_timestamp;
        } t_req_rep;
        
        struct information_req_reply {
            unsigned short int identifier;
            unsigned short int sequence_number;
        } i_req_rep;
    } ids;
};

#endif

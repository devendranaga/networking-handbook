# ICMP (internet control message protocol)


1. ICMP sits in same layer as that of IP and must be implemented as part of ip.
2. used to report error in datagram processing.
3. more than one case that ICMP is sent:
    1. datagram cannot reach destination
    2. gateway does not have the buffering capacity to forward a datagram
    3. when gateway directs host to send traffic on a shorter route

IP protocol field is set to 1 for icmp.

**protocol**

```

0         1        2                  3
|---------|--------|------------------|
| type    | code   | checksum         |
|-------------------------------------|
|          unused                     |
|-------------------------------------|


```

**ip field settings for icmp**


**c header**

```c

// icmp types
typedef enum {
   DESTINATION_UNREACHABLE = 3,
} icmp_type_t;

// code values for destination field
typedef enum {
   DESTINATION_NET_UNREACHABLE = 0,
   DESTINATION_HOST_UNREACHABLE = 1,
   DESTINATION_PROTOCOL_UNREACHABLE = 2,
   DESTINATION_PORT_UNREACHABLE = 3,
   DESTINATION_FRAGMENT_IS_NEEDED_AND_DF_SET = 4,
   DESTINATION_SOURCE_ROUTE_FAILED = 5,
} icmp_dest_code_t;

typedef unsigned int icmp_code_t;

struct icmp_protocol {
    icmp_type_t type;
    icmp_code_t code;
    unsigned short checksum;
    unsigned int unused;
};

```


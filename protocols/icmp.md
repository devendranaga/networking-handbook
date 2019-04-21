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

version: 4
ihl: length of the header
tos: 0 (default and normal)
id, flags and fragoff: used in fragmentation
ttl: 8 bit value
protocol: 1 - icmp


| ICMP type | ICMP code |
|-----------|-----------|
| 3 (Destination unreachable) | 0 (destination network unreachable |
|                             | 1 ( host unreachable) |
|                             | 2 ( protocol unrechable) |
| 11 (time exceeded) | 0 (ttl exceeded in transit) |
|                    | 1 (fragment reassembly exceeded) |


**c header**

```c

// icmp types
typedef enum {
   DESTINATION_UNREACHABLE = 3,
   TIME_EXCEEDED = 11,
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

typedef unsigned int icmp_code_t;

struct icmp_protocol {
    icmp_type_t type;
    icmp_code_t code;
    unsigned short checksum;
    unsigned int unused;
};

```

**destination unreachable:**

1. if do not fragment is set, but fragmentation is required, then the gateway would send destination unreachable.



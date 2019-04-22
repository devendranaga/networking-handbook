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
|                             | 3 ( port unreachable) |
|                             | 4 ( fragment is neded and DF is set) |
|                             | 5 ( source route failed ) |
| 11 (time exceeded) | 0 (ttl exceeded in transit) |
|                    | 1 (fragment reassembly exceeded) |
| 12 (parameter problem) | 0 ( pointer indicates the error) |
| 4 (source quench) | 0 |
| 5 (redirect message) | 0 ( redirect datagrams from the network) |
|                      | 1 ( redirect datagrams from the host) |
|                      | 2 ( redirect datagrams from the tos and network) |
|                      | 3 ( redirect datagrams from the tos and host) |



**c header**

```c

// icmp types
typedef enum {
   DESTINATION_UNREACHABLE = 3,
   TIME_EXCEEDED = 11,
   PARAMETER_PROBLEM = 12,
   SOURCE_QUENCH = 4,
   REDIRECT_MESSAGE = 5,
   ECHO_REQUEST = 8,
   ECHO_REPLY = 0,
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

**time exceeded:**

1. if ttl is 0 at intermediate gateway, it is then discarded and the gateway will send with time exceeded.
2. if there is no fragment 0, then no time exceeded need to be sent.
3. if a host reassembling the fragments, cannot able to assemble all the fragments within its time, it discards the packet and then sends out a time exceeded.

**parameter problem:**

1. in case of parameter problem, the 1st byte of the unused portion 32 bit block is used as a pointer.

```

|-------------|------------|------------------------------|
| type        | code       | checksum                     |
|---------------------------------------------------------|
| pointer     | unused                                    |
|---------------------------------------------------------|

```

when gateway processing the received ip packet, finds an issues with the header elements in the ip packet, it then marks them using the pointer describing where in the byte exactly the problem is.


**source quench:**

the value of source quench set to 0. if the gateway does not have enough resources to process the packet, it may discard and for each discarded packet, it sends a source quench message.

if the destination sees that source is transmitting packets too fast than it can process, it may send source quench until atleast the source reduces its speed to a value that where it does not receive source quench no longer. 

**redirect message:**

```

0            1             2                  3
|------------|-------------|------------------|
| type       | code        | checksum         |
|---------------------------------------------|
| gateway internet address                    |
|---------------------------------------------|

```

The gateway address is the address to which the traffic is redirected.

If there is a nearest gateway that the host can communicate to (that is reducing the hops), then it would simply provide a redirect message to the host informing that the traffic is to be redirected to this gateway by specifying the "gateway address".

**echo request / reply messages:**

```

0          1           2                      3
|----------|-----------|----------------------|
| type     | code      | checksum             |
|---------------------------------------------|
| identifier           | sequence number      |
|---------------------------------------------|

```

identifier may be 0 always but can be a port number of tcp / udp process on top.

For each echo request packet, the sequence number is incremented and reply must contain same value without the increment. Sender must always increment.






















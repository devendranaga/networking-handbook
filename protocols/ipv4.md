# IPv4


```
0         3          7                      15                                31
|--------------------|----------------------|---------------------------------|
| version | IHL      |   type of service    |  total length                   |
|-----------------------------------------------------------------------------|
| identification                            | flags |  fragment offset        |
|-----------------------------------------------------------------------------|
| time to live       | protocol             |   header checksum               |
|-----------------------------------------------------------------------------|
|                 source address                                              |
|-----------------------------------------------------------------------------|
|                 destination address                                         |
|-----------------------------------------------------------------------------|
|                 options                                  | padding          |
|-----------------------------------------------------------------------------|


```




**Protocol in C :**

```c

struct ipv4 {
    uint8_t version;
    uint8_t internet_header_len;
    uint8_t type_of_service;
    uint16_t total_len;
    uint16_t identifier;
    uint8_t flags;
    uint16_t fragment_offset;
    uint8_t time_to_live;
    uint8_t protocol;
    uint16_t header_checksum;
    uint32_t source_address;
    uint32_t destination_address;
    uint8_t options[0]; // varilable in length
    uint8_t padding[0];
}

```

converting ipv4 string to ipv4 address in 32 bit form : `inet_addr`, `inet_aton`

```c
uint32_t ipaddr_int;

ipaddr_int = inet_addr("192.168.1.1");

```

version is set to 4 for ipv4.

IHL is length of internet header in 32 bit words. move offset to header length bytes give the data portion of the ipv4. min value of ihl is 5. that means 5 * 4 bytes = 20. maximum size can be 60 bytes and minium is 20 byte.

**type of service:**



```

0               2     3     4     5    6    7
|---------------|-----|-----|-----|----|----|
| precedence    |  D  |  T  |  R  | 0  | 0  |
|---------------|-----|-----|-----|----|----|

```

0 -2 is precedence: follows

| **type** | **description** |
|------|-------------|
| 0    | routine     |
| 1    | priority    |
| 2    | immediate   |
| 3    | flash       |
| 4    | flash override |
| 5    | critic/ecp  |
| 6    | internetwork control |
| 7    | network control |

D - delay bit: 0 - normal delay, 1 - low delay
T - throughput: 0 - normal throughput, 1 - high throughput
R - reliability: 0 - normal reliability, 1 - high reliability


**total length:**

total length is the length of the datagram mesaured in octets, including the internet header and data. This field is 16 bit and thus 65535 size is acceptable.

Preference of 576 bytes as default. It is receommended that hosts only send datagrams larger than 576 bytes if the destination is prepared to accept datagrams of larger.


**identification:**

set by the sender to assist in assmebling the packets at the receiver.


**flags:** 3 bit

| **bit** | **description** |
|-----|-------------|
| 0   | reserved, always 0 |
| 1   | 0 - may be fragmented , 1 - do not frgament |
| 2   | 0 - last fragment , 1 - more fragments |


**fragment off:**

this field is an offset from the big datagram that is sent by the sender. offset is measured in 8 bytes mutliples. the first fragment has offset 0.


### classes:

1.  multicast: 224.0.0.0 to 239.255.255.255 reserved for multicast
2. 224.0.0.1 - for all systems on this subnet
3. 224.0.0.2 - all routers on this subnet
4. subnetwork broadcast addresses - 192.168.0.255 (direct boradcast addresses)

in linux, to send a packet to the subnet broadcast address, the `SO_BROADCAST` socket option need to be set.






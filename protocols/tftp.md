# TFTP

TFTP can run on any protocol. UDP is default.

## packet format

```

0           2                n
|-----------|----------------|
| type      | -> content <-  |
|----------------------------|

```

## header

```c

typedef enum {
    RRQ = 1,
    WRQ,
    DATA,
    ACK,
    ERROR,
} tftp_op_t;

typedef enum {
    NOT_DEFINED = 0,
    FILE_NOT_FOUND,
    ACCESS_VIOLATION,
    DISK_FULL_OR_ALLOCATION_EXCEEDED,
    ILLEGAL_TFTP_OPERATION,
    UNKNOWN_TRANSFER_ID,
    FILE_ALREADY_EXISTS,
    NO_SUCH_USER,
} tftp_errocodes_t;

struct tftp_read_req {
    char *filename;
    char *mode;
};

struct tftp_data {
    uint16_t block_no;
    uint16_t *data;
};

struct tftp_ack {
    uint16_t block_no;
};

struct tftp_error {
    uint16_t errorcode;
    uint8_t *errmsg;
};

struct tftp_header {
    uint16_t type;
    uint8_t data[0]; // changes based on type .. see above structs
};

```


| **type** | **description** |
|----------|-----------------|
| 01 | Read Request |
| 02 | Write Request |
| 03 | Data |
| 04 | Ack |
| 05 | Error |


3 modes of transfer has been defined.
    -> netascii
    -> octet
    -> mail

## explanation of type field

**Read Request:**

Read and write requests must contain filename and a nullbyte of 0 saying its end of filename. After that, it must contain mode and a null byte of 0 describing the end.

format:

```
  2 bytes                 1 byte      1 byte
|-----------|------------|---|------|---|
| RRQ / WRQ | filename   | 0 | mode | 0 |
|---------------------------------------|

```

connection initilization:

1. send RRQ = 1 to another computer with TID: 69.
2. computer responds with Data = 3, with block_no 1.

1. data block length is fixed in length of 512 bytes.
2. each data block must be acknowledged with an ack packet before the next packet sender may provide.
3. less than 512 bytes mean a termination of data transfer (end of file reached at the sender may be)
4. if packet is lost, receiver timesout, sends the last packet back to sender (a data or may be an ack packet of last packet). The sender upon seeing this, will retransmit the lost packet to the receiver.
5. error packet neither acked nor retransmitted.



# TFTP

TFTP can run on any protocol. UDP is default.

## packet format

```

0           2                n
|-----------|----------------|
| type      | -> content <-  |
|----------------------------|

```

| **type** | **description** |
|----------|-----------------|
| 01 | Read Request |
| 02 | Write Request |
| 03 | Data |
| 04 | Ack |
| 05 | Error |

## explanation of type field

**Read Request:**

Read and write requests must contain filename and a nullbyte of 0 saying its end of filename. After that, it must contain mode and a null byte of 0 describing the end.



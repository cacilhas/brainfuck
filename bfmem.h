#ifndef _BFMEM_H
#define _BFMEM_H

#include <stdint.h>


struct __slot;

typedef struct __slot {
    int64_t        value;
    struct __slot *previous;
    struct __slot *next;
} slot_t;


slot_t *new_slots(size_t);
slot_t *next_slot(slot_t *);
slot_t *prev_slot(slot_t *);


#endif  // _BFMEM_H
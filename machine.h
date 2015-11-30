#ifndef _MACHINE_H
#define _MACHINE_H

#include "bfmem.h"
#include "btree.h"


typedef struct {
    slot_t  *memory;
    node_t  *tape;
    node_t **blocks;
    size_t   block_count;
} machine_t;


machine_t *new_machine(node_t *, size_t);
void machine_perform(machine_t *);


#endif  // _MACHINE_H

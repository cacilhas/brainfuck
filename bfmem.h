#ifndef _BFMEM_H
#define _BFMEM_H

#include <stdint.h>

#define BFMEMSIZE 5000


#pragma pack(push, 4)
typedef struct {
    int64_t  slots[BFMEMSIZE];
    size_t   position;
    int64_t *slot;
} memory_t;
#pragma pack(pop)


void initialise_memory(memory_t *);
void next_slot(memory_t *);
void prev_slot(memory_t *);


#endif  // _BFMEM_H
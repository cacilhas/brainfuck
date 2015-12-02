#include <string.h>
#include "bfmem.h"


void initialise_memory(memory_t *memory) {
    memset(memory->slots, 0, BFMEMSIZE);
    memory->position = 0;
    memory->slot = memory->slots;
}

void next_slot(memory_t *memory) {
    memory->position = (memory->position + 1) % BFMEMSIZE;
    memory->slot = memory->slots + memory->position;
}


void prev_slot(memory_t *memory) {
    memory->position = (BFMEMSIZE + memory->position - 1) % BFMEMSIZE;
    memory->slot = memory->slots + memory->position;
}

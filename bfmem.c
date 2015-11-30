#include <stdlib.h>
#include "bfmem.h"

slot_t *new_slot(int64_t value) {
    slot_t *slot = (slot_t *) malloc(sizeof(slot_t));
    slot->value = value;
    slot->previous = NULL;
    slot->next = NULL;
    return slot;
}


slot_t *next_slot(slot_t *slot) {
    slot_t *next = slot->next;
    if (next == NULL) {
        next = new_slot(0);
        slot->next = next;
        next->previous = slot;
    }
    return next;
}


slot_t *prev_slot(slot_t *slot) {
    slot_t *prev = slot->previous;
    if (prev == NULL) {
        prev = new_slot(0);
        slot->previous = prev;
        prev->next = slot;
    }
    return prev;
}

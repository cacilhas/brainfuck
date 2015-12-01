#include <stdlib.h>
#include "bfmem.h"

slot_t *new_slots(size_t count) {
    if (count == 0)
        return NULL;
    slot_t *slot = (slot_t *) malloc(sizeof(slot_t));
    slot->value = 0;
    slot->previous = NULL;
    slot_t *next = new_slots(count - 1);
    if (next)
        next->previous = slot;
    slot->next = next;
    return slot;
}


slot_t *next_slot(slot_t *slot) {
    slot_t *next = slot->next;
    if (next == NULL) {
        next = new_slots(128);
        slot->next = next;
        next->previous = slot;
    }
    return next;
}


slot_t *prev_slot(slot_t *slot) {
    slot_t *prev = slot->previous;
    if (prev == NULL) {
        prev = new_slots(1);
        slot->previous = prev;
        prev->next = slot;
    }
    return prev;
}

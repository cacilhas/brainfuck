#include <stdlib.h>
#include <iso646.h>
#include <stdio.h>
#include "bfmem.h"
#include "machine.h"


void machine_execute(machine_t *, const node_t *);


void initialise_machine(machine_t *machine, node_t *tape, size_t depth) {
    machine->tape = tape;
    initialise_memory(&machine->memory);
    machine->blocks = (node_t **) malloc(sizeof(node_t *) * depth);
    machine->block_count = 0;
}


void machine_perform(machine_t *machine) {
    node_t *current = machine->tape;

    while (current) {
        machine_execute(machine, current);

        if (current->zero) {
            if (current->nonzero) {
                if (*machine->memory.slot) {
                    machine->blocks[machine->block_count++] = current;
                    current = current->nonzero;

                } else
                    current = current->zero;

            } else
                current = current->zero;

        } else if (machine->block_count == 0)
            break;

        else
            current = machine->blocks[--machine->block_count];
    }
}


void machine_execute(machine_t *machine, const node_t *node) {
    char c;

    switch (node->op) {
        case '>':
            next_slot(&machine->memory);
            break;

        case '<':
            prev_slot(&machine->memory);
            break;

        case '+':
            ++(*machine->memory.slot);
            break;

        case '-':
            --(*machine->memory.slot);
            break;

        case '.':
            c = (const char) *machine->memory.slot;
            printf("%c", c);
            fflush(stdout);
            break;

        case ',':
            scanf("%c", (char *) machine->memory.slot);
            break;

        default:
            break;
    };
}

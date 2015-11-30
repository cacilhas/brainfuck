#include <stdlib.h>
#include <iso646.h>
#include <stdio.h>
#include "machine.h"


void machine_execute(machine_t *, const node_t *);


machine_t *new_machine(node_t *tape, size_t depth) {
    machine_t *machine = (machine_t *) malloc(sizeof(machine_t));
    machine->tape = tape;
    machine->memory = new_slot(0);
    machine->blocks = (node_t **) malloc(sizeof(node_t *) * depth);
    machine->block_count = 0;
    return machine;
}


void machine_perform(machine_t *machine) {
    node_t *current = machine->tape;

    while (current) {
        machine_execute(machine, current);

        if (current->zero) {
            if (current->nonzero) {
                if (machine->memory->value) {
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
            machine->memory = next_slot(machine->memory);
            break;

        case '<':
            machine->memory = prev_slot(machine->memory);
            break;

        case '+':
            ++machine->memory->value;
            break;

        case '-':
            --machine->memory->value;
            break;

        case '.':
            c = (const char) machine->memory->value;
            printf("%c", c);
            break;

        case ',':
            scanf("%c", (char *) &machine->memory->value);
            break;

        default:
            break;
    };
}

#include <stdlib.h>
#include <iso646.h>
#include "btree.h"
#include "machine.h"
#include "bfapi.h"

size_t depth = 0;
size_t block_count = 0;
node_t **blocks = NULL;
node_t *root = NULL;
node_t *statement = NULL;


void bf_add_operator(const char op) {
    if (blocks == NULL)
        blocks = (node_t **) malloc(sizeof(node_t *) * 4096);

    node_t *current = new_node();
    current->op = op;

    if (not statement)
        root = statement = current;

    else {
        current->back = statement;

        if (statement->op == '[') {
            statement->nonzero = current;
            blocks[block_count++] = statement;
            depth = block_count > depth ? block_count : depth;

        } else {
            if (statement->op == ']') {
                if (block_count == 0)
                    yyerror("] without [");
                statement = blocks[--block_count];
            }
            statement->zero = current;
        }
    }

    statement = current;
}


void bf_perform() {
    // Free memory (16KiB)
    free(blocks);
    blocks = NULL;

    machine_t machine;
    initialise_machine(&machine, root, depth);
    machine_perform(&machine);
}

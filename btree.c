#include <stdlib.h>
#include "btree.h"


node_t *new_node() {
    node_t *node = (node_t *) malloc(sizeof(node_t));
    node->op = 0;
    node->back = NULL;
    node->zero = NULL;
    node->nonzero = NULL;
    return node;
}

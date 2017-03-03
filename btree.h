#ifndef _NODES_H
#define _NODES_H

#pragma pack(push, 1)



struct __node;


typedef struct __node {
    char           op;
    struct __node *back;
    struct __node *zero;
    struct __node *nonzero;
} node_t;


node_t *new_node(void);


#pragma pack(pop)

#endif  // _NODES_H

#include "queue.h"


struct bst_node {                                                  struct bst_node * left;                                    struct bst_node * right;                                   int value;                                                 void* data;
};



                                                                                                                      void bst_insert_node (struct bst_node* head, struct bst_node* next);                                                  struct bst_node* bst_create_from_array(int* array, int size);                                                         struct bst_node* bst_find_node (struct bst_node* head, int value);                                                    struct bst_node * bst_create_node (int value, void * data);void bst_bfs_traverse (                                                    struct bst_node* head,
                void (*do_level_order)(struct bst_node *head));

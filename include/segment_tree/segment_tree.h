#ifndef __SEGMENT_TREE__
#define __SEGMENT_TREE__


struct sgt_node {
        int range_start;
        int range_end;
        struct sgt_node* left;
        struct sgt_node* right;
        void* data;
        void* lazy_data;
};

struct segment_tree {
        struct sgt_node* root;
        void* array;
        int array_size;
        struct sgt_node* (*merging_function) (struct sgt_node*, struct sgt_node*);
        struct sgt_node* (*construct_leaf) (void*, int);
};


void sgt_create_tree(struct segment_tree* sgt);
struct sgt_node* sgt_create_node(void *data, int range_start,int range_end);
#endif


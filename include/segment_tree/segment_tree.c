#include "segment_tree.h"
#include <stdlib.h>



struct sgt_node* sgt_create_node(void *data, int range_start, int range_end) {
	struct sgt_node* node = malloc(sizeof(struct sgt_node));
	node->data = data; 
	node->lazy_data = NULL;
	node->left = NULL;
	node->right = NULL;
	node->range_start = range_start;
	node->range_end = range_end;
	return node;

}


int __midpoint_get(int start, int end) {
	return (start+end)/2;
}



struct sgt_node* __sgt_create(struct segment_tree *sgt, int start, int end) {
	if (start == end) return (sgt->construct_leaf)(sgt->array, start);
	int left_start =  start;
	int left_end = __midpoint_get(start, end);
	int right_start = left_end + 1;
	int right_end = end;
	struct sgt_node* created_left_subtree = __sgt_create(sgt, left_start, left_end);
	struct sgt_node* created_right_subtree = __sgt_create(sgt, right_start, right_end);
	struct sgt_node* merged_head = (sgt->merging_function)(created_left_subtree, created_right_subtree);
	merged_head->left = created_left_subtree;
	merged_head->right = created_right_subtree;
	return merged_head;
}


void sgt_create_tree(struct segment_tree* sgt){
	int start = 0;
	int end = sgt->array_size-1;

	sgt->root =  __sgt_create(sgt, start, end); 
}



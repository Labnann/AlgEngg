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
	struct sgt_node* merged_head = (sgt->building_function)(created_left_subtree, created_right_subtree);
	merged_head->left = created_left_subtree;
	merged_head->right = created_right_subtree;
	return merged_head;
}


void sgt_create_tree(struct segment_tree* sgt){
	int start = 0;
	int end = sgt->array_size-1;

	sgt->root =  __sgt_create(sgt, start, end); 
}


int at_left(struct sgt_node* head, int want_point){
	return want_point <  head->range_start;

}

int at_right(struct sgt_node* head, int want_point){
	return want_point >  head->range_end;

}


void* __sgt_range_read(struct segment_tree* sgt, struct sgt_node* head, int wanted_start, int wanted_end){
	
	if (head == NULL) return NULL;

	if (head->lazy_data && (head -> range_start != head-> range_end)){
		head->left->lazy_data = head->lazy_data;
		head->right->lazy_data= head->lazy_data;
		head->lazy_data = NULL;
	}

	int node_has_everything = 
		at_left(head, wanted_start-1) &&
		at_right(head, wanted_end+1);

	if (node_has_everything) {
		void* data = (sgt->data_reader)(head->data);
		void* lazy_data = (sgt->data_reader)(head->lazy_data); 
		return sgt->unify_data(data, lazy_data);
	}

	int node_has_nothing = (at_left (head, wanted_start) && at_left (head, wanted_end))
			||     (at_right(head, wanted_start) && at_right(head, wanted_end));	

	if (node_has_nothing) return NULL;

	int node_has_something = !node_has_nothing;

	if (node_has_something) {
		void* left_subtree_data = __sgt_range_read(sgt, head->left, wanted_start, wanted_end);
		void* right_subtree_data = __sgt_range_read(sgt, head->right, wanted_start, wanted_end);	
		return (sgt->unify_data)(left_subtree_data, right_subtree_data);
	}
}

void* sgt_range_read(struct segment_tree* sgt, int range_start, int range_end) {
	return __sgt_range_read(sgt, sgt->root, range_start, range_end);		
}



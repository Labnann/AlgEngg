#include "../../include/segment_tree/segment_tree.h"
#include <stdlib.h>

struct sgt_node* create_base_leaf(void *data_array, int leaf_position) {
	int *array = data_array;
	int *data = malloc(sizeof(int));
	*data = array[leaf_position];
	return sgt_create_node(data, leaf_position, leaf_position);
}

struct sgt_node* sum_node (struct sgt_node* left_head, struct sgt_node* right_head){
	int left_head_data = *(int*) left_head->data;
	int right_head_data = *(int*) right_head->data;
	int* sum_data = malloc(sizeof(int));

	int start = left_head->range_start;
	int end = right_head->range_end;

	*sum_data = left_head_data + right_head_data;
	struct sgt_node* merged_node = sgt_create_node(sum_data, start, end);	
	return merged_node;
}


int main(){
	int a[9] = {10, 2, 9, 5, 3, 7, 13, 21, 9};
	struct segment_tree sgt = {
		.array = (void*) a,
		.array_size = 9,
		.root = NULL,
		.merging_function = &sum_node,
		.construct_leaf = &create_base_leaf 

	}; 

	sgt_create_tree(&sgt);


}

#include <stdlib.h>
#include <stdio.h>

#include "../../include/segment_tree/segment_tree.h"

struct sgt_node* create_base_leaf(void *data_array, int leaf_position) {
	int *array = data_array;
	int *data = malloc(sizeof(int));
	*data = array[leaf_position];
	return sgt_create_node(data, leaf_position, leaf_position);
}

void* data_reader (void* data)
{
	if (data == NULL) return NULL;
	int* read_data = malloc(sizeof (int));
	*read_data = *(int*) data;
	return read_data;
}

void* unify_node_sum (void* left_data, void* right_data)
{
	int left_sum, right_sum;

	left_sum = (left_data ==NULL)?	   0: 	*(int*) left_data;
	right_sum = (right_data == NULL )? 0:	*(int*) right_data;
	int *unified_sum = malloc(sizeof (int));
	*unified_sum = left_sum + right_sum;
	free(left_data);
	free(right_data);
	return unified_sum;
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
		.building_function = &sum_node,
		.construct_leaf = &create_base_leaf,
		.unify_data = & unify_node_sum,
		.data_reader = & data_reader

	}; 

	sgt_create_tree(&sgt);

	printf("%d\n", *(int *) sgt_range_read(&sgt, 0, 2));
	printf("%d\n", *(int *) sgt_range_read(&sgt, 1, 2));
        printf("%d\n", *(int *) sgt_range_read(&sgt, 2, 2));
	printf("%d\n", *(int *) sgt_range_read(&sgt, 3, 2));
	printf("%d\n", *(int *) sgt_range_read(&sgt, 4, 2));


}

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


void multiply_data (void* data, int multiplier)
{
	if (data == NULL) return;
	int *data_pointer = (int*) data;
	*data_pointer = *data_pointer * multiplier;
}

int min(int x, int y) {
	return x < y? x:y;
}

void* unify_node_min (void* left_data, void* right_data)
{
	int left_min, right_min;

	left_min= (left_data ==NULL)?	   0: 	*(int*) left_data;
	right_min = (right_data == NULL )? 0:	*(int*) right_data;
	int *unified_min = malloc(sizeof (int));
	*unified_min = min(left_min, right_min);
	free(left_data);
	free(right_data);
	return unified_min;
}

struct sgt_node* min_node (struct sgt_node* left_head, struct sgt_node* right_head){
	int left_head_data = *(int*) left_head->data;
	int right_head_data = *(int*) right_head->data;
	int* min_data = malloc(sizeof(int));

	int start = left_head->range_start;
	int end = right_head->range_end;

	*min_data = min(left_head_data, right_head_data);
	struct sgt_node* merged_node = sgt_create_node(min_data, start, end);	
	return merged_node;
}

int stdin_int()
{
	int data;
	scanf("%d",&data);
	return data;
}


int main(){
	int size = stdin_int();
	int *a = malloc(sizeof(int)*size);

	for (int i = 0; i < size; i++)
	{
		a[i] = stdin_int();
	}
	struct segment_tree sgt = {
		.array = (void*) a,
		.array_size = size,
		.root = NULL,
		.building_function = &min_node,
		.construct_leaf = &create_base_leaf,
		.unify_data = & unify_node_min,
		.data_reader = & data_reader,
		.data_multiplier = & multiply_data

	}; 
	sgt_create_tree(&sgt);
	
	int query_num = stdin_int();
	while(query_num--){
		int first = stdin_int();
		int second= stdin_int();
		int result = *(int *)sgt_range_read(&sgt, first, second);	
		printf("%d\n", result);
	}

}

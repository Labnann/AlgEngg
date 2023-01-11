#include <stdio.h>

#include "../../include/bst.h"
#include "../../include/queue.h"

int highest_in_right_till(struct bst_node node, int end){


}

int highest_in_path(struct bst_node* node, int start, int end){
   int rr_case = node->value < start && node->value < end;
   int ll_case = node->value >= start && node->value >= end;

   if (ll_case) return highest_in_path(node->left, start, end);
   if (rr_case) return highest_in_path(node->right, start, end);

   return highest_in_right_till(node, end);

}



int main() {

	int number;
	struct queue *path1, *path2;

	path1 = queue_create();
	path2 = queue_create();


	struct bst_node * bst = NULL;
	int root = 50;

        bst = bst_create_node(root, NULL);

	int node_in[8] = {50, 75, 25, 29, 45, 60, 10, 80};

	int i = 0;

	while (i<8){
		struct bst_node *next= bst_create_node(node_in[i], NULL);
		bst_insert_node(bst, next);
		i++;
	}
	

	printf("%d", bst_find_node(bst, 29)->value);


}

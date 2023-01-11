#include <stdio.h>

#include "../../include/bst.h"


int highest_in_right_till(struct bst_node *node, int end){
	if (end < node->value) return node->value;
	if (end > node->value) return highest_in_right_till(node->right, end);
	return end;

}

int highest_in_path(struct bst_node* node, int start, int end){
   int rr_case = node->value < start && node->value < end;
   int ll_case = node->value > start && node->value > end;

   if (ll_case) return highest_in_path(node->left, start, end);
   if (rr_case) return highest_in_path(node->right, start, end);

   return highest_in_right_till(node, end);

}



int main() {

	int number;
	struct queue *path1, *path2;

	int root = 50;
	int test_cases;

	int node_in[1000];

	int size = 0, scanned, scanned2;

	do{
		scanf("%d", &scanned);
		node_in[size] = scanned;
		size++;

	}while(scanned != -1);

        struct	bst_node *bst = bst_create_from_array(node_in, size); 	

	scanf("%d", &test_cases);
	scanned = 10;
	scanned2 =80;

	while (test_cases--) {
		 scanf("%d%d", &scanned, &scanned2);
		 printf("%d\n", highest_in_path(bst, scanned, scanned2));
		
	}



}

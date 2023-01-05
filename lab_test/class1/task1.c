#include <stdio.h>

#include "../../include/bst.h"

int is_reserved(struct bst_node * bst, int value) {
	return bst_find_node(bst, value) != NULL;
}
void print_node(struct bst_node * head) {
	if (head != NULL && head->data != NULL) 
		printf("%d ", 
				head -> value);
}


void extra_reserve (struct bst_node *bst, int number){
	int flag = 1;
	bst_insert_node(bst, bst_create_node(number+3, NULL));
	bst_insert_node(bst, bst_create_node(number+2, NULL));
	bst_insert_node(bst, bst_create_node(number+1, NULL));
	bst_insert_node(bst, bst_create_node(number-1, NULL));
	bst_insert_node(bst, bst_create_node(number-2, NULL));
	bst_insert_node(bst, bst_create_node(number-3, NULL));

}


int main() {
	int number;
	int flag =1;

	struct bst_node * bst = NULL;
	scanf("%d", & number);
	bst = bst_create_node(number, &flag);
	extra_reserve(bst, number);
	bst_dfs_traverse(bst, NULL, & print_node, NULL);
	do {
		printf("\n");
		scanf("%d", & number);
		if (number == -1) break;
		int reserved = is_reserved(bst, number);
		if (!reserved){
			extra_reserve(bst, number);
			bst_insert_node(bst, bst_create_node(number, &flag));

		}
		bst_dfs_traverse(bst, NULL, & print_node, NULL);
		if (reserved) printf("(Reservation failed)\n");


	} while (1);

}

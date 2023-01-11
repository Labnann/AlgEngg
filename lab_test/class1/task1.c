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

int abs(int x){
	return x<0? -x : x;
}
int is_reservable(struct bst_node * head, struct bst_node* next) {
	return abs(head->value - next->value) > 3;
}

int main() {
	int number;
	int flag =1;

	struct bst_node * bst = NULL;
	scanf("%d", & number);
	bst = bst_create_node(number, &flag);
	bst_dfs_traverse(bst, NULL, & print_node, NULL);
	printf("\n");

	do {
		scanf("%d", & number);
		if (number == -1) break;
		int reserved =	bst_conditional_insert(bst, bst_create_node(number, &flag), is_reservable);

		bst_dfs_traverse(bst, NULL, & print_node, NULL);
		if (!reserved) printf("(Reservation failed)");
		printf("\n");


	} while (1);

}

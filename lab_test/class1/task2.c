#include <stdio.h>

#include "../../include/bst.h"

int is_reserved(struct bst_node * bst, int value) {
	return bst_find_node(bst, value) != NULL;
}
void print_node(struct bst_node * head) {
	if (head != NULL ) 
		printf("%d ", 
				head -> value);
}
int main() {
	int number;

	struct bst_node * bst = NULL;
	scanf("%d", &number);
	bst = bst_create_node(number, NULL);
	do {
		scanf("%d", & number);
		if (number == -1) break;
		bst_insert_node(bst, bst_create_node(number, NULL));
		

	}

	while (1);

	bst_bfs_traverse(bst, &print_node);


}

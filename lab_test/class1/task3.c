#include <stdio.h>

#include "../../include/bst.h"
#include "../../include/queue.h"





struct bst_node* construct_path (struct bst_node* head, int value, struct queue* q){
	queue_push(q, head);
        if (head == NULL) return NULL;
        if (head->value == value) return head;             
        if (value > head->value)
                return construct_path (head->right, value, q);
	
        return construct_path(head->left, value, q);                                                                                                                                 }

int main() {
	int number;
	struct queue *path1, *path2;

	path1 = queue_create();
	path2 = queue_create();


	struct bst_node * bst = NULL;
	scanf("%d", &number);
	bst = bst_create_node(number, NULL);
	do {
		scanf("%d", & number);
		if (number == -1) break;
		bst_insert_node(bst, bst_create_node(number, NULL));
		

	}

	while (1);
	
	int x = 25;
	int y = 60;

	construct_path(bst, x, path1); 
	construct_path(bst, y, path2); 



	while (queue_size_get(path1) != 0)
	{
		struct bst_node* temp = (struct bst_node*) queue_pop(path1);
		printf("%d ", temp->value);
	}

	printf("\n");



	while (queue_size_get(path2) != 0)
	{
		struct bst_node *temp = (struct bst_node*) queue_pop(path2);
		printf("%d ", temp->value);
	}
	printf("\n");




}

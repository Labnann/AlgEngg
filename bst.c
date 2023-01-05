#include <stdio.h>
#include <stdlib.h>
#include "./include/queue.h"


struct node {
	struct node * left;
	struct node * right;
	int value;
	void* data;
};


struct node * create_node (int value, void * data) {
	struct node*  head = malloc(sizeof(struct node));
	head->value = value;
	head->left = NULL;
	head->right = NULL;
	head->data = data;

	return head;
}


void put_at_right(struct node * head, struct node* next){
	head->right = next;
}

void put_at_left (struct node *head, struct node *next) {
	head->left = next;
}


int has_left_subtree (struct node * head){
	return head->left != NULL;
}

int has_right_subtree (struct node * head){
	return head->right != NULL;
}


void bst_insert_node (struct node* head, struct node* next){


	if (next->value > head->value){
		if (has_right_subtree(head))
			return bst_insert_node(head->right, next); 
		return put_at_right(head, next);
	}
	else {
		if (has_left_subtree(head)) 
			return bst_insert_node(head->left,  next);
		return put_at_left(head, next);

	}


}

struct node* bst_create(int* array, int size)
{
	int i = 0;
	if (size == 0) return NULL;	
	struct node *head = create_node(array[0], NULL);


	for (i = 1; i < size; i++){
		struct node *next = create_node(array[i], NULL);
		bst_insert_node(head, next);

	}

	return head;

}



struct node* bst_find_node (struct node* head, int value){
	if (head == NULL) return NULL;
	if (head->value == value) return head;

	if (value > head->value)
		return bst_find_node (head->right, value);

	return bst_find_node(head->left, value);
	

}


void bfs_traverse (
		struct node* head,
		void (*do_level_order)(struct node *head)
		)
{
	struct queue * q = queue_create();

	queue_push (q, (void *) head);


	while (queue_size_get(q) != 0){
		struct node* popped = (struct node*) queue_pop(q);	
		do_level_order(popped);

		if (popped->left != NULL)
			queue_push(q,(void *) popped->left);

		if (popped->right != NULL)
			queue_push(q,(void *) popped->right);


	}


}

void dfs_traverse (
		struct node * head,
		void (*do_pre_order) (struct node *head),
		void (*do_in_order) (struct node *head),
		void (*do_post_order) (struct node *head)

		){
	if (head == NULL) return;

	if (do_pre_order != NULL) do_pre_order(head);

	dfs_traverse(head->left, do_pre_order, do_in_order, do_post_order);

	if (do_in_order != NULL) do_in_order(head);

	dfs_traverse(head->right, do_pre_order, do_in_order, do_post_order);

	if (do_post_order != NULL) do_post_order(head);

}


void print_node(struct node* head){
	if (head != NULL)
		printf("%d ", head->value);
}

int main () {
	int array[20] = {50, 75, 25, 29, 45, 60, 10, 80};
	struct node *bst = bst_create(array, 8);
	dfs_traverse(bst, NULL, &print_node, NULL);

	printf("\n");
	bfs_traverse(bst, &print_node);
	printf("\n");


	printf("%d\n", bst_find_node(bst, 47) == NULL);
	printf("%d\n", bst_find_node(bst, 45) == NULL);
	printf("%d\n", bst_find_node(bst, 75) == NULL);
	printf("%d\n", bst_find_node(bst, 87) == NULL);
}



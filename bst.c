#include <stdio.h>
#include <stdlib.h>
#include "./include/queue.h"


struct node {
	struct node * left;
	struct node * right;
	int value;
};


struct node * create_node (int value) {
	struct node*  head = malloc(sizeof(struct node));
	head->value = value;
	head->left = NULL;
	head->right = NULL;

	return head;
}


void insert_to_right(struct node * head, struct node* next){
	head->right = next;
}

void insert_to_left (struct node *head, struct node *next) {
	head->left = next;
}


int has_left_subtree (struct node * head){
	return head->left != NULL;
}

int has_right_subtree (struct node * head){
	return head->right != NULL;
}


void append_binary_node (struct node* head, struct node* next){


	if (next->value > head->value){
		if (has_right_subtree(head))
			return append_binary_node(head->right, next); 
		return insert_to_right(head, next);
	}
	else {
		if (has_left_subtree(head)) 
			return append_binary_node(head->left,  next);
		return insert_to_left(head, next);

	}


}

struct node* create_bst(int* array, int size)
{
	int i = 0;
	if (size == 0) return NULL;	
	struct node *head = create_node(array[0]);


	for (i = 1; i < size; i++){
		struct node *next = create_node(array[i]);
		append_binary_node(head, next);
	}

	return head;

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
	struct node *bst = create_bst(array, 8);
	dfs_traverse(bst, NULL, &print_node, NULL);

	printf("\n");
	bfs_traverse(bst, &print_node);
}



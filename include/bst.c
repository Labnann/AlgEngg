#include <stdio.h>
#include <stdlib.h>
#include "bst.h"



struct bst_node * bst_create_node (int value, void * data) {
	struct bst_node*  head = malloc(sizeof(struct bst_node));
	head->value = value;
	head->left = NULL;
	head->right = NULL;
	head->data = data;

	return head;
}
void put_at_right(struct bst_node * head, struct bst_node* next){
	head->right = next;
}

void put_at_left (struct bst_node *head, struct bst_node *next) {
	head->left = next;
}


int has_left_subtree (struct bst_node * head){
	return head->left != NULL;
}

int has_right_subtree (struct bst_node * head){
	return head->right != NULL;
}


void bst_insert_node (struct bst_node* head, struct bst_node* next){


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

struct bst_node* bst_create_from_array(int* array, int size)
{
	int i = 0;
	if (size == 0) return NULL;	
	struct bst_node *head = bst_create_node(array[0], NULL);


	for (i = 1; i < size; i++){
		struct bst_node *next = bst_create_node(array[i], NULL);
		bst_insert_node(head, next);

	}

	return head;

}



struct bst_node* bst_find_node (struct bst_node* head, int value){
	if (head == NULL) return NULL;
	if (head->value == value) return head;

	if (value > head->value)
		return bst_find_node (head->right, value);

	return bst_find_node(head->left, value);


}


void bst_bfs_traverse (
		struct bst_node* head,
		void (*do_level_order)(struct bst_node *head)
		)
{
	struct queue * q = queue_create();

	queue_push (q, (void *) head);


	while (queue_size_get(q) != 0){
		struct bst_node* popped = (struct bst_node*) queue_pop(q);	
		do_level_order(popped);

		if (popped->left != NULL)
			queue_push(q,(void *) popped->left);

		if (popped->right != NULL)
			queue_push(q,(void *) popped->right);


	}


}

void bst_dfs_traverse (
		struct bst_node * head,
		void (*do_pre_order) (struct bst_node *head),
		void (*do_in_order) (struct bst_node *head),
		void (*do_post_order) (struct bst_node *head)

		){
	if (head == NULL) return;

	if (do_pre_order != NULL) do_pre_order(head);

	bst_dfs_traverse(head->left, do_pre_order, do_in_order, do_post_order);

	if (do_in_order != NULL) do_in_order(head);

	bst_dfs_traverse(head->right, do_pre_order, do_in_order, do_post_order);

	if (do_post_order != NULL) do_post_order(head);

}



int bst_conditional_insert( 
		struct bst_node* head, 
		struct bst_node* next,  
		int (*is_acceptable)(struct bst_node*, struct bst_node*) 
		)
{

	if (!is_acceptable(head, next)) return 0;

	if (next->value > head->value){
		if (has_right_subtree(head))
			return bst_conditional_insert(head->right, next, is_acceptable); 
		 put_at_right(head, next);
		 return 1;
	}
	else {
		if (has_left_subtree(head)) 
			return bst_conditional_insert(head->left, next, is_acceptable);
		put_at_left(head, next);
		return 1;

	}


}

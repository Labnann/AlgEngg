#include <stdio.h>
#include <stdlib.h>


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



void in_order_traverse(struct node * head){
	if (head == NULL) return;
	in_order_traverse(head->left);
	printf("%d ", head->value);
	in_order_traverse(head->right);
}




int main () {
 int array[20] = {50, 75, 25, 29, 45, 60, 10, 80};
 struct node *bst = create_bst(array, 8);
 in_order_traverse(bst);
}



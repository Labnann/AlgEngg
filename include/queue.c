#include <stdlib.h>
#include "queue.h"


struct list_head {
        struct list_head* next;                                    struct list_head* prev;
        void* val;
};

struct list_head* list_create_head(void* val)
{
        struct list_head* list = malloc(sizeof(struct list_head));
	list->prev = NULL;
	list->next = NULL;
	list->val = val;

	return list;
};

void list_destroy_head (struct list_head* head) 
{
	if (head == NULL) return;

	struct list_head* prev = head->prev;
	struct list_head* next = head->next;

	if (prev != NULL)
		prev->next = next;
	if (next != NULL)
		next->prev = prev;
	free(head);
	return;
}

void list_insert_next (struct list_head* target, struct list_head* head) 
{
	target->next = head;
	head->prev = target;
}



void list_insert_prev (struct list_head* target, struct list_head* head) 
{
	head->next = target;
	target->prev = head;
}







struct queue* queue_create () 
{
	struct queue *q = malloc(sizeof(struct queue));
	q->front = NULL; 
	q->back = NULL;
	q->size = 0;
	return q;
}


void queue_push (struct queue* q, void* val) 
{
	struct list_head *new_head =  list_create_head(val);
	if (q->back) 
	        list_insert_prev(q->back, new_head);	
	else {
		q->front = new_head;
	}
	q->back = new_head;
	q->size++;
	return;
}	


void* queue_pop (struct queue* q) 
{
	if (q->size == 0) return NULL;
	struct list_head* current_front = q->front;
	void* val = current_front->val;
	q->front = current_front->prev;
	list_destroy_head(current_front);
	q->size--;

	return val;
}


void*  queue_front_get (struct queue* q) 
{
	if (q->size == 0) return NULL;
	return q->front->val;
}


void* queue_back_get (struct queue* q) 
{
	if (q->size == 0) return NULL;
	return q->back->val;
}


int queue_size_get (struct queue* q)
{
	return q->size;
}

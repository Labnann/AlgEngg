#ifndef __QUEUE__
#define __QUEUE__

struct queue {
        struct list_head* front;
	struct list_head* back;
	int size;
};




struct queue* queue_create();
void queue_push (struct queue* q, void* val);
void* queue_pop (struct queue* q);
void* queue_front_get (struct queue* q);
void* queue_back_get (struct queue* q);
int queue_size_get (struct queue* q);

#endif

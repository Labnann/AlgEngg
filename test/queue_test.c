#include <stdio.h>
#include "../include/queue.h"

int main(){
	struct queue* q = queue_create(); 
	
	int x[50]; 
	int i = 0;

	x[i] = 10;
        queue_push(q, (void *) &x[i++]);
	printf("%d\n", *(int *) queue_back_get(q));
	x[i] = 20;
        queue_push(q, (void *) &x[i++]);
	printf("%d\n", *(int *) queue_back_get(q));
	x[i] = 30;
        queue_push(q, (void *) &x[i++]);
	printf("%d\n", *(int *) queue_back_get(q));
	x[i] = 40;
        queue_push(q, (void *) &x[i++]);
	printf("%d\n", *(int *) queue_back_get(q));
	x[i] = 50;
        queue_push(q, (void *) &x[i++]);
	printf("%d\n", *(int *) queue_back_get(q));
	x[i] = 60;
        queue_push(q, (void *) &x[i++]);
	printf("%d\n", *(int *) queue_back_get(q));
	x[i] = 70;
        queue_push(q, (void *) &x[i++]);
	printf("%d\n", *(int *) queue_back_get(q));
	x[i] = 75;
        queue_push(q, (void *) &x[i++]);
	printf("%d\n", *(int *) queue_back_get(q));
	x[i] = 80;
        queue_push(q, (void *) &x[i++]);
	printf("%d\n", *(int *) queue_back_get(q));
	x[i] = 85;
        queue_push(q, (void *) &x[i++]);
	printf("%d\n", *(int *) queue_back_get(q));
	x[i] = 90;
        queue_push(q, (void *) &x[i++]);
	printf("%d\n", *(int *) queue_back_get(q));








	for (i = 0; queue_size_get(q); i++)
	{
		int popped = *(int *) queue_pop(q);
		printf("popped %d, front %d, back %d, %d\n", 
			popped 
//			*(int *) queue_front_get(q),
//			*(int *) queue_back_get(q),
//			queue_size_get(q)
		      );
	}




         
}

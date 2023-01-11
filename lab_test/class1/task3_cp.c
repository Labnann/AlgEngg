#include <stdio.h>

#include "../../include/bst.h"
#include "../../include/queue.h"




int main() {
	int number;
	struct queue *path1, *path2;

	path1 = queue_create();
	path2 = queue_create();


	struct bst_node * bst = NULL;
	int root = 50;

        bst = bst_create_node(root, NULL);

	int node_in = {50, 75, 25, 29, 45, 60, 10, 80};

	int i = 0;

	while (i<8){
		bst_insert_node(node_in[i], NULL);
		i++;
	}
	

	printf("%d", bst_find_node(29)->value);


}

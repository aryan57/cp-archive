/*
	group : local
	name : bstLevelOrder.c
	srcPath : /home/aryan/Dropbox/Documents from PC/free/eugene/pa2/bstLevelOrder/bstLevelOrder.c
	url : /home/aryan/Dropbox/Documents from PC/free/eugene/pa2/bstLevelOrder/bstLevelOrder.c
*/
#include <stdlib.h>
#include <stdio.h>

// A program to perform a LEVEL ORDER (BREADTH-FIRST) TRAVERSAL of a binary search tree

// BINARY SEARCH TREE

struct BSTNode
{
	int key;
	struct BSTNode *l_child; // nodes with smaller key will be in left subtree
	struct BSTNode *r_child; // nodes with larger key will be in right subtree
};
typedef struct BSTNode BSTNode;

// Add new data to the BST using recursion
void insert(BSTNode **root, int key)
{
	if (*root == NULL)
	{
		BSTNode *new_node = (BSTNode *)malloc(sizeof(BSTNode));
		new_node->key = key;
		new_node->l_child = NULL;
		new_node->r_child = NULL;
		*root = new_node;
		return;
	}
	if ((*root)->key == key)
		return;
	if ((*root)->key > key)
	{
		if ((*root)->l_child == NULL)
		{
			BSTNode *new_node = (BSTNode *)malloc(sizeof(BSTNode));
			new_node->key = key;
			new_node->l_child = NULL;
			new_node->r_child = NULL;
			(*root)->l_child = new_node;
			return;
		}
		insert(&((*root)->l_child), key);
	}
	else
	{
		if ((*root)->r_child == NULL)
		{
			BSTNode *new_node = (BSTNode *)malloc(sizeof(BSTNode));
			new_node->key = key;
			new_node->l_child = NULL;
			new_node->r_child = NULL;
			(*root)->r_child = new_node;
			return;
		}
		insert(&((*root)->r_child), key);
	}
}

// Delete the BST using recursion
void delete_bst(BSTNode *root)
{
	if (root == NULL)
		return;
	BSTNode *l = root->l_child;
	BSTNode *r = root->r_child;
	free(root);
	delete_bst(l);
	delete_bst(r);
}

// LINKED LIST IMPLEMENTATION OF QUEUE
struct QueueNode
{
	BSTNode* val;
	struct QueueNode *prev;
	struct QueueNode *next;
};
typedef struct QueueNode QueueNode;
struct Queue
{
	QueueNode *front;
	QueueNode *back;
};
typedef struct Queue Queue;

// queue needed for level order traversal
// Append a new QueueNode to the back of the Queue
void enqueue(Queue *queue, BSTNode *data)
{
	if(data==NULL)return;
	QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
	new_node->val = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (queue->front == NULL)
	{
		queue->front = new_node;
		queue->back = new_node;
	}
	else
	{
		queue->back->next = new_node;
		new_node->prev = queue->back;
		queue->back = new_node;
	}
}
BSTNode* dequeue(Queue *queue)
{
	if (queue->front == NULL)
	{
		// underflow
		return NULL;
	}
	else if (queue->front == queue->back)
	{
		BSTNode* answer = queue->front->val;
		free(queue->front);
		queue->front = NULL;
		queue->back = NULL;
		return answer;
	}
	else
	{
		QueueNode *new_head = queue->front->next;
		BSTNode* answer = queue->front->val;
		new_head->prev = NULL;
		free(queue->front);
		queue->front = new_head;
		return answer;
	}
}

int main(int argc, char *argv[])
{

	BSTNode *root = NULL;
	int key;
	while (scanf("%d", &key) != EOF)
	{
		insert(&root, key);
	}


	// FILE *fp = fopen(argv[1], "r");
	// if (!fp)
	// {
	// 	perror("fopen failed");
	// 	return EXIT_FAILURE;
	// }
	// BSTNode *root = NULL;
	// int key;
	// while (fscanf(fp, "%d", &key) != EOF)
	// {
	// 	insert(&root, key);
	// }
	// fclose(fp);

	// USE A QUEUE TO PERFORM LEVEL ORDER TRAVERSAL
	Queue *q = (Queue *)malloc(sizeof(Queue));
	enqueue(q, root);
	while (1)
	{
		BSTNode* front = dequeue(q);
		if(front==NULL)break;
		printf("%d ",front->key);
		enqueue(q,front->l_child);
		enqueue(q,front->r_child);
	}
	
	delete_bst(root);
	free(q);
	return EXIT_SUCCESS;
}

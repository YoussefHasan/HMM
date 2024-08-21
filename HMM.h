#ifndef HMM_H
#define HMM_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE		1024*1024*1024	// SIZE = 100MB
#define STDIN		0
#define STDOUT		1
#define STDERR		2

#define MAX_LINE	1024
#define DECIMAL		10
#define getInt(x, ...)	atoi(x)

struct node
{
	size_t size;		// The size field represents an integer value stored in the node
	struct node* next;	// The next pointer points to the next node in the linked list
	struct node* prev;	// The prev pointer points to the previous node in the linked list
};

void Greeting();
void* HmmAlloc(size_t);
void HmmFree(void*);
void HmmCheckSize();
void HmmInsertAtBegin(int);
void HmmnsertAtEnd(int);
void HmmInsertAfterNode(struct node*, int);
void HmmDeleteAtBegin();
void HmmDeleteAtEnd();
void HmmDeleteNode(int);
#endif

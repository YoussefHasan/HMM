#ifndef Hmm_H
#define Hmm_H

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
		// The size field represents an integer value stored in the node
	// The next pointer points to the next node in the linked list
	// The prev pointer points to the previous node in the linked list
#define getInt(x, ...)	atoi(x)

struct node
{
	size_t size;
	struct node* next;
	struct node* prev;
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

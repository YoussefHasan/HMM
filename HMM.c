#include "HMM.h"

char heap[SIZE];
int program_break;

struct node *head = NULL;
struct node *current = NULL;
struct node* tail = NULL;


void Greeting()
{
	char *text = "\nHi bud, this is a \033[1mHeap Memory Simulation\033[0m.\nHere's a simple guide for its functions:\n\t\033[1;3;4malloc\033[0m: Allocates [size] bytes at Heap.\n\t\033[1;3;4mfree\033[0m: De-allocates [size] bytes at Heap.\n\t\033[1;3;4mcheck\033[0m: allocates [size] bytes at Heap.\n";
	write(STDOUT, text, strlen(text));
}

void* HmmAlloc(size_t size) {
    // Check if the requested size is valid
    if (size <= 0) {
        return NULL;
    }

    // Search for a free block that is large enough to satisfy the request
    struct node* current = head;
    while (current != NULL) {
        if (current->size >= size) {
            // Found a suitable free block, remove it from the list
            if (current == head) {
                head = current->next;
            } else {
                current->prev->next = current->next;
            }

            // Return the address of the payload (after the header)
            return (void*)((char*)current + sizeof(struct node));
        }
        current = current->next;
    }

    // If no suitable free block is found, allocate a new block from the heap
    if (program_break + sizeof(struct node) + size <= SIZE) {
        struct node* new_block = (struct node*)(heap + program_break);
        new_block->size = size;
        new_block->next = NULL;
        new_block->prev = tail;
        if (tail != NULL) {
            tail->next = new_block;
        } else {
            head = new_block;
        }
        tail = new_block;
        program_break += sizeof(struct node) + size;
        return (void*)((char*)new_block + sizeof(struct node));
    }

    // If the heap is exhausted, return NULL
    return NULL;
}

void HmmFree(void* ptr) {
    // Check if the pointer is valid
    if (ptr == NULL) {
        return;
    }

    // Calculate the address of the header
    struct node* header = (struct node*)((char*)ptr - sizeof(struct node));

    // Add the block to the free block list
    header->next = head;
    header->prev = NULL;
    if (head != NULL) {
        head->prev = header;
    } else {
        tail = header;
    }
    head = header;
}
void HmmCheckSize()
{
	printf("total Heap size = %d bytes.\n", SIZE);
	printf("current allocated memory = %d bytes.\n", program_break);
	printf("current free memory = %d bytes.\n\n", (SIZE - program_break));
}

void* HmmAllocNode()
{
	void* ptr = HmmAlloc(sizeof(struct node));	// Try to allocate memory for a new node with size sizeof(struct node)
	if (ptr == NULL)
	{
		printf("Memory allocation failed\n");
		return NULL;
	}
	return ptr;		// Return the allocated memory as a pointer to a struct node
}

void HmmFreeNode(void* ptr)
{
	HmmFree(ptr);
}

void HmmInsertAtBegin(int value)
{
	void* ptr = HmmAllocNode();	// Allocate memory for a new node
	if (ptr == NULL)	return;
	struct node* newNode = (struct node*)ptr;	// Create a new node with the given value and link it to the existing nodes
	newNode->size = value;
	if (head == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{	// Link the new node to the existing nodes
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
}

void HmmInsertAtEnd(int value)
{
	void* ptr = HmmAllocNode();
	if (ptr == NULL)	return;
	struct node* newNode  = (struct node*)ptr;
	newNode->size = value;
	if (head == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}
void HmmDeleteNode(int value)
{
	struct node* current = head;		// Initialize current pointer to head of the list
	while (current != NULL)		// Traverse the linked list until we find the node with the given value
	{
		if (current->size == value)
		{
			if (current->prev != NULL)
				{current->prev->next = current->next;}
			else
				{head = current->next;}
			if (current->next != NULL)
				{current->next->prev = current->prev;}
			else
				{tail = current->prev;}
			HmmFreeNode(current);
			return;
		}
		current = current->next;
	}
}

void printList()
{
	struct node *p = head;
	printf("\n[");
	while(p != NULL)
	{
		printf("Size: %d\n", current->size);
		p = p->next;
	}
	printf("]");
}

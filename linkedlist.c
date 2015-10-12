#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "linkedlist.h"
 
void list_new(list *list, int elementSize, freeFunction freeFn)
{
	assert(elementSize > 0);
	list->logicalLength = 0;
	list->elementSize = elementSize;
	list->head = list->tail = NULL;
	list->freeFn = freeFn;
}
 
void list_destroy(list *list)
{
	listNode *current;
	while(list->head != NULL) {
		current = list->head;
		list->head = current->next;

		if(list->freeFn) {
			list->freeFn(current->data);
		}

		free(current->data);
		free(current);
	}
}
 
void list_prepend(list *list, void *element)
{
	listNode *node = malloc(sizeof(listNode));
	node->data = malloc(list->elementSize);
	memcpy(node->data, element, list->elementSize);

	node->next = list->head;
	list->head = node;

	if(!list->tail) {
		list->tail = list->head;
	}

	list->logicalLength++;
}
 
void list_append(list *list, void *element)
{
	listNode *node = malloc(sizeof(listNode));
	node->data = malloc(list->elementSize);
	node->next = NULL;

	memcpy(node->data, element, list->elementSize);

	if(list->logicalLength == 0) {
		list->head = list->tail = node;
	} else {
		list->tail->next = node;
		list->tail = node;
	}

	list->logicalLength++;
}
 
void list_remove_head(list *list, void *element)
{
	assert(list->head != NULL);
 
	listNode *node = list->head;
	memcpy(element, node->data, list->elementSize);
 
	list->head = node->next;
	list->logicalLength--;

	free(node->data);
	free(node);
}
 
int list_size(list *list)
{
	return list->logicalLength;
}

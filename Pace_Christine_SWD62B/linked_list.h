#pragma once

typedef struct nodeRec
{
	int item;		// Store Number
	struct nodeRec* next;	// Store Pointer to Next Node
} node;

typedef node* nodePtr;		// Pointer to Node
nodePtr top;			// Pointer to the Top of List

int IsEmptyList(node *top);
int Push(node **currentNode, node *newNode);


// Sets pointer(s) to create an empty list
void CreateList(nodePtr *temp) {
	temp = NULL;
}


/*
Accepts a whole number, stores it in a node structure.
Returns pointer to the node if successful or false otherwise.
*/
nodePtr CreateNode(int num) {
	node *newNode = (nodePtr)malloc(sizeof(node));
	if (newNode != NULL) {
		newNode->item = num;
		newNode->next = NULL;

		return newNode;
	}
	return NULL;
}


/*
Adds a new item to the list passed as parameter. Returns
true if successful, or false otherwise.
*/
int Push(nodePtr *currentNode, node *newNode) {
	newNode->next = *currentNode;
	*currentNode = newNode;
	return 1;
}


/*
Removes an item from the list passed as parameter and
returns it. It also returns true if successful or false
otherwise.
*/
int Pop(node  **lastNode) {
	node *newTop = *lastNode;
		
	if (IsEmptyList(newTop) == 0) {
		
		int num = newTop->item;
		*lastNode = newTop->next;
		printf("The number %i was removed.", num);
		return 1;
	}
	printf("Cannot remove item. The list is empty!");
	return 0;
}


/*
Returns true if the list passed as parameter is empty, or
false otherwise.
1 -> Empty
0 -> NOT Empty
*/
int IsEmptyList(node *top) {
	if (top == NULL) {
		return 1;
	}
	return 0;
}


/*
Displays the items on the list passed as parameter, without
removing items from list
*/
int* ShowList(node **currentNode) {
	int *list= (int*)malloc(sizeof(int));
	int counter = 0;
	node *cNode = *currentNode;
	if (IsEmptyList(cNode) == 0) {
		do {
			printf("\nPort: %d\n", cNode->item);
			list[counter] = cNode->item;			
			cNode = cNode->next;
			counter++;			
		} while (cNode != NULL);
	}
	else {
		printf("The list is empty!");
	}
	return list;
}


/*
Returns the number of items on the list, 0 if it is empty, or -1
if it does not exist.
*/
int ListSize(node *cNode) {
	if (IsEmptyList(cNode) == 0) {
		int size = 0;
		do {
			size++;
			cNode = cNode->next;
		} while (cNode != NULL);
		return size;
		
	}else if (IsEmptyList(cNode) == 1) {
		
		return 0;
	}
	else {
		
		return -1;
	}
}
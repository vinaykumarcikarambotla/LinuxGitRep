#include<stdlib.h>
#include<stdio.h>
typedef struct Node{
	int val;
	struct Node *next;
	struct Node *prev;
}node_t;

node_t *head = NULL;

void InsertIntoDLL(int temp){
	node_t *current = malloc(sizeof(node_t));
	current->val = temp;
	current->next = head;
	current->prev = NULL;
	head = current;
}

void InsertIntoDLLAtEnd(int temp1){
	node_t *cursor = head;
	node_t *new_node = malloc(sizeof(node_t));
	while(cursor!=NULL){
		cursor = cursor->next;
	}
	new_node->val = temp1;
	new_node->next = NULL;
	new_node->prev = cursor;
	cursor->next = new_node;

}


void print(){
	node_t *cursor = head;
	while(cursor!=NULL){
		printf("%d\t",cursor->val);
		cursor = cursor->next;
	}
}



int main(){
	int n;
	printf("\nEnter the No.of Nodes of the DLL\n");
	scanf("%d",&n);
	int i;
	int temp;
	printf("\nEnter the Node values\n");
	for (i = 0; i < n;i++) {
		scanf("%d",&temp);
		InsertIntoDLL(temp);
	}
	printf("\nThe Complete List: Insertion of Node at the beginning\n");
	print();
	printf("\nNode insertion at the End\n");
	int n2;
	printf("\nNo.of Nodes at the End\n");
	scanf("%d",&n2);
	int i2;
	int temp1;
	printf("\nEnter the Node values\n");
	for (i2 = 0; i2 < n2; i2++) {
		scanf("%d",&temp1);
		InsertIntoDLLAtEnd(temp1);

	}
	printf("\nList After Insertion at the End\n");
	print();
	return 0;
}


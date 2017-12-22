#include<stdio.h>
#include <stdlib.h>
typedef struct Node{
	int val;
	struct Node *next;
}node_t;

node_t *head = NULL;


void InsertNode(int temp){
	node_t *new_node = malloc(sizeof(node_t));
	new_node->val = temp;
	new_node->next = head;
	head = new_node;
}

void print(){
	node_t *cursor = head;
	while(cursor!= NULL){
		printf("%d\t",cursor->val);
		cursor = cursor->next;
	}
}

void DeleteNode(int key){
	node_t * cursor = head;
	node_t *prev = head;
	while(cursor!= NULL && cursor->val!=key){
		prev = cursor;
		cursor=cursor->next;
	}
	prev->next = cursor->next;
	free(cursor);
}

int main(){
int n;
printf("\nEnter no.of nodes\n");
scanf("%d",&n);
int i,temp;
printf("\nEnter Node values\n");
for(i=0;i<n;i++){
	scanf("%d",&temp);
	InsertNode(temp);
}
// printing the nodes of the Linked List

print();
// delete node at given key
printf("\nEnter the key to delete node in the linked list\n");
n=0;
scanf("%d",&n);
DeleteNode(n);
printf("\nLinked list after deletion of node at the given key\n");
print();

	return 0;
}


#include <stdio.h>
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
	while(cursor!=NULL){
		printf("%d\t",cursor->val);
		cursor = cursor->next;
	}
}


void LengthInIteration(){
	node_t * cursor = head;
	int c=0;
	while(cursor!=NULL){
		c++;
		cursor = cursor->next;
	}
	printf("\nLength of the linked list with Iteration:%d\n",c);
}

int LengthInRecursion(int len){
	if(head == NULL){
		printf("\n%d\n",len);
		return len;
	}
	if (head!=NULL) {
		len++;
		head = head->next;
		LengthInRecursion(len);
		}

	return len;


}






int main(){
	int n;
	printf("\nEnter N:\n");
	scanf("%d",&n);
	int i, temp;
	printf("\nEnter node values\n");
	for(i=0;i<n;i++){
		scanf("%d",&temp);
		InsertNode(temp);
	}

	print();
	LengthInIteration();
	int len=0;
	int x;

	x=LengthInRecusion(len);
	printf("Length in recursion %d :\n",x);

	return 0;
}


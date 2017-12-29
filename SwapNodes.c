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
	while(cursor!=NULL){
		printf("%d\t",cursor->val);
		cursor = cursor->next;
	}
}
void SwapNode(){
	int x,y;
	printf("\nEnter x and y values:\n");
	scanf("%d%d",&x,&y);
	node_t *curx=head,*cury=head;
	node_t *prevx=NULL,*prevy=NULL;
	while(curx && curx->val !=x){
		prevx = curx;
		curx =curx->next;
	}
	while(cury && cury->val !=y){
			prevy = cury;
			cury =cury->next;
		}
	if(prevx!=NULL){
		prevx->next = cury;
	}
	else{
		head = cury;
	}
	if(prevy!=NULL){
		prevy->next = curx;
	}
	else{
		head = curx;
	}
	// swap nodes
	node_t *tem = NULL;
	tem = curx->next;
	curx->next = cury->next;
	cury->next = tem;
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
	SwapNode();
	printf("\nLinked list after swapping:\n");
	print();
	return 0;
}


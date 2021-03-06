#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
	while (cursor != NULL)
	  {
	     printf(" %d ", cursor->val);
	     cursor = cursor->next;
	  }


}

bool SearchElement(int n){
	if(head == NULL){
		return false;
	}

	if(head->val == n){
		return true;
	}

	head = head->next;
	return SearchElement(n);
}


bool SearchElementIteration(int n){
	while(head!=NULL){
		if(head->val == n){
			return true;
		}
		else{
			head=head->next;
		}
		return false;
	}

}


int main(){

	int n;
	printf("\nEnter N:\n");
	scanf("%d",&n);
	int i, temp;
	printf("\nEnter Node values\n");
	for(i=0;i<n;i++){
		scanf("%d",&temp);
		InsertNode(temp);
	}
	print();

	printf("\nEnter a key to search in the LL\n");
	n=0;
	scanf("%d",&n);
	if(SearchElement(n)){
		printf("\nElement found through recursion\n");
	}
	else{
		printf("\nElement not found through recursion\n");
	}
	if(SearchElementIteration(n)){
		printf("\nElement found through iteration\n");

	}
	else {
		printf("\nElement not found through iteration\n");
	}

return 0;


}
#include<stdlib.h>

#include<stdio.h>

 

typedef struct DLL{

    int val;

    struct DLL *next,*prev;

}node_t;

 

node_t *head = NULL;

 

 

void InsertAtHead(int temp){

    node_t *new_node = malloc(sizeof(node_t));

    new_node->val = temp;

    new_node->next = head;

    if(head == NULL){

        new_node->prev = NULL;

    }

    head = new_node;

    }

   

    

void InsertAtEnd(int temp){

    node_t *new_node = malloc(sizeof(node_t));

    new_node->val = temp;

    new_node->next = NULL;

    if(head==NULL){

        new_node->prev = NULL;

        head = new_node;

    }

    node_t *cursor = head;

    while(cursor->next!=NULL){

        cursor = cursor->next;

    }

    cursor->next = new_node;

   new_node->prev = cursor;

   

}

 

void InsertAtPos(int pos,int pval){

    node_t *prev_node = head;

    node_t *new_node = malloc(sizeof(node_t));

    if(prev_node==NULL){

        printf("\nNot possible \n");

        return;

    }

    new_node->val = pval;

    int c=0;

    while(c<pos){

        c++;

        prev_node = prev_node->next;

    }

    new_node->next = prev_node->next;

    prev_node->next = new_node;

    new_node->prev = prev_node;

   

    if(new_node->next!=NULL){

        new_node->next->prev = new_node;

       

    }

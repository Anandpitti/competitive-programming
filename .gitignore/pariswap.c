#include <stdio.h>
#include <malloc.h>

struct node{
	int data;
	struct node* next;
};

struct node* create_newnode(int val){
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->data = val;
	n->next = NULL;
	return n;
}

void insert(struct node** head, int val){
	struct node* newnode = create_newnode(val);
	if((*head)==NULL)
		*head = newnode;
	else{
		struct node* temp = (*head);
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;
	}
}

void printlist(struct node* head){
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}

struct node* pairswap(struct node* head){
	if(head==NULL || head->next==NULL)
		return head;
	else{
		struct node* p = head->next;
		struct node* t = head->next->next;
		head->next->next = head;
		head->next = pairswap(t);
		return p;
	}

}

int main(){
	struct node* head = NULL;
	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	insert(&head, 5);
	insert(&head, 6);
	insert(&head, 7);
	insert(&head, 8);
	insert(&head, 9);
	
	printlist(head);
	
	head = pairswap(head);

	printlist(head);
}

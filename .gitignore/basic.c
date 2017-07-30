#include <stdio.h>
#include <malloc.h>

//data
struct node{
	int val;
	struct node* next;
};


//basic list
struct node* createfreenode(){
        struct node* newnode=NULL;
        return newnode;
}

struct node* createnode(int val){
	struct node* newnode= (struct node*) malloc(sizeof(struct node));
	newnode->val=val;
	newnode->next=NULL;
	return newnode;
}

void printlist(struct node* head){
	while(head){
		printf("%d\t",head->val);
		head=head->next;
	}
	printf("\n");
}

void addathead(struct node** head, int val){
	struct node* newnode=createnode(val);
	
	newnode->next=*head;
	*head=newnode;
}

void addatend(struct node** head, int val){
	struct node* newnode=createnode(val);
	struct node* temp=*head;

	if(*head==NULL){
		*head=newnode;
	}
	else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
	}
}

int ispresent(struct node* head, int val){
	while(head){
		if(head->val==val) return 1;
		head=head->next;
	}
	return 0;
}

struct node* find(struct node* head, int val){
        while(head){
                if(head->val==val) return head;
                head=head->next;
        }
        return NULL;
}

void insertafternode(struct node* after, int val){
	struct node* newnode=createnode(val);

	if(after){
		newnode->next=after->next;
		after->next=newnode;
	}
}

void insertafterval(struct node** head, int after, int val){
        struct node* newnode=createnode(val);
	struct node* temp=*head;

        if(*head==NULL){
                newnode->next=*head;
		(*head)=newnode;
        }
	else{
		while(temp->next!=NULL){
			if(temp->val==after)
				break;
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}

void deletelist(struct node* head){
	struct node* temp= head;
	if(head)
		deletelist(head->next);
	if(temp) 
		free(temp);
}

void deleteathead(struct node** head){
	if(*head){
		struct node* temp=*head;
		*head=(*head)->next;
		free(temp);
	}
}

void deleteatend(struct node** head){
	if(*head){
		if((*head)->next==NULL) 
			*head=(*head)->next;
		else{
			struct node* temp=*head;
			while(temp->next->next!=NULL)
				temp=temp->next;
			temp->next=NULL;
		}
	}
}

//cannot delete empty list, one node list and last element in the list
void deletenode(struct node* node){
	if(node!=NULL && node->next!=NULL){
		struct node* temp=node->next;
		node->val=node->next->val;
		node->next=node->next->next;
		free(temp);
	}
}

void deleteval(struct node** head, int val ){
	if(*head){
		if((*head)->val==val)
			*head=(*head)->next;
		else{
			struct node* temp=*head;
			while(temp->next && temp->next->val!=val)
				temp=temp->next;
			if(temp->next){
				struct node* tofree=temp->next;
				temp->next=temp->next->next;
				free(tofree);
			}
		}	
	}
}


//queue
struct node* createqueue(){
	struct node* temp=createfreenode();
	return temp;	
}

void pop(struct node** head){
	deleteathead(head);
}

int front(struct node* head){
	return head->val;
}

void push_back(struct node** head, int val){
	addatend(head, val);
}

void findqelement(struct node* head, int val){
	ispresent(head, val);
}

void printqueue(struct node* head){
	printlist(head);
}


int main(){
	//struct node* a=createfreenode();
	int i=0;
	struct node* q=createqueue();
	push_back(&q,1);
	printqueue(q);
	push_back(&q,2);
        printqueue(q);
	push_back(&q,3);
        printqueue(q);
	printf("%d\n",front(q));
	pop(&q);
	printqueue(q);
	
	return 0;
}

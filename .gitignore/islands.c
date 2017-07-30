#include <stdio.h>
#include <malloc.h>

#define size 1000000

int parent[size];

struct node{
	long long int s,d;
	long long int w;
	struct node* next;
};

struct islandnode{
	long long int x,y;
};

struct islandnode island[size];

long long int dist(long long int s,long long int d){
	return((island[s].x-island[d].x)*(island[s].x-island[d].x)+(island[s].y-island[d].y)*(island[s].y-island[d].y));
}

void insertinlist(struct node** head,long long int s,long long int d,long long int w){
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
	newnode->s=s;
	newnode->d=d;
	newnode->w=w;

        if(*head==NULL){
                *head=newnode;
        }
        else{
                if(newnode->w < (*head)->w){
                        newnode->next=*head;
                        *head=newnode;
                }
                else{
                        struct node* prev=*head;
                        struct node* curr=(*head)->next;
                        while(curr!=NULL){
                                if(newnode->w>curr->w){
                                        prev=curr;
                                        curr=curr->next;
                                }
                                else break;
                        }
                        if(curr==NULL){
                                prev->next=newnode;
                        }
                        else{
                                prev->next=newnode;
                                newnode->next=curr;
                        }
                }
        }
}

long long int constructpath(struct node** head,long long int n){
	long long int i,count;
	long long int weight=0;

	for(i=0;i<n;i++){
		parent[i]=i;
	}

	count=n;
	struct node* temp=*head;
	while(count!=1 && *head!=NULL){
		temp=*head;
		*head=(*head)->next;
		if(parent[temp->s]==parent[temp->d]){
		}
		else{
			weight+=temp->w;
			count--;
			if(parent[temp->s]>parent[temp->d]){
				for(i=0;i<n;i++){
					if(parent[i]==parent[temp->s])
						parent[i]=parent[temp->d];
				}
			}
			else{
				for(i=0;i<n;i++){
                                        if(parent[i]==parent[temp->d])
                                                parent[i]=parent[temp->s];
                                }
			}
		}
	}

	return weight;
}

int main(){
	long long int n,i,j,testcases;
	double e;

	scanf("%lld",&testcases);
	
	while(testcases--){
	scanf("%lld",&n);
	scanf("%lf",&e);

	for(i=0;i<n;i++){
		scanf("%lld",&island[i].x);
	}
	for(i=0;i<n;i++){
		scanf("%lld",&island[i].y);
	}

	struct node* head=NULL;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j){
				insertinlist(&head,i,j,dist(i,j));
			}
		}
	}

	printf("%lld\n",(long long int)(e*constructpath(&head,n)));
	}

	return 0;
}

#include <stdio.h>
#include <malloc.h>

struct node{
	int x,y;
	struct node* next;
};

int row[]={1,-1,2, 2, 1,-1,-2,-2};
int col[]={2, 2,1,-1,-2,-2, 1,-1};
struct node* front=NULL;
struct node* rear=NULL;

createqueue(){
	front=NULL;
	rear=NULL;
}

int isempty(){
	if(front==NULL && rear==NULL)
		return 1;
	return 0;
}

void add(int x, int y){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->x=x;
	newnode->y=y;
	newnode->next=NULL;

	if(isempty()){
		front=newnode;
		rear=newnode;
	}else{
		rear->next=newnode;
		rear=rear->next;
	}
}

struct node* pop(){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if(isempty()){
		return NULL;
	}
	else{
		if(front==rear){
			temp=front;
			front=NULL;
			rear=NULL;
			return temp;
		}else{
			temp=front;
			front=front->next;
			return temp;
		}
	}
}

int issafe(int x, int y){
	if(x>=0 && x<8 && y>=0 && y<8)
		return 1;
	return 0;
}

void findpath(int sx, int sy, int ex, int ey,int visited[][8]){
	int i;

	if(sx==ex && sy==ey){
		visited[sx][sy]=1;
		return;
	}
	
	createqueue();
	add(sx,sy);

	while(!isempty()){
		struct node* t=pop();
		visited[t->x][t->y]=1;
		if(t->x==ex && t->y==ey){
			return;
		}
		else{	
			for(i=0;i<8;i++){
				if(issafe(t->x+row[i],t->y+col[i]) && visited[t->x+row[i]][t->y+col[i]]!=1)
					add(t->x+row[i],t->y+col[i]);
			}
		}
	}
}

int main(){
	int visited[8][8];
	char ans[100];
	int i,j;

	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			visited[i][j]=0;
		}
	}
	
	findpath(0,0,1,2,visited);

	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			printf("%d ",visited[i][j]);
		}
		printf("\n");
	}

	//printf("%s",ans);

	return 0;
}

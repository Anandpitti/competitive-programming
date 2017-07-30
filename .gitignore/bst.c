// C program to demonstrate insert operation in binary search tree
#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>

struct node
{
	int key;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;
    
    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key); 

	/* return the (unchanged) node pointer */
	return node;
}

// Driver Program to test above functions
int main()
{
	
	struct node *root=NULL;
	
	//GET INPUTS
	int i,no_of_nodes,val;
	scanf("%d",&no_of_nodes);
	for(i=0;i<no_of_nodes;i++){
		scanf("%d",&val);
		if(i==0) 
			root = insert(root,val);
		else
			insert(root,val);
	}
	
	//get k
	scanf("%d",&val);
	struct node* k=search(root,val);
	if(k->left && k->right){
		 printf("%d %d\n",k->left->key,k->right->key);

	}else if(k->right){
		printf("%d\n",k->right->key);
	}	
	else if(k->left){
		printf("%d\n",k->left->key);
	}else{
		printf("-1\n");
	}

	return 0;
}


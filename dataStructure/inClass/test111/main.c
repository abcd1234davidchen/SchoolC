#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node *left;
	struct node *right;
	struct node *parent; 
}Node;

void insert(int n,Node **root){
	Node *temp=malloc(sizeof(Node));
	temp->value=n;
	temp->right=NULL;
	temp->left=NULL;

	if(*root==NULL){
		*root=temp;
		return;
	}

    Node *c=*root;
	Node *p=NULL;

	while(c!=NULL){
		if(temp->value<c->value){
			p=c;
			c=c->left;
		}
		else if(temp->value>c->value){
			p=c;
			c=c->right;
		}
		else{
			printf("The value is repeated!\n\n");
			return;
		}
	}
	if(p->value>temp->value){
		p->left=temp;
	}
	else{
		p->right=temp;
	}
	temp->parent=p;
}

void generate(Node **root){
	
	int used[100]={0};
	int count=0;
	while(count<15){
		int n=rand()%100+1;
		if(used[n-1]==1){
			continue;
		}	
		insert(n,root);
		used[n-1]=1;
		count++;
	}
}

void del(int n,Node **root){
	Node *temp=*root;
	if(temp==NULL){
		printf("The tree is empty!\n\n");
		return;
	}
	while(temp!=NULL){
		if(temp->value==n){
			if(temp->left==NULL&&temp->right==NULL){
				free(temp);
				return;
			}
			else if(temp->left==NULL&&temp->right!=NULL){
				if(temp->value<temp->parent->value){
					temp->parent->left=temp->right;
					free(temp);
				}
				else if(temp->value>temp->parent->value){
					temp->parent->right=temp->right;
					free(temp);
				}
				return;
			}
			else if(temp->left!=NULL&&temp->right==NULL){
				if(temp->value<temp->parent->value){
					temp->parent->left=temp->left;
					free(temp);
				}
				else if(temp->value>temp->parent->value){
					temp->parent->right=temp->left;
					free(temp);
				}
				return;
			}
			else{
				Node *inorder=temp->right;
				while(inorder->left!=NULL){
					inorder=inorder->left;
				}
				if(inorder->right!=NULL){
					inorder->parent->left=inorder->right;
					inorder->right->parent=inorder->parent;
				}
				inorder->left=temp->left;
				inorder->right=temp->right;
				inorder->parent=temp->parent;
				free(temp);
			}
		}
		else if(temp->value<n){
			temp=temp->right;
		}
		else{
			temp=temp->left;
		}
	}
	printf("The element is not in the tree.\n\n");
}

void inorder_traversal(Node **root){
	if(*root==NULL){
		return;
	}
	inorder_traversal(&(*root)->left);
	printf("%d->",(*root)->value);
	inorder_traversal(&(*root)->right);
}

void preorder_traversal(Node **root){
	if(*root==NULL){
		return;
	}
	printf("%d->",(*root)->value);
	preorder_traversal(&(*root)->left);
	preorder_traversal(&(*root)->right);
}

void postorder_traversal(Node **root){
	if(*root==NULL){
		return;
	}
	postorder_traversal(&(*root)->left);
	postorder_traversal(&(*root)->right);
	printf("%d->",(*root)->value);
}

int main(void){
    srand(1);
	Node *root=NULL;
	generate(&root);
	printf("%d",root->value);
	while(1){
		printf("Please choose what you want to do with tree : 1.Insert 2.Delete 3. Traversal 4.Exit\n");
		int choice;
		scanf("%d",&choice);
		if(choice==1){
			printf("Please enter the value to insert : ");
			int n;
			scanf("%d",&n);
			insert(n,&root);
		}
		else if(choice==2){
			printf("Please enter the value to delete : ");
			int n;
			scanf("%d",&n);
			del(n,&root);
		}
		else if(choice==3){
			inorder_traversal(&root);
			printf("\n");
			preorder_traversal(&root);
			printf("\n");
			postorder_traversal(&root);
		}
		else{
			break;
		}
	}
	
} 

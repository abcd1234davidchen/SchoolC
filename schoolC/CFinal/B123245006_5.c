#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

typedef struct Node{
	int host;
	struct Node* next;
}node;

void push(node** top,int value){
	//printf("I GOT VALUE");
	node* new=malloc(sizeof(node));
	new->host=value;
	new->next=*top;
	*top=new;
}

void printStack(node* top){
	node* temp=top;
	while(temp!=NULL){
		printf("%7d->",temp->host);
		temp=temp->next;	
	}
	printf("\n");
}

int pop(node** top){
	node* temp=*top;
	int outValue=temp->host;
	(*top)=(*top)->next;
	free(temp);
	return(outValue);
}

void reverse(node** top){
	node* rTop=NULL;
	while((*top)!=NULL){
		node* temp=*top;
		(*top)=(*top)->next;
		temp->next=rTop;
		rTop=temp;
	}
	*top=rTop;
}

int search(node* top,int key){
	int number=0,flag=1;
	while(top!=NULL){
		number++;
		if (top->host==key) {
			flag=0;
			return number;
		}
		else top=top->next; 
	}
	if(flag){
		return -1;
	}
}

int main(void){
	FILE* file=fopen("Stack.txt","r");
	node* top=NULL;
	int tempInt;
	while(fscanf(file," %d",&tempInt)!=EOF){
		push(&top,tempInt);
	}
	printStack(top);
	int choice;
	printf("\nPlease select the action:\n1.Push 2.Pop 3.Reverse 4.Search: ");
	while(scanf("%d",&choice)!=EOF){
		switch (choice){
			case 1:
				//push
				printf("Enter an interger: ");
				scanf("%d",&tempInt);
				push(&top,tempInt);
				break;
			case 2:
				//pop
				printf("\nThe value at the top is %d.\n",pop(&top));
				break;
			case 3:
				//reverse
				reverse(&top);
				break;
			case 4:
				//search
				printf("Enter an interger: ");
				scanf("%d",&tempInt);
				if(search(top,tempInt)==-1) printf("\nStack does not exist a node contain %d\n",tempInt);
				else printf("\nNo.%d node contains %d\n",search(top,tempInt),tempInt);
				break;
			default:
				printf("Invalid Input");
				break;
		}
		printf("\n");
		printStack(top);
		printf("\nPlease select the action:\n1.Push 2.Pop 3.Reverse 4.Search: "); 
	}
	fclose(file);
}


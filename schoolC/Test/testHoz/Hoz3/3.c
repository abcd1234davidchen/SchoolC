#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int value;
    int addup;
    struct Node* next;
} node;

void push(int a,node** top){
    node *new=malloc(sizeof(node));
    new->value=a;
    new->addup=0;
    int i=1;
    while(a>i){
        new->addup+=a/i%10;
        new->addup+=45;
        i*=10;
    }
    new->next=*top;
    *top=new;
}


int main(void){
    node* top=NULL;
    int in;
    while (scanf(" %d",&in)!=EOF){
        push(in,&top);
    }
    printf("IM HERE\n");
    while(top!=NULL){
        node* min=top;
        node* current=top;
        while(current!=NULL){
            if ((current->addup)<(min->addup)){
                min=current;
            }
            current=current->next;
        }
        printf("%d\n",min->value);
        current=top;
        if(current==min){
            top=top->next;
        }
        else{
            while(current->next!=min){
                current=current->next;
            }
            (current->next)=(current->next->next);
        }
        free(min);
    }
}

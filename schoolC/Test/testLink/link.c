#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node{
    int nest;
    struct Node* next;
} node;
void create(node** top){
    node* now=malloc(sizeof(node));
    now->nest=rand()%10;
    printf("%d ",now->nest);
    now->next=*top;
    *top=now;
}
int pop(node** top){
    node* temp=*top;
    int current=(*top)->nest;
    *top=(*top)->next;
    free(temp);
    return current;
}

void reverse(node** top){
    node* rTop=NULL;
    node* temp;
    while(*top!=NULL){
        temp=*top;
        *top=(*top)->next;
        temp->next=rTop;
        rTop=temp;
    }
    *top=rTop;
}

int main(void){
    srand(time(NULL));
    node* top=NULL;
    for(int i=0;i<5;i++){
        create(&top);
    }
    reverse(&top);
    
    while(top!=NULL){
        printf("%d ",pop(&top));
    }

}

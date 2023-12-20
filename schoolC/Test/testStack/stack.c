#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct Node{
    int x;
    int y;
    struct Node* next;
}node;
//a
void generate(node** top){
    node* new=malloc(sizeof(node));
    new->x=rand()%101-50;
    new->y=rand()%101-50;
    new->next=*top;
    *top=new;
}

//b
void pop(int* x, int* y,node** top){
    node* temp=NULL;
}

int main(void){
    srand(time(NULL));
    node* top;

    //a
    for(int i=0;i<100;i++){
        generate(&top);
        printf("%d %d\n",top->x,top->y);
    }
    
    //b
    int array[100][2];
    for(int i=0;i<100;i++){
        int x,y;
        pop(&x,&y,&top);
        array[i][0]=x;
        array[i][1]=y;
    }

}

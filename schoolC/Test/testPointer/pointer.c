#include<stdio.h>
#include<stdlib.h>
#include<time.h>


struct node{
        char num;
        struct node *next;
    };
    
struct node *add(struct node *top,char value){
    struct node *new = malloc(sizeof(struct node) );
    new -> num = value;
    new -> next = top;
    top = new ;
    return top;
}


void pick(struct node **top_pos,struct node **reverse_top_pos){
    struct node *tmp = (*top_pos)->next; 
    (*top_pos)->next = (*reverse_top_pos);
    (*reverse_top_pos) = (*top_pos);
    (*top_pos) = tmp;
    //for testing 
    //printf("%c-%c\n",(*top_pos)->num,(*reverse_top_pos)->num);
}


int main(){
    printf("link list pracice: \n");
    srand(time(NULL));
    struct node *top = NULL,*tmp;
    int i,j,k;
    for (i=0;i<10;i++){
        top = add(top,rand()%26+65+32);
    }
    tmp = top;
    printf("Origin: ");
    for (i=0;i<10;i++){
        printf("%c ",tmp->num);
        tmp = tmp->next;
    }
    
    struct node *reverse_top = NULL;
    while(top!=NULL){
        if(top->next!=NULL){
            pick(&top,&reverse_top);
        }else{
            top->next = reverse_top;
            reverse_top = top;
            top = NULL;
        }
    }
    
    tmp = reverse_top;
    printf("\nreverse: ");
    for (i=0;i<10;i++){
        printf("%c ",tmp->num);
        tmp = tmp->next;
    }
    
    return 0;
}
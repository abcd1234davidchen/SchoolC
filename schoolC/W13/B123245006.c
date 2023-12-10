#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//13.1 
typedef struct node{
	char title[50];
    char author[50];
    int year;
    int ID;
    struct node *next;
} Book;
void readBooksFromFile(Book** tPos){
    FILE *bookfile=fopen("books.txt","r");
    char temp[5][1024];
    int i=0;
    while(fgets(temp[i],1024,bookfile)!=NULL){
        i++;
        //printf("I AM READING BOOKS\n");
    }
    while(i>0){
        i--;
        Book *newBook=(Book*)malloc(sizeof(Book));
        sscanf(temp[i], "%[^,], %[^,], %d, %d", newBook->title, newBook->author, &(newBook->year), &(newBook->ID));
        //printf("%s %s %d %d\n", newBook->title, newBook->author, newBook->year, newBook->ID);
        newBook->next=*tPos;
        *tPos = newBook;
        //printf("I VE READ BOOKS\n");
    }
    fclose(bookfile);
}
void printBooks(Book* top){
    Book *current = top;
    while(current!=NULL){
        printf("Title: %s, Author: %s, Year: %d, ID: %d\n", current->title, current->author, current->year, current->ID);
        current=current->next;
    }
}
void updateBookInfo(Book* top){
    int updateID;
    char temp[50];
    printf("Enter the ID of the book to update: ");
    scanf("%d", &updateID);
    Book *current = top;
    while(current!=NULL){
        if(current->ID==updateID){
            printf("Enter new title: ");
            fflush(stdin);
            fgets(temp, 50, stdin);
            sscanf(temp,"%[^\n]", current->title);
            printf("Enter new author: ");
            fflush(stdin);
            fgets(temp, 50, stdin);
            sscanf(temp,"%[^\n]", current->author);
            printf("Enter new year: ");
            scanf("%d", &(current->year));
            break;
        }
        current=current->next;
    }
}
void writeBooksToFile(Book* top){
    FILE *bookfile=fopen("books.txt","w");
    Book *current = top;
    while(current!=NULL){
        fprintf(bookfile, "%s, %s, %d, %d\n", current->title, current->author, current->year, current->ID);
        current=current->next;
    }
    fclose(bookfile);
}


//13.2
void getNumber(int arr[]){
    FILE *text=fopen("text.txt","w");
	for(int i=0;i<1000;i++){
        arr[i]=rand()%9001+1000;
        for(int j=0;j<i;j++){
            if(arr[i]==arr[j]){
                i--;
                break;
            }
        }
    }
    for(int i=0;i<1000;i++){
        fprintf(text,"%5d  ",arr[i]);
        if((i+1)%20==0) fprintf(text,"\n");
        //printf("%d\n",arr[i]);
    }
    
}
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubbleSortRecursive(int arr[], int current){
    if(current==1) return;
    for(int i=0;i<current-1;i++){
        if(arr[i]>arr[i+1]) swap(&arr[i],&arr[i+1]);
    }
    bubbleSortRecursive(arr,current-1);
}
int binarySearchRecursive (int arr[], int left, int right, int key){
    if(left>right) return -1;
    int mid=(left+right)/2;
    if(arr[mid]==key) return mid;
    if(arr[mid]>key) return binarySearchRecursive(arr,left,mid-1,key);
    if(arr[mid]<key) return binarySearchRecursive(arr,mid+1,right,key);
}

int main(void) {
    srand(time(NULL));
    //13.1
    
    Book *top=NULL;
    int i=0;
    readBooksFromFile(&top);
    printf("1. Print all books\n2. Update a book\n3. Exit\nEnter your choice: \n");
    while(scanf("%d",&i)!=EOF){
        if (i==3) break;
        switch (i){
        case 1:
            printBooks(top);
            break;
        case 2:
            updateBookInfo(top);
            writeBooksToFile(top);
            break;
        
        default:
            printf("Please enter a valid number\n");
            break;
        }
        printf("1. Print all books\n2. Update a book\n3. Exit\n");
    }
    
    //13.2
    int arr[1024]={0},current=1000,key;
    getNumber(arr);//generate
    bubbleSortRecursive(arr, current);
    FILE *sorted=fopen("sorted.txt","w");
    FILE *hello=fopen("hello.txt","r");
    for(i=0;i<1000;i++){
        fprintf(sorted,"%5d ",arr[i]);
        printf("%6d",arr[i]);
        if((i+1)%20==0) {
            fprintf(sorted,"\n");
            printf("\n");
        }
    }
    printf("Enter a number to search: ");
    while (scanf("%d",&key)!=EOF)
    {
        int left=0,right=current-1;
        if(binarySearchRecursive(arr, left, right, key)==-1){
            printf("你好\n");
            //printf("\n");
        }
        else
        printf("%d\n",binarySearchRecursive(arr, left, right, key)+1);
        printf("Enter a number to search: ");
    }
    char hArr[1024];
    while(fgets(hArr,1024,hello)!=NULL) printf("%s",hArr);
}

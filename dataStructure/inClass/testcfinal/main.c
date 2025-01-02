#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[10];
    int chi;
    int eng;
    int math;
} student;

void swap(student *a, student *b){
    student temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(student arr[],int n, int (*cmp)(student, student)){
    if(n == 1)return ;

    for(int i = 0;i < n - 1;i++){
        if(cmp(arr[i], arr[i+1]) > 0){
            swap(&arr[i], &arr[i+1]);
        }
    } 

    bubbleSort(arr, n - 1, cmp);
}

int cmpid(student a, student b){
    return a.id - b.id;
}

int cmpname(student a, student b){
    return strcmp(a.name, b.name);
}

int cmpChi(student a, student b){
    return b.chi - a.chi; // descending order for Chinese
}

int cmpEng(student a, student b){
    return b.eng - a.eng; // descending order for English
}

int cmpMath(student a, student b){
    return b.math - a.math; // descending order for Math
}

void printStudent(student arr[], int n){
    int i;

    printf("   ID        Name      Chi  Eng  Math\n");
    for(i = 0;i < n;i++){
        printf("%5d   %-10s %4d %4d %4d\n", arr[i].id, arr[i].name, arr[i].chi, arr[i].eng, arr[i].math);
    }
    printf("\n");
}

int main(){
    student Student[100];
    
    FILE *file = fopen("Student.txt","r");
    if (!file) {
        printf("Failed to open file.\n");
        return 1;
    }

    int count = 0;

    while(fscanf(file,"%d %10s %d %d %d",&Student[count].id, Student[count].name, &Student[count].chi, &Student[count].eng, &Student[count].math) == 5){
        count++;
        if(count > 100){
            break;
        }
    }
    fclose(file);

    int option = 0;

    // Print the menu only once before the loop
    printf("Choose sorting method\n1. ID 2. Name 3.Chinese 4.English 5.Math 6.Exit: ");

    while(1){

        if (scanf("%d", &option) != 1) {
            while (getchar() != '\n'); // Clear input buffer
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (option){
            case 1:
                bubbleSort(Student,count,cmpid);
                break;

            case 2:
                bubbleSort(Student, count, cmpname);
                break;

            case 3:
                bubbleSort(Student, count, cmpChi);
                break;

            case 4:
                bubbleSort(Student, count, cmpEng);
                break;
            
            case 5:
                bubbleSort(Student, count, cmpMath);
                break;
            
            case 6:
                return 0;
            
            default:
                printf("Wrong input, input again\n");
                continue;
        }

        printStudent(Student, count);
    }

}
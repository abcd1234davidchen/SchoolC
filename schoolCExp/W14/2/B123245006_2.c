#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct Person {
    char name[50];
    int age;
    double money;
    double debt;
};
void initializePerson(struct Person *person, const char *name){
    int i=0;
    while(name[i]!='\n'){
        person->name[i]=name[i];
        i++;
    }
    person->age=rand()%51+10;
    person->money=rand()%150001+150000;
    person->debt=rand()%50001+50000;
}
int main(void) {
    srand(time(NULL));
    char inputName[100];
    struct Person *person=NULL;
    printf("Input Name:\n");
    while (fgets(inputName, sizeof(inputName), stdin) != NULL) {
        if(inputName[0]=='0') break;
        person = (struct Person*) malloc(sizeof(struct Person));
        initializePerson(person,inputName);
        printf("Name: %s\n",person->name);
        printf("Age: %d\n",person->age);
        printf("Money: %d\n",(int)person->money);
        printf("Debt: %d\n",(int)person->debt);
        free(person); // Free the allocated memory
        printf("Input Name:\n");
    }
    printf("Finish!");
}

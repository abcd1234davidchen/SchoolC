#include<stdio.h>
int main(void){
    //3.2
    int adup=0;
    char ans;
    printf("Did David run a red light?\n");
    scanf("%c",&ans);
    if (ans=='Y'||ans=='y'){
        adup+=3600;
    }
    printf("Was David speeding?\n");
    scanf(" %c",&ans);
    if (ans=='Y'||ans=='y'){
        adup+=1200;
    }
    printf("Does David have a driver's license\n");
    scanf(" %c",&ans);
    if (ans=='N'||ans=='n'){
        adup+=24000;
    }
    printf("Was David wearing his helmet?\n");
    scanf(" %c",&ans);
    if (ans=='N'||ans=='n'){
        adup+=500;
    }
    printf("Was David using the cell phone while riding?\n");
    scanf(" %c",&ans);
    if (ans=='Y'||ans=='y'){
        adup+=3000;
    }
    printf("Was David riding in opposite direction?\n");
    scanf(" %c",&ans);
    if (ans=='Y'||ans=='y'){
        adup+=1800;
    }
    printf("David have to pay $%d.",adup);
    return 0;
}

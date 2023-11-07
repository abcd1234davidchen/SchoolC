#include <stdio.h>
int main(void){
    //1.1
    char name[5],blood[4],id[10];
    double weight,height,bmi;
    printf("Please enter your student ID:");
    scanf("%s",id);
    printf("Please enter your name:");
    scanf("%s",name);
    printf("Please enter your height:");
    scanf("%lf",&height);
    printf("Please enter your weight:");
    scanf("%lf",&weight);
    printf("Please enter your blood type:");
    scanf("%s",blood);
    bmi=weight/height/height*10000;
    printf("Student ID:%s\n",id);
    printf("Name:%s\n",name);
    printf("Height:%lf\n",height);
    printf("Weight:%lf\n",weight);
    printf("Blood type:%s\n",blood);
    printf("BMI:%lf\n\n",bmi);

    //1.2
    printf("A\n");
    printf("Octal representation: %o\n", 'A');
    printf("Decimal representation: %d\n", 'A');
    printf("Octal representation: %x\n\n", 'A');
    printf("a\n");
    printf("Octal representation: %o\n", 'a');
    printf("Decimal representation: %d\n", 'a');
    printf("Octal representation: %x\n\n", 'a');
    printf("0\n");
    printf("Octal representation: %o\n", '0');
    printf("Decimal representation: %d\n", '0');
    printf("Octal representation: %x\n", '0');
return 0;
}

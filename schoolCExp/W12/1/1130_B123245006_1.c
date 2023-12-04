#include<stdio.h>
#include<stdlib.h>
int main(void){
    int method;
    char c1ch,c2[100],c3[100],c4[100];
    printf("Choose a reading method(0~4,0 to exit)\n");
    while(scanf("%d",&method)!=EOF){
        FILE *inputFile = fopen("input.txt","r");
        if(method==0){
            fclose(inputFile);
            break;
        }
        else if(method>=1&&method<=4){
            switch(method){
                case 1:
                    printf("Way: getc()\n");
                    c1ch=getc(inputFile);
                    while(c1ch!=EOF){
                        printf("%c",c1ch);
                        c1ch=getc(inputFile);
                    }                    
                break;
                case 2:
                    printf("Way: fscanf()\n");
                    while (fscanf(inputFile,"%s",c2)!=EOF){
                        printf("%s ",c2);
                    }
                break;
                case 3:
                    printf("Way: fgets()\n");
                    while (fgets(c3,50,inputFile)!=NULL){
                        printf("%s",c3);
                    }
                break;
                case 4:
                    printf("Way: fread()\n");
                    while (!feof(inputFile)){
                        fread(c4,1,100,inputFile);
                        printf("%s",c4);
                    }
                break;
                    
            }
            printf("\n");
            fclose(inputFile);
        }
        else if(method<1||method>4){
            printf("Invalid choice. Please input a number between 0 to 4\n");
            continue;
        }
        printf("Choose a reading method(0~4,0 to exit)\n");
    }
    
}

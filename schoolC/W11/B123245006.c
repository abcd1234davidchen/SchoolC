#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void HW01(void){
    FILE *inFile=fopen("11-1input.txt","r");
    FILE *outFile=fopen("11_1_result.txt","w");
    int length=0,n=0,min;
    char str[256];
    while (fscanf(inFile,"%s",str)!=EOF && n<1000){
        length=(int)strlen(str);
        for (int i = 0; i < length; i++){
            if(isupper(str[i])){
                str[i]=(char)tolower(str[i]);
            }
            else if(islower(str[i])){
                str[i]=(char)toupper(str[i]);
            }
        }
        
        for (int i=0;i<length-1; i++){
            min=i;
            for(int j=i;j<length;j++){
                if(toupper(str[j])<toupper(str[min])){
                    min=j;
                }
            }
            char temp=str[i];
            str[i]=str[min];
            str[min]=temp;
        }
        n++;
        fprintf(outFile,"%s\n",str);
    }
    fclose(inFile);
    fclose(outFile);
}
void HW02(void){
    int length;
    char dir[50];
    int pos[2];
    int times=0;
    FILE *inFile2=fopen("11-2input.txt","r");
    while (fscanf(inFile2,"%s",dir)!=EOF){
        times++;
        length=(int)strlen(dir);
        pos[0]=0;//x
        pos[1]=0;//y
        for(int i=0;i<length;i++){
            switch (dir[i]){
                case 'U':
                    pos[1]++;
                    break;
                case 'D':
                    pos[1]--;
                    break;
                case 'L':
                    pos[0]--;
                    break;
                case 'R':
                    pos[0]++;
                    break;
            }
        }
        printf("Time %2d: ",times);
        if(pos[0]==0&&pos[1]==0){
            printf("TRUE\n");
        }
        else{
            printf("FALSE\n");
        }
    }
    fclose(inFile2);
}

int main(void){
    HW01();
    printf("11.2\n");
    HW02();
}

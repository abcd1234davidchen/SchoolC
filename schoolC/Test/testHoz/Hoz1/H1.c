#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main(void){
    char line[100];
    int length;
    FILE *input=fopen("test.txt","r");
    FILE *output=fopen("OUT.txt","w");

    if (input == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    while(fgets(line, 100, input) != NULL){
        length = strlen(line);
        for(int i = 0; i < length; i++){
            if(isupper(line[i]))
                line[i] = tolower(line[i]);
            else if(islower(line[i]))
                line[i] = toupper(line[i]);
        }
        fprintf(output,"%s", line);
    }

    fclose(input);
    fclose(output);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void generate(void){
    int i,j,temp;
    FILE *matrixFile=fopen("matrix.txt","w");
    FILE *biasFile=fopen("bias.txt","w");
    printf("Matrix\n");
    for(i=0;i<16;i++){
        for(j=0;j<16;j++){
            temp=rand()%21-10;
            fprintf(matrixFile," %3d",temp);
            printf(" %3d",temp);
        }
        fprintf(matrixFile,"\n");
        printf("\n");
    }
    printf("Bias\n");
    for(i=0;i<14;i++){
        for(j=0;j<14;j++){
            temp=1;
            fprintf(biasFile," %d",temp);
            printf(" %3d",temp);
        }
        fprintf(biasFile,"\n");
        printf("\n");
    }
    fclose(matrixFile);
    fclose(biasFile);
}

void convolutional(void){
    printf("Convolutional\n");
    FILE *convFile=fopen("conv.txt","w");
    FILE *biasFile=fopen("bias.txt","r");
    FILE *matrixFile=fopen("matrix.txt","r");
    FILE *kernelFile=fopen("kernel.txt","r");
    int matrix[16][16];
    int i,j,k,l,temp=0;
    double kernel[3][3],tmp;
    for(i=0;i<16;i++){
        for(j=0;j<16;j++){
            fscanf(matrixFile,"%d",&temp);
            matrix[i][j]=temp;
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            fscanf(kernelFile,"%lf",&tmp);
            kernel[i][j]=tmp;
        }
    }
    for(i=0;i<14;i++){
        for(j=0;j<14;j++){
            tmp=0;
            temp=0;
            for(k=0;k<3;k++){
                for(l=0;l<3;l++){
                    tmp+=kernel[k][l]*matrix[i+k][j+l];
                }
            }
            fscanf(biasFile,"%d",&temp);
            temp+=(int)round(tmp);
            fprintf(convFile," %3d",temp);
            printf(" %3d",temp);
        }
        fprintf(convFile,"\n");
        printf("\n");
    }
    fclose(convFile);
    fclose(biasFile);
    fclose(matrixFile);
    fclose(kernelFile);
}

void relu(void){
    printf("Relu\n");
	FILE *resultFile=fopen("result.txt","w");
    FILE *convFile=fopen("conv.txt","r");
    int i,j,temp;
    for(i=0;i<14;i++){
        for(j=0;j<14;j++){
            fscanf(convFile,"%d",&temp);
            if(temp<0) temp=0;
            fprintf(resultFile," %3d",temp);
            printf(" %3d",temp);
        }
        printf("\n");
        fprintf(resultFile,"\n");
    }
    fclose(resultFile);
    fclose(convFile);
}

int main(void){
    srand(time(NULL));

    generate();
    convolutional();
    relu();
}

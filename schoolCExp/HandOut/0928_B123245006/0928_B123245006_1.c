#include<stdio.h>
int main(){
    int r;
    float singleSphere;
    double doubleSphere;
    printf("Please enter the radius of the sphere (interger): ");
    scanf("%d",&r);
    singleSphere = r*r*r*3.14*4/3;
    doubleSphere = r*r*r*3.14*4/3;
    printf("Sphere volume calculated as a single precision floating point number %f\n",singleSphere);
    printf("Sphere volume calculated as a double precision floating point number %lf\n",doubleSphere);
}
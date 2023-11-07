#include <stdio.h>

int main(void) {
    //1.1
    printf("My student ID is B123245006\n\n");
    printf("                 *\n");
    printf("                 *\n");
    printf("         *****************\n");
    printf("         *       *       *\n");
    printf("         *       *       *\n");
    printf("         *****************\n");
    printf("                 *\n");
    printf("                 *\n");
    printf("                 *\n");
    printf("                 *\n\n");
    printf("                 *\n");
    printf("                 *\n");
    printf("                 *\n");
    printf("                 *\n");
    printf("         *       *       *\n");
    printf("         *       *       *\n");
    printf("         *       *       *\n");
    printf("         *       *       *\n");
    printf("         *       *       *\n");
    printf("         *****************\n\n");
    
    //1.2
    int x=5,y=9,sqr,cub;
    float tri,cir,cyl,pi = 3.14,sqro = 1.73;
    tri = x*x*sqro/4;
    sqr = x*x;
    cir = y*y*pi;
    cub = x*x*x;
    cyl = y*y*y*pi;
    printf("The area of the triangle is %f\n",tri);
    printf("The area of the square is %d\n",sqr);
    printf("The area of the circle is %f\n",cir);
    printf("The volume of the cube is %d\n",cub);
    printf("The volume of the cylinder is %f\n\n",cyl);
    return 0;
}

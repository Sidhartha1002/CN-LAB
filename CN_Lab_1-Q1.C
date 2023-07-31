#include <stdio.h>
#include <stdlib.h>

void swap(int *p1,int *p2){    // swap function
    int temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
    
}
int main(int argc,char * argv[])  //the inputs are taken as strings
{
    int a= atoi(argv[1]);  // atoi function coverting the string to an integer type
    int b= atoi(argv[2]);
    printf("The no. before swapping are: a= %d and b= %d\n",a,b);
    swap(&a,&b);
    printf("The no. after swapping are: a= %d and b= %d",a,b);
    return 0;
}
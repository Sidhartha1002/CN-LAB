#include <stdio.h>

int main(){
    unsigned char bytes[4];
    unsigned int n;
    printf("Enter the number:");
    scanf("%d",&n);
    printf("The input number is: %d\n",n);
    bytes[0] = (n >> 24) & 0xFF;
    bytes[1] = (n >> 16) & 0xFF;
    bytes[2] = (n >> 8) & 0xFF;
    bytes[3] = (n >> 0) & 0xFF;
    printf("The 1st byte is: %d\n",bytes[3]);
    printf("The 2nd byte is: %d\n",bytes[2]);
    printf("The 3rd byte is: %d\n",bytes[1]);
    printf("The 4th byte is: %d\n",bytes[0]);
    
}
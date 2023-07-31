#include <stdio.h>

struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};

int main() {
    struct pkt data;

    printf("Enter a number: ");
    scanf("%c", &data.ch1);

    printf("Enter next two digits: ");
    scanf("%s", data.ch2);

    printf("Enter the last digit: ");
    scanf(" %c", &data.ch3);

    // Print the content of each member of the structure
    printf("Content of the structure:\n");
    printf("ch1: %c\n", data.ch1);
    printf("ch2: %s\n", data.ch2);
    printf("ch3: %c\n", data.ch3);

    // Aggregate each member of the structure to form the original number
    int originalNumber = (data.ch1 - '0') * 100 + (data.ch2[0] - '0') * 10 + (data.ch2[1] - '0') * 1 + (data.ch3 - '0');

    // Print the original number
    printf("Original number: %d\n", originalNumber);

    return 0;
}

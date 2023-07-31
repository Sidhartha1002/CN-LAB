#include <stdio.h>

// Union to store the number and its bytes in different ways
union Number {
    int num;
    char bytes[sizeof(int)];
};

// Function to check the Endianness of the host machine
int isLittleEndian() {
    union Number n;
    n.num = 1;
    return n.bytes[0];
}

// Function to convert Endianness from Little to Big or vice versa
void convertEndianness(int *num) {
    union Number n;
    n.num = *num;
    char temp;

    if (isLittleEndian()) {
        // Convert Little Endian to Big Endian
        temp = n.bytes[0];
        n.bytes[0] = n.bytes[3];
        n.bytes[3] = temp;

        temp = n.bytes[1];
        n.bytes[1] = n.bytes[2];
        n.bytes[2] = temp;
    } else {
        // Convert Big Endian to Little Endian
        temp = n.bytes[0];
        n.bytes[0] = n.bytes[3];
        n.bytes[3] = temp;

        temp = n.bytes[1];
        n.bytes[1] = n.bytes[2];
        n.bytes[2] = temp;
    }

    *num = n.num;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // Print the content of each byte location
    union Number n;
    n.num = num;
    printf("Content of each byte location:\n");
    for (int i = 0; i < sizeof(int); i++) {
        printf("Byte %d: %02X\n", i, n.bytes[i]);
    }

    // Check the Endianness of the host machine
    if (isLittleEndian()) {
        printf("Host machine is in Little Endian.\n");
    } else {
        printf("Host machine is in Big Endian.\n");
    }

    // Convert the Endianness of the number
    convertEndianness(&num);

    // Print the converted number
    printf("Converted number: %d\n", num);

    return 0;
}

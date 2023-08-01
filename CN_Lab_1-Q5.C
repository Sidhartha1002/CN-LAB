#include <stdio.h>

void print_bytes(char *data, int size) {
    printf("Bytes: ");
    for (int i = 0; i < size; i++) {
        printf("%02X ", (unsigned char)data[i]);
    }
    printf("\n");
}

void swap_endianness(char *data, int size) {
    for (int i = 0; i < size / 2; i++) {
        char temp = data[i];
        data[i] = data[size - 1 - i];
        data[size - 1 - i] = temp;
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    char *bytes = (char *)&num;
    int size = sizeof(num);

    printf("Endianness: %s Endian\n", (bytes[0] == 0) ? "Big" : "Little");
    print_bytes(bytes, size);

    swap_endianness(bytes, size);

    printf("Converted Endianness: %s Endian\n", (bytes[0] == 0) ? "Big" : "Little");
    print_bytes(bytes, size);

    return 0;
}

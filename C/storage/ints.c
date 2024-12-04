#include <stdint.h>
#include <stdio.h>
int main() {
    int8_t num1;
    int16_t num2;
    int32_t num3;
    int64_t num4;
    char byte[] = "|_|_|_|_|_|_|_|_|";
    //_______________________________________________________
    printf("size of int8_t  = %llu byte\n", sizeof(num1));
    printf("%s", byte);
    printf("\n\n");
    //_______________________________________________________
    printf("size of int16_t = %llu byte\n", sizeof(num2));
    for (int i = 0; i < 2; i++) {
        printf("%s", byte);
    }
    printf("\n\n");
    //_______________________________________________________
    printf("size of int32_t = %llu byte\n", sizeof(num3));
    for (int i = 0; i < 4; i++) {
        printf("%s", byte);
    }
    printf("\n\n");
    //_______________________________________________________
    printf("size of int64_t = %llu byte\n", sizeof(num4));
    for (int i = 0; i < 8; i++) {
        printf("%s", byte);
    }
    printf("\n\n");
    //_______________________________________________________
    return 0;
}

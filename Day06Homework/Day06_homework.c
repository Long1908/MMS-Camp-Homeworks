#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#define PI 3.14159265
#define TINT 1
#define TDOUBLE 2
#define TCHAR 3
#define TUINT_8 4
#define TUINT_16 5
#define TUINT_32 6
#define TUINT_64 7
#define TFLOAT 8

void printValue(const void* valuePtr, uint8_t flag)
{
    switch(flag)
    {
        case 1:
            printf("%d\n", *(int*)valuePtr);
            break;
        case 2:
            printf("%lf\n", *(double*)valuePtr);
            break;
        case 3:
            printf("%c\n", *(char*)valuePtr);
            break;
        case 4:
            printf("%u\n", *(uint8_t*)valuePtr);
            break;
        case 5:
            printf("%u\n", *(uint16_t*)valuePtr);
            break;
        case 6:
            printf("%u\n", *(uint32_t*)valuePtr);
            break;
        case 7:
            printf("%lu\n", *(uint64_t*)valuePtr);
            break;
        case 8:
            printf("%f\n", *(float*)valuePtr);
            break;
    }
}
unsigned int checkBits(unsigned int n)
{
    unsigned count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

unsigned sameBitsCounter(unsigned count, unsigned bitscnt, ...)
{
    int result = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++)
    {
       int mask = va_arg(args,int);
       if (checkBits(mask) == bitscnt)
       {
            result++;
       }
    }
    va_end(args);
    return result;
}

int main()
{
    //Task 1
    /*int number;

    float temp, sqrt;

    printf("Provide the number: ");

    scanf("%d", &number);

    sqrt = number / 2;
    temp = 0;

    while(sqrt != temp){
        temp = sqrt;
        sqrt = ( number/temp + temp) / 2;
    }

    printf("The square root of %d is %f\n", number, sqrt);
    return 0;*/

    //Task 2

    //Task 3
    /*int num = 23;
    printValue(&num, TINT);
    char symbol = 'a';
    printValue(&symbol, TCHAR);*/

    //Task 4
    bitsNCount(4, 2, 0x0a, 0xff, 0, 1);
    bitsNCount(3, 8, 0xff, 0x13f1, 0xaaaa);
    bitsNCount(5, 10, 0x0a, 0xa0ff, 0, 10, 0b1010111110111);
}
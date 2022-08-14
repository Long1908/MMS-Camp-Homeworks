#include <stdio.h>
#include <stdint.h>

void secondMax(const int* arr, size_t n, int* secondMax)
{
    int same_numbers = 0;
    for(int i = 1; i < n; i++)
    {
        if(arr[0] == arr[i])
        {
            same_numbers++;
        }
    }
    if((same_numbers != n - 1) && (n != 0) || (n != 1))
    {
        int max = arr[0];
        for(int i = 1; i < n; i++)
        {
            if(arr[i] > max)
            {
                max = arr[i];
            }
        }
        *secondMax = arr[0];
        if(*secondMax == max) {*secondMax = arr[1];};
        for(int i = 1; i < n; i++)
        {
            if((arr[i] > *secondMax) && (arr[i] != max))
            {
                *secondMax = arr[i];
            }
        }
    }
}

unsigned sumArrayDigits(const int* arr, size_t n) {
    int sum = 0;
    int buf;
    for(int i = 0; i < n; i++)
    {
        buf = arr[i];
        while(buf)
        {
            sum += (buf % 10);
            buf /= 10;     
        }
    }
    return sum;
}
int sum(int* arr, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int))
{
    printf("%d", f(arr, n));
}

int main()
{
    //Task 1
    int sm;
    int arr1[] = {12, 34, 5, 70, 46};
    secondMax(arr1, 5, &sm);
    printf("%d\n", sm);

    //Task 2
    int arr2[] = {12, 34, 5, 70 };
    printf("%d\n", sumArrayDigits(arr2, 4));

    //Task 3
    int arr3[] = {1, 2, 3};
    sum(arr3, 3);
    arrayEvaluate(arr3, 3, sum);


    return 0;
}
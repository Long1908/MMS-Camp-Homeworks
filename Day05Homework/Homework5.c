#include <stdio.h>
#include <math.h>
#include <stdint.h>

double calculate(double num1, char operation, double num2)
{
    if(operation == '+'){
        return num1 + num2;
    }
    else if(operation == '-'){
        return num1 - num2;
    }
    else if(operation == '*'){
        return num1 * num2;
    }
    else if(operation == '/'){
        return num1 / num2;
    }
    else{
        return EOF;
    }
}

int triangleCalculate(double a, double b, double c, double* S, double* P)
{
    if (a > 0 && b > 0 && c > 0 && ((a + b != c) && (a + c != b) && (b + c != a)))
    {
        *P = a + b + c;
        double halfP =  *P / 2;
        *S = sqrt(halfP * (halfP - a) * (halfP - b)* (halfP - c));
        return 0;
    }
    return -1;
}

int rectangleCalculate(double a, double b, double* S, double* P)
{
    if (a > 0 && b > 0)
    {
        *P = 2 * a + 2 * b;
        *S = a * b;
        return 0;
    }
    else
    {
        return -1;
    }
}

int quadEq(double a, double b, double c, double* x1, double* x2)
{
    if((a > 0) && ((pow(b, 2) - (4 * a * c)) >= 0))
    {
        *x1 = (-b + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
        *x2 = (-b - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
        return 0;
    }
    else
    {
        return -1;
    }

}

int countSetBits(uint64_t mask)
{
    int counter = 0;
    for(int i = sizeof(uint64_t) * __CHAR_BIT__ - 1; i >= 0; i--)
    {
        printf("%d", !!(mask & (1ull << i)));
    }
    printf("\n");
    for(int i = 0; i < sizeof(uint64_t) * __CHAR_BIT__ - 1; i++)
    {
        if(!!(mask & (1ull << i)))
        {
            counter++;
        }   
    }
    return counter;
}

int main()
{
    printf("Task1:\n");
    double num1, num2;
    char operation;
    scanf("%lf %c %lf", &num1, &operation, &num2);
    printf("%.2lf %c %.2lf = %.2lf\n", num1, operation, num2, calculate(num1, operation, num2));
    
    printf("Task2:\n");
    double side1, side2, side3, perimeter = 0, area = 0;
    scanf("%lf %lf %lf", &side1, &side2, &side3);
    if(!(triangleCalculate(side1, side2, side3, &area, &perimeter)))
    {
        printf("P = %.2lf\n S = %.2lf\n", perimeter, area);
    }
    else
    {
        printf("Invalid triangle sides! \n ");
    }

    printf("Task3:\n");
    double length, width, perimeterRect = 0, areaRect = 0;
    scanf("%lf %lf", &length, &width);
    if(!(rectangleCalculate(length, width, &areaRect, &perimeterRect)))
    {
        printf("P = %.2lf\nS = %.2lf \n", perimeterRect, areaRect);
    }
    else
    {
        printf("Invalid rectangle sides! \n ");
    }

    printf("Task4:\n");
    double a, b, c, x1, x2;
    scanf("%lf %lf %lf", &a, &b, &c);
    if(!(quadEq(a, b, c, &x1, &x2)))
    {
        printf("x1 = %.2lf\nx2 = %.2lf \n", x1, x2);
    }
    else
    {
        printf("No real roots\n ");
    }

    printf("Task5:\n");
    uint64_t mask;
    scanf("%ld", &mask);
    printf("Number of set bits: %d\n", countSetBits(mask));
    return 0;

}
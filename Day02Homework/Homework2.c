#include <stdio.h>
#include <stdint.h>
//https://docs.google.com/document/d/1lgWbseHfM6_qwjIk_XniNoDLBQIqGjvFe2ySGGPs7vw/edit?fbclid=IwAR04mRqPHaoAHIzj20NWM7ynP31yP_aSBMTbyXM0YrqayT1ZCl0TOOnUnfs

int XOR(int num1, int num2)
{
	if((!!(num1)) != (!!(num2)))
		return 1;
	else
		return 0;
}

int XORofThreeNumbers(int num1, int num2, int num3)
{
	if(((!!(num1)) != (!!(num2))) || ((!!(num1)) != (!!(num3))))
		return 1;
	else
		return 0;
}
int main()
{
	unsigned int num1, num2, num3;
	scanf("%u %u %u", &num1, &num2, &num3);
	if(num1 > num2 && num1 > num3)
	{
		printf("The larges integer is: %u\n", num1);
	}
	else if(num2 > num1 && num2 > num3)
	{
		printf("The larges integer is: %u\n", num2);
	}
	else if(num3 > num1 && num3 > num1)
	{
		printf("The larges integer is: %u\n", num3);
	}

	printf("%d XOR %d : %d\n", num1, num2, XOR(num1, num2));
	printf("%d XOR %d : %d\n", num1, num3, XOR(num1, num3));
	printf("%d XOR %d : %d\n", num2, num3, XOR(num2, num3));
	printf("%d XOR %d XOR %d : %d\n", num1, num2, num3, XORofThreeNumbers(num1, num2, num3));

	return 0;
}


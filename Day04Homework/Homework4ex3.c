#include <stdio.h>
#include <stdint.h>

int convert(int number, int base1, int base2)
{
	int lastDecimal, DECnumber = 0, power = 0, base2Number = 0, lastBase2Int;
	while(number != 0)
	{
		lastDecimal = number % 10;
		DECnumber += lastDEcimal * pow(base1, power);
		++power;
		number /= 10;
	}

	while(DECnumber != 0)
	{
		lastBase2Int = DECnumber / base2;
		if(lastBase2Int < 9)
		{
			
		}
	}
}


int main()
{
	uint64_t number;
	int base1, base2;
	scanf("%d", &number);
	scanf("%d", &base1);
	while(base1 < 2 || base1 > 36)
	{
		printf("Error in entering your number: ");
		scanf("%d", &base1);
	}
	scanf("%d", &base2);
	while(base2 < 2 || base2 > 36)
	{
		printf("Error in entering your number: ");
		scanf("%d", &base2);
	}
	convert(number, base1, base2);
	
	return 0;
}

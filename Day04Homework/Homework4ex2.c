#include <stdio.h>
#include <stdint.h>

int main()
{
	uint32_t mask = 0;
	int choice, bit, numberOfSetBits, numberOfClearedBits;
	while(1)
	{
		printf("1. Set\n2. Clear\n3. Show cleared bits\n4. Showed set bits\n5. Change\n6. Exit\n");
		scanf("%d", &choice);

		while(choice < 1 || choice > 6)
		{
			printf("Error in entering your choice. Please try again: ");
			scanf("%d", &choice);
		}
		
		if(1 == choice){
			scanf("%d", &bit);
			while(bit < 1 || bit > 32)
			{
				printf("Error in entering your bit. Please try again: ");
				scanf("%d", &bit);
			}
			mask |= (1 << bit);
		}
		else if(2 == choice){
			scanf("%d", &bit);
			while(bit < 1 || bit > 32)
			{
				printf("Error in entering your bit. Please try again: ");
				scanf("%d", &bit);
			}
			mask &= ~(1 << bit);
		}
		else if(4 == choice){
			numberOfSetBits = 0;
			for(int i = 0; i < sizeof(uint32_t) * __CHAR_BIT__; ++i)
			{
				if(!!(mask & (1 << i)))
				{
					++numberOfSetBits;
				}
			}
			printf("Set bits: %d\n", numberOfSetBits);
		}
		else if(3 == choice){
			numberOfClearedBits = 0;
			for(int i = 0; i < sizeof(uint32_t) * __CHAR_BIT__; ++i)
			{
				if(!(mask & (1 << i)))
				{
					++numberOfClearedBits;
				}
			}
			printf("Cleared bits: %d\n", numberOfClearedBits);
		}
		else if(5 == choice){
			scanf("%d", &bit);
			while(bit < 1 || bit > 32)
			{
				printf("Error in entering your bit. Please try again: ");
				scanf("%d", &bit);
			}
			if(!!(mask | (1 << bit)))
			{
				mask &= ~(1 << bit);
			}
			else
			{
				mask |= (1 << bit);
			}
		}
		else if(6 == choice){
			break;
		}
	}

	return 0;
}

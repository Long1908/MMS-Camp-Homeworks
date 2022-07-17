#include <stdio.h>
#include <math.h>
//https://docs.google.com/document/d/19iiDVHpLQe1ogADMJTZbiIWXeHNM1IiHrlEdIygmkZA/edit?fbclid=IwAR3TdvxyVG6lZS-lvxjKgOQ-mxvEUNWh2qylkjODdpdf68ztZMYfpNz5g88
int main()
{
	//Task 1 a) and b)
	printf("Task 1\n");
	double BMI, mass, height1, BMInew;
	scanf("%lf  %lf", &mass, &height1);
	BMI = mass / (height1 * height1);
	BMInew = 1.3 * (mass / pow(height1, 2.5)); 
	printf("Your body mass: %lf\n", BMI);
	printf("Your body mass with the new formula : %lf\n", BMInew);

	//Task 2 a) and b)
	printf("Task 2\n");
	double radius, height2, length, volumeWhenStanding, volumeWhenLaying;
	scanf("%lf %lf %lf", &radius, &length, &height2);
	volumeWhenStanding = 3.14 * pow(radius, 2) * height2;
	volumeWhenLaying = acos((radius - height2) / radius) * pow(radius , 2) - (radius - height2) * sqrt(2 * radius * height2 - pow(height2 , 2));
	printf("The volume of the water in the barrel when it's standing: %lf \n", volumeWhenStanding);
	printf("The volume of the water in the barrel when it's laying: %lf\n", volumeWhenLaying);
	return 0;
}


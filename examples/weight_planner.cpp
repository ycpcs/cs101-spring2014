#include <stdio.h>

int main(void) {
	double weight;
	
	printf("How much do you weigh? ");
	scanf("%lf", &weight);
	
	printf("You weigh: %08.2lf\n", weight);
	
	
	double target_weight;
	printf("What is your target weight? ");
	scanf("%lf", &target_weight);
	
	int num_weeks;
	printf("How many weeks? ");
	scanf("%i", &num_weeks);
	
	double units_per_week;
	units_per_week = (weight - target_weight) / num_weeks;
	printf("You need to lose %.2lf units per week\n",
		units_per_week);
	
	return 0;
}

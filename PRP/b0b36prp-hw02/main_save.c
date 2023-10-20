#include <stdio.h>
#include <stdlib.h>
struct all_variables {
	int count;
	int positive;
	int negative;
	int even;
	int odd;
	int min;
	int max;
	int sum;
};
double calculate_percentage(int numerator, int denominator);
double calculate_average(int sum, int count);
void init_my_struct(struct all_variables *my_vars);
void increment_vars(struct all_variables *my_vars, int number);
void print(struct all_variables *my_vars);
int check_input(int number);

#define TRUE 1
#define FALSE 0
#define SUCCESS 0
#define OUT_OF_RANGE 100
#define MAX_NUM 10000
#define MIN_NUM -10000
#define INPUT_INVALID(ret) ret < 1 ? TRUE : FALSE
#define IS_FIRST_ITERATION(count) count == 0 ? TRUE : FALSE
#define IS_POSITIVE(n) n > 0 ? TRUE : FALSE
#define IS_NEGATIVE(n) n < 0 ? TRUE : FALSE
#define IS_EVEN(n) n % 2 == 0 ? TRUE : FALSE
#define PERCENTAGE(x) x * 100

//single line if statements??
//(*my_vars) alebo si mam premenovat pointer ????
//viac riadkove makra? - definovanie default values of struct

int main(int argc, char *argv[]) {
	struct all_variables my_vars;
	init_my_struct(&my_vars);
	int ret = SUCCESS;
	int number;

    while(scanf("%d", &number) >= 1) {
		if (check_input(number) == OUT_OF_RANGE) {
			ret = OUT_OF_RANGE;
			break;
		}
		if(IS_FIRST_ITERATION(my_vars.count)) {
			my_vars.min = number;
			my_vars.max = number;
			printf("%d", number);
		} else {
			printf(", %d", number);
		}
		increment_vars(&my_vars, number);
    }
	printf("\n");
	if(ret == SUCCESS) print(&my_vars);
	return ret;
}

int check_input(int number) {
	int ret = SUCCESS;
	if (number > MAX_NUM || number < MIN_NUM) {
		printf("\nError: Vstup je mimo interval!");
		ret = OUT_OF_RANGE;
	}
	return ret;
}
double calculate_percentage(int numerator, int denominator) {
	double result = (double)numerator / (double)denominator;
	return PERCENTAGE(result);
}

double calculate_average(int sum, int count) {
	return (double)sum / (double) count;
}

void init_my_struct(struct all_variables *my_vars){
	(*my_vars).count = 0;
	(*my_vars).positive = 0;
	(*my_vars).negative = 0;
	(*my_vars).even = 0;
	(*my_vars).odd = 0;
	(*my_vars).min = 0;
	(*my_vars).max = 0;
	(*my_vars).sum = 0;
}

void increment_vars(struct all_variables *my_vars, int number) {
	(*my_vars).count++;
	if(IS_POSITIVE(number)) (*my_vars).positive++;
	if(IS_NEGATIVE(number)) (*my_vars).negative++;
	if(IS_EVEN(number)) {
		(*my_vars).even++;
	} else {
		(*my_vars).odd++;
	}
	if(number > (*my_vars).max) (*my_vars).max=number;
	if(number < (*my_vars).min) (*my_vars).min=number;
	(*my_vars).sum += number;
}

void print(struct all_variables *my_vars){
	printf("Pocet cisel: %d\n", (*my_vars).count);
	printf("Pocet kladnych: %d\n", (*my_vars).positive);
	printf("Pocet zapornych: %d\n", (*my_vars).negative);
	printf("Procento kladnych: %.2lf\n", calculate_percentage((*my_vars).positive, (*my_vars).count));
	printf("Procento zapornych: %.2lf\n", calculate_percentage((*my_vars).negative, (*my_vars).count));
	printf("Pocet sudych: %d\n", (*my_vars).even);
	printf("Pocet lichych: %d\n", (*my_vars).odd);
	printf("Procento sudych: %.2lf\n", calculate_percentage((*my_vars).even, (*my_vars).count));
	printf("Procento lichych: %.2lf\n", calculate_percentage((*my_vars).odd, (*my_vars).count));
	printf("Prumer: %.2lf\n", calculate_average((*my_vars).sum, (*my_vars).count));
	printf("Maximum: %d\n", (*my_vars).max);
	printf("Minimum: %d\n", (*my_vars).min);
}

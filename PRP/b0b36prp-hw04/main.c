#include <stdio.h>
#include <stdlib.h>

void get_prime_decomposition(int number);
void print_result(int all_primes[], int prime_multiples[], int number, int count_primes); 
int get_lowest_prime_divisor(int number, int lowest_prime);
#define SUCCESS 0
#define INVALID_INPUT 100
#define MAX_NUMBER 1000000


/* The main program */
int main(int argc, char *argv[]) {
    int number;
    int ret;
    while(scanf("%d", &number)) {
        if(number == 0) {
            break;
        } else if(number < 0){
            ret = INVALID_INPUT;        
        }
        get_prime_decomposition(number);
    }
    return ret;
}

void get_prime_decomposition(int number){
    int fraction_of_number = number;
    int lowest_prime = 2;
    int all_primes[MAX_NUMBER] = {};
    int prime_multiples[MAX_NUMBER] = {};
    int prime_counter = 0;
    while(number != 1) {
        lowest_prime = get_lowest_prime_divisor(fraction_of_number, lowest_prime);
        fraction_of_number = fraction_of_number / lowest_prime;
        if(lowest_prime == all_primes[prime_counter]) {
            prime_multiples[prime_counter] += 1;
        } else {
            prime_counter++;
            all_primes[prime_counter] = lowest_prime;
            prime_multiples[prime_counter] = 1;
        }
        if(fraction_of_number == 1) {
            break;
        }
    }
    print_result(all_primes, prime_multiples, number, prime_counter);
}
 
int get_lowest_prime_divisor(int number, int lowest_prime) {
    int new_prime = 0;
    for(int i = lowest_prime; i <= number; i++) {
        if(number % i == 0) {
            new_prime = i;
            break;
        }
    }
    return new_prime;
}

void print_result(int all_primes[], int prime_multiples[], int number, int prime_counter) {
    printf("Prvociselny rozklad cisla %d je\n", number);
    if(number == 1) {
        printf("1");
    } else {
        for(int i=1; i <= prime_counter; i++) {
            printf("%d^%d\n", all_primes[i], prime_multiples[i]);
            //if(*prime_multiples[i] > 1) {}
        }
    }
} 


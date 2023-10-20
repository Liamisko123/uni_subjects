#include <stdio.h>

int calculateAndPrint (int num1, int num2, int ret);

#define SUCCESS 0
#define OUT_OF_RANGE 100
#define DIVISION_BY_ZERO 101
#define MAX_NUMBER 10000
#define MIN_NUMBER -10000

int main(void)
{
    int ret = SUCCESS;
    int num1;
    int num2;
    scanf("%d", &num1);
    scanf("%d", &num2);
    if (num1 < MIN_NUMBER || num1 > MAX_NUMBER ||num2 < MIN_NUMBER || num2 > MAX_NUMBER) {
        fprintf(stderr, "Error: Vstup je mimo interval!");
        return OUT_OF_RANGE;
    }
    ret = calculateAndPrint(num1, num2, ret);
    return ret;
}

int calculateAndPrint (int num1, int num2, int ret) {
    int sum = num1 + num2;
    int difference = num1 - num2;
    int multiplication = num1 * num2;
    int division;
    float average = (num1 + num2) / 2.0;

    printf("Desitkova soustava: %d %d\n", num1, num2);
    printf("Sestnactkova soustava: %x %x\n", num1, num2);
    printf("Soucet: %d + %d = %d\n", num1, num2, sum);
    printf("Rozdil: %d - %d = %d\n", num1, num2, difference);
    printf("Soucin: %d * %d = %d\n", num1, num2, multiplication);
    if (num2 == 0) {
        ret = DIVISION_BY_ZERO;
        printf("Podil: %d / %d = NaN\n", num1, num2);
        fprintf(stderr, "Error: Nedefinovany vysledek!");
    } else {
        division = num1 / num2;
        printf("Podil: %d / %d = %d\n", num1, num2, division);
    }
    printf("Prumer: %.1f", average);

    return ret;
}

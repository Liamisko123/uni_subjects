#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct boy {
    int age;
    char name[50];
    double sizeInInches;
};

int main() {
    int x = 5;
    int y = ++x;
    printf("%d %d", x, y);
    puts("");
    x = 5;
    y = x++;
    printf("%d %d", x, y);
    int num1;
    int num2;
    scanf("%d", &num1);
    scanf("%d", &num2);

    if(num2 == 0) {
        fprintf(stderr, "0 Cannot be placed in the denominator!!");
        return 55;
    }

    int sum = num1 + num2;
    int difference = num1 - num2;
    int multiplication = num1 * num2;
    int division = num1 / num2;
    int average = sum / 2;
    printf("%d", sum);
    printf("%d", difference);
    printf("%d", multiplication);
    printf("%d", division);
    printf("%d", average);
    puts("");

    struct boy blackBoy;
    blackBoy.age = 17;
    blackBoy.sizeInInches = 7.3;
    strcpy( blackBoy.name, "Adrian Silva");
    
    printf("%s", blackBoy.name);
    printf("%s", "vis a professional when it comes to sizes, at the age of only ");
    printf("%d", blackBoy.age);
    printf("%s", " he became the youngest boy with length in inches of ");
    printf("%.2lf", blackBoy.sizeInInches);


    return 100;
}

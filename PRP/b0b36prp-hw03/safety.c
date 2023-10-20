#include <stdio.h>
#include <stdlib.h>

void draw(int width, int height);
void draw_roof(int width);
void draw_room(int width, int height);
void draw_white_space(int n);
void draw_line(int n);
int check_input(int s_ret,int width,int height, int fence);



#define SUCCESS 0
#define TRUE 1
#define FALSE 0
#define IS_EVEN(n) n % 2 == 0 ? TRUE : FALSE
#define IS_NOT_IN_RANGE(n) n < 3 || n > 69 ? TRUE : FALSE
/* The main program */
int main(int argc, char *argv[])
{
	int width, height, fence;
	int s_ret = scanf("%d%d%d", &width, &height, &fence);
	int ret = check_input(s_ret, width, height, fence);
	if(ret == SUCCESS) {
		draw(width, height);
	}
	return ret;
}

void draw(int width, int height) {
	printf("\n");
	draw_roof(width);
	draw_room(width, height);
}

void draw_roof(int width) {
	draw_white_space(width / 2);
	printf("X\n");
	for (int i=1; i<width-2; i+=2) {
		draw_white_space((width-2-i) / 2);
		printf("X");
		draw_white_space(i);
		printf("X\n");
	}
}

void draw_room(int width, int height) {
	draw_line(width);
	for(int i=0; i<height-2;i++) {
		printf("X");
		draw_white_space(width-2);
		printf("X\n");
	}
	draw_line(width);
}

void draw_white_space(int n) {
	for(int i=0;i<n;i++){
		printf(" ");
	}
}

void draw_line(int n) {
	for (int i=0; i<n;i++) {
		printf("X");
	}
	printf("\n");
}

int check_input(int s_ret,int width,int height, int fence){
	int ret = SUCCESS;
	if(ret < 2) {
		ret = 100;
		fprintf(stderr, "Error: Chybny vstup!\n");
	} else if(IS_NOT_IN_RANGE(width) || IS_NOT_IN_RANGE(height)) {
		ret = 101;
		fprintf(stderr, "Error: Vstup mimo interval!\n");
	} else if(IS_EVEN(width)) {
		ret = 102;
		fprintf(stderr, "Error: Sirka neni liche cislo!\n");
	} else if(s_ret == 3) {
		if (fence < 0 || fence >= height) {
			ret = 103;
			fprintf(stderr, "Error: Neplatna velikost plotu!");
		}
	}
	printf("%d", fence);
	return ret;
}

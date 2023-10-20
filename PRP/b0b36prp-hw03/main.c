#include <stdio.h>
#include <stdlib.h>

void draw(int width, int height, int fence, int input_count);
void draw_roof(int width);
void draw_room(int width, int height);
void draw_white_space(int n);
void draw_full_space(int n, int start);
void draw_line(int n);
void draw_full_room(int width, int height, int fence);
void draw_fence(int current_height, int fence);
void draw_swapped(int i, char x[], char y[]);
int check_input(int s_ret,int width,int height, int fence, int input_count);



#define SUCCESS 0
#define TRUE 1
#define FALSE 0
#define IS_EVEN(n) n % 2 == 0 ? TRUE : FALSE
#define IS_NOT_IN_RANGE(n) n < 3 || n > 69 ? TRUE : FALSE
/* The main program 
co s for loopkami a +1 coding style
*/
int main(int argc, char *argv[])
{
	int width, height, input_count, fence;
	fence = 0;
	input_count = 2;

	int s_ret = scanf("%d%d", &width, &height);
	if(width == height) {
		input_count = 3;
		s_ret += scanf("%d", &fence);
	}

	int ret = check_input(s_ret, width, height, fence, input_count);
	if(ret == SUCCESS) {
		draw(width, height, fence, input_count);
	}
	return ret;
}

void draw(int width, int height, int fence, int input_count) {
	if (input_count == 2){
		draw_roof(width);
		draw_room(width, height);
	} else {
		draw_roof(width);
		draw_full_room(width, height, fence);
	}
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
	printf("\n");
	for(int i=0; i<height-2;i++) {
		printf("X");
		draw_white_space(width-2);
		printf("X\n");
	}
	draw_line(width);
	printf("\n");
}

void draw_full_room(int width, int height, int fence) {
	draw_line(width);
	printf("\n");
	for(int i=(height-2); i>0;i--) {
		printf("X");
		if(i % 2 != 0) {
			draw_full_space(width-2, TRUE);
		} else {
			draw_full_space(width-2, FALSE);
		}
		printf("X");
		if(i < fence){ //dont include cuz fence is abs height, whereas height starts at 0
			draw_fence(i, fence);
		}
		printf("\n");
	}
	draw_line(width);
	draw_fence(0, fence);
	printf("\n");
}

void draw_fence(int current_height, int fence) {
	if (current_height+1 == fence || current_height == 0) {
		if (fence % 2 == 0) {
			for (int i=0; i< fence; i++) {
				draw_swapped(i, "-", "|");
			}
		} else {
			for (int i=0; i< fence; i++) {
				draw_swapped(i, "|", "-");
			}
		}
	} else {
		if (fence % 2 == 0) {
			for (int i=0; i< fence; i++) {
				draw_swapped(i, " ", "|");
			}
		} else {
			for (int i=0; i< fence; i++) {
				draw_swapped(i, "|", " ");
			}
		}
	}
		
	
}

void draw_white_space(int n) {
	for(int i=0;i<n;i++){
		printf(" ");
	}
}

void draw_full_space(int n, int start) { 
	for(int i=0; i<n;i++) {
		if (start == TRUE) {
			draw_swapped(i, "o", "*");
		} else {
			draw_swapped(i, "*", "o");
		}
	}
}

void draw_line(int n) {
	for (int i=0; i<n;i++) {
		printf("X");
	}
}

void draw_swapped(int i, char x[], char y[]) {
	if (i % 2 == 0) {
		printf("%s", x);
	} else {
		printf("%s", y);
	}
}

int check_input(int s_ret,int width,int height, int fence, int input_count){
	int ret = SUCCESS;
	if(s_ret != input_count) {
		ret = 100;
		fprintf(stderr, "Error: Chybny vstup!\n");
	} else if(IS_NOT_IN_RANGE(width) || IS_NOT_IN_RANGE(height)) {
		ret = 101;
		fprintf(stderr, "Error: Vstup mimo interval!\n");
	} else if(IS_EVEN(width)) {
		ret = 102;
		fprintf(stderr, "Error: Sirka neni liche cislo!\n");
	} else if (fence < 0 || fence >= height) {
		ret = 103;
		fprintf(stderr, "Error: Neplatna velikost plotu!\n");
	}
	return ret;
}

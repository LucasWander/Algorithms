#include <stdio.h>


void testingAnd() {
	int a = 0b10100111 & 0b00000011 == 0b00000011;
	int b = 10100111 & 00000011;
	printf("%d\n", a);
	printf("%d\n", b);

	if(a){
		printf("teste\n");
	}
}

void bitShift() {

	int a = 10 << 2;

	printf("%d\n",a);
}


int main() {

	int a = 10000000 & 01111111;
	int b = 0 ^ 0;



	bitShift();

	return 0;
}

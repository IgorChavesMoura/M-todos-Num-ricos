#include <stdio.h>
#include <stdlib.h>

void precision(){
	double A = 1.0;
	double VAL;
	double s;
	double Prec;
	scanf("%lf",&VAL);
	printf("\n");
	s = VAL + A;
	while (s > VAL){
		A = A/2;
		s = VAL + A;
		Prec = 2*A;
		printf("%f\n", Prec);
	}
}

int main(int argc, char const *argv[])
{
	precision();

	return 0;
}

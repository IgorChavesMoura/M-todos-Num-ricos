#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fatorial(int n){
	int fat = n;
	int x;
	n = n-1;
	for(x = n; x > 0; x--){
		fat = fat*x;
	}
	return fat;
}


double taylor_ex(double x, int n){
	

}
int main(int argc, char const *argv[])
{
	double x = 2;
	int n = 12;

	double ex = taylor_ex(x,n);
	printf("%lf\n",ex);

	return 0;
}
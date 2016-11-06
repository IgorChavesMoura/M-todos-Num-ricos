#include <iostream>
#include <cmath> // ou <math.h
#include <cstdlib>
#include <ctime>
using namespace std;
class Foguete {
	private:
		float a,a0,b0,eps;


	public:
		float f(float d);
		float fl(float d);
		Foguete();
		Foguete(float a);
		Foguete(float a0, float b0);
		Foguete(float a, float a0, float b0);
		float bisseccao(float eps);
		float posFalsa(float eps);
		float newtonRapshon(float eps);
};
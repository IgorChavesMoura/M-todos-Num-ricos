#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
using namespace std;

int binToDecR(string bin, int p){
	
	cout << "p: " << p << endl;
	int temp;
	if(bin[p] == '0'){
		temp = 0;
	} else {
		temp = 1;
	}
	int t;
	if(p > 0) {
			
		return 2*binToDecR(bin,p-1) + temp;
		//return v + 2*(binToDecR(v,bin,p-1));
		
		//return v;
	} else {
		return temp;
		
	}
	
}

int main(int argc, char const *argv[])
{
	string bin = "1011011000";

	int resultado = binToDecR(bin,bin.size()-1);


	cout << resultado << endl;

	return 0;
}
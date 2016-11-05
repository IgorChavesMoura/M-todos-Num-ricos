#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
using namespace std;

void binToDec(string bin){
	int dec = 0;
	int size = bin.size();
	int temp,temp2;
	int y = 0;

	
	

	for (int i = size-1;i >= 0; i--){
		if(bin[i] == '0'){
			temp = 0;
		} else {
			temp = 1;
		}
		temp2 = pow(2,y);
		y++;
		temp = temp*temp2;
		//cout << temp << endl;
				
		dec+= temp;
	}	
	cout << dec << endl;
}
int main(int argc, char const *argv[])
{
	binToDec("100");	
	return 0;
}
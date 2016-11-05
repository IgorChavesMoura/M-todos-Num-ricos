#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void decToBin(int dec){
	int temp = dec;
	string bin;
	int i = 0;

	while(temp >= 1){
		if(temp%2 == 1){
			bin[i] = '1';
		} else {
			bin[i] = '0';
		}
		temp = temp/2;
		cout << bin[i] << endl;
		i++;
	}	
	i--;
	for(int x = i; x >=0; x--){
		cout << bin[x];
	}
	cout << endl;
}
int main(int argc, char const *argv[])
{
	int n << cin;

	decToBin(n);
	

	return 0;
}

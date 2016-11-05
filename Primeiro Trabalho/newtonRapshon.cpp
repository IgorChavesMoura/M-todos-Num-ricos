#include <iostream>
#include <cmath> // ou <math.h
#include <cstdlib>
#include <ctime>
using namespace std;

#define log10(x) log(x)/log(10);

float f(float d) {
   return 1*d-d*log(d); // Função cuja raiz deve ser determinada
}
float fl(float d){
	return -1*log(d);
}
main(){

    float eps, a0, b0, tam; 
    int bolzano_ok = 0; // flag do teorema de Bolzano
    int i = 0;
    cout<<"Digite a precisão requerida: "<<endl;
    cin>>eps;
   
    cout<<"Digite o intervalo onde deve se buscar a raiz. Digite o inicio do intervalo e depois digite o fim."<<endl;
    cin>>a0>>b0;
   

    // O teorema de Bolzano (valor intermediário) foi satisfeito? 
    // f(a0) * f(b0) < 0 -> existe troca de sinal no intervalo dado e, portanto
    // existe raiz nele.
    bolzano_ok = (f(a0)*f(b0) > 0?0:1);

    // Não, então pedir um novo intervalo inicial.
    while(bolzano_ok == 0) {
       cout<<"Intervalo ["<<a0<<";"<<b0<<"] não satisfaz as condições do teorema de Bolzano. Tente outro."<<endl;
       cin>>a0>>b0;
       bolzano_ok = (f(a0)*f(b0) > 0?0:1);
    }
    srand(time(NULL));
    float x0,x1;
    x0 = (a0+b0)/2;  
    x1 = x0 - (f(x0)/fl(x0));
   	i++;
    while(abs(x1 - x0) > eps && abs(f(x1)) > eps){
    	x0 = x1;
    	x1 = x0 - (f(x0)/fl(x0));
   		i++;

    }
   
   	cout << "Raiz aproximada encontrada: " << x0 << endl;
   	cout << "Foram necessárias "<<i<<" iterações"<<endl;	
   		
    
	   
}
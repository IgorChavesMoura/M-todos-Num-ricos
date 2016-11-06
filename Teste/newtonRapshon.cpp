#include <iostream>
#include <cmath> // ou <math.h
#include <cstdlib>
#include <ctime>
using namespace std;

#define log10(x) log(x)/log(10);

float f(float a,float d) {
   return a*d-d*log(d); // Função cuja raiz deve ser determinada
}
float fl(float a,float d){
	return a-log(d)-1;
}
main(){

    float eps, a0, b0, tam, a; 
    int bolzano_ok = 0; // flag do teorem a de Bolzano
    int i = 0;
    cout<<"Digite a precisão requerida: "<<endl;
    cin>>eps;
   
    cout<<"Digite o valor de a: "<<endl;
    cin>>a;

    cout<<"Digite o intervalo onde deve se buscar a raiz. Digite o inicio do intervalo e depois digite o fim."<<endl;
    cin>>a0>>b0;
   

    // O teorema de Bolzano (valor intermediário) foi satisfeito? 
    // f(a,a0) * f(a,b0) < 0 -> existe troca de sinal no intervalo dado e, portanto
    // existe raiz nele.
    bolzano_ok = (f(a,a0)*f(a,b0) > 0?0:1);

    // Não, então pedir um novo intervalo inicial.
    while(bolzano_ok == 0) {
       cout<<"Intervalo ["<<a0<<";"<<b0<<"] não satisfaz as condições do teorema de Bolzano. Tente outro."<<endl;
       cin>>a0>>b0;
       bolzano_ok = (f(a,a0)*f(a,b0) > 0?0:1);
    }
    srand(time(NULL));
    float x0,x1;
    x0 = (a0+b0)/2;  
    x1 = x0 - (f(a,x0)/fl(a,x0));
   	i++;
    while(abs(x1 - x0) > eps && abs(f(a,x1)) > eps){
    	x0 = x1;
    	x1 = x0 - (f(a,x0)/fl(a,x0));
   		i++;

    }
   
   	cout << "Raiz aproximada encontrada: " << x0 << endl;
   	cout << "Foram necessárias "<<i<<" iterações"<<endl;	
   		
    
	   
}
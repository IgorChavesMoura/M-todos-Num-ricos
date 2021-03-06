#include "Foguete.h"

float Foguete ::  f(float d){
	float a1 = this->a;
	return a1*d-d*log(d);
}
float Foguete ::  fl(float d){
	float a1 = this->a;
	return a1-log(d)-1;
}
Foguete :: Foguete(){
	this->a = 1;
	this->a0 = 2;
	this->b0 = 3;

}
Foguete :: Foguete(float a){
	this->a = a;
	this->a0 = 2;
	this->b0 = 3;
}
Foguete :: Foguete(float a0, float b0){
	this->a = 1;
	this->a0 = a0;
	this->b0 = b0;
}
Foguete :: Foguete(float a, float a0, float b0){
	this->a = a;
	this->a0 = a0;
	this->b0 = b0;
}
float Foguete :: bisseccao(float eps){
   float  a0, b0, tam, pm; 
   a0 = this->a0;
   b0 = this->b0;
   int i = 0;

   
   // O teorema de Bolzano (valor intermediário) foi satisfeito? 
   // f(a0) * f(b0) < 0 -> existe troca de sinal no intervalo dado e, portanto
   // existe raiz nele.
   // Um dos extremos do intervalo é a raiz
   float zr;

   if(f(a0) == 0 || f(b0) == 0)  {
      if(f(a0)==0){
         zr = a0;
      } else {
         zr = b0;
      }
      cout<<"O valor " << zr << " é zero da expressão."<<endl;
      return 0;
   }

   // Implementação do método da bisecção
   do {
      i++;
      tam = b0-a0;
      pm = (a0+b0)/2;
      if(f(pm) == 0) {
         cout<<"SOLUÇÃO EXATA ENCONTRADA!! x = "<<pm<<endl;
         cout<<"Foram necessárias "<<i<<" iterações"<<endl;
         return 0;
      }

      if(f(a0)*f(pm) < 0){
         b0 = pm; // a solução está a esquerda
      } else{
         a0 = pm;  // a solução está a direita
       }
      
   } while(tam > eps);
   
   cout<<"Intervalo final: ["<<a0<<","<<b0<<"]"<<endl<<"Solução aproximada: "<<((a0+b0)/2)<<endl;
   cout<<"Foram necessárias "<<i<<" iterações"<<endl;
   return (a0+b0)/2;
}
float Foguete :: posFalsa(float eps){
   
   // eps: erro
   // a0 e b0: pontos iniciais
   // tam: tamanho do intervlao
   // np: novo ponto
   // i: número de iterações
   
   float a0, b0, tam, np;
   a0 = this->a0;
   b0 = this->b0; 
   int i = 0;
   



   // Um dos extremos do intervalo é a raiz
   float zr;

   if(f(a0) == 0 || f(b0) == 0)  {
      if(f(a0)==0){
         zr = a0;
      } else {
         zr = b0;
      }
      cout<<"O valor " << zr << " é zero da expressão."<<endl;
      return 0;
   }
   float fa,fb;
   // Implementação do método da posição falsa
   do {
   	  i++;
   	  fa = f(a0);
   	  fb = f(b0);
      tam = b0-a0;
      np = (a0*fb - b0*fa)/(fb-fa);
      if(f(np) == 0) {
         cout<<"SOLUÇÃO EXATA ENCONTRADA!! x = "<<np<<endl;
         cout<<"Foram necessárias "<<i<<" iterações"<<endl;
         return 0;
     	 
      }

      if(f(a0)*f(np) < 0){
         b0 = np; // a solução está a esquerda
      } else{
         a0 = np;  // a solução está a direita
      }
      
   } while(tam > eps);
   
   cout<<"Intervalo final: ["<<a0<<","<<b0<<"]"<<endl<<"Solução aproximada: "<<((a0*fb - b0*fa)/(fb-fa))<<endl;
   cout<<"Foram necessárias "<<i<<" iterações"<<endl;
   return ((a0*fb - b0*fa)/(fb-fa));
}
float Foguete :: newtonRapshon(float eps){

    float a0, b0, tam; 
  	a0 = this->a0;
   	b0 = this->b0; 
    int i = 0;
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
   	return x0;	
}
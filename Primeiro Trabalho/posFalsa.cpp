#include <iostream>
#include <cmath> // ou <math.h>
using namespace std;

#define log10(x) log(x)/log(10);

float f(float d) {
   return 1*d-d*log(d); // Função cuja raiz deve ser determinada
}


int main() {
   
   // eps: erro
   // a0 e b0: pontos iniciais
   // tam: tamanho do intervlao
   // np: novo ponto
   // i: número de iterações
   
   float eps, a0, b0, tam, np; 
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
   return 0;
}
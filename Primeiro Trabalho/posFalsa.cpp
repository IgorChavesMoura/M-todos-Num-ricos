#include <iostream>
#include <cmath> // ou <math.h>
using namespace std;

#define log10(x) log(x)/log(10);



float funcao(float d){
   
   return 0.85*d-d*log(d);
}
main(){
    double a, b, c, e, f_a, f_b, f_c, erro, aux, i=0;
    cout<<"                         METODO DA POSICAO FALSA"<<endl;
    cout<<"\nDigite o valor de 'a':"<<endl;
    cin>>a;
    cout<<"\nDigite o valor de 'b':"<<endl;
    cin>>b;
    cout<<"\nInforme a precisao desejada:"<<endl;
    cin>>e;
    if(a>b){ ///condição para que o valor de b seja sempre o maior valor
        aux=a;
        a=b;
        b=aux;
    }
    if(a==b){ /// condição para que se o usuário inserir o mesmo valor, possa reinserir outro
        cout<<"\nOs valores devem ser diferentes. Digite um novo valor para 'b':"<<endl;
        cin>>b;
        }
    else{


        f_a=funcao(a);
        f_b=funcao(b);

        if(f_a*f_b<0){ ///Teorema de Bolzano. Se a condição for satisfeita, existe uma raiz no intervalo
                c=(a*f_b-b*f_a)/(f_b - f_a); ///Metodo da Posição Falsa
                f_c=funcao(c);
                     erro=abs(b-a);
                     i++;
                     while(e<=abs(f_c) and e<=erro){
         ///condição do loop: irá executar o procedimento abaixo enquanto o erro for maior que a precisão
                            i++;
                             if(f_a*f_c<0){
                                 b=c;
                                     }
                             if(f_b*f_c<0){
                                 a=c;
                           }
                           erro=abs(b-a);
                           f_a=funcao(a);
                           f_b=funcao(b);
                           c=(a*f_b-b*f_a)/(f_b - f_a);
                           f_c=funcao(c);


                     }
                        cout<<"\nA raiz eh: "<<c<<endl;
                        cout<<"\nO erro eh: "<<erro<<endl;
                        cout<<"\nO numero de iteracoes eh: "<<i<<endl;

                }

         else cout<<"\nEsse intervalo nao possui raizes"<<endl;
        }


    }

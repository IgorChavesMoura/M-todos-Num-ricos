#include "Foguete.h"
#include <iostream>
using namespace std;
int main(int argc,char **argv){
	int n,decisao,decisao2;
	float a[n], eps, intervalo[n][2];
	cout<<"Digite o número de foguetes: "<<endl;
	cin>>n;
	Foguete foguete[n];
	for(int i=0; i<n; i++){
		cout<<"Voce deseja colocar o valor de a no foguete " << i+1 << "(Digite 0) ou usar o padrão(a = 1, Digite 1): "<<endl;
		cin>>decisao;
		cout<<"Voce deseja colocar os valores do intervalo?(0 para Sim, 1 para usar o padrão(2,3)): "<<endl;
		cin>>decisao2;
		if(decisao==0 && decisao2==0){
			cout<<"Digite o a do foguete "<<i+1<<": "<<endl;
	    	cin>>a[i];
	    	cout<<"Digite o primeiro termo do intervalo: "<<i+1<<": "<<endl;
	    	cin>>intervalo[i][0];
	    	cout<<"Digite o segundo termo do intervalo: "<<i+1<<": "<<endl;
	    	cin>>intervalo[i][1];
	    	foguete[i] = Foguete(a[i], intervalo[i][0], intervalo[i][1]);
	    }
	    else if(decisao2==0){
	    	cout<<"Digite o primeiro termo do intervalo: "<<i+1<<": "<<endl;
	    	cin>>intervalo[i][0];
	    	cout<<"Digite o segundo termo do intervalo: "<<i+1<<": "<<endl;
	    	cin>>intervalo[i][1];
	    	a[i]=1;
	    	foguete[i] = Foguete(intervalo[i][0], intervalo[i][1]);
	    }
	    else if(decisao==0){
	    	cout<<"Digite o a do foguete "<<i+1<<": "<<endl;
	    	cin>>a[i];
	    	intervalo[i][0]=2;
	    	intervalo[i][1]=3;
	    	foguete[i] = Foguete(a[i]);	
	    }
	    else{
	    	a[i]=1;
	    	intervalo[i][0]=2;
	    	intervalo[i][1]=3;
	    	foguete[i] = Foguete();
	    }
	}
	cout<<"Digite a precisão requerida: "<<endl;
	cin>>eps;
    cout<<"FOGUETE     A     INICIO INTERVALO     FIM INTERVALO     D(BISSECÇÃO)     D(POSIÇÃO FALSA)     D(NEWTON-RAPSHON)     "<<endl;
    for(int i=0; i<n; i++){
    	cout <<"   "<<i+1 <<"       "<<a[i]<<"          "<<intervalo[i][0]<<"                        "<<intervalo[i][1]<<"          "<<foguete[i].bisseccao(eps)<<"          "<<foguete[i].posFalsa(eps)<<"             "<<foguete[i].newtonRapshon(eps)<<endl;
    }
    
	return 0;
}
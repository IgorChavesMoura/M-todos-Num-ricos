#include "Foguete.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main(int argc,char **argv){
	int n,decisao,decisao2;
	float a[5], eps, intervalo[5][2];
	for(int i=0; i<5; i++){
		a[i]=0;
	}
	printf("Digite o número de foguetes: ");
	scanf("%d",&n);
	Foguete foguete[5];
	cout<<"Digite a precisão requerida: "<<endl;
	cin>>eps;
	for(int i=0; i<n; i++){
		printf("Voce deseja colocar o valor de a no foguete %d (Digite 0) ou usar o padrão(a = 1, Digite 1): ",i+1);
		scanf("%d",&decisao);
		printf("Voce deseja colocar os valores do intervalo?(0 para Sim, 1 para usar o padrão(2,3)): ");
		scanf("%d",&decisao2);
		if(decisao==0 && decisao2==0){
			printf("Digite o a do foguete %d: ",i+1);
	    	scanf("%f",&a[i]);
	    	printf("Digite o primeiro termo do intervalo do foguete %d: ",i+1);
	    	scanf("%f",&intervalo[i][0]);
	    	printf("Digite o segundo termo do intervalo do foguete %d: ",i+1);
	    	scanf("%f",&intervalo[i][1]);
	    	foguete[i] = Foguete(a[i], intervalo[i][0], intervalo[i][1]);
	    }
	    else if(decisao2==0 && decisao==1){
	    	printf("Digite o primeiro termo do intervalo do foguete %d: ",i+1);
	    	scanf("%f",&intervalo[i][0]);
	    	printf("Digite o segundo termo do intervalo do foguete %d: ",i+1);
	    	scanf("%f",&intervalo[i][1]);
	    	a[i]=1;
	    	foguete[i] = Foguete(intervalo[i][0], intervalo[i][1]);
	    
	    }
	    else if(decisao==0 && decisao2==1){
	    	printf("Digite o a do foguete %d: ",i+1);
	    	scanf("%f",&a[i]);
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
	    if(i==n-1){
	    	cout<<"FOGUETE     A     INICIO INTERVALO     FIM INTERVALO     D(BISSECÇÃO)     D(POSIÇÃO FALSA)     D(NEWTON-RAPSHON)     "<<endl;
	    	for(int j=0;j<=i; j++){
	    		cout <<"   "<<j+1 <<"       "<<a[j]<<"          "<<intervalo[j][0]<<"                        "<<intervalo[j][1]<<"          "<<foguete[j].bisseccao(eps)<<"          "<<foguete[j].posFalsa(eps)<<"             "<<foguete[j].newtonRapshon(eps)<<endl;
	    	}
	    }
	   
	}	
	
    
    
	return 0;
}
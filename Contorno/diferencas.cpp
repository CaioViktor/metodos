#include "diferencas.h"
Vetor resolverSistema(Matriz mo,Vetor bo){
	Matriz m;
	m = mo;
	Vetor b;
	b = bo;
	for(int p = 0 ; p < m.getColunas(); p++){
		double pivo = m.getValor(p,p);
		for (int l = 0; l < m.getLinhas() ; l++){
			if(l != p){
				double fator = (m.getValor(l,p)/pivo) * -1;
				for(int c = 0 ; c < m.getColunas() ; c++){
					m.setValor(l,c, m.getValor(l,c) + fator * m.getValor(p,c));
				}
				b.setValor(l,b.getValor(l) + fator * b.getValor(p));
			}
		}
	}
	for(int l = 0 ; l < m.getLinhas() ; l++){
		double pivo = m.getValor(l,l);
		for(int c = 0 ; c < m.getColunas() ; c++ ){
			m.setValor(l,c,m.getValor(l,c)/pivo);
		}
		b.setValor(l,b.getValor(l)/pivo);
	}
	return b;
}
int main(){
	int n;
	cout << "Intervalo de : " << INICIO_INTERVALO << " , " << FIM_INTERVALO << endl;
	cout << "Entre com a quantidade de valores:\n";
	cin >> n;
	Vetor valores;

	valores = diferencasFinitas(n);
	valores.show();
	
	return 0;
}

Vetor diferencasFinitas(int n){
	Matriz contribuicoes(n,n);
	Vetor b(n);
	Vetor y(n);
	double dx;
	dx = (FIM_INTERVALO - INICIO_INTERVALO) / (float)n;
	cout << "dx :" << dx << endl;
	//Povoa contribuicoes e b
	for(int i = 0 ; i < n ; i++){
		contribuicoes = celulaMatriz(contribuicoes,i,dx);
		b = celulaVetor(b,i,dx);
	}

	cout << "contribuicoes:\n";
	contribuicoes.show();
	cout << "b:\n";
	b.show();
	cout << endl;

	y = resolverSistema(contribuicoes,b);

	return y;
}



Matriz celulaMatriz(Matriz m,int i,double dx){
	Matriz resultante;
	resultante = m;

	resultante.setValor(i,i,resultante.getValor(i,i) + 4/(dx*dx) + 1);
	resultante.setValor(i,i - 1,resultante.getValor(i,i - 1) - 2/(dx*dx));
	resultante.setValor(i,i + 1,resultante.getValor(i,i + 1) - 2/(dx*dx));

	if(i == m.getLinhas() - 1){ // é a ultima variável
		resultante.setValor(i,i,resultante.getValor(i,i) + (- 2/(dx*dx)) * (- 2 * dx));
		resultante.setValor(i,i - 1,resultante.getValor(i,i - 1) - 2/(dx *dx));
	}

	return resultante;
}

Vetor celulaVetor(Vetor m,int i,double dx){
	Vetor resultante;
	resultante = m;
	
	resultante.setValor(i,resultante.getValor(i) + exp(-0.2 * (i +1) ) );

	if(i == 0){
		resultante.setValor(i,resultante.getValor(i) + 2/(dx*dx) );		
	}

	return resultante;
}

#include "main.h"
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
	
	Matriz m (3,3);
	m.setValor(0,0,4);
	m.setValor(0,1,2);
	m.setValor(0,2,1);
	m.setValor(1,0,2);
	m.setValor(1,1,8);
	m.setValor(1,2,2);
	m.setValor(2,0,1);
	m.setValor(2,1,2);
	m.setValor(2,2,6);
	Vetor v(3);
	v.identidade();
	
	Resultado r = potencia(m, v, 0.0001);
	m.show();
	cout << "* autoVetor:\n";
	r.autoVetor.show();
	cout << "=\n";
	(m*r.autoVetor).show();
	cout << "------------------------\n autoValor: \n";
	cout << r.autoValor << endl;
	cout << "*\n";
	r.autoVetor.show();
	cout << "=\n";
	(r.autoVetor * r.autoValor).show();
	


	cout << "\n\n\n potencia Inversa:\n";
	Resultado r2 = potenciaInversa(m, v, 0.0001);
	m.show();
	cout << "* autoVetor:\n";
	r2.autoVetor.show();
	cout << "=\n";
	(m*r2.autoVetor).show();
	cout << "------------------------\n autoValor: \n";
	cout << r2.autoValor << endl;
	cout << "*\n";
	r2.autoVetor.show();
	cout << "=\n";
	(r2.autoVetor * r2.autoValor).show();

	cout << "\n\n\n potencia Deslocamento:\n";
	Resultado r3 = potenciaDeslocamento(m, v, 0.0001,2);
	m.show();
	cout << "* autoVetor:\n";
	r3.autoVetor.show();
	cout << "=\n";
	(m*r3.autoVetor).show();
	cout << "------------------------\n autoValor: \n";
	cout << r3.autoValor << endl;
	cout << "*\n";
	r3.autoVetor.show();
	cout << "=\n";
	(r3.autoVetor * r3.autoValor).show();

	cout << "---------------------------------\nHouseHolder\nMatriz:\n";
	cout << "Tridiagonal:\n";
	ResultadoHouseHolder house = HouseHolder(m);
	house.HAH.show();
	cout << "H:\n";
	house.H.show();

	cout << "---------------------------------\nJacobi:\n";
	ResultadoJacobi jacobi = Jacobi(m,0.0001);
	cout << "Jc:\n";
	jacobi.Jc.show();
	cout << "Ak:\n";
	jacobi.Ak.show();
	JacobiResultados* resultados =  jacobi.resultados;
	for(int i = 0 ; i < jacobi.Jc.getLinhas(); i++){
		cout << "AutoValor: " << resultados[i].autoValor << endl;
		cout << "AutoVetor:\n" ;
		jacobi.resultados[i].autoVetor.show();
		cout << endl;
	}

	cout << "---------------------------------\nQR:\n";
	QR(m,0.0001);

	return 0;
}
#include "main.h"
Vetor resolverSistema(Matriz mo,Vetor bo){
	Matriz m;
	m = mo;
	Vetor b;
	b = bo;
	if(m.getLinhas() != b.getLinhas())
		return Vetor();
	for(int c = 0 ; c < m.getColunas() ; c++){
		double pivo = m.getValor(c,c);
		for(int l = 0 ; l < m.getLinhas() ; l++){
			if( c == l ){
				for(int k = 0 ; k < m.getColunas() ; k++){
					m.setValor(l,k,m.getValor(l,k)/pivo);
				}
				b.setValor(c, b.getValor(c)/pivo );
			}else{
				double coeficiente = -1 * (m.getValor(l,c) / pivo);
				// cout << coeficiente << endl;
				double vaiZerar = m.getValor(l,c);
				for(int k = 0 ; k < m.getColunas() ; k++){
					m.setValor(l,k,m.getValor(l,k) + coeficiente * vaiZerar );
				}
				b.setValor(c, b.getValor(c) + coeficiente * b.getValor(c));
			}
		}
	}
	// cout <<v<< "m: \n";
	// m.show();
	return b;
}
int main(){
	Matriz m(4,4);
	m.setValor(0,0,3);
	m.setValor(0,1,1);
	m.setValor(1,1,3);
	m.setValor(2,2,4);
	m.setValor(3,3,3);
	Vetor v(4);
	v.identidade();
	Resultado r = potencia(m, v, 0.001);
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
	Resultado r2 = potenciaInversa(m, v, 0.001);
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
	Resultado r3 = potenciaDeslocamento(m, v, 0.001,2);
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
	return 0;
}
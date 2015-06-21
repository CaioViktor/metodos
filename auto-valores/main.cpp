#include "main.h"
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
	cout << "*\n";
	r.autoVetor.show();
	cout << "=\n";
	(m*r.autoVetor).show();
	cout << "------------------------\n";
	cout << r.autoValor << endl;
	cout << "*\n";
	r.autoVetor.show();
	cout << "=\n";
	(r.autoVetor * r.autoValor).show();
	return 0;
}
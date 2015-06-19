#include "main.h"
int main(){
	Matriz m(2,2);
	Matriz m2(2,2);
	m.identidade();
	m.setValor(0,1,3);
	m.setValor(1,0,3);
	for(int i = 0 ; i < 2 ; i++)
		for(int j = 0 ; j < 2 ; j++)
			m2.setValor(i,j,i+j);
	m.show();
	cout << endl;
	m2.show();
	cout << endl;
	Matriz m3 = (m*m2);
	m3.show();
	(m3 * 2).show();
	return 0;
}
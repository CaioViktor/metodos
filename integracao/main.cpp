#include "main.h"
int main(){
	setprecision(20);
	cout << "Integral de x² de 0 ate 1: \n"<<gauss(20,0,1)<<endl;
	cout << "Integral de x² de 0 ate 1 com erro de 0.000000001:\n" <<gaussError(2,0.000000001,0,1)<<endl;
	return 0;
}
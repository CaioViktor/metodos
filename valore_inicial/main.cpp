#include "main.h"
int main(){
	cout << "Forward-Euler:\n" << forwardEuler(0.2,0.1,f,0) << endl;
	for(int i = 2; i <= 4 ; i++)
		cout <<"Runge-Kutta de " << i << " ordem:\n" << rungeKutta(0.2,0.1,f2,0, i) << endl;
	cout <<"Preditor Corretor de " << 3 << " ordem:\n" << preditorCorretor(0.3,0.1,f3,0,3) << endl;
	cout <<"Preditor Corretor de " << 4 << " ordem:\n" << preditorCorretor(0.4,0.1,f3,0,4) << endl;
	return 0;
}
double f(double y,double t){
	return -20*y+7*exp(0.5*t);
}
double f2(double y, double t){
	return (10 - 20 * y)/50;
}
double f3(double y, double t){
	return t * y + 1;
}
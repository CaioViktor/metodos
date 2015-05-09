#include "main.h"
int main(){
	cout << forwardEuler(0.02,0.01,f,5) << endl;
	return 0;
}
double f(double y,double t){
	return -20*y+7*exp(0.5*t);
}
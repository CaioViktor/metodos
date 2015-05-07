#include "main.h"
double f(double x){
	return pow(x,2);
}
int main(){
	// cout << forward(f,2) << endl;
	
	return 0;
}
// double forward(double (*f)(double) ,double x){
// 	return (*f)(x);
// }
double forward(double (*f)(double) , double x , int ordemDerivacao, int precisao){
	
}
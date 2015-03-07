#include "main.h"
double gauss(int n,double a,double b){
	double sum = 0;
	double delta = deltaX(n,a,b);
	for(int i = 0;i<n;i++){
		double x = a + (2*i + 1 ) * delta / 2;
		sum += f(x);
	}
	return sum * delta;
}
double gaussError(int inc,double error,double a,double b){
	double sum = 0,d,ik,ij;
	int j;
	j = 1;
	do{
		int n = j + inc;
		double delta = deltaX(n,a,b);
		for(int i = 0;i < n;i++){
			double x = a + (2*i + 1 ) * delta / 2;
			sum += f(x);
		}
		ik = delta*sum;
		d = ik-ij;
		
		sum = 0;
		j ++;
		ij = ik;
	}while(d > error);
	return ik;
}
double deltaX(int n,double a,double b){
	return (b - a)/n;
}
double f(double x){
	return x*x;
}

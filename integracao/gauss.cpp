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
		d = fabs((ik-ij)/ik);
		
		sum = 0;
		j ++;
		ij = ik;
	}while(d > error && j <= 100);
	return ik;
}

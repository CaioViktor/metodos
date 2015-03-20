#include "main.h"
double newton(int n,double a,double b,int grau,bool fechado){
	double delta = deltaX(n,a,b);
	double ai = a,bi = a+delta;
	double integral = 0;
	do{
		integral+=integralG(ai,bi,grau,fechado);
		ai = bi;
		bi += delta;
	}while(bi<=b);
	return integral;
}
double newtonError(int inc,double a,double b,double error,int grau,bool fechado){
	double ij = 0,ik,dif;
	int j = 1,n;
	do{
		n = j + inc;
		ik = newton(n,a,b,grau,fechado);
		dif = fabs(ik - ij);
		ij = ik;
		j++;
	}while(dif > error && j <= 100);

	return ik;
}
double integralG(double a,double b,int grau,bool fechado){
	double delta = deltaG(a,b,grau,fechado);
	double somaF = 0;
	switch(grau){
		case 1:
			if(fechado){
				somaF = (f(a) + f(b))/2;
			}
			else{
				somaF = (3 * (f(a+delta)+f(a+2*delta)))/2;
			}
		break;

		case 2:
			if(fechado){
				somaF =  (f(a) + 4*f( a+delta) + f(b))/3;	
			}
			else{
				somaF = (4 * (2*f(a+delta)-( f(a+2*delta) )+2*f(a+3*delta)))/3;
			}
		break;

		case 3:
			if(fechado){
				somaF = (3 *(f(a) + 3*f(a+delta) + 3*f(a+2*delta) + f(b)))/8;
			}
			else{
				somaF = (5 * (11*f(a+delta) +( f(a+2*delta) )+ ( f(a + 3*delta) ) +11*f(a + 4*delta)))/24;	
			}
		break;
	}
	return delta*somaF;
}
double deltaG(double a,double b,double grau, bool fechado){
	if(fechado)
		return (b-a)/grau;
	else
		return (b-a)/(grau+2);
}
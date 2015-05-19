#include "main.h"
double rungeKutta(double t,double deltaT,double (*f)(double ,double),double y0, int ordem){
	double (*r)(double, double,double(*fn)(double,double),double deltaT);
	switch(ordem){
		case 2:
			r = runge2;
		break;
		case 3:
			r = runge3;
		break;
		case 4:
			r = runge4;
		break;
	}
	double yn = y0;
	for(double tn = deltaT; tn <= t ; tn += deltaT){
		yn = yn + (*r)(yn,tn,f,deltaT);
	} 
	return yn;
}
double runge2(double yn,double tn,double (*f)(double,double),double deltaT){
	double k1 = deltaT * (*f)(yn,tn);
	double k2 = deltaT * (*f)(yn+k1,tn+deltaT);
	return (k1 + k2)/2;
}
double runge3(double yn,double tn,double (*f)(double,double),double deltaT){
	double k1 = deltaT * (*f)(yn,tn);
	double k2 = deltaT * (*f)(yn + k1/2,tn + deltaT/2);
	double k3 = deltaT * (*f)(yn - k1 + 2 * k2,tn + deltaT);
	return (k1 + 4 * k2 + k3)/6;
}
double runge4(double yn,double tn,double (*f)(double,double),double deltaT){
	double k1 = deltaT * (*f)(yn,tn);
	double k2 = deltaT * (*f)(yn + k1/3,tn + deltaT/3);
	double k3 = deltaT * (*f)(yn + k2/2,tn + 2 * deltaT/3);
	double k4 = deltaT * (*f)(yn + k1 - k2 + k3,tn + deltaT);
	return (k1 + 3 * k2 + 3 * k3 + k4)/8;
}
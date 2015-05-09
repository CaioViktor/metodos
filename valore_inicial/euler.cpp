#include "main.h"
double forwardEuler(double t,double deltaT,double (*f)(double ,double),double y0){
	int iteracoes = floor(t/deltaT);
	double* y = new double[iteracoes + 1]();
	y[0] = y0;
	int index = 1;
	double tempoAtual = 0 + deltaT;
	while(index <= iteracoes){
		y[index] = y[index-1] + deltaT*(f)(y[index-1],tempoAtual);
		tempoAtual+=deltaT;
		index++;
	}
	return y[iteracoes];
}
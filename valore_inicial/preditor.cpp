#include "main.h"
double preditorCorretor(double t,double deltaT,double (*f)(double ,double),double y0,int ordem = 3){
	if(ordem < 3 || ordem > 4)
		return 0;
	int iteracoes, iteracao = 0;
	if(t == 0)
		iteracoes = 0;
	else
		iteracoes = ceil(t/deltaT);
	double y[iteracoes + 1];
	y[0] = y0;
	double dy[iteracoes + 1];
	dy[0] = (*f)(y0,0);
	double tk = 0;

	for(int i = 1; i < ordem ; i++){
		iteracao ++;
		tk += deltaT;
		y[i] = forwardEuler(tk,deltaT,f,y0);
		dy[i] = (*f)(y[i],tk);
	}
	while( iteracao < iteracoes){
		double ykb;
		double dykb;
		tk += deltaT;	
		iteracao ++;
		// cout << "iteracao: " << iteracao << " tempo: " << tk;
		if(ordem == 3){
			ykb = y[iteracao - 1] + deltaT * (23 * dy[iteracao - 1] - 16 * dy[iteracao - 2] + 5 * dy[iteracao - 3]) / 12;
			dykb = (*f)(ykb,tk);
			y[iteracao] = y[iteracao - 1] + deltaT * (5 * dykb + 8 * dy[iteracao - 1] - dy[iteracao - 2]) / 12;
		}
		if(ordem == 4){
			ykb = y[iteracao - 1] + deltaT * (55 * dy[iteracao - 1] - 59 * dy[iteracao - 2] + 37 * dy[iteracao - 3] - 9 * dy[iteracao - 4]) / 24;
			dykb = (*f)(ykb,tk);
			y[iteracao] = y[iteracao - 1] + deltaT * (9 * dykb + 19 * dy[iteracao - 1] - 5 * dy[iteracao - 2] + dy[iteracao - 3]) / 24;
		}
		dy[iteracao] = (*f)(y[iteracao],tk);
		// cout << "y: " << y[iteracao] << "\ty': " << dy[iteracao] << endl; 
	}
	return y[iteracoes];
}
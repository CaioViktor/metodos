#include "main.h"
double xE(double a, double b,double e){
	return (((a+b)/2)+((b-a)/2)) * tanh(e);
}
double dxE(double a, double b,double e){
	double first,second;
	first = pow(exp(e)+exp(-e),2);
	second = pow(exp(e)-exp(-e),2);
	return ((b-a)/2) * ((first - second)/first);
}

double xED(double a, double b,double e){
	return ((a+b)/2 + (b-a)/2) * tanh(( M_PI * sinh(e))/2);
}
double dxED(double a, double b,double e){
	return (((b-a)/4) * cosh(e))/pow(cosh((M_PI*sinh(e))/2),2);
}
double iE(int incrementoCorte,double erro,int grau){
	int ponto = 1,n,k=1;
	double currentError,dif;
	double Ij=0,Ik,ITk,ITj = 0;
	do{//corte
		do{//calcular integral
			n = k + 2;
			double delta = deltaX(n,-ponto,ponto);
			Ik = 0;
			double ak = -ponto, bk= ak + delta,soma = 0;
			while(bk <= ponto){
				switch(grau){
					case 1:
						soma = (gxE(-ponto,ponto,ak) + gxE(-ponto,ponto,bk))/2;
					break;
					case 2:
						soma = (gxEE(-ponto,ponto,ak) + gxEE(-ponto,ponto,bk))/2;
					break;
				}
				soma *= delta;
				ak = bk;
				bk += delta;
				Ik += soma;
			}
			dif = fabs(Ik - Ij);
			Ij = Ik;
			k++;
		}while(dif > erro);//calcular integral
		ITk = Ik;
		currentError =fabs(ITk - ITj);
		ITj = ITk;
		ponto *= incrementoCorte;
	}while(ponto < 1000000 && currentError > erro); // corte
}
double gxE(double a, double b,double e){
	return f(xE(a,b,e))*dxE(a,b,e);
}
double gxEE(double a, double b,double e){
	return f(xED(a,b,e)) * dxED(a,b,e);
}
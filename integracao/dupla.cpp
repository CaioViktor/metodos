#include "main.h"
double fX(double x){
	return x;
}
double fZ(double z){
	return z;
}
double doubleIntegration(int j,double error,double a, double b){
	int n = 1,v = 1;
	double dif,ij = 0,ik;
	do{
		n += j;
		double delta  = deltaX(n,a,b);
		double ak = a, bk = a + delta;
		ik = 0;
		while(bk <= b){
			ik += gaussLegendreX(4,ak,bk);
			ak = bk;
			bk += delta;
		}
		ik *= integralZ(j,error,fZ(a),fZ(b));
		dif = fabs(ik - ij);
		ij = ik;
		// cout << "loop " << ik << endl;
		v++;
	}while(dif > error && v <= 100);
	return ik;
}
double gEX(double a, double b, double e){
	double x = ((a+b)/2) + (e*( (b-a)/2 ));
	return fX(x);
}
double gaussLegendreX(int n,double a,double b){
	double e[n],w[n],i = 0;
	switch(n){
		case 1:
			e[0] = 0;
			w[0] = 2;
		break;

		case 2:
			e[0] = 0.577350269;
			w[0] = 1;

			e[1] = -0.577350269;
			w[1] = 1;
		break;

		case 3:
			e[0] = 0;
			w[0] = 0.888888889;

			e[1] = 0.774596669;
			w[1] = 0.555555556;

			e[2] = -0.774596669;
			w[2] = 0.555555556;
		break;

		case 4:
			e[0] = 0.339981043;
			w[0] = 0.652145155;

			e[1] = -0.339981043;
			w[1] = 0.652145155;

			e[2] = 0.861136312;
			w[2] = 0.347854845;

			e[3] = -0.861136312;
			w[3] = 0.347854845;
		break;
	}
	for(int c = 0 ; c < n; c++)
		i+= gEX(a,b,e[c]) * w[c];
	return i * (b-a)/2 ;
}





double integralZ(int j,double error,double a, double b){
	int n = 1,v = 1;
	double dif,ij = 0,ik;
	do{
		n += j;
		double delta  = deltaX(n,a,b);
		double ak = a, bk = a + delta;
		ik = 0;
		while(bk <= b){
			ik += gaussLegendreZ(4,ak,bk);
			ak = bk;
			bk += delta;
		}
		dif = fabs(ik - ij);
		ij = ik;
		// cout << "loop " << ik << endl;
		v++;
	}while(dif > error && v <= 100);
	return ik;
}
double gaussLegendreZ(int n,double a,double b){
	double e[n],w[n],i = 0;
	switch(n){
		case 1:
			e[0] = 0;
			w[0] = 2;
		break;

		case 2:
			e[0] = 0.577350269;
			w[0] = 1;

			e[1] = -0.577350269;
			w[1] = 1;
		break;

		case 3:
			e[0] = 0;
			w[0] = 0.888888889;

			e[1] = 0.774596669;
			w[1] = 0.555555556;

			e[2] = -0.774596669;
			w[2] = 0.555555556;
		break;

		case 4:
			e[0] = 0.339981043;
			w[0] = 0.652145155;

			e[1] = -0.339981043;
			w[1] = 0.652145155;

			e[2] = 0.861136312;
			w[2] = 0.347854845;

			e[3] = -0.861136312;
			w[3] = 0.347854845;
		break;
	}
	for(int c = 0 ; c < n; c++)
		i+= gEZ(a,b,e[c]) * w[c];
	return i * (b-a)/2 ;
}
double gEZ(double a, double b, double e){
	double x = ((a+b)/2) + (e*( (b-a)/2 ));
	return fZ(x);
}
#include "main.h"
double gaussLegendre(int n,double a,double b){
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
		i+= gE(a,b,e[c]) * w[c];
	return i * (b-a)/2 ;
}


double gaussHermite(int n){
	double e[n],w[n],i = 0;
	switch(n){
		case 2:
			e[0] = 0.707;
			w[0] = 0.88622;

			e[1] = -0.707;
			w[1] = 0.88622;
		break;

		case 3:
			e[0] = 0;
			w[0] = 1.18163590;

			e[1] = 1.22474487;
			w[1] = 0.29540897;

			e[2] = -1.22474487;
			w[2] = 0.29540897;
		break;

		case 4:
			e[0] = 0.52464762;
			w[0] = 0.80491409;

			e[1] = -0.52464762;
			w[1] = 0.80491409;

			e[2] = 1.65068012;
			w[2] = 0.08131283;

			e[3] = -1.65068012;
			w[3] = 0.08131283;
		break;
	}
	for(int c = 0 ; c < n; c++)
		i+= f(e[c]) * w[c];
	return i;
}

double gaussLaguerre(int n){
	double e[n],w[n],i = 0;
	switch(n){
		case 2:
			e[0] = 0.58578643;
			w[0] = 0.85355339;

			e[1] = 3.41421356;
			w[1] = 0.14644660;
		break;

		case 3:
			e[0] = 0.41577455;
			w[0] = 0.71109300;

			e[1] = 2.24428036;
			w[1] = 0.27851973;

			e[2] = 6.28994508;
			w[2] = 0.01038926;
		break;

		case 4:
			e[0] = 0.32254768;
			w[0] = 0.60315410;

			e[1] = 1.74576110;
			w[1] = 0.35741869;

			e[2] = 4.53662029;
			w[2] = 0.03888791;

			e[3] = 9.39507091;
			w[3] = 0.00053929;
		break;
	}
	for(int c = 0 ; c < n; c++)
		i+= f(e[c]) * w[c];
	return i;
}

double gaussChebyshev(int n){
	double i = 0;
	for(int k = 0 ; k < n; k++)
		i+= f(cos(((k -1/2)/n)*M_PI )); 
	return (M_PI/n)*i;
}


double gaussLegendreError(int j,double error,double a, double b){
	int n = 1,v = 1;
	double dif,ij = 0,ik;
	do{
		n += j;
		double delta  = deltaX(n,a,b);
		double ak = a, bk = a + delta;
		ik = 0;
		while(bk <= b){
			ik += gaussLegendre(4,ak,bk);
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
double gE(double a, double b, double e){
	double x = ((a+b)/2) + (e*( (b-a)/2 ));
	return f(x);
}
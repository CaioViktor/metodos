#include "main.h"
// double gauss(int n,double a,double b){
// 	double sum = 0;
// 	double delta = deltaX(n,a,b);
// 	for(int i = 0;i<n;i++){
// 		double x = a + (2*i + 1 ) * delta / 2;
// 		sum += f(x);
// 	}
// 	return sum * delta;
// }
// double gaussError(int inc,double error,double a,double b){
// 	double sum = 0,d,ik,ij;
// 	int j;
// 	j = 1;
// 	do{
// 		int n = j + inc;
// 		double delta = deltaX(n,a,b);
// 		for(int i = 0;i < n;i++){
// 			double x = a + (2*i + 1 ) * delta / 2;
// 			sum += f(x);
// 		}
// 		ik = delta*sum;
// 		d = fabs((ik-ij)/ik);
		
// 		sum = 0;
// 		j ++;
// 		ij = ik;
// 	}while(d > error && j <= 100);
// 	return ik;
// }

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
		cout << "loop " << ik << endl;
		v++;
	}while(dif > error && v <= 100);
	return ik;
}
double gE(double a, double b, double e){
	double x = ((a+b)/2) + (e*( (b-a)/2 ));
	return f(x);
}
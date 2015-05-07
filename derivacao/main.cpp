#include "main.h"
double f(double x){
	return pow(x,2);
}
int main(){
	double x,dx,r;
	int ordem,precisao,tipo;
	cout << "Entre com o valor de X: \n";
	cin >> x;
	cout << "Entre com o valor de dX: \n";
	cin >> dx;
	cout << "Entre com a ordem da derivada:\n(1)f\'(x)\n(2)f\'\'(x)\n";
	cin >> ordem;
	cout << "Entre com a filosofia da derivada:\n(1)forward\n(2)backward\n(3)central\n";
	cin >> tipo;
	cout << "Entre com a precisão:\n";
	cin >> precisao;
	switch(tipo){
		case 1:
			r = forward(f,x,ordem,precisao,dx);
		break;
		case 2:
			r = backward(f,x,ordem,precisao,dx);
		break;
		case 3:
			r = central(f,x,ordem,precisao,dx);
		break;
		default:
			cout << "Opção inválida!\n";
			return 0;
		break;
	}
	cout << "Resultado: " << r << endl;
	return 0;
}
// double forward(double (*f)(double) ,double x){
// 	return (*f)(x);
// }
double forward(double (*f)(double) , double x , int ordemDerivacao, int precisao,double dx){
	switch(ordemDerivacao){
		case 1:
			switch(precisao){
				case 1:
					return ((*f)(x+dx) - (*f)(x))/dx;
				break;
				case 2:
					return (-(*f)(x+2*dx) +4*(*f)(x+dx) -3 * (*f)(x))/(dx*2);
				break;
			}
		break;
		case 2:
			switch(precisao){
				case 1:
					return ((*f)(x+2*dx) -2*(*f)(x+dx) + (*f)(x))/(dx*dx);
				break;
				case 2:
					return ( -(*f)(x+4*dx)+16*(*f)(x+3*dx) - 30*(*f)(x+2*dx) + 16*(*f)(x+dx) - (*f)(x) )/(12*dx*dx);
				break;
			}
		break;
	}
}

double backward(double (*f)(double) , double x , int ordemDerivacao, int precisao,double dx){
	switch(ordemDerivacao){
		case 1:
			switch(precisao){
				case 1:
					return ((*f)(x) - (*f)(x-dx))/dx;
				break;
				case 2:
					return ((*f)(x-2*dx) -4*(*f)(x-dx) + 3 * (*f)(x))/(dx*2);
				break;
			}
		break;
		case 2:
			switch(precisao){
				case 1:
					return ((*f)(x-2*dx) -2*(*f)(x-dx) + (*f)(x))/(dx*dx);
				break;
				case 2:
					return ( -(*f)(x-4*dx)+16*(*f)(x-3*dx) - 30*(*f)(x-2*dx) + 16*(*f)(x-dx) - (*f)(x) )/(12*dx*dx);
				break;
			}
		break;
	}
}

double central(double (*f)(double) , double x , int ordemDerivacao, int precisao,double dx){
	switch(ordemDerivacao){
		case 1:
			switch(precisao){
				case 1:
					return ((*f)(x+dx) - (*f)(x-dx))/(2*dx);
				break;
				case 2:
					return (-(*f)(x+2*dx)+8*(*f)(x+dx) -8*(*f)(x-dx) + (*f)(x-2*dx))/(dx*12);
				break;
			}
		break;
		case 2:
			switch(precisao){
				case 1:
					return ((*f)(x+2*dx) -2*(*f)(x) + (*f)(x-2*dx))/(4*dx*dx);
				break;
				case 2:
					return ( -(*f)(x+2*dx)+16*(*f)(x+dx) - 30*(*f)(x) + 16*(*f)(x-dx) - (*f)(x-2*dx) )/(12*dx*dx);
				break;
			}
		break;
	}
}
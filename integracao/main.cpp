#include "main.h"

double f(double x){
	return pow(x,2);
}
double deltaX(int n,double a,double b){
	return (b - a)/n;
}
int main(){
	setprecision(20);
	// cout << "Integral de x² de 0 ate 1: \n"<<gauss(20,0,1)<<endl;
	// cout << "Integral de x² de 0 ate 1 com erro de 0.001:\n" <<gaussError(2,0.001,0,1)<<endl;
	
	// cout << "Integral de x² de 0 ate 1 newton grau 1: \n"<< newton(2,0,1,1,true) << endl;
	// cout << "Integral de x² de 0 ate 1 newton grau 2: \n"<< newton(2,0,1,2,true) << endl;
	// cout << "Integral de x² de 0 ate 1 newton grau 3: \n"<< newton(2,0,1,3,true) << endl;

	// cout << "Integral de x² de 0 ate 1 newton grau 1 aberta: \n"<< newton(2,0,1,1,false) << endl;
	// cout << "Integral de x² de 0 ate 1 newton grau 2 aberta: \n"<< newton(2,0,1,2,false) << endl;
	// cout << "Integral de x² de 0 ate 1 newton grau 3 aberta: \n"<< newton(2,0,1,3,false) << endl;


	// cout << "Integral de x² de 0 ate 1 newton grau 1 com erro 0.001: \n"<< newtonError(2,0,1,0.001,1,true) << endl;
	// cout << "Integral de x² de 0 ate 1 newton grau 2 com erro 0.001: \n"<< newtonError(2,0,1,0.001,2,true) << endl;
	// cout << "Integral de x² de 0 ate 1 newton grau 3 com erro 0.001: \n"<< newtonError(2,0,1,0.001,3,true) << endl;

	// cout << "Integral de x² de 0 ate 1 newton grau 1 aberta com erro 0.001: \n"<< newtonError(2,0,1,0.001,1,false) << endl;
	// cout << "Integral de x² de 0 ate 1 newton grau 2 aberta com erro 0.001: \n"<< newtonError(2,0,1,0.001,2,false) << endl;
	// cout << "Integral de x² de 0 ate 1 newton grau 3 aberta com erro 0.001: \n"<< newtonError(2,0,1,0.001,3,false) << endl;
	


	double a,b,error,value;
	int op,n;
	bool whithError = false,fechado = true;

	cout << "entre com o limite inferior de integração (a):"<<endl;
	cin >> a;
	cout << "entre com o limite superior de integração (b):"<<endl;
	cin >> b;
	cout<< "Voce deseja utilizar:\n(1)quantidade de particoes fixa \n(2)erro \n";
	cin >> op;
	switch(op){
		case 1:
			cout << "entre com o numero de particoes:\n";
			cin >> n;
		break;
		case 2:
			cout << "Entre com o erro\n";
			cin >> error;
			cout << "entre com o incremento de particoes:\n";
			cin >> n;
			whithError = true;
		break;
		default:
			cout << "opcao invalida\n";
			return 0;
		break;
	}
	cout << "Entre o método:\n(1)Gauss\n(2)Newton-Cotes\n";
	cin >> op;
	switch(op){
		case 1:
			if(whithError)
				value = gaussError(n,error,a,b);
			else
				value = gauss(n,a,b);
		break;
		case 2:
			int degree;
			cout << "Escolha o grau do polinomio:\n(1)grau 1. Regra do trapezio\n(2)grau 2. Regra simpson 1/3\n(3)grau 3. Regra simpson 3/8\n";
			cin >> degree;
			cout << "O intervalo sera: \n(1)aberto\n(2)fechado\n";
			cin >> op;
			if(op == 1)
				fechado = false;
			if(whithError)
				value = newtonError(n,a,b,error,degree,fechado);
			else
				value = newton(n,a,b,degree,fechado);
		break;
		default:
			cout << "opcao invalida\n";
			return 0;
		break;	
	}
	cout << "Integral = " << value<<endl;
	return 0;
}
#include "main.h"

double f(double x){
	// return 1 + pow((x/2),2);
	// return pow(x,9);
	// return x;
	// return (1/(1+x*x));//Teste Hermite
	// return cos(x);//Teste Cheb
	return (exp(x)/(sqrt(1-x*x))); //Teste expo
}
double deltaX(int n,double a,double b){
	return (b - a)/n;
}
int main(){
	setprecision(20);
	// cout << "(I : (x²/4) + 1) de 0 ate 1 gauss legandre de 2 pontos: " << gaussLegendre(4,0,1)<<endl;
	// cout << "Integral de (x²/4) + 1) de 0 ate 1 newton grau 1: \n"<< newton(2,0,1,2,true) << endl;
	// cout << "(I : (x²/4) + 1) de 0 ate 1 gauss legandre de 2 pontos com erro 0.001: " << gaussLegendreError(2,0.001,0,1)<<endl;
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
	int op,n,metodo;
	bool whithError = false,fechado = true;
	// cout << doubleIntegration(1,0.001,0,1) << endl;
	cout << "Entre com o método:\n(1)Gauss-Legendre\n(2)Newton-Cotes\n(3)Gauss-Chebyshev\n(4)Gauss-Laguerre\n(5)Gauss-Hermite\n(6)Com singularidade\n(7)Dupla:\n";
	cin >> metodo;
	if(metodo == 6){
		cout << "Entre com o erro\n";
		cin >> error;
		cout << "Deseja usar exponencial:\n(1)Simples\n(2)Dupla\n";
		cin >> op;
		cout << "Resultado " << iE(10,error,op) << endl;
		return 0;
	}
	if( metodo > 2 && metodo != 7){
		cout << "Entre com o valor de N:\n";
		cin >> n;
		switch(metodo){
			case 5:
				value =  gaussHermite( n);
			break;
			case 4:
				value =  gaussLaguerre( n);
			break;
			case 3:
				value =  gaussChebyshev( n);
			break;
			default:
				cout << "Opcao invalida\n";
				return 0;
			break;
		}
		cout << "Integral: " << value << endl;
		return 0;
	}
	
	cout << "entre com o limite inferior de integração (a):"<<endl;
	cin >> a;
	cout << "entre com o limite superior de integração (b):"<<endl;
	cin >> b;
	if(metodo != 7){
		cout << "Deseja entrar com limite erro? \n1)Sim\n2)Nao\n";
		cin >> op;
	}
	if(op == 1 || metodo == 7){
		cout << "Entre com o erro\n";
		cin >> error;
		cout << "entre com o incremento de particoes:\n";
		cin >> n;
		if(metodo == 7){
			cout << "Resultado: " << doubleIntegration(n,error,a,b) << endl;
			return 0;
		}
		whithError = true;
	}
	switch(metodo){
		case 1:

			if(whithError)
				value = gaussLegendreError(4,error,a,b);
			else{
				cout << "Entre com o numero de pontos amostrais\n";
				cin >> n;
				value = gaussLegendre(n,a,b);
			}
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
			else{
				cout << "entre com o numero de particoes:\n";
				cin >> n;	
				value = newton(n,a,b,degree,fechado);
			}
		break;
		default:
			cout << "opcao invalida\n";
			return 0;
		break;	
	}
	cout << "Integral = " << value<<endl;

	return 0;
}
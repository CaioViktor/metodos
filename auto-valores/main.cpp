#include "main.h"
Vetor resolverSistema(Matriz mo,Vetor bo){
	Matriz m;
	m = mo;
	Vetor b;
	b = bo;
	for(int p = 0 ; p < m.getColunas(); p++){
		double pivo = m.getValor(p,p);
		for (int l = 0; l < m.getLinhas() ; l++){
			if(l != p){
				double fator = (m.getValor(l,p)/pivo) * -1;
				for(int c = 0 ; c < m.getColunas() ; c++){
					m.setValor(l,c, m.getValor(l,c) + fator * m.getValor(p,c));
				}
				b.setValor(l,b.getValor(l) + fator * b.getValor(p));
			}
		}
	}
	for(int l = 0 ; l < m.getLinhas() ; l++){
		double pivo = m.getValor(l,l);
		for(int c = 0 ; c < m.getColunas() ; c++ ){
			m.setValor(l,c,m.getValor(l,c)/pivo);
		}
		b.setValor(l,b.getValor(l)/pivo);
	}
	return b;
}
int main(){
	
	Matriz m (3,3);
	m.setValor(0,0,4);
	m.setValor(0,1,2);
	m.setValor(0,2,1);
	m.setValor(1,0,2);
	m.setValor(1,1,8);
	m.setValor(1,2,2);
	m.setValor(2,0,1);
	m.setValor(2,1,2);
	m.setValor(2,2,6);
	Vetor v(3);
	v.identidade();
	double erro = 0.0001;
	int op = 0;
	while(op != 7){
		cout << "Matriz utilizada:\n";
		m.show();
		cout << endl;
		cout << "Chute Inicial:\n";
		v.show();
		cout << endl;
		cout << "Erro:\n" << erro;
		cout << endl;
		cout << "Escolha a opção que deseja ver:\n(1)Potência Regular\n(2)Potência Inversa\n(3)Potência Com Deslocamento\n";
		cout << "(4)HouseHolder\n(5)Jacobi\n(6)QR\n(7)Sair\n";
		cin >> op;
		system("clear");
		if(op == 1){
			Resultado r = potencia(m, v, erro);
			cout << "Potência Regular:\n";
			cout << "Auto-Vetor:\n";
			r.autoVetor.show();
			cout << "Auto-Valor: \n";
			cout << r.autoValor << endl;
			cout << "----------------------------TESTE-------------------------\n";
			m.show();
			cout << "*\n";
			r.autoVetor.show();
			cout << "=\n";
			(m*r.autoVetor).show();
			cout << "--------------------------------------------------------\n";
			cout << r.autoValor << endl;
			cout << "*\n";
			r.autoVetor.show();
			cout << "=\n";
			(r.autoVetor * r.autoValor).show();
		}
		if(op == 2){
			Resultado r2 = potenciaInversa(m, v, erro);
			cout << "Potência Inversa:\n";
			cout << "Auto-Vetor:\n";
			r2.autoVetor.show();
			cout << "Auto-Valor: \n";
			cout << r2.autoValor << endl;
			cout << "----------------------------TESTE-------------------------\n";
			m.show();
			cout << "*\n";
			r2.autoVetor.show();
			cout << "=\n";
			(m*r2.autoVetor).show();
			cout << "--------------------------------------------------------\n";
			cout << r2.autoValor << endl;
			cout << "*\n";
			r2.autoVetor.show();
			cout << "=\n";
			(r2.autoVetor * r2.autoValor).show();
		}
		if(op == 3){
			Resultado r3 = potenciaDeslocamento(m, v, erro,2);
			cout << "Potência Deslocamento:\n";
			cout << "Auto-Vetor:\n";
			r3.autoVetor.show();
			cout << "Auto-Valor: \n";
			cout << r3.autoValor << endl;
			cout << "----------------------------TESTE-------------------------\n";
			m.show();
			cout << "*\n";
			r3.autoVetor.show();
			cout << "=\n";
			(m*r3.autoVetor).show();
			cout << "--------------------------------------------------------\n";
			cout << r3.autoValor << endl;
			cout << "*\n";
			r3.autoVetor.show();
			cout << "=\n";
			(r3.autoVetor * r3.autoValor).show();
		}
		if(op == 4){
			cout << "HouseHolder\n";
			cout << "Tridiagonal:\n";
			ResultadoHouseHolder house = HouseHolder(m);
			house.HAH.show();
			cout << "H:\n";
			house.H.show();
		}
		if(op == 5){
			ResultadoJacobi jacobi = Jacobi(m,erro);
			cout << "Jacobi:\n";
			cout << "Jc:\n";
			jacobi.Jc.show();
			cout << "Ak:\n";
			jacobi.Ak.show();
			AutovaloresResultados* resultados =  jacobi.resultados;
			for(int i = 0 ; i < jacobi.Jc.getLinhas(); i++){
				cout << "--------------------------------------------------------\n";
				cout << "AutoValor:\n" << resultados[i].autoValor << endl;
				cout << "AutoVetor:\n";
				jacobi.resultados[i].autoVetor.show();
				cout << "----------------------------TESTE-------------------------\n";
				m.show();
				cout << "*\n";
				jacobi.resultados[i].autoVetor.show();
				cout << "=\n";
				(m*jacobi.resultados[i].autoVetor).show();
				cout << "--------------------------------------------------------\n";
				cout << resultados[i].autoValor << endl;
				cout << "*\n";
				jacobi.resultados[i].autoVetor.show();
				cout << "=\n";
				(jacobi.resultados[i].autoVetor * resultados[i].autoValor).show();
				cout << endl;
				cout << "------------------------------FIM-------------------------------\n";
			}
		}
		if(op == 6){
			ResultadoQR qr = QR(m,erro);
			cout << "QR:\n";
			cout << "Q\n";
			qr.Q.show();
			cout << "R\n";
			qr.R.show();
			cout << "QT\n";
			qr.QT.show();
			cout << "Ak\n";
			qr.Ak.show();
			AutovaloresResultados* resultadosQR =  qr.resultados;
			for(int i = 0 ; i < qr.Ak.getLinhas(); i++){
				cout << "AutoValor:\n" << resultadosQR[i].autoValor << endl;
				cout << "AutoVetor:\n";
				qr.resultados[i].autoVetor.show();
				cout << "----------------------------TESTE-------------------------\n";
				m.show();
				cout << "*\n";
				qr.resultados[i].autoVetor.show();
				cout << "=\n";
				(m*qr.resultados[i].autoVetor).show();
				cout << "---------------------------------------------------------\n";
				cout << resultadosQR[i].autoValor << endl;
				cout << "*\n";
				qr.resultados[i].autoVetor.show();
				cout << "=\n";
				(qr.resultados[i].autoVetor * resultadosQR[i].autoValor).show();
				cout << endl;
				cout << "------------------------------FIM-------------------------------\n";
			}
		}
		if(op == 7)
			return 0;
		cout << "Deseja continuar continuar?(S/N)...\n";
		char p;
		cin >> p;
		system("clear");
		if(p == 'N' || p == 'n')
			return 0;
	}
	return 0;
}
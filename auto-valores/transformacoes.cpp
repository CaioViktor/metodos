#include "main.h"
int sinal(double v){
	if(v > 0 )
		return -1;
	return 1;
}

Matriz subColuna(Matriz A, int coluna){
	Matriz resultante(A.getLinhas() - (coluna + 1),1);
	for(int i = coluna + 1 ; i < A.getLinhas() ; i++)
		resultante.setValor(i - (coluna + 1),0,A.getValor(i,coluna));
	// cout << "subColuna\n";
	// resultante.show();
	// cout << "\n";
	return resultante;
}


Matriz construirN(Matriz A, int coluna){
	Matriz n(A.getLinhas(),1);
	Matriz p = subColuna(A,coluna);
	Matriz nBarra;
	Vetor vetorP;
	vetorP = p;
	Matriz pLinha(p.getLinhas(),p.getColunas());

	double normaP = vetorP.normaEuclidiana();
	pLinha.setValor(0,0, sinal( p.getValor(0,0) ) * normaP );
	// cout << "p\n";
	// p.show();
	// cout << "p'\n";
	// pLinha.show();
	Matriz pLinhaP = p - pLinha;
	Vetor vetorPLinhaP;
	vetorPLinhaP = pLinhaP;
	// cout << "p'p\n";
	// pLinhaP.show();
	double normaPLinhaP = vetorPLinhaP.normaEuclidiana();
	// cout << normaPLinhaP << endl;
	nBarra = pLinhaP * (1/normaPLinhaP);
	for(int i = coluna + 1 ; i < A.getLinhas() ; i++)
		n.setValor(i,0,nBarra.getValor(i - (coluna + 1) ,0));
	// cout << "N\n";
	// n.show();
	// cout << endl;
	return n;

}

Matriz construirH(Matriz A, int coluna){
	Matriz H(A.getLinhas(),A.getColunas());
	H.identidade();
	Matriz n = construirN(A,coluna);
	// n.show();
	// cout << "nt:\n";
	// n.transaposta().show();
	Matriz nnt2 = ( ( n * n.transposta()) * 2);
	H = H - nnt2;
	// cout << "nn:\n";
	// nnt2.show();
	// cout << "HH\n";
	// H.show();
	// cout << endl;
	return H;
}

ResultadoHouseHolder HouseHolder(Matriz A){
	ResultadoHouseHolder resultante;
	Matriz H(A.getLinhas(),A.getColunas());
	H.identidade();
	Matriz Ai;
	Ai = A;
	for(int i = 0 ; i < A.getColunas() - 2 ; i++ ){
		Matriz Hi;
		Hi = construirH(Ai , i);
		// cout << "H\n";
		// Hi.show();
		// cout << "A\n";
		// Ai.show();
		Ai = (Hi * Ai) ; // Erro nessa multiplicação
		// cout << "aux\n";
		// Ai.show();
		Ai = Ai * Hi;
		// cout << "Ai\n";
		// Ai.show();
		// cout << endl;
		H = H * Hi;
	}
	resultante.H = H;
	resultante.HAH = Ai;
	return resultante;
}
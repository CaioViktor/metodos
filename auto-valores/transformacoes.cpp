#include "main.h"
int sinal(double v){
	if(v < 0 )
		return -1;
	return 1;
}

Matriz subColuna(Matriz A, int coluna){
	Matriz resultante(A.getLinhas() - (coluna + 1),1);
	for(int i = coluna + 1 ; i < A.getLinhas() ; i++)
		resultante.setValor(i - 1,0,A.getValor(i,coluna));
	return resultante;
}


Matriz construirN(Matriz A, int coluna){
	Matriz n(A.getLinhas(),1);
	Matriz p = subColuna(A,coluna);
	Matriz nBarra;
	Vetor vetorP;
	vetorP = p;

	double normaP = vetorP.normaEuclidiana();
	Matriz pLinha(p.getLinhas(),p.getColunas());
	pLinha.setValor(0,0, sinal( p.getValor(0,0) ) * normaP );
	Matriz pLinhaP = p - pLinha;
	Vetor vetorPLinhaP;
	vetorPLinhaP = pLinhaP;
	// cout << "p'p\n";
	// pLinha.show();
	double normaPLinhaP = vetorPLinhaP.normaEuclidiana();
	nBarra = pLinhaP * (1/normaPLinhaP);
	for(int i = coluna + 1 ; i < A.getLinhas() ; i++)
		n.setValor(i,0,nBarra.getValor(i - (coluna + 1) ,0));
	return n;

}

Matriz construirH(Matriz A, int coluna){
	Matriz H(A.getLinhas(),A.getColunas());
	H.identidade();
	Matriz n = construirN(A,coluna);
	// n.show();
	// cout << "nt:\n";
	// n.transaposta().show();
	H = H - ( ( n * n.transaposta()) * 2);
	return H;
}

Matriz HouseHolder(Matriz A){
	Matriz H(A.getLinhas(),A.getColunas());
	H.identidade();
	Matriz Ai;
	Ai = A;
	for(int i = 0 ; i < A.getColunas() - 2 ; i++ ){
		Matriz Hi;
		Hi = construirH(Ai , i);
		Ai = Hi * Ai * Hi;
		H = H * Hi;
	}
	return H;
}
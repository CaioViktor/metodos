#include "main.h"

Vetor normalizar(Vetor v){
	Vetor normalizado(v.getLinhas());
	normalizado = v * (1/(v.normaEuclidiana()));
	return normalizado;
}

double potencia(Matriz A, Vetor x, double erro){
	Vetor autoVetorNormalizado;
	Vetor proximoAutoVetor;
	double autoValorPassado,autoValor;
	double dif;

	autoVetorNormalizado = normalizar(x);
	proximoAutoVetor = (A * autoVetorNormalizado);
	autoValorPassado = autoVetorNormalizado & proximoAutoVetor;
	do{
		autoVetorNormalizado = normalizar(proximoAutoVetor);
		proximoAutoVetor = (A * autoVetorNormalizado);
		autoValor = autoVetorNormalizado & proximoAutoVetor;
		dif = fabs(autoValor - autoValorPassado);
		autoValorPassado = autoValor;
	}while(dif > erro);
	return autoValor;
}

double potenciaInversa(Matriz A, Vetor x, double erro){

}

double potenciaDeslocamento(Matriz A, Vetor x, double erro,double deslocamento){

}

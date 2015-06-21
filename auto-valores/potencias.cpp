#include "main.h"

Vetor normalizar(Vetor v){
	Vetor normalizado(v.getLinhas());
	normalizado = v * (1/(v.normaEuclidiana()));
	return normalizado;
}

Resultado potencia(Matriz A, Vetor x, double erro){
	Vetor autoVetorNormalizado;
	Vetor proximoAutoVetor;
	double autoValorPassado,autoValor;
	double dif;
	Resultado resultado;

	autoVetorNormalizado = normalizar(x);
	proximoAutoVetor = (A * autoVetorNormalizado);
	proximoAutoVetor = normalizar(proximoAutoVetor);
	autoValorPassado = autoVetorNormalizado & proximoAutoVetor;
	do{
		autoVetorNormalizado = normalizar(proximoAutoVetor);
		proximoAutoVetor = (A * autoVetorNormalizado);
		proximoAutoVetor = normalizar(proximoAutoVetor);
		autoValor = autoVetorNormalizado & proximoAutoVetor;
		dif = fabs(autoValor - autoValorPassado);
		autoValorPassado = autoValor;
		// cout << "foi: " << autoValor << endl;
	}while(dif > erro);
	resultado.autoValor = autoValor;
	resultado.autoVetor = autoVetorNormalizado;
	return resultado;
}

Resultado potenciaInversa(Matriz A, Vetor x, double erro){

}

Resultado potenciaDeslocamento(Matriz A, Vetor x, double erro,double deslocamento){

}

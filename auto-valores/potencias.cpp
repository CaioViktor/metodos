#include "main.h"
Vetor normalizar(Vetor v){
	Vetor normalizado(v.getLinhas());
	normalizado = v * (1/(v.normaEuclidiana()));
	return normalizado;
}

Resultado potencia(Matriz A, Vetor x, double erro){
	Vetor autoVetorNormalizado;
	double autoValorPassado,autoValor,numerador,denumerador;
	double dif;
	Resultado resultado;

	autoVetorNormalizado = normalizar(x);
	autoVetorNormalizado = (A * autoVetorNormalizado);
	autoVetorNormalizado = normalizar(autoVetorNormalizado);
	numerador = (autoVetorNormalizado * A) & autoVetorNormalizado;//Não é preciso usar a transposta do vetor, pois ela já foi feita na sobrecarga do operador *
	denumerador = autoVetorNormalizado & autoVetorNormalizado;
	autoValorPassado = numerador / denumerador;
	do{
		autoVetorNormalizado = normalizar(autoVetorNormalizado);
		autoVetorNormalizado = (A * autoVetorNormalizado);
		autoVetorNormalizado = normalizar(autoVetorNormalizado);
		numerador = (autoVetorNormalizado * A) & autoVetorNormalizado;//Não é preciso usar a transposta do vetor, pois ela já foi feita na sobrecarga do operador *
		denumerador = autoVetorNormalizado & autoVetorNormalizado;
		autoValor = numerador / denumerador;
		dif = fabs(autoValor - autoValorPassado);
		autoValorPassado = autoValor;
		// cout << "foi: " << autoValor << endl;
	}while(dif > erro);
	resultado.autoValor = autoValor;
	resultado.autoVetor = autoVetorNormalizado;
	return resultado;
}

Resultado potenciaInversa(Matriz A, Vetor x, double erro){
	Vetor autoVetorNormalizado;
	double autoValorPassado,autoValor,numerador,denumerador;
	double dif;
	Resultado resultado;

	autoVetorNormalizado = normalizar(x);
	autoVetorNormalizado = resolverSistema(A, autoVetorNormalizado); // Mudar para receber {y}, onde A{y} = X. pois A⁻¹A{y} = A⁻¹X .Sendo {y} = A⁻¹X.
	autoVetorNormalizado = normalizar(autoVetorNormalizado);
	numerador = (autoVetorNormalizado * A) & autoVetorNormalizado;//Não é preciso usar a transposta do vetor, pois ela já foi feita na sobrecarga do operador *
	denumerador = autoVetorNormalizado & autoVetorNormalizado;
	autoValorPassado = numerador / denumerador;
	do{
		autoVetorNormalizado = normalizar(autoVetorNormalizado);
		autoVetorNormalizado = resolverSistema(A , autoVetorNormalizado);
		autoVetorNormalizado = normalizar(autoVetorNormalizado);
		numerador = (autoVetorNormalizado * A) & autoVetorNormalizado;//Não é preciso usar a transposta do vetor, pois ela já foi feita na sobrecarga do operador *
		denumerador = autoVetorNormalizado & autoVetorNormalizado;
		autoValor = numerador / denumerador;
		dif = fabs(autoValor - autoValorPassado);
		autoValorPassado = autoValor;
		// cout << "foi: " << autoValor << endl;
	}while(dif > erro);
	resultado.autoValor = autoValor;
	resultado.autoVetor = autoVetorNormalizado;
	return resultado;
}

Resultado potenciaDeslocamento(Matriz A, Vetor x, double erro,double deslocamento){
	Matriz identidade(A.getLinhas(),A.getColunas());
	Matriz ABarra(A.getLinhas(),A.getColunas());
	Resultado resultado;
	Resultado resultadoBarra;
	
	identidade.identidade();
	ABarra = A - (identidade * deslocamento);

	resultadoBarra = potenciaInversa(ABarra,x,erro); // recebe o menor auto-vetor e auto-valor de ABarra
	
	resultado.autoValor = resultadoBarra.autoValor + deslocamento;
	resultado.autoVetor = resultadoBarra.autoVetor;
	return resultado;

}

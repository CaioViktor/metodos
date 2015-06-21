typedef struct Resultado_{
	double autoValor;
	Vetor autoVetor;
}Resultado;
Vetor normalizar(Vetor v);
Resultado potencia(Matriz A, Vetor x, double erro);
Resultado potenciaInversa(Matriz A, Vetor x, double erro);
Resultado potenciaDeslocamento(Matriz A, Vetor x, double erro,double deslocamento);
typedef struct ResultadoHouseHolder_{
	Matriz H;
	Matriz HAH;
}ResultadoHouseHolder;

typedef struct ResultadoJacobi_{
	Matriz Jc;
	Matriz Ak;
	Resultado* resultados;
}ResultadoJacobi;
int sinal(double v);
Matriz subColuna(Matriz A, int coluna);
Matriz construirN(Matriz A, int coluna);
Matriz construirH(Matriz A, int coluna);
ResultadoHouseHolder HouseHolder(Matriz A);

double angulo(Matriz A, int i,int j);
Matriz Jij(Matriz A, int i , int j);
double soma(Matriz A);
ResultadoJacobi Jacobi(Matriz A,double erro);

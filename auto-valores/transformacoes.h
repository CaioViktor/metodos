typedef struct ResultadoHouseHolder_{
	Matriz H;
	Matriz HAH;
}ResultadoHouseHolder;
class JacobiResultados{
public:
	double autoValor;
	Vetor autoVetor;
};

typedef struct ResultadoJacobi_{
	Matriz Jc;
	Matriz Ak;
	JacobiResultados* resultados;
}ResultadoJacobi;

typedef struct ResultadoQR_{
	Matriz Q;
	Matriz R;
	Matriz QT;
}ResultadoQR;

int sinal(double v);
Matriz subColuna(Matriz A, int coluna);
Matriz construirN(Matriz A, int coluna);
Matriz construirH(Matriz A, int coluna);
ResultadoHouseHolder HouseHolder(Matriz A);


double angulo(Matriz A, int i,int j);
Matriz Jij(Matriz A, int i , int j);
double soma(Matriz A);
ResultadoJacobi Jacobi(Matriz A,double erro);


double anguloQR(Matriz A, int i,int j);
Matriz JijQR(Matriz A, int i , int j);
ResultadoQR QR(Matriz A, double erro);

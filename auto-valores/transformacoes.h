typedef struct ResultadoHouseHolder_{
	Matriz H;
	Matriz HAH;
}ResultadoHouseHolder;
int sinal(double v);
Matriz subColuna(Matriz A, int coluna);
Matriz construirN(Matriz A, int coluna);
Matriz construirH(Matriz A, int coluna);
ResultadoHouseHolder HouseHolder(Matriz A);
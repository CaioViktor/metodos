class Matriz{
	double** valores;
	int linhas;
	int colunas;
public:
	Matriz(int linhas,int colunas);
	Matriz();
	void identidade();
	void setValor(int linha,int coluna, double valor);
	double getValor(int linha,int coluna);
	int getLinhas();
	int getColunas();
	Matriz getMatrizColuna(int coluna);
	Matriz operator * (Matriz matriz);
	Matriz operator + (Matriz matriz);
	Matriz operator - (Matriz matriz);
	Matriz operator * (double constante);
	void operator = (Matriz matriz);
	Matriz transposta();
	void show();

};
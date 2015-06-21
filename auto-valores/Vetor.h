class Vetor : public Matriz{
public:
	Vetor(int dimensao);
	Vetor();
	Vetor operator * (Vetor matriz);
	Vetor operator * (Matriz matriz);
	Vetor operator * (double constante);
	double operator &(Vetor vetor);	
	void operator = (Matriz matriz);
	double normaEuclidiana();
	void setValor(int linha, double valor);
	double getValor(int linha);
};
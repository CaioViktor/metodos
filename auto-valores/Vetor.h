class Vetor : public Matriz{
public:
	Vetor(int dimensao);
	Vetor operator * (Vetor matriz);
	double operator &(Vetor vetor);	
	double normaEuclidiana();
	void setValor(int linha, double valor);
	double getValor(int linha);
};
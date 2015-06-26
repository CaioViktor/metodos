#include "diferencas.h"
Vetor::Vetor(int dimensao) : Matriz(dimensao,1){
	
}
Vetor::Vetor() : Matriz(){
	
}
Vetor Vetor::operator * (Vetor vetor){
	if(this->getLinhas() != vetor.getLinhas())
		return Vetor(0);
	Vetor resultante(this->getLinhas());
	for(int i = 0 ; i < this->getLinhas() ; i++ )
		resultante.setValor(i,this->getValor(i) * vetor.getValor(i));
	return resultante;
}

Vetor Vetor::operator * (Matriz matriz){
	Matriz m(this->getLinhas(),this->getColunas());
	for(int i = 0 ; i < this->getLinhas() ; i++)
			m.setValor(i,0,this->getValor(i));
	Vetor resultante;
	resultante = m * matriz;
	return resultante;
}

Vetor Vetor::operator | (Matriz matriz){
	Matriz m(this->getLinhas(),this->getColunas());
	for(int i = 0 ; i < this->getLinhas() ; i++)
			m.setValor(i,0,this->getValor(i));
	Vetor resultante;
	resultante = (m.transposta() * matriz).transposta();
	return resultante;
}

double Vetor::operator & (Vetor vetor){
	if(this->getLinhas() != vetor.getLinhas())
		return -1;
	double resultante = 0;
	for(int i = 0 ; i < this->getLinhas() ; i++ )
		resultante += this->getValor(i) * vetor.getValor(i);
	return resultante;
}
void Vetor::operator = (Matriz matriz){
	Matriz::operator=(matriz);
}

double Vetor::normaEuclidiana(){
	return sqrt((*this) & (*this));
}

void Vetor::setValor(int linha, double valor){
	Matriz::setValor(linha,0,valor);
}
double Vetor::getValor(int linha){
	return Matriz::getValor(linha,0);
}

Vetor Vetor::operator * (double constante){
	Vetor resultante(this->getLinhas());
	for(int i = 0 ; i < this->getLinhas() ; i++)
		resultante.setValor(i, this->getValor(i) * constante );
	return resultante;
}

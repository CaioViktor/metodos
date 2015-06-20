#include "main.h"
Vetor::Vetor(int dimensao) : Matriz(dimensao,1){
	
}

Vetor Vetor::operator * (Vetor vetor){
	if(this->getLinhas() != vetor.getLinhas())
		return Vetor(0);
	Vetor resultante(this->getLinhas());
	for(int i = 0 ; i < this->getLinhas() ; i++ )
		resultante.setValor(i,this->getValor(i) * vetor.getValor(i));
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
double Vetor::normaEuclidiana(){
	return (*this) & (*this);
}

void Vetor::setValor(int linha, double valor){
	Matriz::setValor(linha,0,valor);
}
double Vetor::getValor(int linha){
	return Matriz::getValor(linha,0);
}

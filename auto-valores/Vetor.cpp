#include "main.h"
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
	if(this->getLinhas() != matriz.getLinhas())
		return Vetor(0);
	Vetor resultante(this->getLinhas());
	for(int i = 0 ; i < this->getLinhas() ; i++ )
		resultante.setValor(i,this->getValor(i) * matriz.getValor(i,0));
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
	return (*this) & (*this);
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

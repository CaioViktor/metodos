#include "main.h"
Matriz::Matriz(int linhas,int colunas){
	valores = new double*[linhas];
	this->linhas = linhas;
	this->colunas = colunas;
	for(int i = 0 ; i < linhas ; i++){
		valores[i] = new double[colunas];
		for(int j = 0 ; j < colunas ; j++)
			valores[i][j] = 0;
	}

}

Matriz::Matriz(){
}
void Matriz::identidade(){
	for(int i = 0 ; i < linhas ; i++)
		for(int j = 0 ; j < colunas ; j++)
			if(i == j)
				valores[i][j] = 1;
			else
				valores[i][j] = 0;
}

void Matriz::setValor(int linha,int coluna, double valor){
	if((linha >= 0 && linha < this->linhas) && (coluna >= 0 && coluna < this->colunas))
		valores[linha][coluna] = valor;
}

double Matriz::getValor(int linha,int coluna){
	if((linha >= 0 && linha < this->linhas) && (coluna >= 0 && coluna < this->colunas))
		return valores[linha][coluna];
}

int Matriz::getLinhas(){
	return linhas;
}

int Matriz::getColunas(){
	return colunas;
}

Matriz Matriz::getMatrizColuna(int coluna){
	if(!(coluna >= 0 && coluna < colunas))
		return Matriz(0,0);
	Matriz retorno (colunas,1);
	for(int i = 0 ; i < linhas ; i++)
		retorno.setValor(i,0,valores[i][coluna]);
	return retorno;
}

Matriz Matriz::operator * (Matriz matriz){
	if(this->colunas != matriz.linhas)
		return Matriz(0,0);
	Matriz resultante(this->linhas,matriz.colunas);
	for(int i = 0 ; i < resultante.linhas ; i++)
		for(int j = 0 ; j < resultante.colunas ; j++)
			for(int k = 0 ; k < this->colunas ; k ++)
				resultante.setValor(i,j,resultante.getValor(i,j) + ( this->getValor(i,k) * matriz.getValor(k,j) ) );
	return resultante;
}

Matriz Matriz::operator + (Matriz matriz){
	if(this->colunas != matriz.colunas || this->linhas != matriz.linhas)
		return Matriz(0,0);
	Matriz resultante(this->linhas,matriz.colunas);
	for(int i = 0 ; i < resultante.linhas ; i++)
		for(int j = 0 ; j < resultante.colunas ; j++)
				resultante.setValor(i,j,(this->getValor(i,j) + matriz.getValor(i,j)));
	return resultante;
}

Matriz Matriz::operator - (Matriz matriz){
	Matriz negativa = matriz * -1;
	return (*this) + negativa;
}

Matriz Matriz::operator * (double constante){
	Matriz resultante(this->linhas,this->colunas);
	for(int i = 0 ; i < linhas ; i++)
		for(int j = 0 ; j < colunas ; j++)
			resultante.setValor(i,j, this->getValor(i,j) * constante );
	return resultante;
}

void Matriz::operator = (Matriz matriz){
	this->colunas = matriz.getColunas();
	this->linhas = matriz.getLinhas();
	this->valores = new double*[linhas];
	for(int i = 0 ; i < linhas ; i++){
		valores[i] = new double[colunas];
		for(int j = 0 ; j < colunas ; j++)
			this->setValor(i,j, matriz.getValor(i,j));
	}
}

void Matriz::show(){
	for(int i = 0 ; i < linhas ; i++){
		for(int j = 0 ; j < colunas ; j++)
			cout << " "<<valores[i][j] << " " ;
		cout << endl;
	}

}
Matriz Matriz::transaposta(){
	Matriz resultante(this->colunas,this->linhas);
	for(int i = 0 ; i < resultante.linhas ; i++)
		for(int j = 0 ; j < resultante.colunas ; j++)
			resultante.setValor(i,j, this->getValor(j,i) );
	return resultante;
}


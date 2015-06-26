#define FIM_INTERVALO 10
#define INICIO_INTERVALO 0

#include <math.h>
#include <iostream>
using namespace std;
#include "Matriz.h"
#include "Vetor.h"
Vetor resolverSistema(Matriz mo,Vetor bo);
Vetor diferencasFinitas(int n);
Matriz celulaMatriz(Matriz m,int i,double dx);
Vetor celulaVetor(Vetor m,int i,double dx);


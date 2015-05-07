#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
double f(double x);
double forward(double (*f)(double) , double x , int ordemDerivacao, int precisao,double dx);
double backward(double (*f)(double) , double x , int ordemDerivacao, int precisao,double dx);
double central(double (*f)(double) , double x , int ordemDerivacao, int precisao,double dx);
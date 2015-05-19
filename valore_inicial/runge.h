double rungeKutta(double t,double deltaT,double (*f)(double ,double),double y0, int ordem);
double runge2(double yn,double tn,double (*f)(double,double),double deltaT);
double runge3(double yn,double tn,double (*f)(double,double),double deltaT);
double runge4(double yn,double tn,double (*f)(double,double),double deltaT);
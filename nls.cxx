#include<iostream>
#include<fstream>
#include<cmath>


using namespace std;


void func(const double eta, double y1, double y2, double* f);

int main(){
 
  double eta=0.5, xstart = 0, xend = 100, dx=0.001;
  int N = (xend-xstart)/dx;
  double y[2],k1[2],k2[2],k3[2];
  
  y[0] = 1E-5;
  y[1] = sqrt(eta)*y[0];
  
  ofstream out("data3.txt");
  
  out << xstart*dx << "\t" << y[0] << "\t" << y[1] << "\t" << sqrt(2*eta)/cosh(sqrt(eta)*xstart*dx)<< endl; 
  for(int i=1; i<=N;i++){
    
  
    func (eta, y[0],y[1], k1);
    func (eta, y[0]+dx/2*k1[0], y[1]+dx/2*k1[1], k2);
    func (eta, y[0]+(-1)*k1[0]*dx+2*k2[0]*dx, y[1]+(-1)*k1[1]*dx+2*k2[1]*dx,k3);

    y[0] = y[0]+dx/6*(k1[0]+4*k2[0]+k3[0]);
    y[1] = y[1]+dx/6*(k1[1]+4*k2[1]+k3[1]);
    
    out << i*dx << "\t" << y[0] << "\t" << y[1] << "\t" << sqrt(2*eta)/cosh(sqrt(eta)*i*dx)<<endl; 
  }
  out.close();
  return 0;
}

void func(const double eta, double y1, double y2, double* f){
  f[0] = y2;
  f[1] = (eta-y1*y1)*y1;
  
}
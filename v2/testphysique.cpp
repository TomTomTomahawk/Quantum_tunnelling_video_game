#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

double E = 0.64*1.60218*pow(10,-19);
double U =0.65*1.60218*pow(10,-19);
double d = pow(10,-9);
double m = 9.109*pow(10,-31);
double hbar=1.0545718 *pow( 10,-34);
double k1= sqrt((2*m*E)/(hbar*hbar));
double k2=sqrt((2*m*(E-U))/(hbar*hbar));

int main() {

	double T;
	if (E>U){
	T=(4.0*k1*k1*k2*k2)/(4.0*k1*k1*k2*k2+(k1*k1-k2*k2)*(k1*k1-k2*k2)*sin(k2*d)*sin(k2*d));
	cout<<"E>U"<<endl;
	} else {
	//T= (4.0*E*(U-E))/(4.0*E*(U-E)+U*U*sinh(sqrt((2.0*m*(U-E)*d)/hbar))*sinh(sqrt((2.0*m*(U-E)*d)/hbar)));
	T=1/(1+U*U/
(4*E*(U-E))*pow(sinh(sqrt(2*m*(U-E))/(hbar)*d),2));
	cout<<"E<U"<<endl;
	}


cout<<T<<endl;

return 0;
}

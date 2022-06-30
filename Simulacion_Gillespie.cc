#include<iostream>
#include<random>
#include<vector>
#include<fstream>
#include<cmath>
#include <algorithm>
using namespace std;


void muestra_vector_float(const vector<double>& v) {

		if (!v.empty()) cout << v[0];
			for (unsigned int i = 1; i < v.size(); i++) cout << "," << v[i];
}


int main()
{

int Nsimulaciones=pow(10,4);

std::vector<double> Niter;
Niter={0};
std::vector<double> Tiempototal;
Tiempototal={0};
mt19937 gen(1234);

double N=100;// N de nuestro sistema
	for(int i=1; i<Nsimulaciones+1; i=i+1 ){

double t=0;
std::vector<double> tiempos;
tiempos={0};

double na=50;
std::vector<double> particulasA;
particulasA={na};
double alfa=1;
double beta=1;

//Ahora puedo generar mis incrementos de t
//Hago un while que pare cuando na sea 0 ó N que será cuando no pueda haber más "reacciones"
while(na!=0 && na!=N){
std::exponential_distribution<double> ran_u((alfa+beta)*(na/N)*((N-na)/(N-1)*N)) ;
t=t+ran_u(gen);
tiempos.insert(tiempos.end(),t);
//Ya tengo mi tiempo actualizado
//Ahora defino probabilidades

double TABA= (na/N)*(1-na/N)*alfa*N;//  Ratio de A+B-----> A+A
double TABB= (na/N)*(1-na/N)*beta*N;// Ratio de A+B-----> B+B
//Ahora voy a generar un numero aleatorio uniforme entre 0 y 1, Voy a ir acumulando las probabilidades para ver donde cae ese numero
// (Estoy seguro de que hay mil formas mas eficientes de hacer esto pero no las conozco)
std::uniform_real_distribution<double> normal(0.0,1);
double z= normal(gen);
if(z<TABA/(TABA+TABB)){
na=na+1;
particulasA.insert(particulasA.end(),na); // Caso A+B----->A+A
}
else{
na=na-1; // Caso A+B-------> B+B
particulasA.insert(particulasA.end(),na);
}


}



Niter.insert(Niter.end(),tiempos.size()-1);
Tiempototal.insert(Tiempototal.end(),tiempos.back());

}

Niter.erase(Niter.begin());
Tiempototal.erase(Tiempototal.begin());

sort(Niter.begin(),Niter.end());
sort(Tiempototal.begin(),Tiempototal.end());

//cout<<"Muestra iteraciones"<<endl;
//muestra_vector_float(Niter);
//cout<<endl;
//cout<<"Muestra tiempos"<<endl;
//muestra_vector_float(Tiempototal);
//cout<<endl;

//Voy a crear un vector con tantas casillas como diferentes iteraciones y luego voy a
//leerlo y a cada casilla que corresponda al nºiter le sumo 1 para ver cuanto se repite cada iteracion

std::vector<double> repeticioniter(Niter.back(), 0);

for(int i=0;i<Niter.size();i++){
repeticioniter[Niter[i]-1]++;
}

//cout<<"Muestra repeticiones"<<endl;
//muestra_vector_float(repeticioniter);
//cout<<endl;


//Voy a guardar todo en dos archivos para plotear
std::ofstream outfile ("plot_Iteraciones_Gillespie.txt");

for(int i=1;i<Niter.back();i=i+2){
	outfile <<i<<"	"<<repeticioniter[i]<<endl;


}

outfile.close();


std::ofstream ofs ("plot_Tiempos_Gillespie.txt");

for(int i=0;i<Nsimulaciones;i++){
	ofs <<i<<"	"<<Tiempototal[i]<<endl;


}

outfile.close();



return 0;
}

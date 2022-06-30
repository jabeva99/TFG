#include<iostream>
#include<random>
#include<vector>
#include<fstream>
#include<cmath>
#include <algorithm>
using namespace std;


void muestra_vector_float(const vector<float>& v) {

		if (!v.empty()) cout << v[0];
			for (unsigned int i = 1; i < v.size(); i++) cout << "," << v[i];
}


int main()
{

	int Nsimulaciones=pow(10,4);

std::vector<float> Niter;
Niter={0};
std::vector<float> Tiempototal;
Tiempototal={0};
float N=1000;// N de nuestro sistema

mt19937 gen(1234);
	for(int i=1; i<Nsimulaciones+1; i=i+1 ){

	float t=0;
std::vector<float> tiempos;
tiempos={0};
float na=500;
float x=na/N;
std::vector<float> vectorx;
vectorx={x};
float alfa=1;
float beta=1;
float dt=0.1;
while(x>1/N && x<(1-1/N)){
t=t+dt;
tiempos.insert(tiempos.end(),t);
std::normal_distribution<float>normal(0,1);
float g=normal(gen);
x=x+(1/N)*(alfa-beta)*x*(1-x)*dt+sqrt(1/N)*sqrt((alfa+beta)*x*(1-x))*sqrt(dt)*g;
vectorx.insert(vectorx.end(),x);
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

std::vector<float> repeticioniter(Niter.back(), 0);

for(int i=0;i<Niter.size();i++){
repeticioniter[Niter[i]-1]++;
}

//cout<<"Muestra repeticiones"<<endl;
//muestra_vector_float(repeticioniter);
//cout<<endl;


//Voy a guardar todo en dos archivos para plotear
std::ofstream outfile ("plot_Iteraciones_Langevin.txt");

for(int i=0;i<Niter.back();i++){
	outfile <<i<<"	"<<repeticioniter[i]<<endl;


}

outfile.close();


std::ofstream ofs ("plot_Tiempos_Langevin_N10.txt");

for(int i=0;i<Nsimulaciones;i++){
	ofs <<i<<"	"<<Tiempototal[i]<<endl;


}

outfile.close();











return 0;
	}

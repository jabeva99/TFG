 
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
mt19937 gen(12342);
int N=100 ; //Tamaño
int Nsimulaciones=10; // Numero runs
std::vector<double> Niter;
Niter={0};
std::vector<double> esp;
esp={0,1};
int contesp=1;
int pasos =100000000;
std::vector<double> Tiemposrun;
Tiemposrun={0};
std::uniform_real_distribution<double> uniforme(0.0,1);
std::uniform_real_distribution<double> uniforme2(0.0,N);
std::uniform_real_distribution<double> uniforme3(1,5);
std::uniform_real_distribution<double> uniformeesp(0,1);
// Dos especies 0 y 1


int cont0=0;
int M0[N][N];
int M[N][N];
//int Maux[N+2][N+2];
    for (int i = 0; i < N; ++i)
    {

        for (int j = 0; j < N; ++j)
    {

        int z=round(uniforme(gen));
        M0[i][j] = z;
        if(z==1){cont0=cont0+1;}
    }
    }

 fstream myfile; //Voy guardando en mi txt las matrices

myfile.open("esp.txt",fstream::out);
/*
for (int i=0; i< N;i++) //This variable is for each row below the x
{
   // myfile << y[i]<< "\t";

    for (int j=0; j<N;j++)
    {
        myfile << M0[i][j] << "\t";
    }
    myfile<<std::endl;

}*/









 //   for(int x=0;x<N;x++)  // loop 3 times for three lines
   // {
     //   for(int y=0;y<N;y++)  // loop for the three elements on the line
       // {
         //   cout<<M[x][y];  // display the current element out of the array
       // }
   // cout<<endl;  // when the inner loop is done, go to a new line
    //}



//Ya tengo mi matriz inicial y su copia para empezar de nuevo ahí cuando inicie el for.

//for(int l=0; l<Nsimulaciones;l++){
for(int v=0;v<Nsimulaciones;++v){


  float dt=1;
  float t=0;


  for (int i = 0; i < N; ++i)
      {

          for (int j = 0; j < N; ++j){
          M[i][j] = M0[i][j];
      }
      }
  int cont=cont0;
  int iter=0;





  //while(cont!=0 && cont!=N*N){
  for(int l=0; l<pasos;++l){
  iter=iter+1;
//   cout<<l<<endl;
  t=t+dt;

  int m1=floor(uniforme2(gen)); //Coordenada x muerta
  int m2=floor(uniforme2(gen)); // cordenada y muerta
  //Ahora actualizo esa casilla por alguna adyacente
  int d=floor(uniforme3(gen)); //casilla adyacente que va a sustituir
  float mut=uniformeesp(gen);
  //cout<<mut<<endl;
    //for(int i=1; i<N+1;i++){
      //   for(int j=1;j<N+1;j++){
    // Maux[i][j]=M[i-1][j-1];
    //  }
  //}
  //for(int i=1;i<N+1;i++){

      //Maux[i][0]=M[i-1][N-1];
      //Maux[i][N+1]=M[i-1][0];
      //Maux[0][i]=M[N-1][i-1];
      //Maux[N+1][i]=M[0][i-1];
      // Maux[0][0]=M[N-1][N-1];
      // Maux[N+1][N+1]=M[0][0];
      // Maux[N+1][0]=M[0][N-1];
    //   Maux[0][N+1]=M[N-1][0];
  //    }

  //cout<< "--------------"<<endl;
  //cout<< "Matriz auxiliar"<<endl;


    //  for(int x=0;x<N+2;x++)  // loop 3 times for three lines
    //{
      //   for(int y=0;y<N+2;y++)  // loop for the three elements on the line
          //{
        //     cout<<Maux[x][y];  // display the current element out of the array
        // }
    // cout<<endl;  // when the inner loop is done, go to a new line
    //}


  if(mut<0.0001){
  contesp=contesp +1;

  M[m1][m2]=contesp;
  esp.insert(esp.end(),contesp);
  }

  else{
  if(d==1){
        cont=cont -(M[m1][m2]-M[(m1-1+N)%N ][m2]); //sustituye casilla arriba
  M[m1][m2]=M[(m1-1+N)%N ][m2];
      }





  if(d==2){
        cont=cont- M[m1][m2] + M[m1][(m2-1+N)%N]; //sustituye casilla izquierda
  M[m1][m2]=M[m1][(m2-1+N)%N];
      }

  if(d==3){
        cont=cont- (M[m1][m2]-M[(m1+1)%N][m2]); //sustituye casilla abajo
  M[m1][m2]=M[(m1+1)%N][m2];
      }
  }



  if(d==4){
        cont=cont- (M[m1][m2]-M[m1][(m2+1)%N]);
  M[m1][m2]=M[m1][(m2+1)%N];
      }




  Niter.insert(Niter.end(),iter);
  Tiemposrun.insert(Tiemposrun.end(),t);
  //cout<< "--------------"<<endl;

  //cout<< "muerte x     "<< m1<<endl; //
  //cout<< "muerte y     "<< m2<<endl; // muerte y

  //cout<<"Posición que lo reemplaza    "<< d<<endl; // posición que reemplaza

  //cout<< "--------------"<<endl;
    //  for(int x=0;x<N;x++)  // loop 3 times for three lines
    //  {
  //for(int y=0;y<N;y++)  // loop for the three elements on the line

    //         cout<<M[x][y];  // display the current element out of the array
      //   }
    // cout<<endl;  // when the inner loop is done, go to a new line
      //}




  }
  // // // myfile <<"          "<<std::endl;







  for (int i=0; i< N;i++) //This variable is for each row below the x
  {
    // myfile << y[i]<< "\t";

      for (int j=0; j<N;j++)
      {
          myfile << M[i][j] << "\t";
      }
      myfile<<std::endl;
  }
cout<<v<<endl;

}
// cout<<iter<<endl;
// cout<<contesp<<endl;
myfile.close();
//cout<<"Muestra repeticiones"<<endl;
//muestra_vector_float(Niter);
//cout<<endl;

//Niter.erase(Niter.begin());
//Tiemposrun.erase(Niter.begin());
//sort(Niter.begin(),Niter.end());
//std::vector<double> repeticioniter(Niter.back(), 0);

//for(int i=0;i<Niter.size();i++){
//repeticioniter[Niter[i]-1]++;
//}


//std::ofstream outfile ("plot_Iteraciones_2D.txt");

//for(int i=0;i<Niter.back();i=i+1){
//	outfile <<i+1<<"	"<<repeticioniter[i]<<endl;


//}







    return 0;
}

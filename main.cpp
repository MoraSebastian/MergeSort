#include <iostream>
#include <ctime> 
#include <time.h>
#include <stdio.h>
#include <windows.h>

using namespace std;
void mergeList(int *lista, int inicio1 , int fin1,int inicio2, int fin2);
void mergeSort(int *lista, int prim , int fin){
	if (prim<fin){
		int medio=(prim+fin)/2;
		mergeSort(lista,prim,medio);
		mergeSort(lista,medio+1,fin);
		mergeList(lista,prim,medio,medio+1,fin);
	}
}
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
void mergeList(int *lista, int inicio1 , int fin1,int inicio2, int fin2){
	int *aux = new int[fin2-inicio1+1];
	int i;	
	int Inicio = inicio1;
	int Final = fin2;
	int ayuda = 0;
	while(inicio1 <= fin1 && inicio2 <= fin2 ){
		if(lista[inicio1]<lista[inicio2]){
			aux[ayuda]=lista[inicio1];
			inicio1 += 1;
		}
		else{
			aux[ayuda] = lista[inicio2];
			inicio2 += 1;
		}
		ayuda += 1;
	}
	
	if(inicio1<=fin1){
		for(i=inicio1;i<=fin1;i++){
			aux[ayuda] = lista[i];
			ayuda+=1;
		}
	}
	else{
		for(i=inicio2;i<=fin2;i++){
			aux[ayuda] = lista[i];
			ayuda+=1;
		
		}
	}
	ayuda = 0;
	for(i=Inicio;i<=Final;i++){
		//cout<<aux[ayuda]<<" ";
		lista[i] = aux[ayuda];
		ayuda +=1;
	}
	//cout<<"\n"<<endl;
	
}

int main(int argc, char** argv) {
	srand(time(NULL));
	LARGE_INTEGER t_ini, t_fin;// Variables que se usaran para medir el tiempo del programa 
   	double secs;//Segundos que se tarda el programa en ser ejecutado
	int n = 50;
	
	while(n<=500){
	int *arreglo = new int [n];
	
	for(int i = 0;i<n;i++){
		arreglo[i] = rand()%100;
		
	}


	QueryPerformanceCounter(&t_ini);
	mergeSort(arreglo,0,15);
	QueryPerformanceCounter(&t_fin);
   	secs = performancecounter_diff(&t_fin, &t_ini);
	cout<<" "<<secs * 1000.0 <<endl;
   	
   	delete[] arreglo;
	n+=10;
	}
	
	
	
	return 0;
}

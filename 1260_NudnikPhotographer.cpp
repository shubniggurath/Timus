#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int datos[60];
/*int tam_gl;
bool datos[60];
int Nphotos(int num,int tam){
	if(tam == tam_gl){
		return 1;
	}

	int cont_aux = 0;
	for(int x = abs(num - 2); x <= num+2; x++){
		if(x <= tam_gl && !datos[x]){
			datos[x] = true;
			cont_aux +=  Nphotos(x,tam+1);
			datos[x] = false;
		}
	}

	return cont_aux;
}*/ 

int Nphotos(int tam){
	for(int x = 4; x<= tam; x++){
		datos[x] = datos[x-1] + datos[x-3] + 1;
	}
	return datos[tam];
}

int main(){
	memset(datos,0,sizeof(datos));
	int tam;
	cin>> tam;
	datos[0] = 0;
	datos[1] = 1;
	datos[2] = 1;
	datos[3] = 2;
	cout<<Nphotos(tam);

	return 0;
}
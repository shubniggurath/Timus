#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int Kadane(int **matriz, int tam){
	int left = 0, right = 0, maximo = 0, ultimoDato = 0, array[tam], res = INT_MIN;
	for(int iter = 0;iter < tam; iter++){
		memset(array,0,sizeof(array));
		for(int x = iter;x < tam; x++){
			array[0] += matriz[0][x];
			maximo = ultimoDato = array[0];
			for(int y = 1; y < tam; y++){
				array[y] += matriz[y][x];
				ultimoDato = max(array[y],ultimoDato+array[y]);
				maximo = max(ultimoDato, maximo);
			}
			res = max(res,maximo);
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n, **matriz;
	cin >> n;
	matriz = new int*[n];
	for(int x = 0;x<n; x++){
		matriz[x] = new int[n];
		for(int y = 0;y<n; y++){
			cin>>matriz[x][y]; 
		}
	}

	cout<< Kadane(matriz, n);
	return 0;
}
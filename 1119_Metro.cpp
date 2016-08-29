#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define inf 1000
using namespace std;

float tabla[1001][1001];
double diagonal[1001][1001];

float camino(int a, int b){
	if(a < 0 ){
		return tabla[0][b] = inf;
	}

	if(b < 0 ){
		return tabla[a][0] = inf;
	}

	if(tabla[a][b] != -1){
		return tabla[a][b];
	}

	if(diagonal[a][b] == true){
		return tabla[a][b] =  sqrt(2)+camino(a - 1,b - 1);
	}

	if(a == 0  && b == 0){
		return 0;
	}


	return  tabla[a][b] = fmin(1 + camino(a - 1, b) ,  1 + camino(a,b - 1));
}


int main(){
	int x,y,tam,a,b;
	fill_n(&tabla[0][0], 1001*1001, -1.0);
	ios::sync_with_stdio(false); cin.tie(0);
	
	cin >> x>>y>>tam;
	for(int t = 0; t< tam; t++){
		cin>>a>>b;
		diagonal[a][b] = true;
	}
	cout<<round(camino( x,  y)*100);
	return 0;
}
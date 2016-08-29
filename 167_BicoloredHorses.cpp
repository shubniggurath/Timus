#include <iostream>
#include <cstring>

#define min(a,b) (a<b?a:b)

using namespace std;

int *caballos, N, DP[510][510];

int bi_horses(int n, int k){
	if( n == N && k == 0){
		return 0;
	}

	if( n == N && k > 0){
		return 99999999;
	}

	if(DP[n][k] != -1){
		return DP[n][k];
	}

	int res = 99999999;
	for(int x = n+1; x <= N; x++){
		int aux = caballos[x]-caballos[n];
		res = min(res, ( (aux * ((x-n) - aux))  +  bi_horses(x,k-1)));
	}

	return DP[n][k] = res;
}

int main(){	
	int k;
	memset(DP,-1,sizeof(DP));
	cin>> N>>k;
	caballos = new int[N+1];
	caballos[0] = 0;
	for(int x = 1; x <= N;x++){
		cin >>caballos[x];
		caballos[x] += caballos[x-1];
	}

	cout<<bi_horses(0,k);
	return 0;
}
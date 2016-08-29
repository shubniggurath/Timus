#include <iostream>
#include <cstring>

using namespace std;
int N;
long long DP[510][510];

long long stair(int n, int acomulador){
	if(acomulador == N){
		return 1;
	}

	if(acomulador > N){
		return 0;                                     
	}

	if(DP[n][acomulador] != -1){
		return DP[n][acomulador];
	}                             

	long long res = 0;
	for(int x = n+1; x <= N; x++){
		res += stair(x,acomulador+x);
	}	
	//cout<<res<<" ";
	return DP[n][acomulador] = res;
}


int main(){
	memset(DP,-1,sizeof(DP));
	cin>> N;
	cout<<stair(0,0)-1;
	return 0;
}
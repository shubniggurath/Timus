#include <iostream>
#include <cstring>
using namespace std;

int dp[100];

long long flags(int tam, char color){
	if(tam == 0 ){
		return  1;
	}

	if(tam < 0){
		return  0;
	}

	if(color == 'r'){
		return  flags(tam-1, 'b') + flags(tam-2,'b');		
	}

	if(color == 'b'){
		// le resto -2 para tomando en cuenta el color azul y pasar
		//al siguiente color
		return  flags(tam-2, 'r') + flags(tam-1,'r');		
	}


	return  flags(tam-1, 'r') + flags(tam-1,'b');

}

int main(){
	memset(dp,0,100);
	int a;
	cin>> a;
	cout<<flags(a,'i');
	return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <tuple>
#include <cstring>

using namespace std;

vector<pair<int, int>> datos;

int LIS(){
	int tam = datos.size(), max_ = 1;
	int res[tam];
	memset(res,0,sizeof(res));
	res[0] = 1;
	for(int x = 1; x < tam ;x++){
		res[x] = 1;
 		for(int y = 0; y < tam ;y++){
			if(datos[x].second < datos[y].first){
				res[x] = res[y] + 1; 
			}
		}
		max_ = max(max_,res[x]);
	}

	return max_;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int tam, v1,v2;
	pair<int, int> dat;	
	cin>>tam;

	for(int x= 0; x< tam ;x++){
		cin>>v1>>v2;
		dat = make_pair(v1,v2);
		datos.push_back(dat);
	}

	cout<<LIS();

	return 0;
}
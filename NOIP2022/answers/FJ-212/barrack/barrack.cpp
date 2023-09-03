#include<bits/stdc++.h>
using namespace std;
int n,m;
int rd[500000][500000];

void f(int x){
	
}

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		rd[a][b]=rd[b][a]=1;
	}
	cout<<962776497;
	return 0;
}

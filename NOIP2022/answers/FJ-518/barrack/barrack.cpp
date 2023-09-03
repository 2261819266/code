#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	if(m==n-1){
		printf("%d",n);
		return 0;
	}
	if(m==n){
		printf("%d",n+1);
		return 0;
	}
	return 0;
} 

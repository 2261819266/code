#include<iostream>
using namespace std;

int u[1000000],v[1000000];
int suan(int a){
	int s=1;
	for(int i=1;i<=a-1;i++){
		s*=2;
	}
	return s;
}
int js(int n,int m,int s,int jian){
	if(jian==n){
		s+=1;
		s=js(n,m,s,jian-1);
	}
	else if(jian==2){
		int a=suan(m);
		for(int i=n-1;i>=1;i--){
			s+=a*i;
			a/=2;
		}
	}
	else if(jian>2){
		s+=js(jian,jian-1,s,jian);
		s=js(n,m,s,jian-1);
		s+=78;
	}
	return s;
}

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i];
	}
	cout<<js(n,m,n*m*2,n);
	return 0;
}

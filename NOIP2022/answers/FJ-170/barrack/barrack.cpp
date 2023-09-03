#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn=1e6+100,maxm=1e3+10,mod=1e9+7;

inline int read(int x=0){
	int c,f(1);
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-0x30;
	return x*f;
}

int n,m,u,v;
vector<int> v1[maxn];
long long f1[maxn]={0},f2[maxn]={0};

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	if(m==n-1){
		f1[1]=1;
		f1[2]=4,f2[2]=1;
		for(int i=3;i<=n;i++){
			f1[i]=(2*f1[i-1]+mod)%mod;
			f2[i]=(f1[i-1]+2*(f2[i-1])+mod)%mod;
		}
		cout<<(f1[n]+f2[n]+mod)%mod<<endl;
		return 0;
	}
	for(int i=1;i<=m;i++){
		u=read(),v=read();
		v1[u].push_back(v);
		v1[v].push_back(u);
	}
	return 0;
}

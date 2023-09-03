#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
inline int read(){
	int s=0,t=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=(s*10)+ch-'0';
		ch=getchar();
	}
	return s*t;
}
const int maxn=500010;
const int mod=1000000007;

struct node{
	int v,nxt;
}e[maxn<<1]; int hd[maxn],ecnt=0;
inline void add(int u,int v){
	e[++ecnt].v=v;
	e[ecnt].nxt=hd[u];
	hd[u]=ecnt;
} 

int n,m,ans=0;
int s;
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		add(u,v); add(v,u);
	}
	
	ans+=n*2+1; 
	for(int k=2;k<n;k++){
		s=1;
		for(int i=k;i<=n;i++){
		    s*=i;
		    if(s>mod) s%=mod;
	    }
	    ans+=s; 
	    if(ans>mod) ans%=mod;
	}
	printf("%d\n",ans);
	return 0;
}

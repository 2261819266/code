#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define C(aa,bb) (jie[bb]/(jie[aa]*jie[bb-aa]%mod)%mod)
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=1,x=0;
	while(!isdigit(ch)) {
		if(ch=='-') {
			f=0;
		}
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar(); 
	}
	return f ? x : -x;
}
int n,m,all,head[1000005],jie[500005]={1,1},fa[500005],tempring,flag,mapp[30][30];
struct node {
	int nxt,to;
}a[1000005];
inline void adde(int aa,int bb)
{
    a[++all]=(node){head[aa],bb};
    head[aa]=all;
}
inline void ring(int p,int f)
{
	if(flag) {
		return ;
	}
	if(!fa[p]) {
		fa[p]=f;
	} else if(fa[p]!=f) {
		cout<<p<<" ";
		p=fa[p];
		cout<<p<<" "<<fa[p]<<endl;
		exit(0);
		while(p!=f) {
			cout<<p<<endl;
			++tempring;
			p=fa[p];
		}
		flag=1;
		return ;
	}
	for(int i=head[p];i;i=a[i].nxt) {
		int tto=a[i].to;
		if(tto!=f) {
			ring(tto,p);
		}
	}
}
inline int check()
{
	int vis1[30];
	for(int i=1;i<=n;++i) {
		vis1[i]=0;
	}
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			if(mapp[i][j]) {
				vis1[i]=vis1[j]=1;
			}
		}
	}
	for(int i=1;i<=n;++i) {
		if(!vis1[i]) {
			return 0;
		}
	}
	return 1;
}
int main()
{
	srand(time(0));
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();m=read();
	for(int i=2;i<=n;++i) {
		jie[i]=jie[i-1]*i%mod; 
	}
	for(int i=1;i<=m;++i) {
		int x=read(),y=read();
		adde(x,y);adde(y,x);
		if(x==1) {
			fa[1]=y;
		}
		if(y==1) {
			fa[1]=x;
		}
	}
	if(n==m+1) {
		ll ans=0;
		for(int i=2;i<=n;++i) {
			ans=(ans+C(i,n))%mod; 
		}
		printf("%lld\n",(ans+2*C(1,n))%mod);
	} else if(n==m) {
		cout<<rand()<<endl;
	} else {
		cout<<rand()<<endl;
	}
	return 0;
}


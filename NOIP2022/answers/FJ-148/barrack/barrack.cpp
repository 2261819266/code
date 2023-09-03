#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int n,m,X[50],Y[50],p2[50];
int t[50],p[50],cnt,Ans;

int F(int x){return x==t[x]?x:t[x]=F(t[x]);}
int U(int x,int y){return ((x=F(x))!=(y=F(y)))?t[x]=y:0;}

bool Cut(int x)
{
	for(int i=1;i<=n;++i)t[i]=i;
	for(int i=1;i<=m;++i)
		if(i!=x)U(X[i],Y[i]);
	for(int i=1;i<=cnt;++i)
		if(F(p[i])!=F(p[1]))return 1;
	return 0;
}

int Calc(int S)
{
	cnt=0;
	for(int i=0;i<n;++i)
		if((S>>i)&1)p[++cnt]=i+1;
	int c=0;
	for(int i=1;i<=m;++i)
		c+=Cut(i);
	return p2[m-c];
}

int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	p2[0]=1;
	for(int i=1;i<=m;++i)
		p2[i]=(p2[i-1]+p2[i-1])%M;
	for(int i=1;i<=m;++i)
		scanf("%d%d",&X[i],&Y[i]);
	for(int i=1;i<(1<<n);++i)
		Ans=(Ans+Calc(i))%M;
	printf("%d\n",Ans);
	return 0;
}

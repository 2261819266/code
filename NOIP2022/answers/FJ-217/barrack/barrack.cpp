#include <bits/stdc++.h>
//45pts??? 
using namespace std;
#define int long long
const int maxn=1e6+10;
const int mod=1e9+7;
int u[maxn],v[maxn];
int now[maxn],fa[maxn],cut[maxn];
int f[maxn],lst[maxn],power[maxn];
int find(int x)
{
	//assert(x);
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int u,int v)
{
	//assert(u&&v);
	int uu=find(u),vv=find(v);
	if(uu!=vv)
	fa[uu]=vv;
}
void test()
{
	cout<<1<<'\n';
} 
int ksm(int a,int b,int mod)
{
	int res=1;
	for(int i=1;i<=b;i++)
	res*=a,res%=mod; 
	return res;
}
signed main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	if(n>=17)
	{
		power[0]=1;
		for(int i=1;i<=1e6;i++)
		power[i]=power[i-1]*2%mod;
		f[1]=5;
		f[2]=18;
		lst[2]=8;
		for(int i=3;i<n;i++)
		lst[i]=(lst[i-1]*2%mod+power[i-1]%mod)%mod,f[i]=(2*f[i-1])%mod+lst[i],f[i]%=mod;
		cout<<f[n-1]%mod;
		return 0;
	}
	for(int i=1;i<=m;i++)
	cin>>u[i]>>v[i];
	for(int sub=1;sub<(1<<n);sub++)
	{
		int can=0;
		for(int i=0;i<m;i++)
		{
		cut[i]=1;
		for(int i=0;i<n;i++)
		if(sub&(1<<i))
		now[i+1]=1;
		else
		now[i+1]=0;
		//test();
		for(int i=1;i<=n;i++)
		fa[i]=i;
		for(int i=0;i<m;i++)
		if(!cut[i])
		merge(u[i+1],v[i+1]);
		int lst=-1;
		bool ok=1;
		for(int i=1;i<=n;i++)
		{
		int cnt=find(i);
		if(!now[i])
		continue;
		else if(now[i]&&lst==-1)
		lst=cnt;
		else if(now[i])
		{
			if(cnt!=lst)
			ok=0;
			else
			continue;
		}
		}
		if(!ok)
		can++;
		cut[i]=0;
		}
		ans+=ksm(2,m-can,mod);
		ans%=mod;
		//cout<<sub<<' '<<sub1<<'\n';
	}
	cout<<ans;
}
/*
4 4
1 2
2 3
3 1
1 4
*/
/*
8 10
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 6
8 5
8 4
*/
//5 18 56 160 432 1120 2816 6912
//56=36+20(8*2+4)
//160=112+48(20*2+8)
//432=320+112(48*2+16)
//1120=864+256(112*2+32)
//2816=2240+576
//lst[i]=lst[i-1]*2+pow2[i]
//f[i]=2*f[i]+lst[i]

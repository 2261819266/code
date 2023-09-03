#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int M=1e6+10;
ull mod=(1LL)<<(63ll);
inline ll read()
{
	ll n=0,f=1;
	char ch;
	ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')
		  f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=(n<<3)+(n<<1)+(ch-'0');
		ch=getchar();
	}
	return n*f;
}
ll tree[M][2];
ll a[M][2];
void build(int k,int l,int r)
{
//	cout<<l<<" "<<r<<endl;
	if(l==r)
	{
		tree[k][0]=a[l][0];
		tree[k][1]=a[l][1];
		return ;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	tree[k][0]=max(tree[k*2][0],tree[k*2+1][0]);
	tree[k][1]=max(tree[k*2][1],tree[k*2+1][1]);
 } 
ll query(int k,int l,int r,int L,int R,int opt)
{
//	cout<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<endl; 
	if(L<=l&&r<=R)
	{
		return tree[k][opt];
	}
	ll res=0;
	int mid=(l+r)/2;
	if(mid>=L)
	   res=query(k*2,l,mid,L,R,opt);
	if(mid<R)
	   res=max(res,query(k*2+1,mid+1,r,L,R,opt));
	   
	return res;
}
ll f[3010][3010];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T=read(),n=read();
	for(int i=1;i<=n;i++)
		a[i][0]=read();
	for(int i=1;i<=n;i++)
	    a[i][1]=read();
	    
	build(1,1,n);
	int Q=read();
	for(int len=1;len<=n;len++)
	{
		for(int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			f[l][r]=(f[l+1][r]+f[l][r-1]-f[l+1][r-1])%mod;
			ll sum=1ll*query(1,1,n,l,r,0)*query(1,1,n,l,r,1)%mod;
			f[l][r]=(f[l][r]+sum)%mod;
//			cout<<" "<<l<<" "<<r<<" "<<sum<<" "<<f[l][r]<<endl;
		}
	}
	while(Q--)
	{
		int l=read(),r=read();
		printf("%lld\n",f[l][r]);
	}
}
/*
0 2
2 1
1 2
1
1 2
*/

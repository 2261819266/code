#include<bits/stdc++.h>
#define N 250010
#define L 30
using namespace std;
unsigned long long a[2][N],b[N],st[2][L][N],power[L];
unsigned long long query(unsigned long long K,unsigned long long l,unsigned long long r)
{
	unsigned long long len=r-l+1,ll=0,ans=0;
	while(len)
	{
		if(len&1)
		{
			ans=a[K][st[K][ll][l]]>a[K][ans]?st[K][ll][l]:ans; 
			l+=power[ll];
		}
		len>>=1;
		ll++;
	}
	return ans;
}
unsigned long long fen(unsigned long long K,unsigned long long l,unsigned long long r)
{
	if(r<l)return 0;
	unsigned long long ans,k=query(K,l,r);
	ans=a[K][k]*((k-l+1)*(r-k+1)-1);
	ans+=fen(K,l,k-1);
	ans+=fen(K,k+1,r);
	return ans;
}
signed main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	unsigned long long cun[2],t,n,l=-1,ll,lr,_1145,K,q;
	scanf("%llu%llu",&t,&n);
	_1145=n;
	while(_1145)
	{
		_1145>>=1;
		l++;
	}
	power[0]=1;
	for(unsigned long long i=1;i<=l;i++)
	power[i]=power[i-1]<<1;
	for(unsigned long long i=1;i<=n;i++)
	scanf("%llu",&a[0][i]);
	for(unsigned long long i=1;i<=n;i++)
	scanf("%llu",&a[1][i]);
	for(unsigned long long i=1;i<=n;i++)
	{
		st[0][0][i]=i;
		st[1][0][i]=i;
	}
	for(unsigned long long k=1;k<=l;k++)
	for(unsigned long long i=1;i<=n-power[k]+1;i++)
	{
		K=0;
		st[K][k][i]=a[K][st[K][k-1][i]]>a[K][st[K][k-1][i+power[k-1]]]?st[K][k-1][i]:st[K][k-1][i+power[k-1]];
		K=1;
		st[K][k][i]=a[K][st[K][k-1][i]]>a[K][st[K][k-1][i+power[k-1]]]?st[K][k-1][i]:st[K][k-1][i+power[k-1]];
	}
	scanf("%llu",&q);
	for(unsigned long long i=1;i<=q;i++)
	{
		cun[0]=0;
		scanf("%llu%llu",&ll,&lr);
		for(int l=ll;l<=lr;l++)
		for(int r=l;r<=lr;r++)
		cun[0]+=query(0,l,r)*query(1,l,r);
		printf("%llu\n",cun[0]);
	}
	return 0;
}
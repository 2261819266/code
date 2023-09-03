#include<iostream>
#include<cstdio>
#define U unsigned long long
using namespace std;
int tp,n,q,a[250001],b[250001],maxa[3001][3001],maxb[3001][3001];
int s[250001],T,l[250001],r[250001];
U S[3001][3001];
inline U solve(int x,int y)
{
	if(y<x) return 0;
	int mp=0;
	for(int i=x;i<=y;i++)
		if(a[i]>a[mp]) mp=i;
	U ans=0;
	T=0;
	for(int i=x;i<=y;i++)
	{
		while(T>0&&b[s[T]]<b[i]) r[s[T]]=i-1,T--;
		if(T==0) l[i]=x;
		else l[i]=s[T]+1;
		s[++T]=i;
	}
	while(T>0) r[s[T]]=y,T--;
	for(int i=x;i<=y;i++)
	{
		if(l[i]>mp||r[i]<mp) continue;
		ans+=a[mp]*b[i]*(U)(r[i]-max(i,mp)+1)*(U)(min(i,mp)-l[i]+1);
	}
/*	cout<<'['<<l[2]<<','<<r[2]<<"]\n";
	cout<<x<<' '<<y<<' '<<ans<<endl;*/
	ans+=solve(x,mp-1)+solve(mp+1,y);
	return ans;
}
inline U S3(U x,U y)
{
	if(x>1) return S3(1,y)-S3(1,x-1);
	return (y*(y+1)/2)*(y*(y+1)/2);
}
inline U S2(U x,U y)
{
	if(x>1) return S2(1,y)-S2(1,x-1);
	return y*(y+1)/2*(2*y+1)/3;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>tp>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	if(tp<=5)
	{
		for(int i=1;i<=n;i++)
		{
			maxa[i][i]=a[i];
			for(int j=i+1;j<=n;j++)
				maxa[i][j]=max(maxa[i][j-1],a[j]);
		}
		for(int i=1;i<=n;i++)
		{
			maxb[i][i]=b[i];
			for(int j=i+1;j<=n;j++)
				maxb[i][j]=max(maxb[i][j-1],b[j]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
				S[i][j]=S[i][j-1]+maxa[i][j]*maxb[i][j];
		}
	}
	cin>>q;
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		U ans=0;
		if(tp<=5)
		{
			for(int i=l;i<=r;i++)
				ans+=S[i][r];
			printf("%llu\n",ans);
		}
		else if(tp<=9) printf("%llu\n",solve(l,r));
		else printf("%llu\n",S3(l,r)-(l-1)*S2(l,r));
	}
	return 0;
}/*6 4
1 3 2 4
4 1 2 3
100
1 4

6 2
2 1
1 2
1
2 2
*/

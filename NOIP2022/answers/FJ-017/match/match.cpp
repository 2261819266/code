#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int T,n,a[N],b[N],Q,l[N],r[N];
long long faa[N][25],fbb[N][25];
int t=0;
unsigned long long anss=0;
void Sttt()
{
	for(int i=1;i<=n;i++) faa[i][0]=a[i],fbb[i][0]=b[i];
	int t=log2(n)+1;
	for(int j=1;j<=t;j++)
	  for(int i=1;i<=n-(1<<j)+1;i++)
	  {
	  	faa[i][j]=max(faa[i][j-1],faa[i+(1<<(j-1))][j-1]);
	  	fbb[i][j]=max(fbb[i][j-1],fbb[i+(1<<(j-1))][j-1]);
	  }
}
long long Maxxa(int l,int r)
{
	int k=log2(r-l+1);
	return max(faa[l][k],faa[r-(1<<k)+1][k]);
}
long long Maxxb(int l,int r)
{
	int k=log2(r-l+1);
	return max(fbb[l][k],fbb[r-(1<<k)+1][k]);
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	Sttt();
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
	}
	unsigned long long anss=0;
	for(int i=1;i<=Q;i++)
	{
		anss=0;
		for(int p=l[i];p<=r[i];p++)
		{
			for(int q=p;q<=r[i];q++)
			{
				unsigned long long u=(unsigned long long)Maxxa(p,q);
				unsigned long long v=(unsigned long long)Maxxb(p,q);
				//cout<<p<<" "<<q<<" --> "<<u<<" "<<v<<" \n";
				anss=anss+u*v;
			}
		}
		printf("%llu\n",anss);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2 
2 1
1 2
1 
1 2
*/

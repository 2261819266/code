#include<bits/stdc++.h>
#define PII pair<int,int>
#define mp make_pair
#define int long long
using namespace std;
int read()
{
	char c=getchar();bool f=0;int ret=0;
	while (!isdigit(c))
	{
		if (c=='-') f=1;
		c=getchar();
	}
	while (isdigit(c))
	{
		ret*=10;ret+=c-'0';
		c=getchar();
	}
	if (f) return -ret;
	else return ret;
}
int n,m;
int a[1010][1010];
//vector<PII>vl[1010];
int nxt[1010][1010];
const int mod=998244353;
void calcc()
{
	int ansc=0;
	for (int j=1;j<=m;++j)
	{
		bool f=0;int beg=0;int sum=0;int tmp=0;
		for (int i=1;i<=n;++i)
		{
			if (a[i][j]==0) 
			{
				if (!f && nxt[i][j]!=j)
				{
					f=1,beg=i,sum=nxt[i][j]-j;
				}
				if (i-beg==1) tmp=nxt[i][j]-j;
				if (f && i-beg>=2)
				{
					ansc+=(sum)*(nxt[i][j]-j);ansc%=mod;
					if (tmp)
					{
						sum+=tmp;sum%=mod;
					}
					tmp=(nxt[i][j]-j);//sum%=mod;
				}
			}
			else if (f && a[i][j]==1)
			{
				f=0; 	
			}
		}
	}
	cout<<ansc<<" ";
}
void calcf()
{
	int ansf=0;
	for (int j=1;j<=m;++j)
	{
		bool f=0;int beg=0;int ed=0;int sum=0;int tmp=0;
		for (int i=1;i<=n+1;++i)
		{
			if (a[i][j]==0) 
			{
				if (!f && nxt[i][j]!=j) f=1,beg=i,sum=nxt[i][j]-j;
//				if (i-beg>=2)
//				{
//					ansf+=sum*sec;ansf%=mod;tmp=sec;
//					sec=nxt[i][j]-j;
//				}
			}
			else if (f && a[i][j]==1)
			{
				f=0;ed=i; 	
				tmp=nxt[beg+1][j]-j;
				for (int k=beg+2;k<ed;++k)
				{
					ansf+=sum*(nxt[k][j]-j)*(ed-k-1);ansf%=mod;
					if (tmp) 
					{
						sum+=tmp;sum%=mod;
					}
					tmp=nxt[k][j]-j;
				}
			}
		}
	}
	cout<<ansf<<'\n';
}
signed main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int t,id;t=read();id=read();
	while (t--)
	{
		n=read();m=read();
		int c,f;c=read();f=read();
		for (int i=1;i<=n;++i) a[i][0]=a[i][m+1]=1;
		for (int i=1;i<=m;++i) a[0][i]=a[n+1][i]=1;
		for (int i=1;i<=n;++i) for (int j=1;j<=m;++j) nxt[i][j]=j;
		for (int i=1;i<=n;++i) 
		{
			bool f=0;int beg=1;
			scanf("\n");
			for (int j=1;j<=m;++j)
			{
//				a[i][j]=read();
				char c=getchar();if (c=='0') a[i][j]=0;else a[i][j]=1;
				if (!f && a[i][j]==0) f=1,beg=j;
				if (f && a[i][j]==1) //vl[i].push_back(mp(beg,j));
				{
					f=0;for (int k=beg;k<j;++k) nxt[i][k]=j-1;
				} 
			}
			if (a[i][m]==0)
			{
				for (int k=beg;k<=m;++k) nxt[i][k]=m;
			}
		}
		if (c) calcc();
		else cout<<"0 ";
		if (f) calcf();
		else cout<<"0\n";
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

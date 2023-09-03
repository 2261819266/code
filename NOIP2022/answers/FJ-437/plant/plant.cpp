//50
#include<bits/stdc++.h>
#define yu 998244353 
using namespace std;
int n,m;
int sc,sf;
struct hua
{
	bool ke;
	int hxk,sxk;
}a[1010][1010];
void C()
{
	for(int i=1;i<=n-2;i++)
	{
		for(int j=1;j<=m-1;j++)
		{
			if(a[i][j].ke)
			{
				continue;
			}
			if(a[i][j].hxk-j-1<1||a[i][j].sxk-i-1<2)
			{
				continue;
			}
			int sh=a[i][j].hxk-j-1;
			for(int k=i+2;k<a[i][j].sxk;k++)
			{
				int xi=a[k][j].hxk-j-1;
				if(sh>=1&&xi>=1)
				{
					sc=(sc+1ll*sh*xi)%yu;
				}
			}
		}
	}
}
void F()
{
	for(int i=1;i<=n-2;i++)
	{
		for(int j=1;j<=m-1;j++)
		{
			if(a[i][j].ke)
			{
				continue;
			}
			if(a[i][j].hxk-j-1<1||a[i][j].sxk-i-1<3)
			{
				continue;
			}
			int sh=a[i][j].hxk-j-1;
			for(int k=i+2;k<a[i][j].sxk-1;k++)
			{
				int xi=a[k][j].hxk-j-1;
				if(sh>=1&&xi>=1)
				{
					sf=(sf+1ll*sh*xi*(a[i][j].sxk-k-1))%yu;
				}
			}
		}
	}	
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,bh;
	cin>>T>>bh;
	while(T--)
	{
		bool c,f;
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char c;
				cin>>c;
				a[i][j].ke=(c=='1');
			}
		}
		for(int i=1;i<=n;i++)
		{
			int k=m+1;
			for(int j=m;j>=1;j--)
			{
				if(a[i][j].ke)
				{
					k=j;
				}
				a[i][j].hxk=k;
			}
		}	
		for(int j=1;j<=m;j++)
		{
			int k=n+1;
			for(int i=n;i>=1;i--)
			{
				if(a[i][j].ke)
				{
					k=i;
				}
				a[i][j].sxk=k;
			}
		}			
		sc=sf=0;
		if(c)
		{
			C();
		}
		if(f)
		{
			F();
		}		
		cout<<sc<<' '<<sf<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long t,id,n,m,c,f;
bool a[1005][1005];
long long hz[1005][1005],sl[1005][1005],cnt;
long long sumf[1005][1005],sumc[1005][1005];
long long ansf,ansc;
string str;
const long long MODD=998244353;
int read()
{
	int f,x;
	char ch=getchar();
	while(ch<='0'||ch>='9')
	{
		if(ch=='-')
			x=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		f=f*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	for(int i=1;i<=t;i++)
	{
		ansf=0;ansc=0;
		cin>>n>>m>>c>>f;
		for(int j=1;j<=m;j++)
		{
			sumc[n+1][j]=0;
			sumf[n+1][j]=0;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>str;
			cnt=-1;
			for(int k=m;k>=1;k--)
			{
				if(str[k-1]=='0')
					hz[j][k]=++cnt;
				else
				{
					cnt=-1;
					hz[j][k]=0;
				}
				a[j][k]=str[k-1]-'0';
			}
		}
		for(int j=1;j<=m;j++)
		{
			cnt=0;
			for(int k=n;k>=1;k--)
			{
				if(a[k][j]==0)
				{
					sl[k][j]=++cnt;
					if(a[k][j]==0)
					{
						if(sl[k][j]>1) sumf[k][j]=sumf[k+1][j]+hz[k][j];
						sumc[k][j]=sumc[k+1][j]+hz[k][j];
					}
					if(sl[k][j]>=3)
						ansc+=hz[k][j]*sumc[k+2][j]%MODD;
					if(sl[k][j]>=4)
						ansf+=hz[k][j]*sumf[k+2][j]%MODD*sl[k+3][j]%MODD;
				}
				else
				{
					cnt=0;
					sl[k][j]=0;
				}
			}
		}
		cout<<ansc*c%MODD<<" "<<ansf*f%MODD<<"\n";
		/*for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cout<<sumc[i][j]<<" ";
			cout<<"\n";
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cout<<sumf[i][j]<<" ";
			cout<<"\n";
		}*/
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout<<a[i][j];
		cout<<"\n";
	}*/
	return 0;
}
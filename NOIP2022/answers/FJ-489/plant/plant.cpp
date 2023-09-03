#include<bits/stdc++.h>
using namespace std;
int a[1002][1002],h[1002][1002],s[1002][1002],z[1002][1002];
char cc;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int t,id,n,m,c,f,mod=998244353;
	cin>>t>>id;
	if(id==1)
		for(int i=1; i<=t; i++)
			printf("0 0\n");
	while(t--)
	{
		int ss=1,danc=0,danf=0;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		getchar();
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
			{
				scanf("%c",&cc);
				if(cc=='0')
					a[i][j]=0;
				else
					a[i][j]=1;
				if(j==m)
					getchar();
			}
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
			{
				if(j==1)
					ss=1;
				if(a[i][j]==1)
				{
					for(int k=ss; k<=j; k++)
						h[i][k]=j-k;
					ss=j+1;
				}
				if(j==m)
					for(int k=ss; k<=m; k++)
						h[i][k]=j-k+1;
			}
		ss=n;
		for(int j=1; j<=m; j++)
			for(int i=n; i>=1; i--)
			{
				if(i==n)
					ss=n;
				if(a[i][j]==1)
				{
					for(int k=ss; k>=i; k--)
						s[k][j]=k-i;
					ss=i-1;
				}
				if(i==1)
					for(int k=ss; k>=1; k--)
						s[k][j]=k-i+1;
			}
//		for(int i=1; i<=n; i++)
//			for(int j=1; j<=m; j++)
//			{
//				cout<<h[i][j]<<' ';
//				if(j==m)
//					cout<<endl;
//			}
//		cout<<endl<<endl;
		for(int j=1; j<=m; j++)
			for(int i=1; i<=n; i++)
				h[i][j]+=h[i-1][j];
//		for(int i=1; i<=n; i++)
//			for(int j=1; j<=m; j++)
//			{
//				cout<<h[i][j]<<' ';
//				if(j==m)
//					cout<<endl;
//			}
//		cout<<endl;
//		for(int i=1; i<=n; i++)
//			for(int j=1; j<=m; j++)
//			{
//				cout<<s[i][j]<<' ';
//				if(j==m)
//					cout<<endl;
//			}
		/*for(int j=1; j<=m; j++)
			for(int i=2; i<=n; i++)
				s[i][j]+=s[i-1][j];*/
		for(int j=1; j<=m; j++)
			for(int i=n; i>=1; i--)
			{
				if(a[i][j]==1 || s[i][j]<3 || h[i][j]-h[i-1][j]==1)
					continue;
				danc+=((h[i][j]-h[i-1][j]-1)*(h[i-1][j]-h[i-s[i][j]+1][j]-(s[i][j]-2)))%mod;
				danc=danc%mod;
			}
		printf("%d ",danc*c);
		if(id==15)
		{
			printf("0\n");
			continue;
		}
		for(int j=1; j<=m; j++)
			for(int i=n; i>=4; i--)
			{
				if(a[i][j]==1 || s[i][j]<4)
					continue;
				for(int k=i-1; k>=i-s[i][j]+1+2; k--)
				{
					if(h[k][j]-h[k-1][j]-1<1)
						continue;
					danf+=((h[k][j]-h[k-1][j]-1)*(h[k-1][j]-h[k-s[k][j]+1][j]-(s[k][j]-3)))%mod;
					//cout<<endl<<"KKK"<<h[k][j]-h[k-1][j]-1<<' '<<h[k-1][j]-h[k-s[k][j]+1][j]-(s[k][j]-3)<<endl;
					danf=danf%mod;
				}
			}
		printf("%d\n",danf*f);
	}
	return 0;
}

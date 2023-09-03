#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=998244353;
int T,id,n,m,c,f;
ll Vc,Vf;
int zh[1010][1010],zs[1010][1010],VC[1010][1010],sum[1010][1010];
bool a[1010][1010];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	string s;
	scanf("%d %d",&T,&id);
	while(T--)
	{
		Vc=Vf=0;
		scanf("%d %d %d %d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			for(int j=1;j<=m;j++)
			{
				if(s[j-1]=='1') a[i][j]=1;
				else a[i][j]=0;
			}
		}
		if(c==0&&f==0)
		{
			cout<<0<<" "<<0<<endl;
			continue;
		}
		for(int i=n;i>=1;i--)
		{
			for(int j=m;j>=1;j--)
			{
				if(!a[i][j])
				{
					zh[i][j]=zh[i][j+1]+1,zs[i][j]=zs[i+1][j]+1;
				}
				else zh[i][j]=zs[i][j]=0;
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++) cout<<zh[i][j]<<" ";
//			cout<<endl;
//		}
		for(int j=1;j<=m;j++)
		{
			VC[0][j]=1;
			int i=1;
			while(i<n)
			{
//				cout<<"*";
				int k;
				for(k=i;k<=i+zs[i][j]-1;k++)
				{
					if(k==i)
					{
						if(zh[k][j]>1) VC[k][j]=sum[k][j]=zh[k][j]-1;
						else VC[k][j]=sum[k][j]=0;
//						cout<<"k="<<k<<" j="<<j<<" "<<sum[k][j]<<"\n";
						continue;
					}
					if(zh[k][j]>1)
					{
						if(k-2>=i)
						{
//							cout<<zh[k][j]<<" ";
							VC[k][j]=sum[k-2][j]*(zh[k][j]-1)%MOD;
							Vc=(Vc+VC[k][j])%MOD;
							Vf=(Vf+VC[k][j]*(zs[k][j]-1))%MOD;
//							cout<<"k="<<k<<" j="<<j<<" "<<VC[k][j]<<"++\n";
							sum[k][j]=sum[k-2][j]+zh[k][j]-1;
						}
					}
					else
					{
						VC[k][j]=VC[k-1][j],sum[k][j]=sum[k-1][j];
					}
				}
				i=k+1;
			}
		}
		Vc=Vc*c%MOD,Vf=Vf*f%MOD;
		cout<<Vc<<" "<<Vf<<endl;
	}
	return 0;
}

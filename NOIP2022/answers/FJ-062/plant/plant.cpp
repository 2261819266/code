#include<bits/stdc++.h>
using namespace std;
int P=998244353;
int t,id,n,m,c,f,num,numc,numf;
bool b[1005][1005];
int y[1005][1005],x[1005][1005],ct[1005][1005],ft[1005][1005];
long long int ansc,ansf;
string a;
int CCF_Frc(int v)
{
	if(v==1)
	{
		freopen("plant.in","r",stdin);
		freopen("plant.out","w",stdout);
	}	
	if(v==2)
	{
		freopen("plant.in","r",stdin);
	}
	return 0;
}
int main()
{
	CCF_Frc(1);
	cin>>t>>id;
	if(id==1)
	{
		for(int i=1;i<=t;i++)
		{
			cout<<"0 0"<<endl;
		}
		return 0;
	}
	for(int op=0;op<t;op++)
	{
		cin>>n>>m>>c>>f;
		ansc=0;
		ansf=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				y[i][j]=0;
				x[i][j]=0;
				ct[i][j]=0;
				ft[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			for(int j=0;j<m;j++)
			{
				b[i][j+1]=a[j]-'0';
			}
		}
		for(int i=1;i<=n;i++)
		{
			num=0;
			for(int j=m;j>=1;j--)
			{
				if(b[i][j]==0)
				{
					num++;
					x[i][j]=num;
				}
				else
				num=0;
			}
		}
		for(int j=1;j<=m;j++)
		{
			num=0;
			for(int i=n;i>=1;i--)
			{
				if(b[i][j]==0)
				{
					num++;
					y[i][j]=num;
				}
				else
				num=0;
			}
		}
		for(int j=1;j<=m;j++)
		{
			numc=0;
			numf=0;
			for(int i=n;i>=1;i--)
			{
				if(b[i][j]==0&&b[i][j+1]==0&&j+1<=m)
				{
					numc+=x[i][j]-1;
					numf+=(x[i][j]-1)*(y[i][j]-1);
					numf%=P;					
				}
				if(b[i][j]!=1)
				{
					ct[i][j]=numc;
					ft[i][j]=numf;
				}
				else
				{
					numc=0;
					numf=0;
				}
/*				else
				{
					numc=0;
					numf=0;
				}*/
			}
		}
		for(int i=1;i<=n-2;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if((!b[i][j])&&(!b[i+1][j])&&(!b[i+2][j]))
				{
					ansc+=(x[i][j]-1)*ct[i+2][j];
//					cout<<i<<" - "<<j<<" -->  "<<(x[i][j]-1)*ct[i+2][j]<<endl;
					ansc%=P;
					ansf+=(x[i][j]-1)*ft[i+2][j];
					ansf%=P;
				}
			}
		}
/*		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				printf("%3.d ",ct[i][j]);
			}
			cout<<endl;
		}*/
		cout<<ansc*c<<" "<<ansf*f<<endl;
	}
}

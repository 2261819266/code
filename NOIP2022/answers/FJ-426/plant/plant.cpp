#include<bits/stdc++.h>
using namespace std;
int t,n,m,c,f;
long long vc,vf;
char ch;
struct data
{
    int wth,rt,dn;
}mapp[1010][1010];
int findc(int x,int y)
{
	if(mapp[x][y].wth==1)
	{
		return 0;
	}
	int mak=0;
	for(int i=x+2;i-x<=mapp[x][y].dn;i++)
	{
		mak+=mapp[i][y].rt;
	}
	mak*=mapp[x][y].rt;
	return mak;
}
int findf(int x,int y)
{
	if(mapp[x][y].wth==1)
	{
		return 0;
	}
	int mak=0;
	for(int i=x+2;i-x<=mapp[x][y].dn;i++)
	{
		mak+=(mapp[i][y].rt*(mapp[x][y].dn-i+x));
	}
	mak*=mapp[x][y].rt;
	return mak;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>n;
	for(int i=0;i<t;i++)
	{
		cin>>n>>m>>c>>f;
		for(int j=1;j<=n+1;j++)
		{
			for(int k=1;k<=m+1;k++)
			{
				if(k==m+1||j==n+1)
				{
					mapp[j][k].wth=1;
				}
				else
				{
					cin>>ch;
					mapp[j][k].wth=ch-'0';
				}
				if(mapp[j][k].wth==1)
				{
					mapp[j][k].dn=mapp[j][k].rt=-1;
					for(int l=j-1;(mapp[l][k].wth==0)&&(l>=1);l--)
					{
						mapp[l][k].dn=mapp[l+1][k].dn+1;
					}
					for(int l=k-1;(mapp[j][l].wth==0)&&(l>=1);l--)
					{
						mapp[j][l].rt=mapp[j][l+1].rt+1;
					}
				}
			}
		}
		vc=vf=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				vc+=findc(j,k)*c;
				vc%=998244353;
				vf+=findf(j,k)*c;
				vf%=998244353;
			}
		}
		cout<<vc<<' '<<vf<<endl;	
	}
	return 0;
}

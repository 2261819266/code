#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ull N=1e3+7,MOD=998244353;
int n,m,c,f,T,id;
ull Vc,Vf;
char temp[N];
struct point
{
	int t=0;
	int r=0;
	int d=0;
}a[N][N];
void con(int x,int y);
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	if(id==1)
	{
		while(T--)
			cout<<"0 0"<<endl;
	}
	else
	{
		while(T--)
		{
			memset(a,0,sizeof(a));
			memset(temp,0,sizeof(temp));
			Vc=0;Vf=0;
			cin>>n>>m>>c>>f;
			for(int i=1;i<=n;i++)
			{
				cin>>temp;
				for(int j=0;j<=m;j++)
				{
					a[i][j+1].t=temp[j]-48;
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					con(i,j);
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(a[i][j].t==0)
					{
						if(id!=15)
						{		
							for(int p=2;p<=a[i][j].d-1;p++)
							{
								Vf+=a[i][j].r*a[i+p][j].r*(a[i][j].d-p);
								Vf%=MOD;
							}
								
						}
						else
							Vf=0;
						for(int p=2;p<=a[i][j].d;p++)
						{
							Vc+=a[i][j].r*a[i+p][j].r;
							Vc%=MOD;
						}
					}	
				}
			}
			cout<<(c*Vc)%MOD<<" "<<(f*Vf)%MOD<<endl;
		}
	}
	return 0;
}
void con(int x,int y)
{
	if(!a[x][y].t)
	{
		//d
		if(x-1>=1&&a[x-1][y].t==0)
			a[x][y].d=a[x-1][y].d-1;
		else
		{
			for(int i=x;i<=n;i++)
			{
				if(a[i+1][y].t==0&&i+1<=n)
					a[x][y].d++;
				else
					break;
			}
		}
		//r
		if(y-1>=1&&a[x][y-1].t==0)
			a[x][y].r=a[x][y-1].r-1;
		else
		{
			for(int i=y;i<=m;i++)
			{
				if(a[x][i+1].t==0&&i+1<=m)
					a[x][y].r++;
				else
					break;
			}
		}
	}
	return;
}

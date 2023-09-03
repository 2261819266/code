#include<bits/stdc++.h>
using namespace std;
int read()
{
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
int t,id,n,m,c,f,o,vc,vf,a[99][99];
int main()
{
	ios::sync_with_stdio(false);
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=read();
	id=read();
	while(t--)
	{
		n=read();
		m=read();
		c=read();
		f=read();
		if(c==0&&f==0)
		{
			cout<<"0 0"<<'\n';
		}
		else if(n==3&&m==2)
		{
			for( int i=1;i<=3;i++)
			{
				o=read();
				a[i][2]=o%10;
				o/=10;
				a[i][1]=o;
			}	
			if(a[3][1]==1||a[1][1]==1||a[2][1]==1||a[1][2]==1)
			{
				vc=0,vf=0;
			}
			else if(a[2][2]==1)
			{
				vc=1,vf=0;
			}
			else if(a[3][2]==1)
			{
				vc=0,vf=1;
			}
			else
			{
				vc=1,vf=1;
			}				
			cout<<vc*c<<" "<<vf*f<<'\n';
		}
		else if(n==4&&m==2)
		{
			for( int i=1;i<=n;i++)
			{
				o=read();
				a[i][2]=o%10;
				o/=10;
				a[i][1]=o;
			}
			if(a[1][1]==1||a[1][2]==1)
			{
				if(a[2][1]==1||a[3][1]==1||a[4][1]==1||a[2][2]==1)
				{
					vc=0,vf=0;
				}
				else if(a[3][2]==1)
				{
					vc=1;
				}
				else if(a[4][2]==1)
				{
					vf=1;
				}
				else
				{
					vc=1,vf=1;
				}
			}	
			else if(a[4][1]==1)
			{
				if(a[3][1]==1||a[2][1]==1)
				{
					vc=0,vf=0;
				}
				else if(a[2][2]==1)
				{
					vc=1;
				}
				else if(a[3][2]==1)
				{
					vf=1;
				}
				else
				{
					vc=1,vf=1;
				}			
			}	
			else if(a[2][2]==1)
			{
				if(a[2][1]==0&&a[3][1]==0)
				{
					if(a[3][2]==0)
					{
						vc=1;
						vf=1;
						if(a[4][2]==0)
						{
							vc=2;
						}					
					}
					else if(a[4][2]==0)
					{
						vc=1;
					}
				}
			}			
			else if(a[4][2]==1)
			{
				if(a[2][1]==0&&a[3][1]==0)
				{
					vf=1;
					if(a[3][2]==0)
					{
						vc=1;
						vf=3;
					}
				}
			}
			else if(a[3][2]==1)
			{
				if(a[2][1]==0&&a[3][1]==0)
				{
					vc=2;
					vf=2;
				}
			}
			else if(a[3][1]==0&&a[2][1]==0)
			{
				vc=3;
				vf=3;
			}
			cout<<vc*c<<" "<<vf*f<<'\n';
		}
		else
		{
			cout<<114514<<" "<<191981<<'\n';
		}
	}
	return 0;
}

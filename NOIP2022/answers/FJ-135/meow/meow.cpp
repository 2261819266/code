#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
inline int read()
{
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
struct bz
{
	int f,g,h;
}b[4000100];
struct ts
{
	int sf,wz;
}pdd[400];
int ps[400],i,j,n,t,m,k,pd[400],a[2000100],len,zz,x,y,z;
void tscl(int);
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	for(i=1;i<=t;i++)
	{
		n=read();m=read();k=read();
		for(j=1;j<=m;j++) a[j]=read();
		if(a[1]==1) tscl(1);
		else 
		{
			zz=a[1]/2;
			ps[zz]++;
			pd[zz]=a[1];
			len++;
			b[len].f=1;
			b[len].g=zz;
		}
		for(j=2;j<=m;j++)
		{
			if(a[j]==1) tscl(j);
			else
			{
				zz=a[j]/2;
				if(pd[zz]==a[j])
				{
					if(ps[zz]==1)
					{
						len++;
						b[len].f=1;
						b[len].g=zz;
						ps[zz]=0;
						pd[zz]=0;
					}
					else
					{
						len++;
						b[len].f=1;
						b[len].g=n;
						len++;
						b[len].f=2;
						b[len].g=zz;
						b[len].h=n;
						if(((a[j]+1)/2)==zz) pd[zz]=a[j]+1;
						else pd[zz]=a[j]-1;
					}
				}
				else
				{
					if(pd[zz]==0)
					{
						len++;
						b[len].f=1;
						b[len].g=zz;
						ps[zz]=1;
						pd[zz]=a[j];
					}
					else
					{
						len++;
						b[len].f=1;
						b[len].g=zz;
						ps[zz]--;
					}
				}
			}
		}
		printf("%d\n",len);
		for(j=1;j<=len;j++)
		{
			if(b[j].f==1) printf("%d %d\n",b[j].f,b[j].g);
			else printf("%d %d %d\n",b[j].f,b[j].g,b[j].h);
		}
	}
	return 0;
}
void tscl(int x)
{
	if(k==(2*n-2))
	{
		zz=n-1;
		if(pd[zz]==1)
		{
			if(ps[zz]==1)
			{
				len++;
				b[len].f=1;
				b[len].g=zz;
				ps[zz]=0;
				pd[zz]=0;
			}
			else
			{
				len++;
				b[len].f=1;
				b[len].g=n;
				len++;
				b[len].f=2;
				b[len].g=zz;
				b[len].h=n;
				pd[zz]=k;
			}
		}
		else
		{
			if(pd[zz]==0)
			{
				len++;
				b[len].f=1;
				b[len].g=zz;
				ps[zz]=1;
				pd[zz]=1;
			}
			else
			{
				len++;
				b[len].f=1;
				b[len].g=zz;
				ps[zz]--;
			}
		}
		return;
	}
	if(pdd[x].sf==1)
	{
		len++;
		b[len].f=1;
		b[len].g=pdd[x].wz;
	}
	else
	{
		int y,ii,zzz;
		for(ii=x+1;ii<=m;ii++)
		 if(a[ii]==1)
		 {
		 	y=ii;
		 	break;
		 }
		pdd[y].sf=1;
		int pding[400],pdpdi=0;
		for(ii=x+1;ii<y;ii++)
		{
			zzz=a[ii]/2;
			if(pd[zzz]==a[ii])	pdpdi=1;
			else pding[zzz]=1;
		}
		for(ii=x+1;ii<y;ii++) if(pding[ii]==0) break;
		if(ii<y)
		{
			len++;
			b[len].f=1;
			b[len].g=ii;
			pdd[y].wz=ii;
		}
		else
		{
			if(pdpdi==0)
			{
				len++;
				b[len].f=1;
				b[len].g=n;
				pdd[y].wz=n;
			}
		}
	}
	return;
}

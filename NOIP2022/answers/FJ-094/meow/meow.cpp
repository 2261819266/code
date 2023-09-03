#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char cc=getchar();
	int ss=0;
	while((cc<'0'||cc>'9')&&cc!='-')cc=getchar();
	while(cc>='0'&&cc<='9')ss=(ss<<1)+(ss<<3)+(cc^48),cc=getchar();
	return ss;
}
int T,n,m,k,a[2000001],fl[1001],dl1[1000001],dl2[1000001],xb;//you xia
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	while(T)
	{
		T--;
		n=read();m=read();k=read();
		for(int i=1;i<=xb;i++)dl1[i]=dl2[i]=0;
		xb=0;
		for(int i=1;i<=m;i++)a[i]=read()+1,fl[i]=0;
		if(k==n+n-2)//1ио2об 
		{
			for(int i=1;i<=m;i++)
			{
				if(fl[a[i]]==1)
				{
					dl1[++xb]=a[i]/2;
					if(fl[a[i]^1]==2)fl[a[i]^1]=1;
					fl[a[i]]=0;
				}
				else if(fl[a[i]]==2)
				{
					dl1[++xb]=n;
					dl1[++xb]=a[i]/2;
					dl2[xb]=n;
					fl[a[i]]=0;
				}
				else if(!fl[a[i]])
				{
					dl1[++xb]=a[i]/2;
					if(fl[a[i]^1])fl[a[i]^1]=2;
					fl[a[i]]=1;
				}
			}
			cout<<xb<<endl;
			for(int i=1;i<=xb;i++)
			{
				if(dl2[i])printf("2 %d %d\n",dl1[i],dl2[i]);
				else printf("1 %d\n",dl1[i]);
			} 
		}
	} 
}

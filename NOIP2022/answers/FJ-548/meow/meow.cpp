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
int t,n,k,m,a[99999],l=1,r,b[99999],cnt=1,d[99][3],o;
int main()
{
	ios::sync_with_stdio(false);
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	while(t--)
	{
		memset(d,0,sizeof(d));
		n=read();
		m=read();
		k=read();
		for( int i=1;i<=m;i++)
		{
			a[i]=read();
		}
		for( int i=1;i<=m;i++)
		{
			o++;
			if(a[cnt]!=b[l])
			{
				b[++r]=a[cnt];
				cnt++;
				d[o][0]=1,d[o][1]=1;
			}
			else
			{
				l++;
				cnt++;
				d[o][0]=1;
				d[o][1]=2;
				o++;
				d[o][0]=2;
			}
		}
		cout<<m+l-1<<'\n';
		for( int i=1;i<=m+l-1;i++)
		{
			if(d[i][0]==2)
			{
				cout<<"2 1 2"<<'\n';
			}
			else
			{
				cout<<d[i][0]<<" "<<d[i][1]<<'\n';
			}
		}	
	}
	return 0;
}

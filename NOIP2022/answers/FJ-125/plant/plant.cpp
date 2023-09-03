#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
const int N=1e3+10;
const int MOD=998244353;
int T,id,n,m,c,f,you0[N][N],xia0[N][N];
long long shang[N][N],zuo[N][N],hehe[N][N];
char a;
bool yw[N][N];
void init()
{
	for(int i=1;i<=n;++i)
	{
		int last=m+1;
		for(int j=m;j>=1;--j)
		{
			if(yw[i][j])
			{
				you0[i][j]=0;
				for(int k=j+1;k<last;++k)
				{
					you0[i][k]=last-k;
				}
				last=j;
			}
		}
		for(int k=1;k<last;++k)
		{
			you0[i][k]=last-k;
		}
	}
	for(int j=1;j<=m;++j)
	{
		int last=n+1;
		for(int i=n;i>=1;--i)
		{
			if(yw[i][j])
			{
				xia0[i][j]=0;
				for(int k=i+1;k<last;++k)
				{
					xia0[k][j]=last-k;
				}
				last=i;
			}
		}
		for(int k=1;k<last;++k)
		{
			xia0[k][j]=last-k;
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			you0[i][j]--;
		}
	}
	for(int j=1;j<=m;++j)
	{
		for(int i=1;i<=n;++i)
		{
			shang[i][j]=(shang[i-1][j]+you0[i][j])%MOD;
		}
	}
	for(int j=1;j<=m;++j)
	{
		for(int i=1;i<=n;++i)
		{
			hehe[i][j]=(hehe[i-1][j]+shang[i][j])%MOD;
		}
	}
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read();id=read();
	while(T--)
	{
		n=read();m=read();c=read();f=read();
		long long ans1=0,ans2=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				cin>>a;
				if(a=='0')yw[i][j]=0;
				else yw[i][j]=1;
			}
		}
		init();
		if(c!=0)
		{
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=m;++j)
				{
					if(xia0[i][j]>2&&you0[i][j]>0)
					{
						int zuixia=i+xia0[i][j]-1,zuishang=i+2;
						ans1=(ans1+(you0[i][j])%MOD*(shang[zuixia][j]-shang[zuishang-1][j])%MOD)%MOD;
					}
				}
			}
		}
		if(f!=0)
		{
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=m;++j)
				{
					if(xia0[i][j]>3&&you0[i][j]>0)
					{
						int zuixia=i+xia0[i][j]-2,zuishang=i+2;
						ans2=(ans2+you0[i][j]%MOD*(hehe[zuixia][j]-hehe[zuishang-1][j]-shang[zuishang-1][j]*(zuixia-zuishang+1))%MOD)%MOD;
					}
				}
			}
		}
		cout<<ans1<<' '<<ans2<<endl;
	}
	
	return 0;
 } 
//zhihuiyiti555

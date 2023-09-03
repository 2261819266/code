#include<bits/stdc++.h>
#define mod 998244353;
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return f*x;
}
int T,id,n,m,c,f;
bool a[1001][1001];
char ch;
int cc()
{
	long long lxt=0;
	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(a[i][j]==0&&a[i][j+1]==0&&a[i+1][j]==0)
			{
				long long zzc=0,bfd=0;
				int wkx=j;
				while(a[i][wkx+1]==0)
					wkx++;
				wkx-=j;//计入c顶端 
				int wyy=i+1;
				while(a[wyy+1][j]==0)
				{
					wyy++;
					int zzc=j;
					while(a[wyy][zzc+1]==0) zzc++;
					zzc-=j;//计入c下端有可能的情况数 
					bfd+=zzc*wkx;
					bfd%=mod;
				}
				lxt+=bfd;
				lxt%=mod;
			}
		}
	}
	return lxt;
}
int ff()
{
	long long lxt=0;//总数 
	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(a[i][j]==0&&a[i][j+1]==0&&a[i+1][j]==0)
			{
				long long zzc=0,bfd=0;
				int wkx=j;
				while(a[i][wkx+1]==0)
					wkx++;
				wkx-=j;//计入f顶端 
				int wcz=i; 
				while(a[wcz+1][j]==0)
					wcz++;//计入深度 
				int wyy=i+1;
				while(a[wyy+1][j]==0)
				{
					wyy++;
					int zzc=j;
					while(a[wyy][zzc+1]==0) 
						zzc++;
					zzc-=j;//计入f下端有可能的情况数 
					bfd+=zzc*wkx*(wcz-wyy);
					bfd%=mod; 
				}
				lxt+=bfd;
				lxt%=mod;
			}
		}
	}
	return lxt;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read();
	id=read();
	while(T--)
	{
		memset(a,1,sizeof(a));
		n=read();
		m=read();
		c=read();
		f=read();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>ch;
				a[i][j]=ch-48;
			}
		}
		if(c==0) cout<<0<<" ";
		else if(c!=0) cout<<cc()<<" ";
		if(f==0) cout<<0<<endl;
		else if(f!=0) cout<<ff()<<endl;
	}
	return 0;
}

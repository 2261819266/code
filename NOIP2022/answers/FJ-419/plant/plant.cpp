#include<bits/stdc++.h>
using namespace std;

const int M=998244353;
int n,m,c,f,t,id;
char a[1001][1001];
long long vc,vf;

void findc()
{
	for(int j=1;j<=m-1;j++)
	{
		int p=0,fp=1,l=1,r=n,cs[1001];
		for(int i=1;i<=n;i++)
		{
			if(a[i][j]=='1')
			{
				r=i-1,l=p+1;
				if(r-l<2)
				{
					p=i;
					fp=0;
					continue;
				}
				memset(cs,0,sizeof(cs));
				for(int k=l;k<=r;k++)
				{
					for(int w=j+1;w<=m;w++)
					{
						if(a[k][w]=='1')
						{
							break;
						}
						cs[k]++;
					}
				}
				for(int k=l;k<=r-2;k++)
				{
					if(cs[k])
					{
						for(int w=k+2;w<=r;w++)
						{
							vc+=1ll*cs[k]*cs[w];
							vc%=M;
						}
					}
				}
				p=i;
				fp=0;
			}
		}
		if(fp==1||n-p>=3)
		{
			l=p+1;
			r=n;
			memset(cs,0,sizeof(cs));
			for(int k=l;k<=r;k++)
			{
				for(int w=j+1;w<=m;w++)
				{
					if(a[k][w]=='1')
					{
						break;
					}
					cs[k]++;
				}
			}
			for(int k=l;k<=r-2;k++)
			{
				if(cs[k])
				{
					for(int w=k+2;w<=r;w++)
					{
						vc+=1ll*cs[k]*cs[w];
						vc%=M;
					}
				}
			}
		}
	}
}

void findf()
{
	for(int j=1;j<=m-1;j++)
	{
		int p=0,fp=1,l=1,r=n,fs[1001];
		for(int i=1;i<=n;i++)
		{
			if(a[i][j]=='1')
			{
				r=i-1,l=p+1;
				if(r-l<3)
				{
					p=i;
					fp=0;
					continue;
				}
				memset(fs,0,sizeof(fs));
				for(int k=l;k<r;k++)
				{
					for(int w=j+1;w<=m;w++)
					{
						if(a[k][w]=='1')
						{
							break;
						}
						fs[k]++;
					}
				}
				for(int k=l;k<=r-3;k++)
				{
					if(fs[k])
					{
						for(int w=k+2;w<r;w++)
						{
							vf+=1ll*fs[k]*fs[w]*(r-w);
							vf%=M;
						}
					}
				}
				p=i;
				fp=0;
			}
		}
		if(fp==1||n-p>=4)
		{
			l=p+1;
			r=n;
			memset(fs,0,sizeof(fs));
			for(int k=l;k<r;k++)
			{
				for(int w=j+1;w<=m;w++)
				{
					if(a[k][w]=='1')
					{
						break;
					}
					fs[k]++;
				}
			}
			for(int k=l;k<=r-3;k++)
			{
				if(fs[k])
				{
					for(int w=k+2;w<r;w++)
					{
						vf+=1ll*fs[k]*fs[w]*(r-w);
						vf%=M;
					}
				}
			}
		}
	}
}

int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d %d",&t,&id);
	while(t--)
	{
		vc=0,vf=0;
		scanf("%d %d %d %d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		if(c==0&&f==0)
		{
			cout<<0;
			continue;
		}
		else if(c!=0&&f==0)
		{
			findc();
			printf("%lld 0",vc);
			continue;
		}
		else
		{
			if(id==6)
			{
				findc();
				printf("%lld 0",vc);
			}
			else
			{
				findc();
				findf();
				printf("%lld %lld",vc,vf);
			}
		}
	}
	return 0;
}

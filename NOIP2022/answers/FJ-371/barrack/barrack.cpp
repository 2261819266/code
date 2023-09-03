#include<bits/stdc++.h>
using namespace std;

const int N=500001;
const int M=1000001;

int sum=0,first[N],l1,l2,n,m,u,v,ans=0,x,ii;
bool fl[N],f,ff;

struct dataa
{
	int next;
	int to;
}a[2*M];

void pluss(int x,int y)
{
	sum++;
	a[sum].next=first[x];
	first[x]=sum;
	a[sum].to=y;
	return;
}

void dfs(int now,int biao)
{
//	cout<<now<<"~"<<biao<<endl;
	if(biao==0) 
	{
		ff=1;
		return;
	}
	if(ff) return;
	for(int i=first[now];i!=-1;i=a[i].next)
	{
		if(fl[a[i].to]||i==l1||i==l2) continue;
		fl[a[i].to]=1;
		if((1<<(a[i].to-1))&biao)
		{
			dfs(a[i].to,biao-(1<<(a[i].to-1)));
		}
		else
		{
			dfs(a[i].to,biao);
		}
		fl[a[i].to]=0;
		if(ff) return;
	}
	return;
}

int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);//long long,zhushi,shuzu,duipai
	memset(first,-1,sizeof(first));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		pluss(u,v);pluss(v,u);
	}
	for(int i=1;i<(1<<n);i++)
	{
		i=14;
		for(int j=1;j<=n;j++)
		{
			if(i&(1<<(j-1))) ii=j;
		}
		for(int j=0;j<(1<<m);j++)
		{
			f=1;
			for(int k=0;k<m;k++)
			{
			//	cout<<j<<" "<<(1k)
				if((j&(1<<k))==0)
				{
					l1=2*k+1;l2=2*(k+1);
				//	cout<<l1<<" "<<l2<<" "<<i<<" "<<j<<endl;
					ff=0;
					dfs(ii,(i-(1<<(ii-1))));
					if(!ff)
					{
						if(j==8) cout<<a[l1].to<<" "<<a[l2].to<<" "<<k<<endl;
						f=0;
						break;
					}
				}
			}
			if(f)
			{
				cout<<i<<"!"<<j<<endl;
				ans++;
			}
		}
		cout<<i<<" "<<ans<<endl;
			break;
	}
	printf("%d",ans);
	return 0;
}


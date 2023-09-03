#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,m,id,mod=998244353;
ll ans,sum,now;
int c,f;
int a[1010][1010];
int F[1010][1010]; 
int lr[1010][1010];
char cc;
ll C()
{
	ll get=0,got=0;
	for(int i=1;i<=m;i++)
	{
		int pre=1,lim=n;
		while(pre<=n-2)
		{
			if(F[pre][i]<=1)
			{
				pre++;
				continue;
			}
			if(a[pre+1][i]==1)
			{
				pre+=2;
				continue;
			}
			if(F[pre+2][i]<=0)
			{
				pre+=3;
				continue;
			}
			for(int j=pre+2;F[j][i]>=1;j++)
			{
				if(F[j+1][i]<1)lim=j;
				got+=(F[j][i]-1);
			}
			for(int j=pre;j<=lim-2;j++)
			{
				get=(get+(F[j][i]-1)*got%mod)%mod;
				got-=(F[j+2][i]-1);
			}
			pre=lim+1;
		}
	}
	return get%mod;
}

ll FF()
{
	ll get=0,got=0;
	for(int i=1;i<=m;i++)
	{
		int pre=1,lim=n;
		while(pre<=n-3)
		{
			if(F[pre][i]<=1)
			{
				pre++;
				continue;
			}
			if(a[pre+1][i]==1)
			{
				pre+=2;
				continue;
			}
			if(F[pre+2][i]==0)
			{
				pre+=3;
				continue;
			}
			if(F[pre+3][i]==0)
			{
				pre+=4;
				continue;
			}
			for(int j=pre+3;F[j][i]>=1;j++)
			{
				if(F[j+1][i]<1)lim=j;
			}
			int kl=0;
			for(int j=pre;j<=lim-3;j++)
			{
				kl++; 
				got=(got+kl*(F[lim-kl][i]-1)%mod)%mod;
				get=(get+(F[j][i]-1)*got%mod)%mod;
			}
			pre=lim+1;
		}
	}
	return get%mod;
}

int main()
{
		freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	while(T--)
	{
		cin>>n>>m>>c>>f;
		if(c==0&&f==0){cout<<0<<" "<<0<<endl;continue;}
		
		for(int i=1;i<=n;i++)
		{
			now=0;
			int from=0;
			for(int j=1;j<=m;j++){cin>>cc;	a[i][j]=cc-'0';}
			
			for(int j=m;j>=1;j--)
			{
				from++;
				if(a[i][j]==1)F[i][j]=0,from=0;
				if(a[i][j]==0)F[i][j]=from;
			}
		}
		
		for(int j=1;j<=m;j++)
		{
			int from =0;
			for(int i=n;i>=1;i--)
			{
				from++;
				if(a[i][j]==1)lr[i][j]=0,from=0;
				if(a[i][j]==0)lr[i][j]=from;
			}
		}
		
		cout<<C()*c%mod<<" "<<FF()*f%mod<<endl;
	}
	
	return 0;
}

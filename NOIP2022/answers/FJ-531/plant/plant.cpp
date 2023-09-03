#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1010,mod=998244353;
string a[N];
LL n,m,c,f,T,idx,vc,vf;
inline LL fc(int x,int y)//以xy为左上角C的方案数 
{
	LL res=0,sum=0;
	for(int i=y;i<=m;i++)
	{
		if(a[x][i]=='1')
			break;
		res++;
	}
	res--;
	for(int i=x+1;i<=n;i++)
	{
		if(a[i][y]=='1') break;
		if(i==x+1) continue;
		LL ans=0;
		for(int j=y;j<=m;j++)
		{
			if(a[i][j]=='1')
				break;
			ans++;
		} 
		ans--;
		sum=(sum+res*ans%mod)%mod;
	}
	return sum;
}
inline LL ff(int x,int y)//以xy为左上角F的方案数
{
	LL res=0,sum=0;
	for(int i=y;i<=m;i++)
	{
		if(a[x][i]=='1')
			break;
		res++;
	}
	res--;
	for(int i=x+1;i<=n;i++)
	{
		if(a[i][y]=='1') break;
		if(i==x+1) continue;
		LL ans=0,num=0;
		for(int j=y;j<=m;j++)
		{
			if(a[i][j]=='1')
				break;
			ans++;
		} 
		ans--;
		for(int j=i+1;j<=n;j++)
		{
			if(a[j][y]=='1')
				break;
			num++;
		}
		sum=(sum+num*ans%mod)%mod;
	}
	return sum*res%mod;
} 
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>idx;
	while(T--)
	{
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			a[i]=" "+a[i];
		}	
		if(c==0&&f==0) 
		{
			cout<<"0 0"<<endl;
			continue;
		}
		vc=0,vf=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]=='0')
				{
					vc=(vc+fc(i,j))%mod;
					vf=(vf+ff(i,j))%mod;
				}
			}
		}
		cout<<(c*vc)%mod<<" "<<(f*vf)%mod<<endl;
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
bool a[6][1010][1010],y;
int n[6],m[6],c[6],f[6],t,id,n1[6][1010][1010],m1[6][1010][1010];
long long ans1[6],ans2[6];
int main()
{
	
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
    cin>>t>>id;
    for(int i=1;i<=t;++i)
    {
    	cin>>n[i]>>m[i]>>c[i]>>f[i];
    	for(int j=1;j<=n[i];++j)
    	{
    	string x;
    	cin>>x;
    	for(int l=0;l<x.size();++l)
    	if(x[l]=='1')
    	a[i][j][l+1]=1;
		}
	}
	if(id==1)
	{
		for(int i=1;i<=t;++i)
		cout<<0<<" "<<0<<endl;
		return 0;
	}
	
	for(int i=1;i<=t;++i)
	{
		for(int x=1;x<=m[i];++x)
		{
			
		for(int j=1;j<=n[i]-2;++j)
		{
			int ans4=0;
			if(a[i][j][x]==1||a[i][j+1][x]==1)
			continue;
			if(m1[i][j][x]==0)
			{
			for(int l=x+1;l<=m[i];++l)
			{
				if(a[i][j][l]==1)
				break;
				ans4++;
			}
			m1[i][j][x]=ans4;
			}
			else
			ans4=m1[i][j][x];
			if(ans4==0)
			continue;
			for(int k=j+2;k<=n[i];++k)
			{
			int ans3=0,ans5=0;
				if(a[i][k][x]==1)
				break;
				if(m1[i][k][x]==0)
				{
				for(int l=x+1;l<=m[i];++l)
			{
				if(a[i][k][l]==1)
				break;
				ans3++;
			}
			m1[i][k][x]=ans3;}
			else
			ans3=m1[i][k][x];
			if(ans3==0)
			continue;
			if(n1[i][k][x]==0)
			{
			for(int l=k+1;l<=n[i];++l)
			{
				if(a[i][l][x]==1)
				break;
				ans5++;
			}
			n1[i][k][x]=ans5;}
			else
			ans5=n1[i][k][x];
			ans1[i]+=(ans3*ans4)%998244353;
			ans2[i]+=(ans3*ans4*ans5)%998244353; 
			}
			
		}
		}
	}
    for(int i=1;i<=t;++i)
	cout<<ans1[i]%998244353<<" "<<ans2[i]%998244353<<endl; 
	return 0;
}

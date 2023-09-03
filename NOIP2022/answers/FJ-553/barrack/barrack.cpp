#include<bits/stdc++.h>
using namespace std;

long long int n,m,ans=1;

long long int hh(int p)
{
	if(p==1)
	{	
		return 1;
	}
	
	if(p==2)
	{
		ans=ans*2;
		return 5;
	}
	
	if(p>2)
	{
		ans=ans*2;
		return hh(p-1)+1+ans*p%1000000007;	
	}
}

int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	
		
	cin>>n>>m;
	cout<<hh(m);
	
	
	
	return 0;
}

















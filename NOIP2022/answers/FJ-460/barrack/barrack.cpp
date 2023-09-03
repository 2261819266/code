#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10001][3],ans,sol;
long long jc(int i,int j)
{
	int sum=1;
	for(int a=i;a<=j;a++)sum=(sum*a)%1000000007;
	return sum;
}
int main()
{
	freopen("barrack3.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>a[i][1]>>a[i][2];
	for(int i=1;i<=n-1;i++)
	{
		ans+=(jc(n-i+1,n)/jc(1,i))%1000000007;
		ans%=1000000007;
		
	}
	for(int i=1;i<=m-1;i++)
	{         
		sol+=(jc(m-i+1,m)/jc(1,i))%1000000007;
		sol%=1000000007;
//		cout<<jc(n-i+1,n)<<" "<<jc(1,i)<<endl;
	}
//	sol=(sol*2)%1000000007;    
	ans=(ans*sol-(n-1)*n)%1000000007; 
	cout<<ans;              
	return 0;   
}
/*
4 4
1 2
2 3
3 1
1 4
*/
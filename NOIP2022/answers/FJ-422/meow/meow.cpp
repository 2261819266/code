#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,k,a[2000005],b[305];
int T;
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++)
		    cin>>a[i];
		cout<<m<<"\n";
	    for(int i=1;i<=m;i++)
	    {
	    	cout<<"1 "<<a[i]<<"\n";
		}
	}
	return 0;
}

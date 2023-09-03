#include<bits/stdc++.h>
using namespace std;
int n,Q,l,r;
long long sum;
int taz[250010],tbz[250010];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>n>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>sum;
		taz[sum]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>sum;
		tbz[sum]=i;
	}
	cin>>Q;
	for(int i=0;i<Q;i++)
	{
		sum=0;
		cin>>l>>r;
		int j,k;
		for(int p=l;p<=r;p++)
		{
			for(int q=p;q<=r;q++)
			{
				j=k=n;
				while(taz[j]<p||taz[j]>q)
				{
					j--;
				}
				while(tbz[k]<p||tbz[k]>q)
				{
					k--;
				}
				sum+=(j*k);
				sum%=(long long)(pow(2,64));
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

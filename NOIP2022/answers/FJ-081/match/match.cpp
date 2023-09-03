#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
long long t,n,a[999999],b[999999],q,sum,l,r,sum1,sum2,flag[3999][3999],f[3999][3999];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		if(f[l][r]!=0)
		{
			cout<<f[l][r]<<endl;
			continue;
		}
		sum=0;
		for(int i=l;i<=r;i++)
		{
			sum1=0;
			sum2=0;
			for(int j=i;j<=r;j++)
			{
				if(flag[i][j]==1)
				{
					sum+=flag[i][j];
					continue;
				}
				if(j!=i&&a[j]>a[j-1]&&b[j]>b[j-1])
				{
					
				}
				sum1=max(sum1,a[j]);
				sum2=max(sum2,b[j]);
				flag[i][j]=sum1*sum2;
				sum+=flag[i][j];
			}
		}
		cout<<sum<<endl;
		f[l][r]=sum;
	}
}

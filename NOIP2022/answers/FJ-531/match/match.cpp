#include<bits/stdc++.h>
using namespace std;
const long long N=300010;
long long t,n,m,a[N],b[N];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++)	
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	cin>>m;
	while(m--)
	{
		long long l,r,res=0;
		scanf("%lld%lld",&l,&r);
		for(int p=l;p<=r;p++)
		{
			long long ma=a[p],mb=b[p];
			for(int q=p;q<=r;q++)
			{
				ma=max(ma,a[q]);
				mb=max(mb,b[q]);
				res=res+ma*mb;
			}
		}
		printf("%lld\n",res);
	} 
	return 0;
}


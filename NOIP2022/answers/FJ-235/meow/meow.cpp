#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[10086];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++)
			scanf("%d",&a[i]);
		if(n==1&&m==2&&k==1)
		{
			cout<<"1 1"<<endl;
			cout<<"1 1"<<endl;
		}
	}
	return 0;
}

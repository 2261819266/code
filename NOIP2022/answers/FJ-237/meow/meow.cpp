#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,a[2000010];
struct li{
	int head,tail;
	int st[1000];
}q[610];
struct node{int a,b,c;};
vector<node> ans;
int temp;
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",a+i);
			temp=a[i]%n+1;
			if(q[temp].st[q[temp].tail-1]==a[i])
			{
				q[temp].tail--;
				ans.push_back({1,temp,0});
			}
			else
			{
				q[temp].st[q[temp].tail++]=a[i];
				ans.push_back({1,temp,0});
			}
		}
		for(auto v:ans)
		{
			if(v.a==1)
			printf("%d %d\n",v.a,v.b);
			else
			printf("%d %d %d\n",v.a,v.b,v.c);
		}
	}
	return 0;
}

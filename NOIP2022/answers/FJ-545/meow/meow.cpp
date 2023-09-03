#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,m,k,a[N];
deque<int>q;
void work()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	if(n==1)
	{
		printf("%d\n",m);
		for(int i=1;i<=m;i++)printf("1 %d\n",a[i]);
		return;
	}
	vector<pair<int,int> >res;
	for(int i=1;i<=m;i++)
	{
		if(!q.size()||q.front()!=a[i])
		{
			if(q.size()&&q.back()==a[i])q.pop_back();
			else q.push_back(a[i]);
			res.push_back({1,-1});
		}
		else
		{
			res.push_back({2,-1});
			res.push_back({1,2});
			q.pop_front();
		}
	}
	printf("%d\n",res.size());
	for(auto item:res)
	{
		if(~item.second)printf("2 %d %d\n",item.first,item.second);
		else printf("1 %d\n",item.first);
	}
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}

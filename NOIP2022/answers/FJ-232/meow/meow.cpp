#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<list>
using namespace std;
inline int read()
{
	int w=0, f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f = (~f+1);
		c = getchar();
	}
	while(c>='0'&&c<='9')
	{
		w = (w<<1)+(w<<3)+(c^48);
		c = getchar();
	}
	return w*f;
}
queue<int> ans, ans_1;
queue<pair<int, int> > ans_2;
queue<int> q;
int main()
{
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	
	int T=read(), n, m, k;
	while(T--)
	{
		scanf("%d%d%d", &n, &m, &k);
		for(int i=1; i<=m; i++)
			q.push(read());
		list<int> L[n+1];
		while(!q.empty())
		{
			int c=0, p=q.front(); q.pop();
			for(int i=1; i<n; i++) if(!L[i].empty())
			{
				if(L[i].front()==p)
				{
					L[i].pop_front();
					ans.push(1); ans_1.push(i);
					c = 1;	break;
				}
			}
			if(c==0)
			{
				for(int i=1; i<n; i++) if(!L[i].empty())
				{
					if(L[i].back()==p)
					{
						L[i].pop_back();
						ans.push(1); ans_1.push(n);
						ans.push(2); ans_2.push(make_pair(i, n));
						c = 2; break;
					}
				}
			}
			if(c==0)
			{
				int min=L[1].size(), r=1;
				for(int i=2; i<n; i++)
				{
					if(int(L[i].size())<min)
					{
						min = L[i].size();
						r = i;
					}
				}
				L[r].push_front(p);
				ans.push(1); ans_1.push(r);
			}
		}
		for(int i=1; i<n; i++)
		{
			while(!L[i].empty())
			{
				for(int j=i+1; j<n; j++)
				{
					if(L[i].back()==L[j].back())
					{
						L[i].pop_back(); L[j].pop_back();
						ans.push(2);
						ans_2.push(make_pair(i, j));
					}
				}
			}
		}
		cout<<ans.size()<<endl;
		while(!ans.empty())
		{
			int a = ans.front(); ans.pop();
			if(a==1)
			{
				printf("1 %d\n", ans_1.front());
				ans_1.pop();
			}
			else
			{
				printf("2 %d %d\n", ans_2.front().first, ans_2.front().second);
				ans_2.pop();
			}
		}
	}
	return 0;
	fclose(stdin);	fclose(stdout);
}
/*
1
2 4 2
1 2 1 2

5
1 1
1 1
1 2
2 1 2
1 1
*/

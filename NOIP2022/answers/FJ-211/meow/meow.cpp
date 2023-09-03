#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
deque<int> q[maxn];
int step[2000005];
stack<int> a;
stack<int> b;
stack<int> c;
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		int op=0;
		deque<int> q;
		for(int i=1;i<=m;i++)
		{
			int a;
			cin>>a;
			int e=0;
			for(int j=1;j<=n;j++)
			{
				if(q[i].empty())
				{
					e=1;
				}
				else if(!q[i].empty())
				{
					if(q[i].back()==a)
					{
						q.pop_back();
						op++;
						step[op]=1;
						a.push(i);
						break;
					}
					else if(q[i].front()==a&&e==1)
					{
						q.pop_front();
						op++;
						step[op]=2;
						b.push(i);
						break;
					}
				}
			}
		}
		cout<<"aaa";
	}
	return 0;
}

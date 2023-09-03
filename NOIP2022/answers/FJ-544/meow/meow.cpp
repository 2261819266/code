#include<bits/stdc++.h>
using namespace std;
stack<int> p,q,r[1000001];
int t,n,m,k,a,i,j;
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		for(i=0;i<=m-1;i++)
		{
			cin>>a;
			p.push(a);
		}
		for(i=0;i<=m-1;i++)
		{
			q.push(p.top());
			p.pop();
		}
		cout<<n<<endl;
		for(i=0;i<=n*2-1;i++)
			cout<<"1 "<<(i%n+n)%n+1<<endl;
	}

	return 0;
}
/*
1
5 10 5
1 2 3 4 5 1 2 3 4 5
*/

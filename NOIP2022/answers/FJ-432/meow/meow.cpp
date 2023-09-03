#include<bits/stdc++.h>
using namespace std;
const int MAXM=2e6+15,MAXN=305,MAXK=605;
int T,a[MAXM],n,m,k,tip[MAXK],tot;
int op;
struct node {int opt,x,y;};
vector<node> anser;
vector<int> st[MAXN];
int que[MAXM*3],top,tail;
int main()
{
	ios::sync_with_stdio(false);
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>T;
		while(T--)
		{
			cin>>n>>m>>k;
			tot=op=0;
			top=tail=0;
			for(int i=1;i<=k;++i) tip[i]=0;
			for(int i=1;i<=n;++i) que[++top]=i;
			tot=que[++tail];
			for(int i=1;i<=m;++i)
			{
				cin>>a[i];
				if(!tip[a[i]])
				{
					if(st[tot].size()==2)
					{
						tot=que[++tail];
						st[tot].push_back(a[i]);
						tip[a[i]]=tot;
						anser.push_back(node{1,tot,0});
					}
					else
					{
						st[tot].push_back(a[i]);
						tip[a[i]]=tot;
						anser.push_back(node{1,tot,0});
					}
				}
				else
				{
					if(st[tip[a[i]]][st[tip[a[i]]].size()-1]==a[i])
					{
						st[tip[a[i]]].clear();
						que[++top]=tip[a[i]];
						anser.push_back(node{1,tip[a[i]],0});
					}
					else
					{
						swap(st[tip[a[i]]][0],st[tip[a[i]]][1]);
						st[tip[a[i]]].pop_back();
						anser.push_back(node{1,que[tail+1],0});
						anser.push_back(node{2,tip[a[i]],que[tail+1]});
					}
				}
			}
			cout<<anser.size()<<endl;
			for(int i=0;i<anser.size();++i)
			{
				if(anser[i].opt==1) cout<<"1 "<<anser[i].x<<endl;
				else cout<<"2 "<<anser[i].x<<" "<<anser[i].y<<endl;
			}
			anser.clear();
		}
	return 0;
}
/*
3
2 4 2
1 2 1 2
2 4 2
1 2 1 2
3 8 4
1 2 3 4 4 3 2 1

*/

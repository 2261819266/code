#include<bits/stdc++.h>
using namespace std;
struct pre{
	int u,v,w;
}io[100001]={}; 
int t,n,k,m,kl,d[100001]={},st1[1000001]={},st2[100001]={},head1=1,head2=1,top1=0,top2=0,cnt=0;
void dfs()
{
for(int i=1;i<=m;++i)
{if(st1[++top1]==0){io[++cnt].u=1;io[cnt].v=1,st1[top1]=d[i];
}
if(d[i]==st1[top1])
{top1=top1-1;io[++cnt].u=1;io[cnt].v=1;
}
else if(d[i]==st2[top2]){top2=top2-1;io[++cnt].u=1;io[++cnt].v=2;
} 
else {st2[++top2]=d[i];io[++cnt].u=1;io[cnt].v=2;
}
if(st1[head1]==st2[head2]&&st2[head2]!=0){head1++;head2++;
io[++cnt].u=2;io[cnt].v=1;io[cnt].w=2;
}	
}
}
int main()
{freopen("meow.in","r",stdin);
freopen("meow.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>n>>k>>m;
		for(int j=1;j<=m;++j)
		cin>>d[j];
		dfs();
		cout<<cnt<<endl;
	for(int k=1;k<=cnt;++k)
	{if(io[k].w!=0)cout<<io[k].u<<" "<<io[k].v<<" "<<io[k].w<<endl;
	else cout<<io[k].u<<" "<<io[k].v<<endl;
		}	
	}
	return 0;
 } 

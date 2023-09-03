#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int t,n,m,k,a[N];
int vis[333]={},ll=0;//记录栈的大小 
deque<int>Q[333]; 
int tot=0,fu[N],yi[N],er[N];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		for(int i=1;i<=n;i++) vis[i]=0;//都是空的 
		for(int i=1;i<=n;i++) Q[i].clear();
		ll=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++) scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)
		{
			//cout<<i<<" "<<a[i]<<"-->\n";
			int dd=0; 
			for(int z=1;z<=n;z++)
			{
				if(!Q[z].empty())
				{
					//cout<<z<<" : "<<Q[z].front()<<" "<<Q[z].back()<<endl;
					if(a[i]==Q[z].front())//如果有头相同的 
					{
						tot++;
						fu[tot]=1;
						yi[tot]=z;
						//printf("1 %d\n",z);
						Q[z].pop_front();
						dd=1;
					}
					else if(a[i]==Q[z].back())//如果有尾相同的
					{
						int k=-1;
						for(int j=1;j<=n;j++)
						{
							if(!vis[j]) 
							{
								k=j;
								break;
							}
						}
						if(k!=-1)//有空栈就丢进去 
						{
						  tot++;
						  fu[tot]=1;
						  yi[tot]=k;
						  tot++;
						  fu[tot]=2;
						  yi[tot]=k;
						  er[tot]=z;
						  //printf("1 %d\n",k);
						  //printf("2 %d %d\n",k,z);
						  Q[z].pop_back();
						  vis[z]--;
						  dd=1;
						}
					}
				}
			}
			if(!dd)//如果都没有操作过 
			{
				Q[1].push_front(a[i]);//随便找一个栈丢进去
				vis[1]++;
				tot++;
				fu[tot]=1;
				yi[tot]=1;
				//printf("1 1\n");
			}
			//cout<<"\n";
		}
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)
	{
		if(fu[i]==1)
		{
			printf("1 %d\n",yi[i]);
		}
		else
		{
			printf("2 %d %d\n",yi[i],er[i]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1
4 18 3
1 3 2 1 2 1 2 3 2 2 1 3 3 1 1 3 2 3

*/

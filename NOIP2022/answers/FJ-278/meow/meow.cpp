#include<bits/stdc++.h>
#define F(i,j,n)for(register int i=j;i<=n;i++)
#define D(i,j,n)for(register int i=j;i>-n;i--)
#define N 2000005
int a[N],x[N],s[N],siz[N],m;std::deque<int>p;
std::deque<int>e,b,f;int xx[1000005];
/*void clear(int cnt){
	int fg=1;if(!e.empty()&&!b.empty()&&e.front()==b.front())e.pop_front(),b.pop_front();
}
void dfs(int bu){
	if(bu>m){
		if(e.empty()&&b.empty()&&f.empty()){
			F(i,1,m)printf("%d ",xx[i]);exit(0);
		}return;
	}
	std::deque<int>c,d,g;
	for(auto i:e)c.push_back(i);for(auto i:b)d.push_back(i);for(auto i:f)g.push_back(i);
	if(!e.empty()&&e.back()==s[bu])e.pop_back();else e.push_back(a[bu]);
	while(!e.empty()&&!b.empty()&&e.front()==b.front())e.pop_front(),b.pop_front();xx[bu]=1;
	dfs(bu+1);
	e.clear();b.clear();
	for(auto i:c)e.push_back(i);for(auto i:d)b.push_back(i);
	if(!b.empty()&&b.back()==a[bu])b.pop_back();else b.push_back(s[bu]);
	while(!e.empty()&&!b.empty()&&e.front()==b.front())e.pop_front(),b.pop_front();xx[bu]=2;dfs(bu+1);
}*/
int main(){
	//freopen("meow.in","r",stdin);freopen("meow.out","w",stdout);
	int T;scanf("%d",&T);while(T--){
		int n,k;scanf("%d%d%d",&n,&m,&k);F(i,1,m)scanf("%d",a+i);
		if(k==2*n-2){
			F(i,1,n-1)p.push_back(i);
			F(i,1,m){
				if(x[a[i]]==2)printf("1 %d\n",s[a[i]]),p.push_back(s[a[i]]),siz[s[a[i]]]--,x[a[i]]=s[a[i]]=0;
				else if(x[a[i]]==1)printf("1 %d\n2 %d %d\n",n,s[a[i]],n),
				p.push_back(s[a[i]]),siz[s[a[i]]]--,x[a[i]]=s[a[i]]=0;
				else{
					int u=p.front();siz[u]++;if(siz[u]==2)p.pop_front();
					s[a[i]]=u;x[a[i]]=siz[u];printf("1 %d\n",u);
				}
			}continue;
		}
		int p1=0,p2=0,s1=0,s2=0;if(n==2){
			F(i,1,m){
				if(a[i]==p1){p1=s1;s1=0;printf("1 1\n");continue;}
				if(a[i]==p2){p2=s2;s2=0;printf("1 2\n");continue;}
				if(a[i]==s1){s1=0;printf("1 2\n2 1 2\n");continue;}
				if(a[i]==s2){s2=0;printf("1 1\n2 1 2\n");continue;}
				if(!p1&&!s2){p1=a[i];printf("1 1\n");continue;}
				if(!s1&&!p2){p2=a[i];printf("1 2\n");continue;}
				if(p1&&p2){
					if(a[i+1]==p1)printf("1 2\n"),s2=p2,p2=a[i];
					else printf("1 1\n"),s1=p1,p1=a[i];continue;
				}
				if(s1){
					if(a[i+1]==s1)printf("1 1\n1 2\n2 1 2\n"),s1=p1,p1=a[i],i++;
					else printf("1 2\n"),p2=a[i];continue;
				}
				if(a[i+1]==s2)printf("1 2\n1 1\n2 1 2\n"),s2=p2,p2=a[i],i++;
				else printf("1 1\n"),p1=a[i];continue;
			}continue;
		}
		
	}return 0;
}

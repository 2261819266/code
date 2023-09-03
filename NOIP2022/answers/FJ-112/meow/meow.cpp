#include<bits/stdc++.h>
using namespace std;
const int N=305,M=2e6+5;
int T,n,m,k,c[M],w[N<<1],z[N<<1],cnt,s[M],flag;
queue<int> a;
deque<int> q[5];
void dfs(int x){
	if(x>m){
		for(int i=1;i<=m;++i){
			int f=0;
			if(q[s[i]].size()&&q[s[i]].back()==c[i])q[s[i]].pop_back(),f=1;
			else if(!q[s[i]].size())for(int j=1;j<=3;++j)if(j!=s[i]&&q[j].size()&&q[j].front()==c[i]){q[j].pop_front(),f=1;break;}
			if(!f)q[s[i]].push_back(c[i]);
		}
		for(int i=1;i<=3;++i)if(q[i].size()){
			for(int j=1;j<=3;++j)q[i].clear();
			return;
		}
		return flag=1,void();
	}
	for(int i=1;i<=3;++i){
		s[x]=i,dfs(x+1);
		if(flag)return;
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	for(scanf("%d",&T);T--;){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;++i)scanf("%d",&c[i]);
		if(n==2){
			for(int i=1;i<=m;++i){
				if(w[c[i]]){
					if(z[1]&&z[2])printf("1 %d\n",w[c[i]]),z[w[c[i]]]=0;
					else if(w[c[i]]<=n)printf("1 %d\n2 %d %d\n",3-w[c[i]],1,2),w[z[w[c[i]]+n]]=w[c[i]],z[w[c[i]]+n]=0;
					else printf("1 %d\n",w[c[i]]-n),z[w[c[i]]]=0;
					w[c[i]]=0,--cnt;
				}else{
					if(!cnt)printf("1 1\n"),z[1]=c[i],w[c[i]]=1,++cnt;
					else if(cnt==1){
						++cnt;
						if(z[1])printf("1 2\n"),z[2]=c[i],w[c[i]]=2;
						else printf("1 1\n"),z[1]=c[i],w[c[i]]=1;
					}else if(cnt==2){
						if(z[1]&&z[2]){
							++i;
							if(c[i]==c[i-1])printf("1 1\n1 1\n");
							else printf("1 %d\n1 %d\n",3-w[c[i]],w[c[i]]),w[c[i-1]]=3-w[c[i]]+n,z[3-w[c[i]]+n]=c[i-1],z[w[c[i]]]=0,w[c[i]]=0;
						}else{
							++i;
							if(w[c[i]]<=n){
								printf("1 %d\n1 %d\n2 %d %d\n",w[c[i]],3-w[c[i]],1,2);
								w[z[w[c[i]]+n]]=w[c[i]],w[c[i-1]]=w[c[i]]+n,z[w[c[i]]]=z[w[c[i]]+n],z[w[c[i]]+n]=c[i-1],w[c[i]]=0;
							}else{
								printf("1 %d\n1 %d\n",3-w[c[i]]+n,w[c[i]]-n);
								z[3-w[c[i]]+n]=c[i-1],w[c[i-1]]=3-w[c[i]]+n,z[w[c[i]]]=0,w[c[i]]=0;
							}
						}
					}
				}
			}
		}else if(n==3){
			flag=0,dfs(1);
			for(int i=1;i<=m;++i){
				int f=0;
				printf("1 %d\n",s[i]);
				if(q[s[i]].size()&&q[s[i]].back()==c[i])q[s[i]].pop_back(),f=1;
				else if(!q[s[i]].size())for(int j=1;j<=3;++j)if(j!=s[i]&&q[j].size()&&q[j].front()==c[i]){q[j].pop_front(),printf("2 %d %d\n",min(j,s[i]),max(j,s[i])),f=1;break;}
				if(!f)q[s[i]].push_back(c[i]);
			}
		}else if(k==n+n-2){
			for(int i=1;i<n;++i)a.push(i),a.push(i+n);
			for(int i=1;i<=m;++i){
				if(w[c[i]]){
					if(w[c[i]]<n)printf("1 %d\n2 %d %d\n",n,w[c[i]],n),w[z[w[c[i]]+n]]=w[c[i]],a.push(w[c[i]]+n);
					else printf("1 %d\n",w[c[i]]-n),a.push(w[c[i]]);
					w[c[i]]=0;
				}else printf("1 %d\n",a.front()%n),w[c[i]]=a.front(),z[a.front()]=c[i],a.pop();
			}
		}
	}
	return 0;
}

#include<bits/stdc++.h>
#define N 1000
using namespace std;
int T,n,m,k,ns,a,p[N],f[N],stp[N],op[N][3],zhan[N][3];
void init(){
	ns=0;
	memset(p,0,sizeof(p));
	memset(f,0,sizeof(f));
	memset(stp,0,sizeof(stp));
	memset(op,0,sizeof(op));
	memset(zhan,0,sizeof(zhan));
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	for(scanf("%d",&T);T;T--){
		init();
		priority_queue<pair<int,int> > q;
		scanf("%d%d%d",&n,&m,&k),ns=1;
		for(int i=1;i<=n;i++)q.push(make_pair(-i,-1)),q.push(make_pair(-i,-2));
		for(int i=1;i<=m;i++){
			scanf("%d",&a);
			if(p[a]){
				if(f[a]==2 || zhan[p[a]][2]==0){
					op[ns][0]=1,op[ns][1]=p[a],ns++;
					q.push(make_pair(-p[a],-f[a])),zhan[p[a]][f[a]]=0,p[a]=0,f[a]=0;
				}
				else{
					op[ns][0]=1,op[ns][1]=n,ns++,op[ns][0]=2,op[ns][1]=p[a],op[ns][2]=n,ns++;
					zhan[p[a]][1]=zhan[p[a]][2],zhan[p[a]][2]=0,q.push(make_pair(-p[a],-2));
				}
			}
			else{
				int now=-q.top().first,nf=-q.top().second;
				q.pop();
				zhan[now][nf]=a,stp[a]=ns,p[a]=now,f[a]=nf;
				op[ns][0]=1,op[ns][1]=now,ns++;
			}
		}
		printf("%d\n",ns-1);
		for(int i=1;i<ns;i++)if(op[i][0]==1)printf("%d %d\n",op[i][0],op[i][1]);else printf("%d %d %d\n",op[i][0],op[i][1],op[i][2]);
	}
	return 0;
}


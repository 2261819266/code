#include <iostream>
#include <cstdio>
using namespace std;
const int N=310,K=N>>1,M=2100000;
int n,m,k,c,w,g[K],a[N];
int t,d[M],l[N],r[N],nxt[M],lst[M];
int op,opt[M<<1],s1[M<<1],s2[M<<1];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	scanf("%d",&T);
while(T--){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		g[i]=(i+1)/2;
	c=2*k+1;
	w=n;
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	a[m+1]=0;
	for(int i=1;i<=m;i++){
		if(a[i]==c)
			if(d[l[g[a[i+1]]]]==a[i+1]){
				opt[++op]=1;s1[op]=g[a[i+1]];
				d[++t]=c;
				nxt[r[g[a[i+1]]]]=t;
				lst[t]=r[g[a[i+1]]];
				r[g[a[i+1]]]=1;
				opt[++op]=1;s1[op]=w;
				opt[++op]=2;s1[op]=g[a[i+1]];s2[op]=w;
				lst[nxt[l[g[a[i+1]]]]]=0;
				l[g[a[i+1]]]=nxt[l[g[a[i+1]]]];
				c=a[i+1];
				w=g[a[i+1]];
				i++;
			}
			else{
				
			}
		else
			if(d[l[g[a[i]]]]==a[i]){
				opt[++op]=1;s1[op]=g[a[i]];
				lst[nxt[l[g[a[i]]]]]=0;
				l[g[a[i]]]=nxt[l[g[a[i]]]];
			}
			else
				if(d[r[g[a[i]]]]==a[i]){
					opt[++op]=1;s1[op]=w;
					opt[++op]=2;s1[op]=g[a[i]];s2[op]=w;
					nxt[lst[r[g[a[i]]]]]=0;
					r[g[a[i]]]=lst[r[g[a[i]]]];
				}
				else{
					opt[++op]=1;s1[op]=g[a[i]];
					d[++t]=a[i];
					nxt[r[g[a[i]]]]=t;
					lst[t]=r[g[a[i]]];
					r[g[a[i]]]=1;
				}
	}
	printf("%d\n",op);
	for(int i=1;i<=op;i++)
		if(opt[i]==1)
			printf("1 %d\n",s1[i]);
		else
			printf("2 %d %d\n",s1[i],s2[i]);
}
	return 0;
}

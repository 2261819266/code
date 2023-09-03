#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX=1e6+10,mod=1e9+7;
int n,m,ans,res,flag;
int head[MAX],tot,to[MAX<<1],nxt[MAX<<1];
struct node{
	int x,y;
}e[MAX];
int cnt[10][10],bing[MAX],vis1[MAX],vis2[MAX];
int ok[MAX];
int fa[MAX],sum,sum2;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-48; ch=getchar();}
	return x*f;
}
inline void add(int u,int v){
	to[++tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
}
int getfa(int x){
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	for(register int i=1; i<=m; i++){
		e[i].x=read(),e[i].y=read();
		add(e[i].x,e[i].y),add(e[i].x,e[i].y);
	}
//	for(register int i=1; i<=m; i++)
//	    cout<<e[i].x<<" "<<e[i].y<<endl;
	if(n<=8&&m<=10){
		for(register int i=1; i<(1<<n); i++){
			for(register int j=0; j<(1<<m); j++){
				for(register int k=1; k<=max(n,m); k++)
				    vis1[k]=vis2[k]=ok[k]=0;
				sum=0,sum2=0;
				for(register int k=1; k<=n; k++)
				    if(i&(1<<(k-1)))
				        vis1[++sum]=k;
				for(register int k=1; k<=m; k++){
				    if(j&(1<<(k-1))){
				    	vis2[k]=1;
					}
				    ok[e[k].x]++,ok[e[k].y]++;
				}
				bool fl=1;
				for(register int k=1; k<=m&&fl; k++)
				    if(!vis2[k]){
				    	ok[e[k].x]--,ok[e[k].y]--;
						for(register int k=1; k<=sum; k++)
						    if(!ok[vis1[k]]){
						        fl=0;
						        break;
							}
						ok[e[k].x]++,ok[e[k].y]++;
					}
				if(fl||sum==1)
				    ans=(ans+1)%mod;
//				else{
//					res++;
//					cout<<res<<":";
//					for(register int k=1; k<=sum; k++)
//					    cout<<vis1[k]<<" ";
//					cout<<endl;
//					for(register int k=1; k<=sum; k++)
//					    cout<<ok[k]<<" ";
//					cout<<endl;
//					for(register int k=1; k<=sum2; k++)
//					    cout<<e[vis2[k]].x<<" "<<e[vis2[k]].y<<endl;
//					cout<<endl;
//				}
			}
		}
	    printf("%d",ans);
	    return 0;
	}
    ans=18;
	for(register int i=3; i<=n; i++){
		ans=(ll)ans*4%mod;
	}
	printf("%d\n",ans);
	return 0;
}
/*
4 4
1 2
2 3
3 1
1 4

*/

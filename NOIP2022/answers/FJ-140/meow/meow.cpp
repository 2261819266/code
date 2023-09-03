#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int type,s1,s2;
}cz[4000010];
int T,n,m,k,a[2000010],op,tot,h[301],t[301],li[5][2000010];
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void pr(){
	printf("%d\n",op);
	for(int i=1;i<=op;i++){
		if(cz[i].type==1){
			printf("1 %d\n",cz[i].s1);
		}
		else{
			printf("2 %d %d\n",cz[i].s1,cz[i].s2);
		}
	}
	exit(0);
}
inline void dfs(int now){
	if(now==m+1&&!tot)  pr();
	if(now==m+1) return;
	for(int i=1;i<=n;i++){
		li[i][++t[i]]=a[now];
		cz[++op].type=1;
		cz[op].s1=i;
		if(t[i]-h[i]>=2){
			if(li[i][t[i]]==li[i][t[i]-1]){
				t[i]-=2;
				tot-=2;
				dfs(now+1);
				t[i]+=2;
				tot+=2;
				continue;
			}
		}
		for(int j=1;j<=n;j++){
			if(j==i||t[j]-h[j]<=0) continue;
			if(li[i][h[i]+1]==li[j][h[j]+1]){
				cz[++op].type=2;
				cz[op].s1=min(i,j);
				cz[op].s2=max(i,j);
				h[i]++;
				h[j]++;
				tot-=2;
				dfs(now+1);
				op--;
				tot+=2;
				h[i]--;
				h[j]--;
			}
		}
		dfs(now+1);
		t[i]--;
		op--;
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++){
			a[i]=read(); 
		}
		tot=m;
		dfs(1);
	} 
	return 0;
}

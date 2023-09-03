#include<cstdio>
const int N=500050;
int n,m,L[N],R[N],f[N];
int find(int x){
	while(x!=f[x])x=f[x]=f[f[x]];
	return x;
}
bool check(int x,int all){
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)if(i!=x){
		int u=find(L[i]),v=find(R[i]);
		if(u!=v)f[u]=v;
	}
	int now=0;
	for(int i=0;i<n;i++)if(all>>i&1)now=find(i+1);
	if(!now)return 0;
	for(int i=0;i<n;i++)if(all>>i&1)if(now!=find(i+1))return 0;
	return 1; 
}
int main(){
	freopen("barrack.in","r",stdin),freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",L+i,R+i);
	int ans=0;
	for(int i=0;i<(1<<n+m);i++){
		int flag=1,oo=0;
		for(int j=0;j<n;j++)if(i>>j&1)oo=1;
		if(!oo)continue;
		for(int j=1;j<=m;j++)if(!(i>>(n+j-1)&1))flag&=check(j,i);
		ans+=flag;
	}
	printf("%d\n",ans);
	return 0;
}

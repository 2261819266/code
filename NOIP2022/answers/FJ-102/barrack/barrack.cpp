#include<iostream>
#include<cstdio>
using namespace std;

const int M=2000006,N=500005,mod=1000000007;
int n,m,E,e1,e2;
int u[M],v[M],o[M],h[M],w[M],cnt;
int a[N],ans=0,now,book[N];

void adde(int x,int y){
	u[++cnt]=x;
	v[cnt]=y;
	o[cnt]=h[x];
	h[x]=cnt;
}

int dfs2(int x,int id){
	int sum=a[x];
	book[x]=id;
	for(int i=h[x];i;i=o[i]){
		if(book[v[i]]!=id&&w[i]==1){
			sum+=dfs2(v[i],id);
		}
	}
	return sum;
}

void dfs1(int x,int y,int tot){
	if(x>n+m){
		/*
		for(int i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		for(int i=1;i<=cnt;i++){
			printf("%d ",w[i]);
		}
		printf("\n");
		*/
		if(tot!=0){
			if(dfs2(y,++E)==tot){
				//printf("YES\n");
				ans++;
				ans%=mod;
			}
		}
		return ;
	}
	if(x<=n){
		a[x]=1;
		dfs1(x+1,x,tot+1);
		a[x]=0;
		dfs1(x+1,y,tot);
	}
	else{
		w[(x-n)*2]=1;
		w[(x-n)*2-1]=1;
		dfs1(x+1,y,tot);
		w[(x-n)*2]=0;
		w[(x-n)*2-1]=0;
		dfs1(x+1,y,tot);	
	}
}

int main(){
	
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&e1,&e2);
		adde(e1,e2);
		adde(e2,e1);
	}
	
	dfs1(1,0,0);
	
	printf("%d\n",ans);
	
	return 0;
} 

#include<iostream>
#include<cstdio>
using namespace std;

const int N=250005;
int T,n,a[N],b[N],c[N],d[N],q,l,r;
int fa[17][N],fb[17][N];
int lgg[N];
unsigned long long ans;

int finma(int x,int y){
	int len=y-x+1;
	int e=lgg[len];
	return max(fa[e][x],fa[e][y-(1<<e)+1]);
}

int finmb(int x,int y){
	int len=y-x+1;
	int e=lgg[len];
	return max(fb[e][x],fb[e][y-(1<<e)+1]);
}

int main(){
	
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		d[b[i]]=i;
	}
	
	lgg[0]=-1;
	for(int i=1;i<=n;i++){
		lgg[i]=lgg[i/2]+1; 
		fa[0][i]=a[i];
		fb[0][i]=b[i];
	}
	
	for(int i=1;i<=17;i++){
		for(int j=1;j<=n-(1<<i)+1;j++){
			fa[i][j]=max(fa[i-1][j],fa[i-1][j+(1<<(i-1))]);
			fb[i][j]=max(fb[i-1][j],fb[i-1][j+(1<<(i-1))]);
		}
	}
	
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		ans=0;
		scanf("%d%d",&l,&r);
		for(int x=l;x<=r;x++){
			for(int y=x;y<=r;y++){
				ans+=(finma(x,y)*finmb(x,y));
			}
		}
		printf("%llu\n",ans);
	}
	
	
	return 0;
} 

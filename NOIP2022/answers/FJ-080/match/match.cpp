#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int T,t,n,l,r,size,lo2[300010];
struct yyq{
	int l,r,id,k;
} q[300010];
ull a[300010],b[300010],f1[300010][21],f2[300010][21],anss[300010],ans,g1[3010][3010],g2[3010][3010];
ull query(int x,int y){
	if(x==y) return a[x]*b[x];
	int u=lo2[y-x];
	ull u1=max(f1[x][u],f1[y-(1<<u)+1][u]);
	ull u2=max(f2[x][u],f2[y-(1<<u)+1][u]);
	return u1*u2;
}
bool cmp(yyq e,yyq o){
	if(e.l!=o.l) return e.k<o.k;
	else return e.r<o.r;
}
void add(int x,int w){
	if(x==0||x==n+1) return;
	if(w==0){
		ans+=g1[x][r];
	} else{
		ans+=g2[l][x];
	}
}
void del(int x,int w){
	if(x==0||x==n+1) return;
	if(w==0){
		ans-=g1[x][r];
	} else{
		ans-=g2[l][x];
	}
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++){
		lo2[i]=log2(i);
	}
	for(int i=1;i<=n;i++) scanf("%llu",&a[i]);
	for(int i=1;i<=n;i++) scanf("%llu",&b[i]);
	for(int i=1;i<=n;i++){
		f1[i][0]=a[i];f2[i][0]=b[i];
	}
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++){
			if(i+(1<<j)-1>n) break;
			f1[i][j]=max(f1[i][j-1],f1[i+(1<<(j-1))][j-1]);
			f2[i][j]=max(f2[i][j-1],f2[i+(1<<(j-1))][j-1]);
		}
	}
	for(int i=1;i<=n;i++){
		g1[i][i]=query(i,i);
		for(int j=i+1;j<=n;j++){
			g1[i][j]=g1[i][j-1]+query(i,j);
		}
	}
	for(int j=n;j>=1;j--){
		g2[j][j]=query(j,j);
		for(int i=j-1;i>=1;i--){
			g2[i][j]=g2[i+1][j]+query(i,j);
		}
	}
	size=sqrt(n);
	cin>>T;
	for(int i=1;i<=T;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].k=(q[i].l-1)/size+1;
		q[i].id=i;
	}
	sort(q+1,q+T+1,cmp);
	ans=0;
	for(int i=1;i<=T;i++){
		while(q[i].l<l) add(--l,0);
		while(q[i].r<r) del(r--,1);
		while(q[i].l>l) del(l++,0);
		while(q[i].r>r) add(++r,1);
		anss[q[i].id]=ans;
	}
	for(int i=1;i<=T;i++){
		printf("%llu\n",anss[i]);
	}
}

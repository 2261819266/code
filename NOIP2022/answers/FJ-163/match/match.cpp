#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAXN=250005;
inline ull maxx(ull x,ull y){
	return x>y?x:y;
}
int T,n,Q,l,r;
ull f1[MAXN][21],f2[MAXN][21];
int log2n[MAXN];
void getlog2(){
	log2n[0]=-1;
	for(int i(2);i<MAXN;++i){
		if(i&(i-1)) log2n[i]=log2n[i-1];
		else log2n[i]=log2n[i-1]+1;
	}
	return;
}
void ST_create1(){
	for(int i(1);i<=log2n[n];++i){
		for(int j(1);j<=n-(1<<i)+1;++j){
			f1[j][i]=maxx(f1[j][i-1],f1[j+(1<<(i-1))][i-1]);
		}
	}
}
void ST_create2(){
	for(int i(1);i<=log2n[n];++i){
		for(int j(1);j<=n-(1<<i)+1;++j){
			f2[j][i]=maxx(f2[j][i-1],f2[j+(1<<(i-1))][i-1]);
		}
	}
}
ull query1(int l,int r){
	int k=log2n[r-l+1];
	return maxx(f1[l][k],f1[r-(1<<k)+1][k]);
}
ull query2(int l,int r){
	int k=log2n[r-l+1];
	return maxx(f2[l][k],f2[r-(1<<k)+1][k]);
}
int main(){
//	freopen("E:\\NOIP2022\\match\\match2.in","r",stdin);
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i(1);i<=n;++i){
		scanf("%llu",&f1[i][0]);
	}
	for(int i(1);i<=n;++i){
		scanf("%llu",&f2[i][0]);
	}
	ST_create1();
	ST_create2();
	scanf("%d",&Q);
	while(Q--){
		scanf("%d%d",&l,&r);
		ull ans=0;
		for(int p(l);p<=r;++p){
			for(int q(p);q<=r;++q){
				ans+=(query1(p,q)*query2(p,q));
			}
		}
		printf("%llu\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


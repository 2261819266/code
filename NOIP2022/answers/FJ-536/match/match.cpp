#include<stdio.h>
unsigned long long tr1[270000],tr2[270000];
int n;
inline unsigned long long max(int a,int b){
	return a>b?a:b;
}
unsigned long long query2(int l,int r,int s,int e,int i){
	int m=(s+e)/2;
	if(l==s&&r==e){
		return tr2[i];
	}else if(l<=m&&r<=m){
		return query2(l,r,s,m,i*2);
	}else if(l<=m&&r>m){
		return max(query2(l,m,s,m,i*2),query2(m+1,r,m+1,e,i*2+1));
	}else{
		return query2(l,r,m+1,e,i*2+1);
	}
}
void store2(int k,unsigned long long v,int s,int e,int i){
	int m=(s+e)/2;
	tr2[i]=max(tr2[i],v);
	if(k==s&&k==e)return;
	else if(k<=m)store2(k,v,s,m,i*2);
	else if(k>m)store2(k,v,m+1,e,i*2+1);
}
unsigned long long query1(int l,int r,int s,int e,int i){
	int m=(s+e)/2;
	if(l==s&&r==e){
		return tr1[i];
	}else if(l<=m&&r<=m){
		return query1(l,r,s,m,i*2);
	}else if(l<=m&&r>m){
		return max(query1(l,m,s,m,i*2),query1(m+1,r,m+1,e,i*2+1));
	}else{
		return query1(l,r,m+1,e,i*2+1);
	}
}
void store1(int k,unsigned long long v,int s,int e,int i){
	int m=(s+e)/2;
	tr1[i]=max(tr1[i],v);
	if(k==s&&k==e)return;
	else if(k<=m)store1(k,v,s,m,i*2);
	else if(k>m)store1(k,v,m+1,e,i*2+1);
}
int main(){
	int T,Q;
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++){
		int v;
		scanf("%d",&v);
		store1(i,v,1,n,1);
	}
	for(int i=1;i<=n;i++){
		int v;
		scanf("%d",&v);
		store2(i,v,1,n,1);
	}
	scanf("%d",&Q);
	for(int i=0;i<Q;i++){
		int s,e;
		scanf("%d%d",&s,&e);
		unsigned long long val=0;
		for(int p=s;p<=e;p++){
			for(int q=p;q<=e;q++){
				val+=query1(p,q,1,n,1)*query2(p,q,1,n,1);
			}
		}
		printf("%lld\n",val);
	}
	return 0;
}
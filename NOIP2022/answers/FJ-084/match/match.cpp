#include<bits/stdc++.h>
#define ll unsigned long long 
#define N 250010
#define GC getchar()
using namespace std;
ll re(){
	ll s=0,b=1; char c=GC;
	while(c>'9'||c<'0'){if(c=='-')b=-b; c=GC;}
	while(c<='9'&&c>='0'){s=(s<<1)+(s<<3)+(c^48); c=GC;}
	return s*b;
}
void ks(ll s){
	if(s<0){s=-s; putchar('-');} 
	if(s>=10)ks(s/10); 
	putchar((s%10)|48);
}
int n,zh[N],zi[N],zd,ze,q,L,R;
ll ans,a[N],b[N];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	n=re(); n=re();
	for(int i=1; i<=n; i++)a[i]=re();
	for(int i=1; i<=n; i++)b[i]=re();
	q=re();
	while(q--){
		ans=0; L=re(),R=re();
		ans=a[L]*b[L]; zh[1]=zi[1]=L; zd=ze=1;
		for(int r=L+1; r<=R; r++){
			while(a[zh[zd]]<a[r]&&zd)zd--; 
			zh[++zd]=r;
			while(b[zi[ze]]<b[r]&&ze)ze--; 
			zi[++ze]=r; 
			ll law=L-1,w;
			for(int i=1,j=1; i<=zd&&j<=ze;){
				if(zh[i]<=zi[j]){
					w=zh[i]; ans+=(w-law)*a[zh[i]]*b[zi[j]];
					if(zh[i]==zi[j])j++; i++; 
				} else{
					w=zi[j]; ans+=(w-law)*a[zh[i]]*b[zi[j]]; j++;
				} law=w;
			}
		} ks(ans),putchar('\n');
	}
} 

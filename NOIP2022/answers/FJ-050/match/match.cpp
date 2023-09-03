#include<bits/stdc++.h>
#define For(i,a,b) for(int i(a);i<=b;++i)
#define foR(i,a,b) for(int i(a);i>=b;--i)
#define int unsigned long long
#define in8 int
using namespace std;
inline void read(int &x){
	x=0;bool w=0;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	if(w)x=-x;
}
inline void print(int x){
	if(x<0){putchar('-'); print(-x); return;}
	if(x>9){print(x/10);}putchar(x%10+'0');
}
const int N=1e6+78;
const in8 Mod=9223372036854775808;
in8 T,n,t,Q,a[N],b[N];
in8 ans,f[N][22],g[N][22],cnt;
in8 Max(in8 x,in8 y){
	return x>=y ? x : y;
}
void ST(){
	For(i,1,n)f[i][0]=a[i];
	For(i,1,t)
	for(int j=1;j+(1<<i)-1<=n;j++)
	f[j][i]=Max(f[j][i-1],f[j+(1<<(i-1))][i-1]);	
	
	For(i,1,n)g[i][0]=b[i];
	For(i,1,t)
	for(int j=1;j+(1<<i)-1<=n;j++)
	g[j][i]=Max(g[j][i-1],g[j+(1<<(i-1))][i-1]);	
}
in8 Sa(int l,int r){
	int k=(log(r-l+1)/log(2));
	return Max(f[l][k],f[r-(1<<k)+1][k]);
}
in8 Sb(int l,int r){
	int k=(log(r-l+1)/log(2));
	return Max(g[l][k],g[r-(1<<k)+1][k]);
}

signed main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	read(T);read(n);
	For(i,1,n)read(a[i]);
	For(i,1,n)read(b[i]);
	t=log(n)/log(2)+1;
	ST();
	read(Q);
	int l,r;
	while(Q--){
		ans=0;cnt=0;
		read(l);read(r);
		For(p,l,r){
			For(q,p,r){
				in8 aa=Sa(p,q);
				in8 bb=Sb(p,q);
				int cc=aa*bb;
				while(cc>Mod)cc-=Mod,cnt++;
				ans=(ans+cc);
				while(ans>Mod)ans-=Mod,cnt++;
			}
		}
		if(cnt%2==0)print(ans);
		else print(ans+Mod);
		puts("");
	}
}

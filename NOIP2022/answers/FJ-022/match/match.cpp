#include<bits/stdc++.h>
#define spa putchar(' ')
#define ent putchar('\n')
typedef unsigned long long ll;
using namespace std;
inline void read(int &x){
	char c=getchar();
	int f=1;x=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	x*=f;
}
inline void write(ll x){
	char F[65];
	int cnt=0;
	if(x<0){putchar('-');x=-x;}
	do{F[++cnt]=x%10+'0';x/=10;}while(x);
	while(cnt)putchar(F[cnt--]);
}
const int maxn=250000+5;
int T,n,a[maxn],b[maxn],q,l,r;
ll ans;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	read(T);
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int j=1;j<=n;j++)read(b[j]);
	read(q);
	while(q--){
		read(l);
		read(r);
		ans=0;
		int maxa=0,maxb=0;
		for(int i=l;i<=r;i++){
			for(int j=i;j<=r;j++){
				maxa=0;
				maxb=0;
				for(int k=i;k<=j;k++){
					maxa=max(maxa,a[k]);
					maxb=max(maxb,b[k]);
				}
				ans+=1ll*maxa*maxb;
			}
		}
		write(ans);
		ent;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

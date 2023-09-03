#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;++i)
#define D(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
using namespace std;
bool star;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	int x=0,w=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	return x*w;
}
const int N=1e5+10;
int a[N<<1],st[310][N],top[310];int cnt;
struct node{
	int opt,x,y;
}ans[N<<2];
inline void sol(){
	int n=read(),m=read(),k=read();//n zhanshu
//	if(k==2n-2){
		F(i,1,m>>1){
			a[i]=read();
			int x=a[i]%n;if(x==0) x=n-1;
			if(st[x][top[x]]==a[i]) --top[x];
			else st[x][++top[x]]=a[i];
			ans[++cnt].opt=1;ans[cnt].x=x;
		}
//		F(i,1,m){
//			a[i]=read();
//			int x=a[i]%n;if(x==0) x=n-1;
//			if(st[x][top[x]]==a[i])
//		}
		F(i,(m>>1)+1,m) {
			a[i]=read();
			int x=a[i]%n;if(x==0) x=n-1;
			if(st[x][top[x]]==a[i]) {
				--top[x];ans[++cnt].opt=1;ans[cnt].x=x;
			}
			else{
				ans[++cnt].opt=1;ans[cnt].x=n;
				ans[++cnt].opt=2;ans[cnt].x=x;ans[cnt].y=n;
			}
		}
		printf("%d\n",cnt);
		F(i,1,cnt){
			printf("%d %d",ans[i].opt,ans[i].x);
			if(ans[i].opt==2) printf(" %d",ans[i].y);
			putchar('\n');
		}
//	}
//	else{
//		F(i,1,m>>1){
//			a[i]=read();
//			int x=a[i]%n;if(x==0) x=1;
//			if(st[x][top[x]]==a[i]) {
//				--top[x];
//			}
//			else st[x][++top[x]]=a[i];printf("1 %d\n",x);
//		}
//		F(i,(m>>1)+1,m) {
//			a[i]=read();
//			int x=a[i]%n;if(x==0) x=1;
//			if(st[x][top[x]]==a[i]) {
//				--top[x];printf("1 %d\n",x);
//			}
//			else printf("1 %d\n2 %d %d\n",n,x,n);
//		}
//	}
	
}
bool ed;
signed main(){
//	cerr<<(&star-&ed)/1024.0/1024.0<<endl;
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T=read();while(T--) sol();
//	if(T%10==1) while(T--) sol1();
//	else if(T%10==2) while(T--) sol2();
//	else if(T%10==3) while(T--) sol3();
//	else if(T%10==4) while(T--) sol4();
//	else while(T--) sol5();
	return 0;
}

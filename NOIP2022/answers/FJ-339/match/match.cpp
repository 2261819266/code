#include<bits/stdc++.h>
#define ull unsigned long long
#define N 250004
using namespace std;
int t,n,q,l=1,r=0;
ull val;
int a[N],b[N],pos[N];
ull ans[N];
inline int read(){
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x;
}
struct Q{
	int l,r,id;
	inline void input(int x){
		l=read(),r=read(),id=x;
	}
}query[N];

inline bool cmp(Q x,Q y){
	if(pos[x.l]!=pos[y.l])
		return pos[x.l]<pos[y.l];
	return x.r<y.r;
}
inline void add(int ax,int bx,int op){
	val+=ax*bx;
	if(!op){
		for(int i=l;i<=r;i++){
			ax=max(ax,a[i]);
			bx=max(bx,b[i]);
			val+=ax*bx;
		}
	}
	else{
		for(int i=r;i>=l;i--){
			ax=max(ax,a[i]);
			bx=max(bx,b[i]);
			val+=ax*bx;
		}
	}
}
inline void sub(int ax,int bx,int op){
	val-=ax*bx;
	if(!op){
		for(int i=l;i<=r;i++){
			ax=max(ax,a[i]);
			bx=max(bx,b[i]);
			val-=ax*bx;
		}
	}
	else{
		for(int i=r;i>=l;i--){
			ax=max(ax,a[i]);
			bx=max(bx,b[i]);
			val-=ax*bx;
		}
	}
}
void write(ull x){
	if(x<10){
		putchar(x^48);
		return;
	}
	write(x/10);
	putchar((x%10)^48);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	
	q=read();
	int sqt=sqrt(n);
	for(int i=1;i<=q;i++){
		query[i].input(i);
		pos[i]=i/sqt;
	}
	sort(query+1,query+q+1,cmp);
	
	for(int i=1;i<=q;i++){
		while(r<query[i].r){
			add(a[r+1],b[r+1],1);
			r++;
		}
		while(l>query[i].l){
			add(a[l-1],b[l-1],0);
			l--;
		}
		while(r>query[i].r){
			r--;
			sub(a[r+1],b[r+1],1);
		}
		while(l<query[i].l){
			l++;
			sub(a[l-1],b[l-1],0);
		}
		ans[query[i].id]=val;
	}
	for(int i=1;i<=q;i++){
		write(ans[i]);
		putchar('\n');
	}
}

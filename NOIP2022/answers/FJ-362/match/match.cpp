#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const int N=5e5+3;
int a[N],b[N];

int read(){
	int ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T=read(),n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	int Q=read();
	for(int l,r;Q--;){
		l=read(); r=read(); ll ans=0;
		for(int p=l;p<=r;p++)
			for(int q=l;q<=r;q++){
				int Max=0,Min=0;
				for(int i=p;i<=q;i++){
					Max=max(Max,a[i]);
					Min=max(Min,b[i]);
				}
				ans+=Max*Min;
			}
		printf("%lld\n",ans);
	}
}

/*

TMD

Segment Tree xie zha le

chao

#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const int N=5e5+3;
int a[N][2];

void pushup(int i){
	a[i][0]=max(a[i][0],max(a[i<<1][0],a[i<<1|1][0]));
	a[i][1]=max(a[i][1],max(a[i<<1][1],a[i<<1|1][1]));
}

int read(){
	int ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}

void build(int i,int k,int l,int r){
	if(l==r){a[i][k]=read(); return;}
	int mid=(l+r)>>1;
	build(i<<1,k,l,mid);
	build(i<<1|1,k,mid+1,r);
	pushup(i);
}

ll query(int i,int l,int r,int x,int y){
	if(l>y||r<x) return 0;
	if(l>=x&&r<=y) return a[i][0]*a[i][1];
	int mid=(l+r)>>1;
	return query(i<<1,l,mid,x,y)+query(i<<1|1,mid+1,r,x,y);
}

int main(){
	freopen("match2.in","r",stdin);
	//freopen("match.out","w",stdout);
	int T=read(),n=read();
	build(1,0,1,n); build(1,1,1,n);
	int Q=read();
	while(Q--){
		int l=read(),r=read(); ll ans=0;
		for(int i=l;i<=r;i++)
			for(int j=l;j<=r;j++)
				ans+=query(1,1,n,i,j);
		printf("%lld\n",ans);
	}
}
*/

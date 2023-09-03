#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
inline ull read(){
	ull ans=0,f=1;
	char x;
	x=getchar();
	while(!(('0'<=x&&x<='9')||x!='-')){
		x=getchar();
	}
	if(x=='-'){
		f=-1;
		x=getchar();
	}
	while('0'<=x&&x<='9'){
		ans*=10;
		ans+=x-'0';
		x=getchar();
	}
	return ans*f;
}
const int N=3001;
int T;
int n,q;
int a[N],b[N];
int t1[100000],t2[100000];
int build(int l,int r,int p,int t[],int x[]){
	if(l==r) {
		t[p]=x[l];
		return 0;
	}
	int mid=(l+r)/2;
	build(l,mid,p*2,t,x);
	build(mid+1,r,p*2+1,t,x);
	t[p]=max(t[p*2],t[p*2+1]);
	return 0;
}
int see(int l,int r,int p,int pl,int pr,int t[]){
	if((pl==l)&&(pr==r)) return t[p];
	int mid=(pl+pr)/2;
	if(l>mid) return see(l,r,p*2+1,mid+1,pr,t);
	if(r<=mid) return see(l,r,p*2,pl,mid,t);
	return max(see(l,mid,p*2,pl,mid,t),see(mid+1,r,p*2+1,mid+1,pr,t));
}
int ma(int l,int r,int sz[]){
//		for(int j=1;j<=n;j++){
//		for(int i=1;i+(1<<j)-1<=n;i++){
//			f[i][j]=max(f[i][j-1],f[i+(1<<j)-1][j-1]);
//		}
//	}
//	int s=log(n)+1;
//	cout<<s<<endl;
//	cout<<max(f[1][1+(1<<s)-1],f[n-(1<<s)+1][n])<<endl;
	int ans=0;
	for(int i=l;i<=r;i++){
		ans=max(ans,sz[i]);
	}
	return ans;
}
//void init(){
//	int ma=0,mb=0;
//	for(int i=1;i<=n;i++){
//		ma=a[i],mb=b[i];
//		for(int j=i;j<=n;j++){
//			if(a[j]>ma){
//				ma=a[j];
//			}
//			if(b[j]>mb){
//				mb=b[j];
//			}
//			f[i][j]=ma*mb;
//		}
//	}
//	return;
//}
void solve(int l,int r){
	ull ans=0;
	for(int i=l;i<=r;i++){
		for(int j=i;j<=r;j++){
			ans+=see(i,j,1,1,n,t1)*
			see(i,j,1,1,n,t2);
		}
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read(),n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		b[i]=read();
	}
//	init();
	build(1,n,1,t1,a);
	build(1,n,1,t2,b);
	q=read();
	int l,r;
	for(int i=0;i<q;i++){
		l=read(),r=read();
		solve(l,r);
	}
	return 0;
}
/*
0 2
2 1
1 2
1
1 2
*/

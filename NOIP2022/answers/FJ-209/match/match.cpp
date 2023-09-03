#include<bits/stdc++.h>
#define r(x) x=read()
using namespace std;
const int maxn=250002;
unsigned long long ans;
int read(){
	//unsigned
	int num=0;
	char a=getchar();
	while(a<'0'||a>'9') a=getchar();
	while(a>='0'&&a<='9'){
		num=(num*10)+a-'0';
		a=getchar();
	}
	return num;
}
int t,n,q;
unsigned long long a[maxn][20],b[maxn][20],c[5000][5000];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	r(t),r(n);
	for(int i=1;i<=n;i++) r(a[i][0]);
	for(int i=1;i<=n;i++) r(b[i][0]);
	for(int i=1;1;i++){
		int l=(1<<(i-1)),mm=n-2*l+1;
		if(l*2>n) break;
		for(int q=1;q<=mm;q++){
			a[q][i]=max(a[q][i-1],a[q+l][i-1]);
			b[q][i]=max(b[q][i-1],b[q+l][i-1]);
		}
	}
	r(q);
	ans=0;
	for(int i=0;i<=n;i++){
		c[0][i]=0;
	}
	for(int i=1;i<=n;i++){
		ans+=(a[i][0]*b[i][0]);
		c[i][1]=ans;
	}
	for(int i=2;i<=n;i++){
		ans=0;
		int w=0,le=2;
		while(le<=i){
			le*=2;
			w++;
		}
		le/=2;
		for(int q=1;q<=n-i+1;q++){
			ans+=(max(a[q][w],a[q+i-le][w])*max(b[q][w],b[q+i-le][w]));
			c[q][i]=ans;
		}
	}
	while(q--){
		ans=0;
		int l,r,lenn;
		r(l),r(r);
		lenn=r-l+1;
		for(int i=1;i<=lenn;i++){
			//cout<<i<<" "<<c[r-i+1][i]-c[l-1][i]<<endl;
			ans+=(c[r-i+1][i]-c[l-1][i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}

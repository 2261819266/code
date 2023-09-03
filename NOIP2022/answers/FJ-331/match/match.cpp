#include<map>
#include<cstdio>
#include<iostream>
using namespace std;

typedef unsigned long long ull;
const int N=250010;
int T,n,Q,l,r,a[N],b[N];
map<ull,ull> mp;

int main(){
	freopen("match.in","r",stdin);freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);}
	for(int i=1;i<=n;i++){scanf("%d",&b[i]);}
	scanf("%d",&Q);
	for(int p=1;p<=n;p++){
		int mxa=0,mxb=0;ull tmp=0;
		for(int q=p;q<=n;q++){
			mxa=max(mxa,a[q]);
			mxb=max(mxb,b[q]);
			tmp+=mxa*mxb;
			mp[(ull)(p)*(ull)(n+1)+(ull)q]=tmp;
		}
	}
	while(Q--){
		scanf("%d%d",&l,&r);
		ull ans=0;
		for(int i=l;i<=r;i++){
			ans+=mp[(ull)i*(ull)(n+1)+(ull)r];
		}
		printf("%llu\n",ans);
	}
	return 0;
}

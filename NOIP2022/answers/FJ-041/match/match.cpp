#include <bits/stdc++.h> 
typedef unsigned long long ll;

ll a[250000],b[250000];

int read(){
	int ans=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
}

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T=read(),n=read(),Q,l,r;
	ll ans=0,maxa,maxb;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	Q=read();
	for(int i=0;i<Q;i++){
		l=read();r=read();
		for(int p=l;p<=r;p++){
			for(int q=p;q<=r;q++){
				maxa=0;maxb=0;
				for(int x=p;x<=q;x++){
					maxa=std::max(maxa,a[x]);
					maxb=std::max(maxb,b[x]);
				}
				ans+=maxa*maxb;
		}}
		printf("%llu\n",ans);
	}
	return 0;
}

#include<bits/stdc++.h>//0xnnb2ndsb
using namespace std;
#define ll long long
#define db double
#define ull unsigned long long
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10-'0'+ch;
		ch=getchar();
	}
	return x*f;
}
int t,n,a[250005],b[250005],q;
unsigned long long ans;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	t=read();
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read(),b[i]=read();
	}
	q=read();
	while(q--){
		int l=read(),r=read();
		ans=0;
		for(int p=l;p<=r;p++){
			int maxa=0,maxb=0;
			for(int q=p;q<=r;q++){
				maxa=max(maxa,a[q]);
				maxb=max(maxb,b[q]);
				ans+=(ull)maxa*maxb;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

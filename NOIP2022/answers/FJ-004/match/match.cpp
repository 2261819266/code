#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
typedef unsigned long long ull;
int T,n;
int read(){
	int ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret;
}
int a[N],b[N];
int st1[N][21];
int st2[N][21];
int qMax1(int l,int r){
	int ret=-0x3f3f3f3f;
	for(int i=20;i>=0;i--){
		if(l+(1<<i)-1<=r){
			ret=max(ret,st1[l][i]);
			l=l+(1<<i);
		}
	}
	return ret;
}
int qMax2(int l,int r){
	int ret=-0x3f3f3f3f;
	for(int i=20;i>=0;i--){
		if(l+(1<<i)-1<=r){
			ret=max(ret,st2[l][i]);
			l=l+(1<<i);
		}
	}
	return ret;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read();
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();	
	for(int i=1;i<=n;i++){
		st1[i][0]=a[i];
		st2[i][0]=b[i];
		for(int j=1;j<=20;j++){
			st1[i][j]=-0x3f3f3f3f;
			st2[i][j]=-0x3f3f3f3f;
		}
	}
	for(int j=1;j<=20;j++){
		for(int i=1;i+(1<<(j-1))-1<=n;i++){
			st1[i][j]=max(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
			st2[i][j]=max(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
		}
	}
	ull ans,tmp;
	int q=read();
	int ql,qr;
	while(q--){
		ans=0;
		ql=read();
		qr=read();
		for(int i=ql;i<=qr;i++){
			for(int j=i;j<=qr;j++){
				tmp=qMax1(i,j)*qMax2(i,j);
				ans+=tmp;
			}
		}	
		printf("%lld\n",ans);
	}
	return 0;
}

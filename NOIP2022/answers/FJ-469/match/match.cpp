#include <bits/stdc++.h>
using namespace std;
template<class T>T Max(T x,T y){
	return x>y?x:y;
}
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void write(long long x){
	static char buf[64];
	static long long len=-1;
	if(x<0){
		putchar('-');
		x=-x;
	}
	do{
		buf[++len]=x%10;
		x/=10;
	}
	while(x);
	while(len>=0){
		putchar(buf[len--]+'0');
	}
	putchar('\n');
}
inline void Write(unsigned long long x){
	static char buf[64];
	static long long len=-1;
	if(x<0){
		putchar('-');
		x=-x;
	}
	do{
		buf[++len]=x%10;
		x/=10;
	}
	while(x);
	while(len>=0){
		putchar(buf[len--]+'0');
	}
	putchar('\n');
}
const long long N=300300;
const long long INF=1000000000000000;
long long id,n,q,l,r,mxa,mxb;
long long a[N],b[N];
unsigned long long ans;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	id=read();
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		b[i]=read();
	}
	q=read();
	for(int Q=1;Q<=q;Q++){
		l=read();
		r=read();
		for(int L=l;L<=r;L++){
			for(int R=L;R<=r;R++){
				mxa=-INF;
				mxb=-INF;
				for(int i=L;i<=R;i++){
					mxa=Max(mxa,a[i]);
					mxb=Max(mxb,b[i]);
				}
				ans+=mxa*mxb;
			}
		}
	}
	Write(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
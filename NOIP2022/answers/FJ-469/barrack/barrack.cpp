#include <bits/stdc++.h>
using namespace std;
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
const long long MOD=1000000007;
long long n,m;
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();
	m=read();
	write((n*n%MOD+1)%MOD);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
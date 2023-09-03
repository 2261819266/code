#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
inline void write(unsigned long long x){
	if(x>=10)write(x/10);
	putchar(x%10^48);
}
unsigned long long ans,a[250005],b[250005],max1,max2;
int t,n,q,l,r;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	t=read(),n=read();
	for(register int i = 1;i<=n;i++)a[i]=read();
	for(register int i = 1;i<=n;i++)b[i]=read();
	q=read();
	while(q--){
		ans=0;
		l=read(),r=read();
		for(register int i = l;i<=r;i++){
			max1=max2=0;
			for(register int j = i;j<=r;j++){
				max1=max(max1,a[j]),max2=max(max2,b[j]);
				ans+=(unsigned long long)max1*max2;
			}
		}
		write(ans);putchar('\n');
	}
	return 0;
}

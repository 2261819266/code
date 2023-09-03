#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1,mod=1e9+7;
int n,m;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
void work(){
	
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();bool flag_of_case=1;
	for(int i=1;i<=m;i++){
		int f=read(),t=read();
		if((f!=i&&t!=i+1)&&(f!=i+1&&t!=i))flag_of_case=0;
		//add(f,t);add(t,f);
	}
	//if(flag_of_case&&m==n-1){work();return 0;}
	cout<<(n%mod*(n+1)%mod*m%mod*(m+1)%mod)/2;
	return 0;
}

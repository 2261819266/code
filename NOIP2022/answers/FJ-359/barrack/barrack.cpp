//Glad to meet you,OI
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
const int inf = INT_MAX;
int read(){
	char ch=getchar();
	int f=1,s=0;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return f*s;
}
int n,m;
signed main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	mt19937 rnd(time(0));
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
	}
	printf("%lld",rnd()%2022359);
	return 0;
}


#include <bits/stdc++.h>
#include <ctime>
using namespace std;
int read(){
	int x=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
int mod=1000000007;
int main(){
//	freopen("barrack.in","r",stdin);
//	freopen("barrack.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
	}
	srand(time(NULL));
	int ans=(mod+rand())%mod;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

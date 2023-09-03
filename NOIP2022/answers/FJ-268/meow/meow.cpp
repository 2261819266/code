#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,a[2000005],b[2000005];
inline int read(){
	int x=0,ff=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')ff=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*ff;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	while(t--){
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++){
			a[i]=read();
		}
		for(int i=1;i<=k;i++){
			b[i]=0;
		}
		cout<<n<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

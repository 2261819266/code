#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,ff=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')ff=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*ff;
}
int main(){
//	freopen("match.in","r",stdin);
//	freopen("match.out","w",stdout);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

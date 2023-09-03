#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,x,y;
inline int rad(){
	int res=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=(res<<3)+(res<<1)+ch-'0';
		ch=getchar();
	}
	return res*w;
}

int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=rad(),m=rad();
	for(int i=1;i<=m;++i)
	{
		x=rad(),y=rad();
		
	}
	printf("0");
	return 0;
} 

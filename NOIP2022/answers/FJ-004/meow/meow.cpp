#include<bits/stdc++.h>
using namespace std;
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
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	
	return 0;
}

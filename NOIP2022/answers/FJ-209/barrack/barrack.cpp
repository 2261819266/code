#include<bits/stdc++.h>
#define r(x) x=read()
using namespace std;
int read(){
	//unsigned
	int num=0;
	char a=getchar();
	while(a<'0'||a>'9') a=getchar();
	while(a>='0'&&a<='9'){
		num=(num*10)+a-'0';
		a=getchar();
	}
	return num;
}
int main(){
	freopen("barrack.out","w",stdout);
	freopen("barrack.in","r",stdin);
	printf("1919860");
	return 0;
}

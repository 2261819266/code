#include <bits/stdc++.h>
#define int long long
#define RR =read()
using namespace std;

int read(){
	int b=0,d=1;
	char c=getchar();
	while(c<'0' or c>'9'){
		if(c=='-')d*=-1;
		c=getchar();
	}
	while(c>='0' and c<='9'){
		b=b*10+c-'0';
		c=getchar();
	}
	return b*d;
}

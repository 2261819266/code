#include <bits/stdc++.h>
using namespace std;


long long random(long long l,long long r){
	return long(rand()*rand())%(r-l)+l;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cout<<random(1,100000000);
	return 0;
}


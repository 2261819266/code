#include <bits/stdc++.h>
using namespace std;


long long random(long long l,long long r){
	return long(rand()*rand())%(r-l)+l;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	srand(time(0));
	cout<<random(1,100000000000000);
	return 0;
}


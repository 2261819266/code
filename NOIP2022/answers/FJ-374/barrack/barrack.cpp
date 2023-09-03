#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	mt19937 gen(time(0));
	cout<<gen()%(int)(1e9+7)<<endl;
	return 0;
}
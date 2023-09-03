#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int R=1e9+7;

int n, m;

int qpow(int x, int y){
	if(y==0) return 1;
	int sub=qpow(x, y/2);
	return (ll)sub*sub%R*(y&1 ? x : 1)%R;
}

int main(){
	freopen("barrack.in", "r", stdin); freopen("barrack.out", "w", stdout);

	cin>>n>>m;
	cout<<(ll)(qpow(2, n)-1)*qpow(2, m)%R;
}

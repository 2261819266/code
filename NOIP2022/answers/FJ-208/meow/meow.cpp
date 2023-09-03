#include<bits/stdc++.h>
#define maxn 114514
#define maxn1 780+45+37+8

using namespace std;
typedef long long ll;


inline ll read(){
	ll n=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') n=n*10+ch-'0',ch=getchar();
	return n;
}

inline void print(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar(x%10+'0');
	return ;
}

ll T,n,m,k;

ll card[maxn];

deque<ll>Q[maxn];

struct Node{
	ll wh,str;
}ans[maxn1];

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	while(T--){
		ll a1=rand();
		cout<<a1<<endl;
		for(ll i=1;i<=a1;i++){
			card[i]=rand()%2;
			if(card[i]==1){
				cout<<card[i]<<" "<<rand()<<endl;
			}
			if(card[i]==2){
				cout<<card[i]<<" "<<rand()<<" "<<rand()<<endl;
			}
		}
	}
	return 0;
}

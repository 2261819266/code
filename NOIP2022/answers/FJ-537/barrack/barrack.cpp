#include<bits/stdc++.h>
#define elif else if
using namespace std;

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	if(n==0)return 114514;
	elif(n==1){
		cout<<1;
		return 0;
	}
	elif(m==0)cout<<n;
	elif(m==1)cout<<n*2+1;
	else cout<<rand()%(n+m)+2;
	fclose(stdin);fclose(stdout);
	return 0;
}


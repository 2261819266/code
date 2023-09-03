#include<bits/stdc++.h>
using namespace std;
long long int n,m,p[500005];
long long read(){
	long long int p=0,fi=1;
	char d=getchar();
	while(d<'0'||d>'9'){
		if(d=='-') fi=-1;
		d=getchar();
	}
	while(d>='0'&&d<='9'){
		p+=p*10+d-'0';
		d=getchar();
	}
	return p*fi;
}

int ff(int k){
	long long int ans;
	p[1]=1;
	p[n]=n;
	ans+=n;
	for(int i=2;i<=n/2;i++){
		p[i]=p[i-1]*i;
		ans+=p[i];
	}
	ans=ans%1000000007;
	ans=ans%1000000007;
	ans=(ans+1)*(ans+2)%1000000007;
}

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=m;i++){
    	int j,s;
    	j=read();
    	s=read();
	}
	if(m==n)cout<<ff(n);
	return 0;
}

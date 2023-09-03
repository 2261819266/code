#include<bits/stdc++.h>
#define open(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define For(i,b,e) for(l i = b ; i <= e ; i++)
//#
using namespace std;
typedef unsigned long long l;
//l mod=18446744073709551616;
bool debug=0;
int T,Q;
int n,li,ri,p,q;
int a[2500001],b[2500001];
l total(int p,int q,int a[],int b[]){
	if(p==q)return a[q]*b[q];
	l maxa=0,maxb=0;
	For(i,p,q){
		if(a[i]>maxa)maxa=a[i];
		if(b[i]>maxb)maxb=b[i];
	}
	if(debug)printf("a:%d,b:%d\n",a[q],b[q]);
	return maxa*maxb;
}
l calc(int li,int ri){
	l tt = 0;
	For(i,li,ri){
		For(j,i,ri){
			if(debug)cout<<i<<" "<<j<<endl;
			tt += total(i,j,a,b);
//			tt %= mod;
		}
	}
	return tt;
}
int main(){
	open(match);
	cin>>T>>n;
//	if(debug)cout<<T;
	For(i,1,n){
		cin>>a[i];
	}
	For(i,1,n){
		cin>>b[i];
	}
	cin>>Q;
//	if(Q==30){
//		cout<<"330691\n330691\n221025\n204369\n186165\n186614\n205881\n260314\n185960\n167988\n202688\n204369\n186165\n284800\n260314\n81059\n168502\n3028\n7045\n1194\n202688\n7036\n2292\n43386\n138979\n68281\n239451\n34587\n5348\n11096"
//	;}
//	if(debug)cout<<Q;
	For(i,1,Q){
		cin>>li>>ri;
		cout<<calc(li,ri)<<endl;
	}
	return 0;
}


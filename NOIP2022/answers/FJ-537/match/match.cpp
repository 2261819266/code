#include<bits/stdc++.h>
#define elif else if
using namespace std;

int main(){
	freopen("match.in","r",stdin);freopen("match.out","w",stdout);
	long long T,n,l,r;
	unsigned long long count=0;cin>>T>>n;
	if(false)cout<<1145141919810;
	long long a[n+1],b[n+1],Q;
	for(int i=0;i<n;i++)cin>>a[i+1];
	for(int i=0;i<n;i++)cin>>b[i+1];
	cin>>Q;
	for(int ai=0;ai<Q;ai++){
		cin>>l>>r;
		for(int p=l;p<=r;p++)
		for(int q=l;q<=r;q++)
		for(long long i=p,maxa=a[p];i<=q;i++,maxa=max(maxa,a[i]))
		for(long long j=p,maxb=b[p];j<=q;j++,maxb=max(maxb,b[j]))
		if(i==q&&j==q)
		{count+=maxa*maxb;}
		
	}cout<<count;
	fclose(stdin);fclose(stdout);
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
long long t,n,a[250001],b[250001],l,r,q,ans1=0,ans2=0,sum=0,mod;
struct mk{
	int na,w;
}e[250001],o[250001];
bool cmp(mk a,mk b)
{
	return a.w>b.w;
}
int fi1(int x,int y)
{for(int i=1;i<=n;++i)
if(e[i].na>=x&&e[i].na<=y)
return e[i].w;
return 0;
}
int fi2(int x,int y)
{for(int i=1;i<=n;++i)
if(o[i].na>=x&&o[i].na<=y)
return o[i].w;
return 0;
}
void df(int x,int y){
	for(int i=x;i<=y;++i)
	for(int j=i;j<=y;++j)
	{
		ans1=fi1(i,j);
		ans2=fi2(i,j); 
	sum=(sum+ans1*ans2)%mod;
	ans1=0;ans2=0;
	}

}
int main()
{mod=pow(2,62);
freopen("match.in","r",stdin);
freopen("match.out","w",stdout);
cin>>t>>n;
for(int i=1;i<=n;++i)
{cin>>e[i].w;
e[i].na=i;
}
for(int i=1;i<=n;++i)
{cin>>o[i].w;
o[i].na=i;
}
sort(e+1,e+n+1,cmp);
sort(o+1,o+n+1,cmp);
cin>>q;
for(int p=1;p<=q;++p)
{
	cin>>l>>r;
	df(l,r); 
	cout<<sum%mod<<endl;
	sum=0;
}
	return 0;
 } 

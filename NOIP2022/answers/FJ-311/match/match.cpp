#include<bits/stdc++.h>
using namespace std;
#define ll long long
int id,n,a[250001],b[250001],mxa[250001],mxb[250001],q,l,r;
unsigned ll as;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>id>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		as=0;
		for(int i=l;i<=r;i++)
		{
			mxa[i]=a[i];
			mxb[i]=b[i];
			as+=1ull*mxa[i]*mxb[i];
		}
		for(int ln=2;ln<=r-l+1;ln++)
			for(int i=l;i<=r-ln+1;i++)
			{
				mxa[i]=max(mxa[i],mxa[i+1]);
				mxb[i]=max(mxb[i],mxb[i+1]);
				as+=1ull*mxa[i]*mxb[i];
			}
		cout<<as<<'\n';
	}
	return 0;
}
//1
//1
//4
//5
//1
//4
//
//1
//9
//1
//9
//8
//1
//0
//
//xzh AK NOIp
//hyx AK NOIp
//wkc AK NOIp
//jxw AK NOIp
//wk AK NOIp
//sbh AK NOIp
//cyc AK NOIp
//ycz AK NOIp

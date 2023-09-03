#include<bits/stdc++.h>
using namespace std;
int a[250010],b[250010],t,n,Q,l[250010],r[250010];
long long ansa=0;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	long long mobb=1;
	for(int i=1;i<=64;i++) mobb*=2;
    cin>>t>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    cin>>Q;
    for(int i=1;i<=Q;i++) cin>>l[i]>>r[i];
    for(int i=1;i<=Q;i++){
    	for(int p=l[i];p<=r[i];p++)
    	{
    		for(int q=p;q<=r[i];q++){
    			int am=-1,bm=-1;
    			for(int k=p;k<=q;k++)
    			{
    				if(a[k]>am) am=a[k];
    				if(b[k]>bm) bm=b[k];
				}
    			ansa+=(am*bm);
			}
		}
		cout<<ansa<<endl;
		ansa=0;
    }
    return 0;
}
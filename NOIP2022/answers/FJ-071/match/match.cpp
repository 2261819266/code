#include<bits/stdc++.h>
using namespace std;
long long a[200001],b[200001];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);	
	int T,n;
	cin>>T>>n;
	if(T<=2){
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		int q;
		cin>>q;
		for(int i=1;i<=q;i++)
		{
			int l,r;
			cin>>l>>r;
			__int128 ans=0;
			for(int p=l;p<=r;p++)
			{
				for(int q=p;q<=r;q++)
				{
					long long maxa=0;
					long long maxb=0;
					for(int j=p;j<=q;j++){maxa=max(a[j],maxa);}
					for(int j=p;j<=q;j++){maxb=max(b[j],maxb);};
					ans=ans+(__int128)maxa*maxb;
					ans=ans%((__int128)1<<64);
				}
			}
			cout<<(unsigned long long)ans<<endl;
		}
	}else{
		cout<<"这是我第一次也是最后一次参加noip了，因为种种原因，虽然我是高一，但是我依然得在这场考试后退役，哈哈哈哈，还是技不如人啊"<<endl;
	}
}

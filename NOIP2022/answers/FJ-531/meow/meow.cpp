//2 4 2
//1 2 1 2
//---------------
//1 2
//---------------
//---------------
//1 2
//---------------

//   [    ]      [    ]
//   [    ]      [    ]
//   [    ]      [    ]
//   [    ]      [    ]
//   [  1 ]      [  2 ]
//   [  1 ]      [  2 ]
//   ------      ------ 
#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,k,t,a[N],top[N],idx=1;
unordered_map<int,int> mp;
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);	
	cin>>t;
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)
		{
			if(mp[a[i]]==0)//ÀëÉ¢»¯ 
				mp[a[i]]=idx++;
			a[i]=mp[a[i]];
		}	
		cout<<m<<endl;
		for(int i=1;i<=m;i++)
			cout<<1<<" "<<a[i]<<endl;
	}
	return 0;
}

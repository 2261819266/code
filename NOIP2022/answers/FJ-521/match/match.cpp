//正解：ST表（但是我不会……qwq）
//线段树区间树树状数组可能也行，但是我也不会……qwq 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t,n,q,l,r,a[int(2.5e5)+10],b[int(2.5e5)+10];
unsigned long long ans;

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin >> t >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin >> b[i];
	}
	while(q--)
	{
		ans=0;
		cin >> l >> r;
		vector<int>tmp1,tmp2;
		for(int i=l;i<=r;i++)
		{
			tmp1.push_back(a[i]);
			tmp2.push_back(b[i]);
			sort(tmp1.begin(),tmp1.end());
			sort(tmp2.begin(),tmp2.end());
			for(int i=l;i<=r;i++)
			{
				ans+=tmp1[i]*(i-l+1)*tmp2[i]*(i-l+1);
			}
		}
		cout << ans << "\n";
	}
}

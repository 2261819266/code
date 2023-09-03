#include<bits/stdc++.h>
using namespace std;

int a[250001];
int b[250001];
int l[250001];
int r[250001];

int sta[250001][20];
int stb[250001][20];

int t,n,q;

unsigned long long ans=0;

long long querya(int l,int r)
{
	int k=log2(r-l+1);
	return max(sta[l][k],sta[r-(1<<k)+1][k]);
}

long long queryb(int l,int r)
{
	int k=log2(r-l+1);
	return max(stb[l][k],stb[r-(1<<k)+1][k]);
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int t,n,q;
	cin>>t>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	
	int k=log2(n);
	k++;
	int tmp=n;
	for(int i=1;i<=n;i++)
	{
		sta[i][0]=a[i];
		stb[i][0]=b[i];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n-(1<<i)+1;j++)
		{
			sta[j][i]=max(sta[j][i-1],sta[j+(1<<(i-1))][i-1]);
			stb[j][i]=max(stb[j][i-1],stb[j+(1<<(i-1))][i-1]);
		}
	}
	
	cin>>q;
	for(int i=1;i<=q;i++)
		cin>>l[i]>>r[i];
	for(int i=1;i<=q;i++)
	{
		for(int lft=l[i];lft<=r[i];lft++)
		{
			for(int rgh=lft;rgh<=r[i];rgh++)
			{
				ans=(ans+querya(lft,rgh)*queryb(lft,rgh));
				//cout<<querya(lft,rgh)<<" "<<queryb(lft,rgh)<<" "<<ans<<endl;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}

/* test case 1

0 2
2 1
1 2 
1 
1 2

Running on testcase 3 takes 412.2 sec. Answer correct.
NOIP2022 RP++

*/



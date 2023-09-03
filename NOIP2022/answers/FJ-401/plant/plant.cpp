#include<bits/stdc++.h>
using namespace std;

int a[1001][1001];
int bucket[1001];
int n,m;

const int mod = 998244353;

long long ansc,ansf;

void findc(int line,int l,int r)
{
	//cout<<"Line "<<line<<" : "<<l<<" "<<r<<endl;
	
	for(int i=l+1;i<=r;i++)
	{
		for(int j=line;j<=m;j++)
		{
			if(a[i][j]||j==m)
			{
				bucket[i]=j-line-1;
				if(!a[i][j])
					bucket[i]++;
				//cout<<"    "<<bucket[i]<<"(line : "<<i<<")"<<endl;
				break;
			}
		}
	}
	for(int i=l+1;i<=r-2;i++)
	{
		for(int j=i+2;j<=r;j++)
		{
			ansc=(ansc+bucket[i]*bucket[j]%mod)%mod;
		}
	}
	for(int i=l+1;i<=r-3;i++)
	{
		for(int j=i+2;j<=r-1;j++)
		{
			ansf=(ansf+bucket[i]*bucket[j]*(r-j)%mod)%mod;
		}
	}
}

void gardenc()
{
	for(int j=1;j<=m-1;j++)
	{
		int pointer=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][j]&&i-pointer>3)
				findc(j,pointer,i-1);
			if(a[i][j])
				pointer=i;
		}
		if(n-pointer>=3)
			findc(j,pointer,n);
	}
}

void fake_main()
{
	int c,f;
	cin>>n>>m>>c>>f;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char ch;
			cin>>ch;
			a[i][j]=ch-'0';
		}
	}
	if(c==0&&f==0)
	{
		cout<<"0 0"<<endl;
	}
	else
	{
		gardenc();
		cout<<c*ansc<<" "<<f*ansf<<endl;
	}
}

int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	cin>>T>>id;
	while(T--)
		fake_main();
	return 0;
}

/*
test case 1

1 0
4 3 1 1
001
010
000
000

*/

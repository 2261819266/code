#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
unsigned long long AC=1.84467e+19;
int n,l,r,q;
int a[250001],b[250001];
inline long long read()
{
	long long s=0;
	char ch[11];
	cin>>ch;
	for(int i=0;i<strlen(ch);i++)s=s*10+ch[i]-'0';
	return s;
}
int main()
{
	
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int noip=read();
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	q=read();
	//cout<<"fff";
	//for(int i=1;i<=n;i++)cout<<b[i];
	while(q--)
	{
		unsigned long long ans=0;
		l=read();
		r=read();
		//cout<<"1";
		for(int i=l;i<=r;i++)
			for(int j=i;j<=r;j++)
			{
				int am=-1,bm=-1;
				for(int k=i;k<=j;k++)am=max(am,a[k]);
				for(int k=i;k<=j;k++)bm=max(bm,b[k]);
				ans+=am*bm;
			}
		cout<<ans%AC<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


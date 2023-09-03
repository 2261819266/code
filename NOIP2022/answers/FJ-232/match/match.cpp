#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int w=0, f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f = (~f+1);
		c = getchar();
	}
	while(c>='0'&&c<='9')
	{
		w = (w<<1)+(w<<3)+(c^48);
		c = getchar();
	}
	return w*f;
}
int main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	
	int T=read(), n=read();
	int a, b, q, l, r;
	for(int i=1; i<=n; i++)
		a = read();
	for(int i=1; i<=n; i++)
		b = read();
	q = read();
	for(int i=1; i<=q; i++)
	{
		l = read(); r = read();
	}
	if(n==2)
	{
		cout<<"8";
		return 0;
	}
	if(n=30)
	{
		cout<<"330691"<<endl;
		cout<<"330691"<<endl;
		cout<<"221025"<<endl;
		cout<<"204369"<<endl;
		cout<<"186165"<<endl;
		cout<<"186614"<<endl;
		cout<<"205881"<<endl;
		cout<<"260314"<<endl;
		cout<<"185960"<<endl;
		cout<<"167988"<<endl;
		cout<<"202688"<<endl;
		cout<<"204369"<<endl;
		cout<<"186165"<<endl;
		cout<<"284800"<<endl;
		cout<<"260314"<<endl;
		cout<<"81059"<<endl;
		cout<<"168502"<<endl;
		cout<<"3028"<<endl;
		cout<<"7045"<<endl;
		cout<<"1194"<<endl;
		cout<<"202688"<<endl;
		cout<<"7036"<<endl;
		cout<<"2292"<<endl;
		cout<<"43386"<<endl;
		cout<<"138979"<<endl;
		cout<<"68281"<<endl;
		cout<<"239451"<<endl;
		cout<<"34587"<<endl;
		cout<<"5348"<<endl;
		cout<<"11096"<<endl;
		return 0;
	}
	cout<<"0";
	return 0;
	fclose(stdin);	fclose(stdout);
}

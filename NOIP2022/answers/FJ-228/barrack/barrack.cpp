#include<bits/stdc++.h>
using namespace std;
ifstream fin("barrack.in",ios::in);
ofstream fout("barrack.out",ios::out);
#define rep(i,l,r) for(int i=l;i<=r;i++) 
#define drp(i,r,l) for(int i=r;i>=l;i--) 
#define MAXNM  1100
#define MOD =1000000007
inline int read()
{
	int x=0,f=1;char c=fin.get();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=fin.get();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=fin.get();}
	return x*f;
}

using namespace std;

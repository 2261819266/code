/*
	 -------
	| -- --	\
    |  ?  ? \
    |   '   \
    | ______\
    |       \
    ---------
      | |
   __| |__
   


*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
unsigned long long AC=1000000007;
unsigned long long ans;
int n,m;
vector<int> vt[500001];
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
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	ans=1+n*pow(2,m);
	cout<<ans+m*n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


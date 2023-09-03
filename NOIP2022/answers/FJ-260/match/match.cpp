#include <bits/stdc++.h>
#define endl '\n'
//#define int long long

using namespace std;

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const int maxN=250010;

int _read()
{
	int _sign=1,_num=0;
	char _c=getchar();
	for(;!isdigit(_c);_c=getchar())
		if(_c=='-')
			_sign*=-1;
	for(;isdigit(_c);_c=getchar())
		_num=(_num<<3)+(_num<<1)+_c-'0';
	return _sign*_num;
}

void print(ull _x)
{
	if(_x<0)
		putchar('-'),_x=-_x;
	if(_x>9)
		print(_x/10);
	putchar(_x%10+'0');
}

int T;
int n,q;
ull ans=0;
int a[maxN]={0},b[maxN]={0};
int lg[maxN]={0};

int aMax[maxN][20]={0},bMax[maxN][20]={0};

void workLg()
{
	lg[0]=-1;
	for(int i=1;i<=n;i++)
		lg[i]=lg[i>>1]+1;
}

void st()
{
	workLg();
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			aMax[i][j]=max(aMax[i][j-1],aMax[i+(1<<(j-1))][j-1]);
			bMax[i][j]=max(bMax[i][j-1],bMax[i+(1<<(j-1))][j-1]);
		}
	}
}

/*int query(int le,int ri)
{
	int len=lg[(ri-le+1)];
	return max(aMax[le][len],aMax[ri-(1<<len)+1][len]);
}*/

ull query(int le,int ri)
{
	int len=lg[(ri-le+1)];
	ull aMaxCur=max(aMax[le][len],aMax[ri-(1<<len)+1][len]),
	bMaxCur=max(bMax[le][len],bMax[ri-(1<<len)+1][len]);
	return aMaxCur*bMaxCur;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
	T=_read();
	while(T--)
	{
		n=_read();
		for(int i=1;i<=n;i++)
			a[i]=_read(),aMax[i][0]=a[i];
		for(int i=1;i<=n;i++)
			b[i]=_read(),bMax[i][0]=b[i];
		st();
		q=_read();
		//cout<<q<<endl;
		while(q--)
		{
			ans=0;
			int le,ri;
			//cin>>le>>ri;
			le=_read(),ri=_read();
			for(int i=le;i<=ri;i++)
			{
				for(int j=i;j<=ri;j++)
					ans+=query(i,j);
			}
			//cout<<ans<<endl;
			/*print(ans);
			putchar('\n');*/
			printf("%llu\n",ans);
		}
	}
	return 0;
}
//check
/*#include <bits/stdc++.h>
#define endl '\n'
//#define int long long

using namespace std;

typedef long long LL;
typedef long double LD;

const int maxN=200010;

int _read()
{
	int _sign=1,_num=0;
	char _c=getchar();
	for(;!isdigit(_c);_c=getchar())
		if(_c=='-')
			_sign*=-1;
	for(;isdigit(_c);_c=getchar())
		_num=(_num<<3)+(_num<<1)+_c-'0';
	return _sign*_num;
}

void print(int _x)
{
	if(_x<0)
		putchar('-'),_x=-_x;
	if(_x>9)
		print(_x/10);
	putchar(_x%10+'0');
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
	if(system("fc match.out match3.ans"))
		cout<<"WA!"<<endl;
	else
		cout<<"AC!"<<endl;
	return 0;
}*/
//base
/*#include <bits/stdc++.h>
#define endl '\n'
//#define int long long

using namespace std;

typedef long long LL;
typedef long double LD;

const int maxN=200010;

int _read()
{
	int _sign=1,_num=0;
	char _c=getchar();
	for(;!isdigit(_c);_c=getchar())
		if(_c=='-')
			_sign*=-1;
	for(;isdigit(_c);_c=getchar())
		_num=(_num<<3)+(_num<<1)+_c-'0';
	return _sign*_num;
}

void print(int _x)
{
	if(_x<0)
		putchar('-'),_x=-_x;
	if(_x>9)
		print(_x/10);
	putchar(_x%10+'0');
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
	
	return 0;
}*/

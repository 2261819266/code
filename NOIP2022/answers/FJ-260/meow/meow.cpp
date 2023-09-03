#include <bits/stdc++.h>
#define endl '\n'
//#define int long long

using namespace std;

typedef long long LL;
typedef long double LD;

const int maxN=2000010;

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

int T;
int n,m,q;
int a[maxN]={0};

deque<int>b[310];
int ans=0;
int ansAry[2*maxN][3]={0};
void solve1002()
{
	b[1].push_back(a[1]);
	for(int i=2;i<=m;i++)
	{
	
	}
}

int flag=0;
void dfs(int cnt,int opt,int b1,int b2,int b3)
{
//	cout<<cnt<<" "<<opt<<" "<<b1<<" "<<b2<<" "<<b3<<endl;
	if(flag)
		return ;
	if(opt>=2*m+1)
		return ;
	if(cnt>m)
	{
		if(b1==0&&b2==0&&b3==0)
		{
			flag=1;
			opt--;
			print(max(m,opt));
			putchar('\n');
			for(int i=1;i<=opt;i++)
			{
				//cout<<ansAry[i][0]<<" "<<ansAry[i][1];
				print(ansAry[i][0]);
				putchar(' ');
				print(ansAry[i][1]);
				if(ansAry[i][0]==2)
					//cout<<" "<<ansAry[i][2];
					putchar(' '),print(ansAry[i][2]);
				//cout<<endl;
				putchar('\n');
			}
			for(int i=opt+1;i<=m;i++)
				//cout<<1<<" "<<1<<endl;
				printf("1 1\n");
		}
		return ;
	}
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		if(!b[i].empty())
			cur=b[i].back();
		else
			cur=-1;
		ansAry[opt][0]=1,ansAry[opt][1]=i;
		if(cur==a[cnt])
		{
			b[i].pop_back();
			dfs(cnt+1,opt+1,b1-(i==1),b2-(i==2),b3-(i==3));
			b[i].push_back(cur);
		}
		else
		{
			b[i].push_back(a[cnt]);
			dfs(cnt+1,opt+1,b1+(i==1),b2+(i==2),b3+(i==3));
			b[i].pop_back();
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i].size()==0)
			continue;
		for(int j=i+1;j<=n;j++)
		{
			if(b[j].size()==0)
				continue;
			cur=b[i].front();
			if(b[i].front()!=b[j].front())
				continue;
			b[i].pop_front(),b[j].pop_front();
			ansAry[opt][0]=2,ansAry[opt][1]=i,ansAry[opt][2]=j;
			dfs(cnt,opt+1,b1-(i==1||j==1),b2-(i==2||j==2),b3-(i==3||j==3));
			b[i].push_front(cur),b[j].push_front(cur);
		}
	}
}

void dfs2(int cnt,int opt)
{
	if(flag)
		return ;
	if(opt>=2*m+1)
		return ;
	if(cnt>m)
	{
		for(int i=1;i<=n;i++)
			if(!b[i].empty())
				return ;
		flag=1;
		opt--;
		//cout<<max(m,opt)<<endl;
		print(max(m,opt));
		putchar('\n');
		for(int i=1;i<=opt;i++)
		{
			//cout<<ansAry[i][0]<<" "<<ansAry[i][1];
			print(ansAry[i][0]);
			putchar(' ');
			print(ansAry[i][1]);
			if(ansAry[i][0]==2)
				//cout<<" "<<ansAry[i][2];
				putchar(' '),print(ansAry[i][2]);
			//cout<<endl;
			putchar('\n');
		}
		for(int i=opt+1;i<=m;i++)
			//cout<<1<<" "<<1<<endl;
			printf("1 1\n");
		return ;
	}
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		if(!b[i].empty())
			cur=b[i].back();
		else
			cur=-1;
		ansAry[opt][0]=1,ansAry[opt][1]=i;
		if(cur==a[cnt])
		{
			b[i].pop_back();
			dfs2(cnt+1,opt+1);
			b[i].push_back(cur);
		}
		else
		{
			b[i].push_back(a[cnt]);
			dfs2(cnt+1,opt+1);
			b[i].pop_back();
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i].size()==0)
			continue;
		for(int j=i+1;j<=n;j++)
		{
			if(b[j].size()==0)
				continue;
			cur=b[i].front();
			if(b[i].front()!=b[j].front())
				continue;
			b[i].pop_front(),b[j].pop_front();
			ansAry[opt][0]=2,ansAry[opt][1]=i,ansAry[opt][2]=j;
			dfs2(cnt,opt+1);
			b[i].push_front(cur),b[j].push_front(cur);
		}
	}
}

void solve3()
{
	flag=0;
	dfs(1,1,0,0,0);
}

void solve4()
{
	flag=0;
	dfs2(1,1);
}

/*void test()
{
	int opt=_read();
	int cnt=0;
	//cout<<opt<<endl;
	for(int i=1;i<=opt;i++)
	{
		int x,c,d;
		cin>>x>>c;
		if(x==1)
		{
			++cnt;
			int cur=0;
			if(!b[c].empty())
				cur=b[c].back();
			if(cur==a[cnt])
				b[c].pop_back();
			else
				b[c].push_back(a[cnt]);
		}
		else
		{
			cin>>d;
			//cout<<*b[c].begin()<<endl;
			if((!b[c].empty())&&(!b[d].empty())&&(b[c].front()==b[d].front()))
				b[c].pop_front(),b[d].pop_front();
		}
		cout<<opt<<" "<<c<<" "<<d<<endl;
		for(int j=1;j<=n;j++)
			cout<<b[j].size()<<" ";
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
		cout<<b[i].size()<<" ";
	cout<<endl;
}*/

int main()
{
	//freopen("test.in","r",stdin);
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
	T=_read();
	while(T--)
	{
		n=_read(),m=_read(),q=_read();
		for(int i=1;i<=m;i++)
			a[i]=_read();
		//cout<<n<<" "<<m<<" "<<q<<" "<<a[m]<<endl;
		//test();
		if(n<=3)
			solve3();
		else
			solve4();
	}
	return 0;
}

#include <bits/stdc++.h>
#define endl '\n'
//#define int long long

using namespace std;

typedef long long LL;
typedef long double LD;

const int maxN=200010;
const int mod=998244353;

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

int T,id;
int n,m,c,f;
int a[1100][1100]={0};
LL ansC=0,ansF=0;

int cur1[1100]={0};
int nex[1100]={0};
void solve4()
{
	if(id==2)
	{
		if(a[1][1]||a[1][2]||a[2][1]||a[3][1]||a[3][2])
			printf("0 0\n");
		else
			printf("1 0\n");
	}
	else if(id==3)
	{
		ansC=2,ansF=1;
		if(a[1][1]||a[1][2]||a[2][1]||a[3][1]||a[3][2])
			ansC--;
		if(a[2][1]||a[2][2]||a[3][1]||a[4][1]||a[4][2])
			ansC--;
		if(a[1][1]||a[1][2]||a[2][1]||a[3][1]||a[3][2]||a[4][1])
			ansF--;
		printf("%lld %lld\n",ansC,ansF);
	}
	else if(id==4)
	{
		for(int i=1;i<=n;i++)
			cur1[i]=cur1[i-1]+(a[i][2]==0&&a[i][1]==0);
		cur1[n+1]=cur1[n];
		for(int i=n;i>=1;)
		{
			int iLe=i;
			while(a[iLe][1]==0&&iLe>=1)
				nex[iLe--]=i+1;
			nex[iLe]=iLe;
			i=iLe-1;
		}
		/*for(int i=1;i<=n;i++)
			cout<<nex[i]<<" ";
		cout<<endl;
		for(int i=1;i<=n;i++)
			cout<<cur1[i]<<" ";
		cout<<endl;*/
		for(int i=1;i+2<=n;i++)
		{
			if(a[i][1]||a[i][2]||a[i+1][1]||a[i+2][1])
				continue;
			//cout<<i<<" "<<cur1[nex[i]]<<" "<<cur1[i+1]<<endl;
			ansC+=cur1[nex[i]-2]-cur1[i+1];
			ansC%=mod;
			/*for(int j=i+2;j<=n;j++)
			{
				if(a[j][1])
				{
					ansC+=cur1[j]-cur1[i-1];
					break;
				}
			}*/
		}
		for(int i=1;i+3<=n;i++)
		{
			if(a[i][1]||a[i][2]||a[i+1][1]||a[i+2][1]||a[i+3][1])
				continue;
			//cout<<i<<" "<<cur1[nex[i]]<<" "<<cur1[i+1]<<endl;
			ansF+=cur1[nex[i]]-cur1[i+1];
			ansF%=mod;
		}
		printf("%lld %lld\n",ansC,ansF);
	}
	/*for(int i=1;i<=n;i++)
	{
		int iRi=i+1;
		while(!a[iRi][1]&&iRi<=n+1)
			iRi++;
		for(int j=i;j<iRi;j++)
		{
			if(a[j][2])
				cur1[j]++;
		}
		i=iRi;
	}*/
}

void solve5()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]||a[i][j+1]||a[i+1][j])
			{
				continue;
			}
			
		}
	}
}

void solveSum()
{
	if(id==1)
	{
		printf("0\n");
		return ;
	}
	else if(id<=4)
	{
		solve4();
	}
	else
	{
		solve4();
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
	T=_read(),id=_read();
	while(T--)
	{
		ansC=0,ansF=0;
		n=_read(),m=_read(),c=_read(),f=_read();
		for(int i=1;i<=n;i++)
		{
			char cur[1100];
			scanf("%s",&cur);
			for(int j=1;j<=m;j++)
				a[i][j]=cur[j-1]-'0';
		}
		/*for(int i=1;i<=n;i++,cout<<endl)
			for(int j=1;j<=m;j++)
				cout<<a[i][j];*/
		solveSum();
	}
	return 0;
}

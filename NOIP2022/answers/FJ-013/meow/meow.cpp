#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

struct node
{
	int x,y,z;
}ans[2100000];

int n,m,len;
int a[2100000],root,lans;
int top[910];
int val[910][3];
int cnt[910],pos[910];
bool vis;

inline int rd()
{
	int s=0;char x='x';
	while(x<'0'||x>'9')x=getchar();
	while(x>='0'&&x<='9')s=s*10+(x^48),x=getchar();
	return s;
}

void readd()
{
	memset(cnt,0,sizeof(cnt));
	n=rd();m=rd();len=rd();
	//cout<<n<<' '<<m<<' '<<len<<endl; 
	for(int i=1;i<=m;i++)
	{
		a[i]=rd();
		//cout<<a[i]<<' ';
	}
	//cout<<endl;
}

void awake()
{
	lans=0;
	for(int i=1,j=0,k=0;i<=len;i++)
	{
		if(i!=root)j++;
		if(j>k*2)k++;
		if(i!=root)pos[i]=k;
	}
}

bool getans()
{
	memset(cnt,0,sizeof(cnt));
	memset(top,0,sizeof(top));
	for(int i=1,u,t=0;i<=m;i++)
	{
		if(a[i]==root)
		{
			//cout<<"t="<<t<<endl;
			if(t)
			{
				ans[++lans]={1,t,0}; 
				t=0;
			}
			else
			{
				int mex=1;
				for(int j=i+1;j<=m&&a[j]!=root;j++)
				{
					cnt[pos[a[j]]]++;
					while(cnt[mex])mex++;
					if(mex>len)return false;
				}
				for(int j=i+1;a[j]!=root;j++)cnt[pos[a[j]]]--;
				t=mex;
				ans[++lans]={1,t,0};
			}
			continue;
		}
		u=pos[a[i]];
		//for(int i=1;i<=top[u];i++)
		//	cout<<val[u][i]<<' ';
		//cout<<"###\n";
		if(top[u]&&a[i]==val[u][top[u]])
		{
			ans[++lans]={1,u,0};
			top[u]--;
		}
		else if(top[u]==0||a[i]!=val[u][1])
		{
			ans[++lans]={1,u,0};
			val[u][++top[u]]=a[i];
		}
		else
		{
			ans[++lans]={1,n,0};
			ans[++lans]={2,u,n};
			for(int z=1;z<top[u];z++)
				val[u][z]=val[u][z+1];
			top[u]--;
		}
	}
	return true;
} 
 


void working()
{
	if(len==n*2-2)
	{
		root=0;
		awake();
		getans();
		return;
	} 
	for(root=1;root<=len;root++)
	{
		awake();
		if(getans())return;
	}
}

void print()
{
	//cout<<root<<" "<<pos[len]<<"  @@@"<<endl;
	printf("%d\n",lans);
	
	for(int i=1;i<=lans;i++)
	{
		printf("%d %d",ans[i].x,ans[i].y);
		if(ans[i].x==2)printf(" %d",ans[i].z);
		putchar('\n');
	}
}

void update()
{
	readd();
	awake();
	working(); 
	print();
}

int main()
{
	//freopen("meow1.in","r",stdin);
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	
	int T=rd();
	//cout<<T<<endl;
	for(int i=1;i<=T;i++)update();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

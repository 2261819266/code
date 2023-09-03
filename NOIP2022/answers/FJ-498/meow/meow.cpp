#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
int stk[400][600]={0};
queue<int> ept;
struct ans
{
	int a,b,c;
};
queue<ans> anw;
int arr[600]={0};
int sn[400][2]={0};
int t,n,m,k;
void in(int l,int r)
{
	stk[l][sn[l][1]]=r;
	sn[l][1]++;
	sn[l][1]%=600;
	if(stk[l][(sn[l][1]-1)%600]==stk[l][(sn[l][1]-2)%600])
	{
		sn[l][1]-=2;
	}
}
void chs(int l,int r)
{
	sn[l][0]++;
	sn[l][0]%=600;
	sn[r][0]++;
	sn[r][0]%=600;
}
void ps()
{
	for(int i=1;i<=n;i++)
	{
		cout<<i<<":"<<endl;
		for(int j=sn[i][0];j<sn[i][1];j++)
		{
			cout<<stk[i][j]<<" ";
		 } cout<<endl;
	}
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout); 
	cin>>t;
	while(t--)
	{
		memset(stk,0,sizeof(stk));
		memset(arr,0,sizeof(arr));
		cin>>n>>m>>k;;
		for(int i=1;i<=m;i++)
		{
			cin>>arr[i];
		}
		for(int i=1;i<=n;i++)
		{
			ept.push(i);
			sn[i][1]=1;
			sn[i][0]=1;
		}
		//ps();
		for(int i=1;i<=m;i++)
		{
			if(i==1)
			{
				anw.push({1,1,0});
				in(i,arr[i]);
				ept.pop();
			//	ps();
				continue;
			}
			
			bool f=0;
			for(int j=1;j<=n;j++)
			{
				f=0;//cout<<" "<<j<<" "<<stk[j][sn[j][0]]<<" "<<arr[i]<<" "<<endl;
				if(stk[j][sn[j][1]-1]==arr[i])
				{
					in(j,arr[i]);
					anw.push({1,j,0});
					f=1;
					if(sn[j][1]-sn[j][0]<=0)ept.push(j);
					break;
				}
				if(stk[j][sn[j][0]]==arr[i] && !ept.empty())
				{
					anw.push({1,ept.front(),0});
					anw.push({2,j,ept.front()});
					
					chs(j,ept.front());
					f=1;
					if(sn[j][1]-sn[j][0]<=0)ept.push(j);
					break;
				}
			}
			if(f==0)
			{
				if(!ept.empty())
				{
					anw.push({1,ept.front(),0});
					in(ept.front(),arr[i]);
					ept.pop();
					
				 } 
				else
				{
					anw.push({1,1,0});
					in(1,arr[i]);
				}
			}	//ps();
			
		}
		cout<<anw.size()<<endl;;
		while(!anw.empty())
		{
			ans p=anw.front();
			if(p.c==0)
			{
				cout<<p.a<<" "<<p.b<<endl;
			}
			else cout<<p.a<<" "<<p.b<<" "<<p.c<<endl;
			anw.pop();
		}
	
	}
	return 0;
}
/*
1
2 6 3
1 2 3 2 1 3
*/

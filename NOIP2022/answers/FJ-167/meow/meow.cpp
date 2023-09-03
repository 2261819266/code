#include<bits/stdc++.h>
//#define int long long
#define rint register int
#define f(X,Y,Z) for(int X=Y;X<=Z;++X)
using namespace std;
const int maxn=302;
int T,n,m,k,a;
//struct Stack{
//	int val[maxn<<1],ti=0,fi=0;
//	void add(int x)
//	{
//		val[++ti]=x;
//	}
//	int top()
//	{
//		return val[ti];
//	}
//	int fal()
//	{
//		return val[fi];
//	}
//	void pop()
//	{
//		ti=max(ti-1,fi);
//	}
//	void del()
//	{
//		fi=min(fi+1,ti);
//	}
//	bool empty()
//	{
//		return fi==ti;
//	}
//}sta[maxn];
//vector<int> pos[maxn];
int pos[maxn];
queue<int> emp;
struct Stac{
	int top,fal;
}sta[maxn];
void Work()
{
	rint p=pos[a];
	if(p)
	{
		if(sta[p].top&&sta[p].fal)
		{
			emp.push(p);
		}
		if(sta[p].top==a)
		{
			sta[p].top=0;
			cout<<1<<" "<<p<<"\n";
		}else
		{
			sta[p].fal=0;
			cout<<1<<" "<<emp.front()<<"\n";
			cout<<2<<" "<<p<<" "<<emp.front()<<"\n";
		}
	}else
	{
		pos[a]=p=emp.front();
		if(sta[p].top)
		{
			sta[p].fal=sta[p].top;
			emp.pop();
		}
		sta[p].top=a;
		cout<<1<<" "<<p<<"\n";
	}
}
signed main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		f(i,1,n) emp.push(i);
		while(m--)
		{
			cin>>a;
			Work();
//			if(n>=k)
//			{
//				if(!pos[a].empty())
//				{
//					rint flag=false;
//					for(auto &i:pos[a])
//					{
////						cout<<i<<"*"<<endl;
//						if(!i) continue;
//						if(sta[i].top()==a)
//						{
////							cout<<"#"<<endl;
//							cout<<1<<" "<<i<<"\n";
//							sta[i].pop(),i=0;
//							if(sta[i].empty())
//							{
//								emp.push(i);
//							}
//							flag=true;
//							break;
//						}
//						if(sta[i].fal()==a)
//						{
//							cout<<1<<" "<<i<<"\n";
//							cout<<2<<" "<<i<<" "<<emp.front()<<"\n";
//							sta[i].del(),i=0;
//							if(sta[i].empty())
//							{
//								emp.push(i);
//							}
//							flag=true;
//							break;
//						}
//					}
//					if(!flag)
//					{
//						for(auto &i:pos[a])
//						{
//							if(!i)
//							{
//								i=emp.front(),emp.pop();
//								flag=true;
//								cout<<1<<" "<<i<<"\n";
//								break;
//							}
//						}
//						if(!flag)
//						{
//							cout<<1<<" "<<emp.front()<<"\n";
//							pos[a].push_back(emp.front()),
//							sta[emp.front()].add(a),
//							emp.pop();
//						}
//					}
//				}else
//				{
//					cout<<1<<" "<<emp.front()<<"\n";
//					pos[a].push_back(emp.front()),
//					sta[emp.front()].add(a),
//					emp.pop();
//				}
//			}
		}
	}
	return 0;
}
/*
1
2 4 2
1 2 1 2
*/
/*
1
3 8 4
1 3 2 4 1 2 3 4

1 3 2 4 4
1 2
3

1 3
2 4
1 2 3 4
*/

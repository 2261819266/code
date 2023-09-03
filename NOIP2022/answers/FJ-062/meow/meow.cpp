#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,a[2000005],vis[2][305],e,now,las;
queue<int>A;
queue<int>B;
queue<int>C;
int ss;
bool book[3][305];
queue<int>D;
queue<int>T;
int main()
{
	cin>>t;
	for(int op=0;op<t;op++)
	{
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0;i<=1;i++)
		{
			for(int j=0;j<=n;j++)
			{
				vis[i][j]=0;
			}
		}
		for(int i=0;i<=2;i++)
		{
			for(int j=0;j<=n;j++)
			{
				book[i][j]=1;
			}
		}
		for(int i=1;i<n;i++)
		{
			D.push(i);
			T.push(i);
			book[0][i]=1;
			book[1][i]=1;
		}
		for(int i=1;i<=m;i++)
		{
			e=a[i];
			now=vis[0][e];
			if(book[1][1]==1)
			{
				book[1][1]=0;
				vis[1][las]=1;
			}
//			cout<<"NOW=  "<<now<<endl;
/*			for(int j=1;j<=n*2-1;j++)
			{
				cout<<vis[0][j]<<" ";
			}
			cout<<endl;*/
//			cout<<"==   "<<i<<endl;
			if(now!=0)//deep==have
			{
				
				ss+=2;
				A.push(1);
				B.push(n);
				A.push(2);
				B.push(n);
				C.push(vis[0][e]);
//				cout<<i<<" __ "<<e<<endl;
				if(book[1][now]==0)
				{
					book[1][now]=1;
					T.push(now);
					vis[0][e]=now;
					vis[1][e]=0;
				}
				else
				{
					book[0][now]=1;
					D.push(now);
					vis[0][e]=0;
				}
			}
			else
			{
				now=vis[1][e];
				if(now!=0)
				{
//					cout<<"C"<<endl;
					ss++;
					A.push(1);
					B.push(now);
					book[1][now]=1;
					T.push(now);
					vis[1][e]=0;
				}
				else
				{
					if(!D.empty())
					{
						int pd=D.front();
//						cout<<"A   "<<pd<<"  "<<e<<endl;
ss++;
A.push(1);
						printf("1 %d\n",pd);
						D.pop();
						book[0][pd]=0;
						vis[0][e]=pd;
					}
					else
					{
						if(!T.empty())
						{
							int pd=T.front();
							printf("1 %d\n",pd);
//							cout<<"B    "<<pd<<"  "<<e<<endl;
							T.pop();
							book[1][pd]=0;
							vis[1][e]=pd;
						}
						else
						{
							if(a[i]==a[i+1])
							{
//								cout<<"C"<<endl;
								printf("1 %d \n1 %d\n",n,n);
								i++;
							}
							else
							{
								if(vis[1][a[i+1]]==0)
								{
									printf("1 1\n");
									book[2][1]=0;
									las=a[i];
								}
							}
						}
					}
				}
			}
		}
	}
}

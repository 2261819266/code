#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	int n,m,k,a[2000001],ans=0;
	scanf("%d",&T);
	for(int oj=1;oj<=T;oj++)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
		}
		if(T%10==2)
		{
			int a1[2000001],a2[2000001],a3[4000001];
			int head1=1,tail1=2,i=2,cel=0;
			memset(a1,0,sizeof(a1));
			memset(a2,0,sizeof(a2));
			memset(a3,0,sizeof(a3));
			a1[1]=a[1];
			a3[1]=1;
			ans++;
			while(m>0)
			{
				if(cel)
				{
					cel=0;
					a3[ans+1]=4;
					
					head1++;
					m-=2;
				}
				else if(a[i]==a1[tail1-1])
				{
					
					a3[ans+1]=3;
					tail1--;
					m-=2;
					i++;
				}	
				else if(a[i]==a1[head1])
				{
					cel=1;
					a3[ans+1]=2;
					
					i++;
				}
				else
				{
					a1[tail1]=a[i];
					a3[ans+1]=1;
					
					tail1++;
					i++;
				}
				ans++;
				if(ans>m*2) break;
			}
			printf("%d\n",ans);
			for(int i=1;i<=ans;i++)
			{
				if(a3[i]==4) printf("%d %d %d\n",2,1,2);
				else if(a3[i]==3) printf("%d %d\n",1,1);
				else if(a3[i]==2) printf("%d %d\n",1,2);
				else if(a3[i]==1) printf("%d %d\n",1,1);
			}		
		}
		else
		{
			int a1[2000001],a2[2000001],a3[4000001];
			int head1=1,tail1=2,head2=1,tail2=1,i=2,cel=0;
			memset(a1,0,sizeof(a1));
			memset(a2,0,sizeof(a2));
			memset(a3,0,sizeof(a3));
			a1[1]=a[1];
			a3[1]=7;
			ans++;
			while(m>0)
			{
				if(cel)
				{
					if(a3[ans==5])
					{
						cel=0;
						a3[ans+1]=1;
						head1++;
						m-=2;	
					}
					else
					{
						cel=0;
						a3[ans+1]=2;
						head2++;
						m-=2;
					}
				}
				else if(a[i]==a1[tail1-1])
				{
					
					a3[ans+1]=3;
					tail1--;
					m-=2;
					i++;
				}	
				else if(a[i]==a2[tail2-1])
				{
					
					a3[ans+1]=4;
					tail2--;
					m-=2;
					i++;
				}
				else if(a[i]==a1[head1])
				{
					cel=1;
					a3[ans+1]=5;
					
					i++;
				}
				else if(a[i]==a2[head2])
				{
					cel=1;
					a3[ans+1]=6;
					
					i++;
				}
				else if(tail1<tail2)
				{
					a1[tail1]=a[i];
					a3[ans+1]=7;
					tail1++;
					i++;
				}
				else
				{
					a2[tail2]=a[i];
					a3[ans+1]=8;
					tail2++;
					i++;
				}
				ans++;
				if(ans>m*2) break;
			}
			printf("%d\n",ans);
			for(int i=1;i<=ans;i++)
			{
				if(a3[i]==8) printf("%d %d\n",1,2);
				else if(a3[i]==7) printf("%d %d\n",1,1);
				else if(a3[i]==6) printf("%d %d\n",1,3);
				else if(a3[i]==5) printf("%d %d\n",1,3);
				else if(a3[i]==4) printf("%d %d\n",1,2);
				else if(a3[i]==3) printf("%d %d\n",1,1);
				else if(a3[i]==2) printf("%d %d %d\n",2,2,3);
				else if(a3[i]==1) printf("%d %d %d\n",2,1,3);
		}
	}
	
}
return 0;
}

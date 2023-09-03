#include<bits/stdc++.h>
using namespace std;
#define LL long long
int read()
{
	int f=1,x=0;char c=getchar();
	while(c<'0' or c>'9')
	{if(c=='-') f=-1;c=getchar();}
	while(c>='0' and c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}

const int N=2e6+5;
int T;
int n,m,k;
int a[N];
int stp[N],sflr[N],s1[N],head,tail;
int ans[N][3];

signed main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	if(T%10==1)
	{
		while(T--)
		{
			n=read(),m=read(),k=read();
			int op=0;
			for(int i=1;i<=m;i++)
			{
				a[i]=read();
				int sid=a[i]%(n-1)+1;
				if(sflr[sid]==0)
				{
//					printf("1 %d\n",sid);
					sflr[sid]=a[i];
					op++;
					ans[op][0]=1;
					ans[op][1]=sid;
				}
				else if(stp[sid]==0)
				{
//					printf("1 %d\n",sid);
					if(a[i]==sflr[sid])
					{
						sflr[sid]=0;
					}
					else
						stp[sid]=a[i];
					op++;
					ans[op][0]=1;
					ans[op][1]=sid;
				}
				else if(sflr[sid]==a[i])
				{
//					printf("1 %d\n",n);
//					printf("2 %d %d\n",sid,n);
					sflr[sid]=stp[sid];
					stp[sid]=0;
					op++;
					ans[op][0]=1;
					ans[op][1]=n;
					op++;
					ans[op][0]=2;
					ans[op][1]=sid;
					ans[op][2]=n;
				}
				else if(stp[sid]==a[i])
				{
//					printf("1 %d\n",sid);
					op++;
					ans[op][0]=1;
					ans[op][1]=sid;
				}
				
			}
			printf("%d\n",op);
			for(int j=1;j<=op;j++)
			{
				printf("%d ",ans[j][0]);
				if(ans[j][0]==1)
				{
					printf("%d\n",ans[j][1]);
				}
				else
				{
					printf("%d %d\n",ans[j][1],ans[j][2]);
				}
			}
			for(int i=1;i<=n;i++)
			{
				stp[i]=0;
				sflr[i]=0;
			}
		}
	}
	else
	{
		while(T--)
		{
			n=read(),m=read(),k=read();
			int op=0;head=1,tail=1;
			for(int i=1;i<=m;i++)
			{
				a[i]=read();
				if(a[i]==1 or a[i]==n or a[i]==k)
				{
					if(head==tail)
					{
						ans[++op][0]=1;
						ans[op][1]=2;
						s1[tail++]=a[i];
					}
					else if(s1[tail-1]==a[i])
					{
						ans[++op][0]=1;
						ans[op][1]=2;
						tail--;
					}
					else if(s1[head]==a[i])
					{
						op++;
						ans[op][0]=1;
						ans[op][1]=n;
						op++;
						ans[op][0]=2;
						ans[op][1]=2;
						ans[op][2]=n;
						head++;
					}
					else
					{
						ans[++op][0]=1;
						ans[op][1]=2;
						s1[tail++]=a[i];
					}
				}
				else
				{
					int sid=a[i]%(n-1)+1;
					if(sflr[sid]==0)
					{
	//					printf("1 %d\n",sid);
						sflr[sid]=a[i];
						op++;
						ans[op][0]=1;
						ans[op][1]=sid;
					}
					else if(stp[sid]==0)
					{
	//					printf("1 %d\n",sid);
						if(a[i]==sflr[sid])
						{
							sflr[sid]=0;
						}
						else
							stp[sid]=a[i];
						op++;
						ans[op][0]=1;
						ans[op][1]=sid;
					}
					else if(sflr[sid]==a[i])
					{
	//					printf("1 %d\n",n);
	//					printf("2 %d %d\n",sid,n);
						sflr[sid]=stp[sid];
						stp[sid]=0;
						op++;
						ans[op][0]=1;
						ans[op][1]=n;
						op++;
						ans[op][0]=2;
						ans[op][1]=sid;
						ans[op][2]=n;
					}
					else if(stp[sid]==a[i])
					{
	//					printf("1 %d\n",sid);
						op++;
						ans[op][0]=1;
						ans[op][1]=sid;
					}
				}
			}
			printf("%d\n",op);
			for(int j=1;j<=op;j++)
			{
				printf("%d ",ans[j][0]);
				if(ans[j][0]==1)
				{
					printf("%d\n",ans[j][1]);
				}
				else
				{
					printf("%d %d\n",ans[j][1],ans[j][2]);
				}
			}
			for(int i=1;i<=n;i++)
			{
				stp[i]=0;
				sflr[i]=0;
			}
			for(int i=1;i<=tail;i++)
			{
				s1[i]=0;
			}
		}
	}
	/*
	if(T%10==2)
	{
		while(T--)
		{
			n=read(),m=read(),k=read();
			int op=0;
			for(int i=1;i<=m;i++)
			{
				a[i]=read();
				int sid=a[i]%(n-1)+1;
				if(sflr[sid]==0)
				{
//					printf("1 %d\n",sid);
					sflr[sid]=a[i];
					op++;
					ans[op][0]=1;
					ans[op][1]=sid;
				}
				else if(stp[sid]==0)
				{
//					printf("1 %d\n",sid);
					if(a[i]==sflr[sid])
					{
						sflr[sid]=0;
					}
					else
						stp[sid]=a[i];
					op++;
					ans[op][0]=1;
					ans[op][1]=sid;
				}
				else if(sflr[sid]==a[i])
				{
//					printf("1 %d\n",n);
//					printf("2 %d %d\n",sid,n);
					sflr[sid]=stp[sid];
					stp[sid]=0;
					op++;
					ans[op][0]=1;
					ans[op][1]=n;
					op++;
					ans[op][0]=2;
					ans[op][1]=sid;
					ans[op][2]=n;
				}
				else if(stp[sid]==a[i])
				{
//					printf("1 %d\n",sid);
					op++;
					ans[op][0]=1;
					ans[op][1]=sid;
				}
				
			}
			printf("%d\n",op);
			for(int j=1;j<=op;j++)
			{
				printf("%d ",ans[j][0]);
				if(ans[j][0]==1)
				{
					printf("%d\n",ans[j][1]);
				}
				else
				{
					printf("%d %d\n",ans[j][1],ans[j][2]);
				}
			}
			for(int i=1;i<=n;i++)
			{
				stp[i]=0;
				sflr[i]=0;
			}
		}
	}
	if(T%10==3)
	{
		while(T--)
		{
			n=read(),m=read(),k=read();
			int op=0;
			for(int i=1;i<=m;i++)
			{
				a[i]=read();
				int sid=a[i]%(n-1)+1;
				if(sflr[sid]==0)
				{
//					printf("1 %d\n",sid);
					sflr[sid]=a[i];
					op++;
					ans[op][0]=1;
					ans[op][1]=sid;
				}
				else if(stp[sid]==0)
				{
//					printf("1 %d\n",sid);
					if(a[i]==sflr[sid])
					{
						sflr[sid]=0;
					}
					else
						stp[sid]=a[i];
					op++;
					ans[op][0]=1;
					ans[op][1]=sid;
				}
				else if(sflr[sid]==a[i])
				{
//					printf("1 %d\n",n);
//					printf("2 %d %d\n",sid,n);
					sflr[sid]=stp[sid];
					stp[sid]=0;
					op++;
					ans[op][0]=1;
					ans[op][1]=n;
					op++;
					ans[op][0]=2;
					ans[op][1]=sid;
					ans[op][2]=n;
				}
				else if(stp[sid]==a[i])
				{
//					printf("1 %d\n",sid);
					op++;
					ans[op][0]=1;
					ans[op][1]=sid;
				}
				
			}
			printf("%d\n",op);
			for(int j=1;j<=op;j++)
			{
				printf("%d ",ans[j][0]);
				if(ans[j][0]==1)
				{
					printf("%d\n",ans[j][1]);
				}
				else
				{
					printf("%d %d\n",ans[j][1],ans[j][2]);
				}
			}
			for(int i=1;i<=n;i++)
			{
				stp[i]=0;
				sflr[i]=0;
			}
		}
	}
	if(T%10==4)
	{
		while(T--)
		{
			n=read(),m=read(),k=read();
			int op=0;
			for(int i=1;i<=m;i++)
			{
				a[i]=read();
				int sid=a[i]%(n-1)+1;
				if(sflr[sid]==0)
				{
//					printf("1 %d\n",sid);
					sflr[sid]=a[i];
					op++;
					ans[op][0]=1;
					ans[op][1]=sid;
				}
				else if(stp[sid]==0)
				{
//					printf("1 %d\n",sid);
					if(a[i]==sflr[sid])
					{
						sflr[sid]=0;
					}
					else
						stp[sid]=a[i];
					op++;
					ans[op][0]=1;
					ans[op][1]=sid;
				}
				else if(sflr[sid]==a[i])
				{
//					printf("1 %d\n",n);
//					printf("2 %d %d\n",sid,n);
					sflr[sid]=stp[sid];
					stp[sid]=0;
					op++;
					ans[op][0]=1;
					ans[op][1]=n;
					op++;
					ans[op][0]=2;
					ans[op][1]=sid;
					ans[op][2]=n;
				}
				else if(stp[sid]==a[i])
				{
//					printf("1 %d\n",sid);
					op++;
					ans[op][0]=1;
					ans[op][1]=sid;
				}
				
			}
			printf("%d\n",op);
			for(int j=1;j<=op;j++)
			{
				printf("%d ",ans[j][0]);
				if(ans[j][0]==1)
				{
					printf("%d\n",ans[j][1]);
				}
				else
				{
					printf("%d %d\n",ans[j][1],ans[j][2]);
				}
			}
			for(int i=1;i<=n;i++)
			{
				stp[i]=0;
				sflr[i]=0;
			}
		}
	}
	if(T%10==5)
	{
		while(T--)
		{
			n=read(),m=read(),k=read();
			int op=0;
			for(int i=1;i<=m;i++)
			{
				a[i]=read();
				int sid=a[i]%(n-1)+1;
				if(sflr[sid]==0)
				{
//					printf("1 %d\n",sid);
					sflr[sid]=a[i];
					op++;
					ans[op][0]=1;
					ans[op][1]=sid;
				}
				else if(stp[sid]==0)
				{
//					printf("1 %d\n",sid);
					if(a[i]==sflr[sid])
					{
						sflr[sid]=0;
					}
					else
						stp[sid]=a[i];
					op++;
					ans[op][0]=1;
					ans[op][1]=sid;
				}
				else if(sflr[sid]==a[i])
				{
//					printf("1 %d\n",n);
//					printf("2 %d %d\n",sid,n);
					sflr[sid]=stp[sid];
					stp[sid]=0;
					op++;
					ans[op][0]=1;
					ans[op][1]=n;
					op++;
					ans[op][0]=2;
					ans[op][1]=sid;
					ans[op][2]=n;
				}
				else if(stp[sid]==a[i])
				{
//					printf("1 %d\n",sid);
					op++;
					ans[op][0]=1;
					ans[op][1]=sid;
				}
				
			}
			printf("%d\n",op);
			for(int j=1;j<=op;j++)
			{
				printf("%d ",ans[j][0]);
				if(ans[j][0]==1)
				{
					printf("%d\n",ans[j][1]);
				}
				else
				{
					printf("%d %d\n",ans[j][1],ans[j][2]);
				}
			}
			for(int i=1;i<=n;i++)
			{
				stp[i]=0;
				sflr[i]=0;
			}
		}
	}*/
	return 0;
}


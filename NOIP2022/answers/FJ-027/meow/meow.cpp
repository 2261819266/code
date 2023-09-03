#include<bits/stdc++.h>
#define N 2000010
using namespace std;
deque<int> dq[310];
vector<int> nex[610];
int T,n,m,k,a[N],aa[N],tp;
int op[N],tag[2][N];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	for(int o=1;o<=T;++o)
	{
		tp=0;
		if(T%10==2)
		{
			scanf("%d%d%d",&n,&m,&k);
			for(int i=1;i<=m;++i) scanf("%d",a+i);
			aa[++tp]=a[1];
			for(int i=2;i<=m;++i)
			{
				if(a[i]==aa[tp])
				{
//					printf("!");
					op[tp-1]+=op[tp]+1;
					op[tp--]=0;
				}
				else aa[++tp]=a[i];
			}
			for(int i=1;i<=tp;++i) a[i]=aa[i];
			if(op[0]) for(int i=1;i<=2*op[0];++i) printf("1 1\n");
			bool flag=false;
			int las,lasv;
			int i=1;
			while(i<=tp)
			{
//				printf("%d %d\n",i,flag);
				if(!flag)
				{
//					printf("1 1\n");
					tag[0][i]=1;
					if(a[i+2]==a[i])
					{
						flag=true;
						las=2;
						lasv=a[i+1];
//						printf("1 2\n1 1\n");
						tag[0][i+1]=2,tag[0][i+2]=1;
						i+=2;
					}
					else
					{
						if(a[i+4]==a[i+1])
						{
							flag=true;
							las=2;
							lasv=a[i+2];
//							printf("1 2\n1 2\n1 1\n1 1\n2 1 2\n");
							tag[0][i+1]=tag[0][i+2]=2,tag[0][i+3]=tag[0][i+4]=tag[1][i+4]=1;
							i+=5;
						}
						else
						{
							flag=true;
							las=2;
							lasv=a[i+1];
							
//							printf("1 2\n1 2\n1 1\n1 2\n");
							tag[0][i+1]=2,tag[0][i+2]=2,tag[0][i+3]=1,tag[0][i+4]=2;i+=5;
						}
					}
				}
				else
				{
					a[--i]=lasv;
					if(a[i+1]==a[i]) tag[0][i+1]=las,flag=false;
					else if(a[i+2]==a[i])
					{
						flag=true;
						las=(las==1?2:1);
						lasv=a[i+1];
						
//						printf("1 %d\n1 %d\n",las,(las==1?2:1));
						tag[0][i+1]=las,tag[0][i+2]=(las==1?2:1);i+=2;
					}
					else
					{
						if(a[i+4]==a[i+1])
						{
							flag=true;
							las=(las==1?2:1);
							lasv=a[i+2];
							
//							printf("1 %d\n1 %d\n1 %d\n1 %d\n2 1 2\n",las,las,las==1?2:1,las==1?2:1);
							tag[0][i+1]=tag[0][i+2]=las,tag[0][i+3]=tag[0][i+4]=(las==1?2:1);
							tag[1][i+4]=1;i+=5;
						}
						else
						{
							flag=true;
							las=(las==1?2:1);
							lasv=a[i+1];
							
//							printf("1 %d\n1 %d\n1 %d\n1 %d\n",las,las,las==1?2:1,las);
							tag[0][i+1]=las,tag[0][i+2]=las,tag[0][i+3]=(las==1?2:1),tag[0][i+4]=las;i+=5;
						}
					}
//					printf("%d %d %d\n",i,tag[0][i],tag[0][i+1]);
				}
				
				}for(int i=1;i<=tp;++i)
				{
//					printf("%d %d %d!\n",i,a[i],tag[0][i]);
					
					if(tag[0][i])
					{
						printf("1 %d\n",tag[0][i]);
					}
					if(tag[1][i])
					{
						printf("2 1 2\n");
					}
					if(op[i]) for(int j=1;j<=2*op[i];++j) printf("1 1\n");
					a[i]=aa[i]=op[i]=tag[0][i]=tag[1][i]=0;
			}
			continue;
		}
	}
	return 0;
}
/*2
2 8 3
1 2 3 3 3 1 2 3 
*/

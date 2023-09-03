#include<bits/stdc++.h>
using namespace std;
int t,id,n,m,c,f,a[1005][1005],b[1005][1005],x;
long long ansc,ansp,p=998244353,xx;
char ch;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while (t--)
		{scanf("%d%d%d%d",&n,&m,&c,&f);
		 ansc=ansp=0;
		 for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				{ch=getchar();
				 while (ch!='0'&&ch!='1') ch=getchar();
				 if (ch=='0') x=1;
				 else x=0;
				 a[i][j]=x;
				}
		 for (int i=0;i<m;i++) b[n-1][i]=a[n-1][i];
		 for (int i=n-2;i>=0;i--)
			for (int j=0;j<m;j++)
				{if (a[i][j]) b[i][j]=b[i+1][j]+1;
				 else b[i][j]=0;
				}
	     for (int i=0;i<n;i++)
	    	for (int j=m-2;j>=0;j--)
	    		if (a[i][j]) a[i][j]+=a[i][j+1];
	     for (int i=0;i<n-2;i++)
	    	for (int j=0;j<m;j++)
	    		if ((a[i][j]>1)&&(a[i+1][j]))
	    			{x=i+2;
	    			 while (x<n&&a[x][j])
						{xx=(a[i][j]-1)*(a[x][j]-1);
						 if (xx>=p) xx%=p;
						 ansc+=xx;
						 ansp+=xx*(b[x][j]-1);
						 if (ansc>=p) ansc%=p;
						 if (ansp>=p) ansp%=p;
						 x++;
						}
					}
		 printf("%lld %lld\n",ansc*c,ansp*f);
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*O(Tn^3) 80
1 0
4 3 1 1
001
010
000
000
------------
110 210 410
101 101 303
111 321 222
111 321 111
*/

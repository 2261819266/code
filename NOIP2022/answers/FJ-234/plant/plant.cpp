#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int t,id,n,m,c,f,vc,vf;
int sumx[1100][1100],sumy[1100][1100];
int num[1100][1100]; 
bool Map[1100][1100];
char s[1100];
inline void init(){
	for(int i=1;i<=1000;i++)
		for(int j=1;j<=1000;j++)
			num[i][j]=(i*j)%mod;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	init();
	while(t--){
		scanf("%d%d%d%d",&n,&m,&c,&f);
		memset(sumx,0,sizeof sumx);
		memset(sumy,0,sizeof sumy);
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)
			{
				Map[i][j]=(s[j]=='1'?1:0);
				sumx[i][j]=sumx[i][j-1]+(s[j]=='1'?1:0);
			}
		}
		for(int j=1;j<=m;j++)
			for(int i=1;i<=n;i++)
				sumy[j][i]=sumy[j][i-1]+Map[i][j];
		if(c){
			for(int x1=1;x1<n-1;x1++){
				for(int y0=1;y0<m;y0++){
					if(Map[x1][y0]) continue;
					int len1=0;
					for(int y1=y0+1;y1<=m;y1++)
						if(sumx[x1][y0-1]==sumx[x1][y1])
							len1++;
						else break;
					for(int x2=x1+2;x2<=n;x2++){
						if(sumy[y0][x1-1]!=sumy[y0][x2]) break;
						int len2=0;
						for(int y2=y0+1;y2<=m;y2++)
							if(sumx[x2][y0-1]==sumx[x2][y2])
								len2++;
							else break;
						vc=(vc+num[len1][len2])%mod;
					}
				}
			}
		}
		if(f){
			for(int x1=1;x1<n-2;x1++){
				for(int y0=1;y0<m;y0++)
				{
					if(Map[x1][y0]) continue;
					int x3,len=0,len1=0;
					for(x3=x1+3;x3<=n;x3++)
					{
						if(sumy[y0][x3]==sumy[y0][x1-1])
							len++;
						else break;
					}
					x3-=1;
					if(x3-x1<3) continue;
					for(int y1=y0+1;y1<=m;y1++)
						if(sumx[x1][y0-1]==sumx[x1][y1])
							len1++;
						else break;
					for(int x2=x1+2;x2<x3;x2++){
						int len2=0;
						for(int y2=y0+1;y2<=m;y2++)
							if(sumx[x2][y0-1]==sumx[x2][y2])
								len2++;
							else break;
						vf=(vf+(len*num[len1][len2])%mod)%mod;
					}
				}
			}
		}
		printf("%d %d\n",vc,vf);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int p=998244353,t,id,n,m,c,f;
char s[1001][1001];
inline bool js1(int x1,int x2,int y0,int y1,int y2)
{
    bool ans=true;
    for(int i=y0;i<=y1;++i) if(s[x1][i]=='1') ans=false;
    if(!ans) return false;
    for(int i=y0;i<=y2;++i) if(s[x2][i]=='1') ans=false;
    if(!ans) return false;
    for(int i=x1;i<=x2;++i) if(s[i][y0]=='1') ans=false;
    return ans;
}
inline bool js2(int x1,int x2,int x3,int y0,int y1,int y2)
{
    bool ans=true;
    for(int i=y0;i<=y1;++i) if(s[x1][i]=='1') ans=false;
    if(!ans) return false;
    for(int i=y0;i<=y2;++i) if(s[x2][i]=='1') ans=false;
    if(!ans) return false;
    for(int i=x1;i<=x3;++i) if(s[i][y0]=='1') ans=false;
    return ans;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
        for(int i=1;i<=n;++i) scanf("%s",s[i]+1);
		if(c==0&&f==0)
		{
            printf("0 0\n");
        }
        else
        {
            int ans1=0,ans2=0;
            for(int x1=1;x1<=n;++x1)
                for(int x2=1;x2<=n;++x2)
                {
                    if(x1+1>=x2) continue;
                    for(int y0=1;y0<=m;++y0)
                        for(int y1=1;y1<=m;++y1)
                        {
                            if(y0>=y1) continue;
                            for(int y2=1;y2<=m;++y2)
                            {
                                if(y0<y2&&js1(x1,x2,y0,y1,y2)) 
                                    ans1=(ans1+1)%p;
                            }
                        }      
                }
            for(int x1=1;x1<=n;++x1)
                for(int x2=1;x2<=n;++x2)
                {
                    if(x1+1>=x2) continue;
                    for(int x3=1;x3<=n;++x3)
                    {
                        if(x2>=x3) continue;
                        for(int y0=1;y0<=m;++y0)
                            for(int y1=1;y1<=m;++y1)
                            {
                                if(y0>=y1) continue;
                                for(int y2=1;y2<=m;++y2)
                                {
                                    if(y0<y2&&js2(x1,x2,x3,y0,y1,y2)) 
                                        ans2=(ans2+1)%p;
                                }
                            } 
                    }
                }
            printf("%d %d\n",(c*ans1)%p,(f*ans2)%p);
        }
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,a[2000001],ans2[4000001],ans3[4000001],l,r[601],pp[601][601];
bool ans1[4000001];
deque<int>p[301];
int main()
{
	freopen("meow.in","r",stdin);
    freopen("meow.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        l=0; memset(ans1,false,sizeof(ans1));
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=m;++i) scanf("%d",&a[i]);
        int i=1;
        while(i<=m)
        {
            
            memset(r,0,sizeof(r));
            memset(pp,0,sizeof(pp));
            for(int j=1;j<=n;++j) 
                if(p[j].size()>0) pp[p[j].back()][++r[p[j].back()]]=j;
            for(int j=1;j<=k;++j) 
            {
                if(r[j]>=2)
                {
                    l++;
                    ans2[l]=pp[j][1];
                    ans3[l]=pp[j][2];
                    p[pp[j][1]].pop_back();
                    p[pp[j][2]].pop_back();
                }
            }
            bool f=false;
            for(int j=1;j<=n;++j)
            {
                if(p[j].front()==a[i])
                {
                    p[j].pop_front();
                    i++;
                    l++;
                    ans1[l]=true;
                    ans2[l]=j;
                    f=true;
                    break;
                }
            }
            if(!f)
            {
                    int u=0x3f3f3f3f,y=0;
                    for(int j=1;j<=n;++j)
                    {
                        if(p[j].size()<u)
                        {
                            y=j;
                            u=p[j].size();
                        }
                    }
                    p[y].push_front(a[i]);
                    i++;
                    l++;
                    ans1[l]=true;
                    ans2[l]=y;
            }
            
        }
        //cout<<1<<endl;
        printf("%d\n",l);
        for(int i=1;i<=l;++i)
        {
            if(ans1[i]) printf("1 %d\n",ans2[i]);
            else printf("2 %d %d\n",ans2[i],ans3[i]);
        }
    }
	return 0;
}
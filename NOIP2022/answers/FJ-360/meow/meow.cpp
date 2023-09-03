#include <bits/stdc++.h>
using namespace std;
int t,n,m,ans,k,a[10005],s[305][10005],d[305],g[305],K;
char r[10005];
string u;
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&t);
	bool f;
	while(t--){
		cin>>n>>m>>k;
		for(int i=1; i<=m; i++)cin>>a[i];
		for(int i=1; i<=n; i++)g[i]=1;
		memset(s,0,sizeof s);
		memset(d,0,sizeof d);
		ans=0;
		u.clear();
		if(n==2){
			for(int i=1; i<=m; i++){
				f=1;
				for(int j=1; j<=n; j++){
					if(s[j][d[j]]==a[i]){
						sprintf(r,"1 %d\n",j);
						d[j]--;
						u+=r;
						f=0;
						ans++;
						break;
					}
					if(s[j][g[j]]==a[i]&&d[3-j]-g[3-j]<0){
						sprintf(r,"1 %d\n",3-j);
						u+=r;
						sprintf(r,"2 %d %d\n",j,3-j);
						u+=r;
						g[j]++;
						f=0;
						ans+=2;
						break;
					}
				}
				if(f==0)continue;
				srand(time(0)+clock()+K);
				K+=23;
				int yy=rand()%2+1;
				s[yy][++d[yy]]=a[i];
				sprintf(r,"1 %d\n",yy);
				u+=r;
				ans++;
			}
		}
		else
			for(int i=1; i<=m; i++){
				f=1;
				for(int j=1; j<=n; j++)
					if(s[j][d[j]]==a[i]){
						sprintf(r,"1 %d\n",j);
						d[j]--;
						u+=r;
						f=0;
						ans++;
						break;
					}
				for(int j=1; j<=n; j++){
					if(s[j][g[j]]==a[i]){
						for(int k=1; k<=n; k++){
							if(d[k]-g[k]<0){
								sprintf(r,"1 %d\n",k);
								u+=r;
								sprintf(r,"2 %d %d\n",k,j);
								u+=r;
								ans+=2;
							}
						}
					}
				}
				if(f==0)continue;
				srand(time(NULL)+clock()+K);
				K+=9;
				f=1;
				int yy=rand()%n+1;
				sprintf(r,"1 %d\n",yy);
				u+=r;
				ans++;
				if(d[yy]-g[yy]<0){
					for(int i=1; i<=n; i++){
						if(i==yy)continue;
						if(yy==s[i][g[yy]]){
							sprintf(r,"2 %d %d\n",yy,i);
							ans++;
							u+=r;
							g[yy]++;
						}
					}
				}
				if(f)s[yy][++d[yy]]=a[i];
			}
		cout<<ans<<endl<<u;
	}
	return 0;
}


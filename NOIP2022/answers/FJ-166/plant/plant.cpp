#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
const int p = 998244353;
#define ll long long
bool g[N][N];
int shu[N][N], sxia[N][N];
//ll ansc[N][N], ansf[N][N];

int main(){
	//freopen("E:\\NOIP2022\\plant\\plant3.in","r",stdin);
	freopen("plant.in", "r",stdin);
	freopen("plant.out", "w",stdout);
	int t, id;
	scanf("%d%d", &t, &id);
	while(t--){
		int n, m, c, f;
		memset(shu, 0, sizeof shu);
		memset(sxia, 0, sizeof sxia);
		scanf("%d%d%d%d", &n, &m, &c, &f);
		for(int i=0;i<n;i++){
			char tmp[N];
			scanf("%s", tmp);
			for(int j=0;j<m;j++) 
				g[i][j]=tmp[j]=='1';
		}
		if(c==0&&f==0) {
			printf("0 0\n");
			continue;
		}
//		for(int i=0;i<n;i++, cout<<endl)
//			for(int j=0;j<m;j++)
//				cout<<g[i][j]<<' '; 
		for(int i=0;i<n;i++){
			int tmp =0, lst=0;
			for(int j=0;j<m;j++){
				if(g[i][j]==0) tmp++;
				else if(tmp>0&&(j-1)>=0){
					for(int k=j-1, tot=0;k>=lst;tot++, k--)
						if(g[i][k]==0)shu[i][k]=tot+1;
					lst = j, tmp=0;
				}
			}
			if(tmp>0)
				for(int k=m-1, tot=0;k>=lst;tot++, k--)
					if(g[i][k]==0)shu[i][k]=tot+1;
		}
		for(int i=0;i<m;i++){
			int tmp =0, lst=0;
			for(int j=0;j<n;j++){
				if(g[j][i]==0) tmp++;
				else if(tmp>0&&(j-1)>=0){
					for(int k=j-1, tot=0;k>=lst;tot++, k--)
						if(g[k][i]==0) sxia[k][i]=tot+1;
					lst = j, tmp=0;
				}	 
			}
			if(tmp>0) 
				for(int k=n-1, tot=0;k>=lst;tot++, k--)
					if(g[k][i]==0) sxia[k][i]=tot+1;
		}
		//for(int i=0;i<n;i++,cout<<endl)
		//	for(int j=0;j<m;j++) cout<<shu[i][j]<<' ';
		//cout<<endl<<endl;
		ll ccc =0, fff=0;
		if(!(n<3||m<2))
		for(int i=0;i<n-2;i++){
			for(int j=0;j<m-1;j++){
				ll tmpans=0;
				if(shu[i][j]<=1) continue;
				for(int k=i+2;k<n;k++) {
					if(shu[k-1][j]==0) break;
					if(shu[k][j]>1)
					tmpans = (tmpans+(shu[i][j]-1)*(shu[k][j]-1)%p)%p;
				}
				ccc=(ccc+tmpans)%p;
			} 
		}
		if(f==0) goto NOF;
		if(!(n<4||m<2))
		for(int i=0;i<n-3;i++)
			for(int j=0;j<m-1;j++){
				ll tmpans=0;
				if(shu[i][j]<=1) continue;
				for(int k=i+2;k<n-1;k++){
					if(shu[k-1][j]==0) break;
					if(sxia[k][j]<=1) break;
					if(shu[k][j]>1)
						tmpans=(tmpans+(sxia[k][j]-1)*(shu[i][j]-1)%p*(shu[k][j]-1)%p)%p;
				}
				fff=(fff+tmpans)%p;
			}
//		for(int i=0;i<n;i++, cout<<endl)
//			for(int j=0;j<m;j++) cout<<ansf[i][j]<<' ';
//		for(int i=0;i<n;i++)
//			for(int j=0;j<m;j++) 
//				fff=(fff+ansf[i][j])%p,ccc=(ccc+ansc[i][j])%p;
		NOF:;
		if(f==0) printf("%lld 0\n", (ccc*c)%p);
		else printf("%lld %lld\n", (ccc*c)%p, (fff*f)%p);
	}
	return 0;
}

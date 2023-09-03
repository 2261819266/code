#include<bits/stdc++.h>
using namespace std;
long long t,t1,n,m,c,f,k,l,l2=1,h1,h2,a[100010],b[100010],u[100010][2],w[310];
vector<long long> r[310];
string s;
int main(){
	freopen("meow.in","r",stdin);freopen("meow.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
		cin>>n>>m>>k;
		f=0;l=0;
		for(int i=1;i<=m;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			r[i].clear();
		for(int i=1;i<=m;i++){
			int p=0;
			for(int j=1;j<=l;j++){
				int x=r[j].size();
				if(r[j][x-1]==a[i]){
					f++;
					r[j].pop_back();
					b[f]=1;u[f][0]=l;u[f][1]=0;
					p=1;
					break;
				}
			}	
				if(p==1) continue;
				else{
					if(h1>0){
						r[w[h1]].push_back(a[i]);
						h1--;
						f++;
						b[f]=1;
						u[f][0]=w[h1+1];u[f][1]=0;
						p=1;
					}
					if(p==0&&l<n){
						l++;
						r[l].push_back(a[i]);
						f++;
						b[f]=1;
						u[f][0]=l;u[f][1]=0;
						}
						/*for(int j=1;j<l;j++){
							if(r[l][0]==r[j][0]){
								f++;
								b[f]=2;
								u[f][0]=l;
								u[f][1]=j;
								for(int q=0;q<r[j].size();q++)
									r[j][q]=r[j][q+1];
								r[j].pop_back();
								r[l].pop_back();
								l--;
								break;
							}
						} */
					r[l].push_back(a[i]);
				}
				for(int j=1;j<=l;j++){
					for(int y=1;y<=l;y++){
						if(j!=y){
							if(r[j][0]==r[y][0]){
								f++;
								b[f]=2;
								u[f][0]=y;
								u[f][1]=j;
								for(int q=0;q<max(r[j].size(),r[y].size());q++){
									if(r[j].size()>q)r[j][q]=r[j][q+1];
									if(r[y].size()>q)r[y][q]=r[y][q+1];
								}
								r[j].pop_back();
								r[y].pop_back();
								if(!r[j].size()){
									h1++;
									w[h1]=j;
								}
								if(!r[y].size()){
									h1++;
									w[h1]=y;
								}
							}
						}
					}
				}
			}
		cout<<f<<endl;
		for(int i=1;i<=f;i++){
			cout<<b[i]<<" "<<u[i][0];
			if(u[i][1]!=0) cout<<" "<<u[i][1]<<endl;
			else cout<<endl;
		}
	}
	return 0;
}

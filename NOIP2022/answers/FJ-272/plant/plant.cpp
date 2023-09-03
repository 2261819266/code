#include<bits/stdc++.h>
using namespace std;
long long t,t1,n,m,c,f,l=0,l2=1,h1,h2,a[1010][1010],b[1010][1010];
vector<long long> r[1010000];
string s;
int main(){
	freopen("plant.in","r",stdin);freopen("plant.out","w",stdout);
	cin>>t>>t1;
	for(int o=1;o<=t;o++){
		cin>>n>>m>>c>>f;
		l=0;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				a[i][j]=0;b[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=1;j<=m;j++){
				a[i][j]=s[j-1]-'0';
				if(a[i][j]==0) b[i][j]=b[i][j-1]+1;
				//cout<<b[i][j]<<" ";
			}
			//cout<<endl;
		}
		if(c==0&&f==0){
			cout<<"0 0"<<endl;continue;
		}
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}*/
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				//cout<<l;
				if(a[j][i]==0){
					if(a[j-1][i]==1||j-1==0){l++;r[l].clear();}
					int h=i;
					while(b[j][h+1]!=0&&h<m) h++;
					//cout<<j<<" "<<h<<" "<<b[j][h]<<endl;
					if(h!=i&&b[j][h]-b[j][i]>0) r[l].push_back(b[j][h]-b[j][i]);
					else r[l].push_back(0);
					//cout<<l<<": ";
					//for(int yy=0;yy<r[l].size();yy++) cout<<r[l][yy]<<" ";
					//cout<<endl;
				}
			}
		}
		h1=0,h2=0;
		for(int k=1;k<=l;k++){
			//cout<<r[k].size();
			if(r[k].size()<=2) continue;
			int x=r[k].size();
			for(int i=0;i<r[k].size();i++){
				for(int j=i+2;j<r[k].size();j++){
					//cout<<r[k][i]<<" "<<r[k][j]<<endl;
					h1+=r[k][i]*r[k][j];
					int y=x-j-1;
					if(y<=0) y=0;
					h2+=r[k][i]*r[k][j]*(x-j-1);
					//if(j!=r[k].size()) h2+=r[k][i]*r[k][j];
					//cout<<h1<<" "<<h2<<endl;
				}
			}
		}
			h1*=c;h2*=f;
			h1%=998244353;h2%=998244353;
			cout<<h1<<" "<<h2<<endl;
	}
	return 0;
}

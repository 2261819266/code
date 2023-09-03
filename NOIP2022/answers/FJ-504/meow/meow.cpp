#include<bits/stdc++.h>
using namespace std;

int T,n,m,k,temp;

inline void read(int &x){
	x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x+=(x<<3)+((x)<<1)+c^48,c=getchar();
}

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	read(T);
	while(T--){
		read(n),read(m),read(k);
		vector<int> a;
		vector<vector<int> > s(n+5),ans;
		for(int i=1;i<=m;i++){
			read(temp);
			a.push_back(temp);
		}
		while(!a.empty()){
			int back=a.back();
			a.pop_back();
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j&&!s[i].empty()&&!s[j].empty()&&s[i][0]==s[j][0]){
						s[i].erase(s[i].begin());
						s[j].erase(s[j].begin());
						vector<int> Ans;
						Ans.push_back(2);
						Ans.push_back(i);
						Ans.push_back(j);
						ans.push_back(Ans);
					}
				}
				if(!s[i].empty()){
					if(s[i].back()==back){
						s[i].pop_back();
						vector<int> Ans;
						Ans.push_back(1);
						Ans.push_back(i);
						ans.push_back(Ans);
					}
					else if(s[i][0]==back){
						for(int j=1;j<=n;j++){
							if(s[j].empty()){
								s[j].push_back(back);
								break;
							}
						}
					}
				}
			}
		}
		cout<<ans.size()<<"\n";
		for(int i=0;i<ans.size();i++){
			for(int j=0;j<ans[i].size();j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}
//I can't finish this problem!!!
//0pts!!!
//***!!!
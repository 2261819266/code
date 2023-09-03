#include<bits/stdc++.h>
using namespace std;
int a[2000100];
int s1[200100];
int s2[200100];
int s3[200100];
int s[501];
int r[3][10001];
int x,y,p,q,z,c;
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	cin>>T;
	int ans;
	while(T--){
		int n,m,k;
		ans=0;
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++){
			cin>>a[i];
			s[a[i]]++;
		}
		if(n==2){
			x=y=p=q=1;
			for(int i=1;i<=m;i++){
				if(x==y&&p==q){
					s1[++y]=a[i];
					ans++;
					
				}
				else{
					if(a[i]==s1[y]){
						y--;
						ans++;
					}
					else if(a[i]==s2[q]){
						q--;
						ans++;
					}
					else if(p==q&&a[i]==s1[x+1]){
						x++;
						ans++;
					}
					else if(x==y&&a[i]==s2[p+1]){
						p++;
						ans++;
					}
					else if(a[i+1]!=s1[y]){
						s1[++y]=a[i];
						ans++;
					}
					else if(a[i+1]!=s2[q]){
						s2[++q]=a[i];
						ans++;
					}
				}
			}
			cout<<ans<<endl;
			x=y=p=q=1;
			for(int i=1;i<=m;i++){
				if(x==y&&p==q){
					s1[++y]=a[i];
					ans++;
					cout<<1<<" "<<1<<endl;
				}
				else{
					if(a[i]==s1[y]){
						y--;
						cout<<1<<" "<<1<<endl;
						ans++;
					}
					else if(a[i]==s2[q]){
						q--;
						cout<<1<<" "<<2<<endl;
						ans++;
					}
					else if(p==q&&a[i]==s1[x+1]){
						x++;
						ans+=2;
						cout<<1<<" "<<2<<endl;
						cout<<2<<" "<<1<<" "<<2<<endl;
					}
					else if(x==y&&a[i]==s2[p+1]){
						p++;
						ans+=2;
						cout<<1<<" "<<1<<endl<<2<<" "<<1<<" "<<2<<endl;
					}
					else if(a[i+1]!=s1[y]){
						s1[++y]=a[i];
						ans++;
						cout<<1<<" "<<1<<endl;
					}
					else if(a[i+1]!=s2[q]){
						s2[++q]=a[i];
						cout<<1<<" "<<2<<endl;
						ans++;
					}
				}
			}
		}
	}
}

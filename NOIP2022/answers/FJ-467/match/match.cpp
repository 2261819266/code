#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[1005],b[1005];
unsigned long long sum;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>b[i];
	}
	int Q;
	cin>>Q;
	while(Q--){
		sum = 0;
		int l,r;
		cin>>l>>r;
		for(int p = l;p<=r;p++){
			for(int q = p;q<=r;q++){
				int maxia = 0;
				int maxib = 0;
				for(int i = p;i<=q;i++){
					maxia = max(maxia,a[i]);
					maxib = max(maxib,b[i]);
				}
				sum+=maxia*maxib;
			}
		}
		cout<<sum<<endl;
	}
}
/*
¹À·Ö10pts 
*/

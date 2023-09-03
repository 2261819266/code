#include <bits/stdc++.h>
using namespace std;
unsigned long long sa[250005] = {0},sb[250005] = {0},sc[250005] = {0},sd[250005] = {0};
int a[250005],b[250005],ca[250005],cb[250005];
int l,r,n,q,t;
int v,w;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&t,&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d",&b[i]);
	}
	for(int i = 1; i <= n; i++){
		sa[i] = sa[i - 1];
		for(int j = 1; j < i; j++){
			if(a[i] > a[ca[j]]){
				ca[j] = i;
			}
			if(b[i] > b[cb[j]]){
				cb[j] = i;
			}
		}
		ca[i] = i;
		cb[i] = i;
		for(int j = 1; j <= i; j++){
			sa[i] += a[ca[j]] * b[cb[j]];
		}
	}
	memset(ca,0,sizeof(ca));
	memset(cb,0,sizeof(cb));
	for(int i = 1; i <= n; i++){
		sc[i] = sc[i - 1];
		for(int j = i - 1; j >= 1; j--){
			if(a[i] > a[ca[j]]){
				ca[j] = i;
			}
			if(b[i] > b[cb[j]]){
				cb[j] = i;
			}
		}
		ca[i] = i;
		cb[i] = i;
		for(int j = 1; j <= i; j++){
			sc[i] += a[ca[j]] * b[cb[j]];
		}
	}
	memset(ca,0,sizeof(ca));
	memset(cb,0,sizeof(cb));
	for(int i = n; i >= 1; i--){
		sb[i] = sb[i - 1];
		for(int j = 1; j < i; j++){
			if(a[i] > a[ca[j]]){
				ca[j] = i;
			}
			if(b[i] > b[cb[j]]){
				cb[j] = i;
			}
		}
		ca[i] = i;
		cb[i] = i;
		for(int j = 1; j <= i; j++){
			sb[i] += a[ca[j]] * b[cb[j]];
		}
	}	
	memset(ca,0,sizeof(ca));
	memset(cb,0,sizeof(cb));
	for(int i = n; i >= 1; i--){
		sd[i] = sd[i - 1];
		for(int j = i - 1; j >= 1; j--){
			if(a[i] > a[ca[j]]){
				ca[j] = i;
			}
			if(b[i] > b[cb[j]]){
				cb[j] = i;
			}
		}
		ca[i] = i;
		cb[i] = i;
		for(int j = 1; j <= i; j++){
			sd[i] += a[ca[j]] * b[cb[j]];
		}
	}
	scanf("%d",&q);
	for( ; q; q--){
		scanf("%d%d",&l,&r);
		v = n - r + 1;
		w = n - l + 1;
		cout << (sa[l] + sb[v] + sc[w] + sd[r] - sa[n] - sa[n] + sa[r] + sb[w] + sc[v] + sd[l]) / 2 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

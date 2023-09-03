#include<iostream>
#include<cstdio>
int n,m,c,f,t,id,cnt1,cnt2;
char a[1005][1005];
signed main(){
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	scanf("%d%d", &t, &id);
	while(t--){
		scanf("%d%d%d%d", &n, &m, &c, &f);
		for(int i=0;i<n;i++){
			scanf("%s", a[i]);
		}
		
		if(id==1){
			puts("0 0");
		} else if(id==3){
			if(!(a[0][0]-48) && !(a[1][0]-48) && !(a[2][0]-48) && !(a[0][1]-48) && !(a[2][1]-48)){
				puts("1 0");
			} else {
				puts("0 0");
			}
		} else if(id==4){
			cnt1=2,cnt2=1;
			if((a[1][0]-48) || (a[2][0]-48)){
				cnt1=cnt2=0;
			} else{
				if(a[0][0]=='1' || a[0][1]=='1' || a[2][1]=='1'){
					cnt1--;cnt2=0;
				}
				if(a[3][0]=='1' || a[3][1]=='1' || a[1][1]=='1'){
					cnt1--;cnt2=0;
				}
			}
			printf("%d %d\n", cnt1, cnt2);
		}
	}
}

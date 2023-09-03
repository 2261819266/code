#include<bits/stdc++.h>
using namespace std;
bool did;
struct ans{
	int a,b,c,a1,b1,c1;
}ans[4000000];
struct card{
	bool used;
	int type,next,up,s1,s2;
}a[2000000];
long long op;
int clean[2000000],cleans1[2000000];
struct zan{
	bool used;
	int type,end;
}zhan[600];
int t,m,n,k,s1=0,anss=1;
void make1(int t){
	bool flag=false;
	for(int l=1;l<=n;l++)
		if(!did&&zhan[l].used==true&&zhan[l].type==2&&a[t].next>zhan[l].end){
			ans[a[t].next].a=1;
			ans[a[t].next].b=l;
			ans[a[t].next].a1=2;
			ans[a[t].next].b1=l;	
			clean[zhan[l].end]=0;
			zhan[l].end=a[t].next;
			clean[a[t].next]=l;
			s1++;
			did=true;
			for(int f=1;f<=n;f++)
				if(zhan[f].used==false){
					ans[t].a=1;
					ans[t].b=f;
					ans[a[t].next].c1=f;
					zhan[f].used==true;
					zhan[f].type=3;
					zhan[f].end=a[t].next;
					flag=true;
					break;
				}
			if(!flag)
				for(int f=1;f<=n;f++)
					if(zhan[f].used==true&&zhan[f].type==3){
						ans[t].a=1;
						ans[t].b=f;
						ans[a[t].next].c1=f;
						zhan[f].used==true;
						zhan[f].type=3;
						zhan[f].end=a[t].next;
						flag=true;
						break;
					}
			op+=3;
		}
}
void make2(int i){
	s1--;
	for(int l=1;l<=n;l++)
		if(zhan[l].used==true&&zhan[l].type==3){
			ans[i].a=1;
			ans[i].b=l;
			ans[a[i].next].a=1;
			ans[a[i].next].b=l;
			zhan[l].type=1;
			if(a[i].next>zhan[l].end){
				clean[a[i].next]=l;
				clean[zhan[l].end]=0;
			}
			else cleans1[a[i].next]=l;
			break;
		}
	op+=2;
}
void make3(int i){
	for(int l=1;l<=n;l++)
		if(zhan[l].used==false){
			ans[a[i].next].a=1;
			ans[a[i].next].b=l;
			ans[a[i].next].b1=l;
			zhan[l].used=true;
			zhan[l].type=2;
			zhan[l].end=a[i].next;
			clean[a[i].next]=l;
			break;
		}
	for(int l=1;l<=n;l++)
		if(zhan[l].used==false){
			s1++;
			ans[i].a=1;
			ans[i].b=l;
			ans[a[i].next].c1=l;
			ans[a[i].next].a1=2;
			zhan[l].used=true;
			zhan[l].type=3;
			zhan[l].end=a[i].next;
			clean[a[i].next]=l;
			break;
		}
	op+=3;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++){
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++){
			cin>>a[i].type;
			a[i].used=true;
		}
		for(int i=1;i<=n;i++){
			zhan[i].used=false;
			zhan[i].type=0;
		}
		for(int i=1;i<=m;i++)
			if(a[i].used)
				for(int l=i+1;l<=m;l++)
					if(a[l].type==a[i].type){
						a[i].next=l;
						a[l].used=false;
						break;
					}
		for(int i=1;i<=m;i++)
			if(a[i].used){
				did=false;
				make1(i);
				if(!did){
					if(s1>0)make2(i);
					else make3(i);
				}
			}
			else{
				zhan[clean[i]].used=false;
				zhan[clean[i]].type=0;
				zhan[clean[i]].end=0;
				if(cleans1[i]){
					zhan[cleans1[i]].type=3;
					s1++;
				}	
			}
		cout<<op<<endl;
		for(int i=1;i<=m;i++){
			cout<<ans[i].a<<' '<<ans[i].b<<endl;
			if(ans[i].a1==2)cout<<ans[i].a1<<' '<<ans[i].b1<<' '<<ans[i].c1<<endl;
		}
	}
}

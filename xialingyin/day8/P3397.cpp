#include<iostream>
#include<cstdio>
using namespace std;
int a[1001][1001];
void pu(int x1,int y1,int x2,int y2){
    for(int c=x1;c<=x2;c++){
        for(int d=y1;d<=y2;d++){
            a[c][d]++;
        }
    }
}
int n,m,c,d,e;
int main(){
    scanf("%d%d",&n,&m);
    for(c=1;c<=m;c++){
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        pu(x1,y1,x2,y2);
    }
    for(c=1;c<=n;c++){
        for(d=1;d<=n;d++){
            printf("%d ",a[c][d]);
        }
        printf("\n");
    }
}
#include<cstdio>

const int maxn=1000005;
int *a[maxn],b,c,d,e,n,m;

int main(){
    scanf("%d%d",&n,&m);
    for(c=0;c<n;c++)
    a[c]=new int[maxn];
    for(c=0;c<m;c++){
        int i,j,k;
        scanf("%d%d%d",&k,&i,&j);
        if(k==1){
            int s;
            scanf("%d",&s);
            a[i][j]=s;
        }
        if(k==2){
            printf("%d",a[i][j]);
        }
    }
}
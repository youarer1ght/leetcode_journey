#include <stdio.h>
int main(){
    int l,m,u[100],v[100],i,j,s[10000];
    scanf("%d%d",&l,&m);
    for(i=0;i<m;i++){
        scanf("%d%d",u+i,v+i);
        for(j=u[i];j<=v[i];j++){
            s[j]++;
        }
    }
    int count=0;
    for(i=0;i<=l;i++){
        if(!s[i])
        count++;
    }
    printf("%d",count-1);
    return 0;
}
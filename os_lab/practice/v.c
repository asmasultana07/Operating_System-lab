#include<stdio.h>
int main()
{

    long long int L,R,i,j;
    scanf("%lld %lld",&L,&R);
    R=min(R,L+2019);
    int ans=2018;
    for(i=L;i<=R;i++){
        for(j=i+1;i<=R;j++){
           int x=i*j%2019;
       // ans=min(ans,i*j%2019);
          ans=min(ans,x);
        }
    }
    printf("%d",ans);
    return 0;
}

#include<stdio.h>
int main()
{
  int n,i,p,v,t,sum,count=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
  scanf("%d %d %d",&p,&v,&t);
  sum=p+v+t;
  if(sum>=2)
  {
  count++;
  }
}
   printf("%d",count);
   return 0;
}



#include<stdio.h>
#include<stdlib.h>

int n, mutex=1,full=0,empty=4, x=0;

int main(){

void producer();
void consumer();

int wait(int), signal(int);

printf("\n1.Producer\n2.Consumer\n3.Exit");

while(1)
{
printf("\nenter ur choice- ");
scanf("%d",&n);
switch(n)
{
case 1: if((mutex==1) && (empty!=0))
producer();
else
printf("stack is full. ...\n");
break;
case 2: if((mutex==1) && (full!=0))
consumer();
else20101084
20101086
20101089
printf("stack is empty. No item here...");
break;

case 3:
exit(0);
break;
}
}
return 0;
}


int wait(int s)
{ return (--s); }

int signal(int s)
{ return(++s); }


 //function
void producer()
{
mutex= wait(mutex);
full= signal(full);
empty= wait(empty);
x++;
printf("\nProducing item -%d \n",x);
mutex=signal(mutex);
}

void consumer()
{
mutex= wait(mutex);
full= wait(full);
empty= signal(empty);
printf("\nConsuming item- %d \n",x);
x--;
mutex=signal(mutex);
}

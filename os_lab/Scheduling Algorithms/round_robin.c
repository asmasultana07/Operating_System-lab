#include<stdio.h>
#include<conio.h>

int main()
{
    int n, i,j, counter=0,wt=0, tat=0,total=0 ;
    int burst[20],p[20],pr[20], at[20],temp[20];
    float avrg = 0, avrgtt = 0;

    printf(" enter total num of process- ");
    scanf("%d", &n);

    printf("\nenter arrival time & burst time \n");
    for (i = 0; i < n; i++)
    {
        printf("\n p[%d] \n", i+1);
        printf("enter arraival time-");
        scanf("%d",&at[i]);
        printf("enter burst time-");
        scanf("%d",&burst[i]);
     
       temp[i]= burst[i];  //store burst time in temp
    }
    //quantam
    int q;
    printf("\nenter quantam slot-");
        scanf("%d",&q);

    
    //total indicates total time
    //counter indicates which process is executed
    int x =n;
    printf("\n process \tburst time \twaiting time \tturnaround time");
    for(total=0, i=0; x!=0; )  
    {  
        if(temp[i] <= q && temp[i] > 0)    
        {  
            total = total + temp[i];  
            temp[i] = 0;  
            counter=1;  
        }     
        else if(temp[i] > 0)  
        {  
            temp[i] = temp[i]- q;  
            total  += q;    
        }  
        if(temp[i]==0 && counter==1)  
        {  
                x--; //decrement the process no. 
               
               int bb= total- at[i] ;
               int cc= total- at[i]-burst[i];
            //printf("\nProcess No %d  \t\t %d\t\t\t\t %d\t\t\t %d", i+1, burst[i], total- at[i], total- at[i]-burst[i]); 
                   
            printf("\n p[%d] \t\t[%d] \t\t\t[%d] \t\t [%d]", i+1, burst[i], bb, cc);    
            
            wt = wt+ cc;  
            tat += bb;  
            counter =0;     
        }  
        
        if(i== n-1)  
            {  i=0;  }  
        else if(at[i+1] <= total)  
            { i++; }
  
        else  {  i=0;   }  
    }  
    
     avrg = wt/n;
    printf("\n\n avrg waiting time: %.2f", avrg);
return 0;
}

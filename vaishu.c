#include<stdio.h> 
#include<stdlib.h>
#include<conio.h>
int main() 
{ 
 
  int count,n,time_quantum,i,j,temp,pos,total=0,tmp; 
  int at[5],bt[5],priority[4],p[4],wt[10],tat[10],pr[5]; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
   printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
for(count=0;count<n;count++)
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    scanf("%d",&at[count]); 
    scanf("%d",&bt[count]); 
    
  } 
    	 printf("\n\nProcess\t| arrival time  |  burst time\n\n"); 

  for(count=0;count<n;count++)
  {
      printf("P[%d]\t|\t%d\t|\t%d\n",count,at[count],bt[count]); 

  }
  for(count=0;count<n;count++)
  {
  
 bt[count]=bt[count]-time_quantum;
 
}
printf("\nAfter one iteration");
printf("\n\nProcess\t| arrival time  |  burst time\n\n"); 
 for(count=0;count<n;count++)
  {
      printf("P[%d]\t|\t%d\t|\t%d\n",count,at[count],bt[count]); 
       }

printf("enter the time_quantum ");
scanf("%d",&time_quantum);
  for(count=0;count<n;count++)
  {
  
 bt[count]=bt[count]-time_quantum;
 
}
printf("\nAfter second iteration");
printf("\n\nProcess\t| arrival time  |  burst time\n\n"); 
 for(count=0;count<n;count++)
  {
      printf("P[%d]\t|\t%d\t|\t%d\n",count,at[count],bt[count]); 

  }
   printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;           
    }
     for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
      wt[0]=0;	//waiting time for first process is zero
  for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
      printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    
getch();
}

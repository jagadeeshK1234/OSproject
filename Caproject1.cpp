#include<stdio.h>
#include<conio.h>
int main()
{
    int B_T[10],Process_no[10],AVERAGE_W_T[10],AVERAGE_T_A_T[10];
    int A_T[10],Prior[10],i,j,Number_of_Process,tot=0,flag,temp,TOTAL_Avg_W_T,TOTAL_Avg_T_A_T;
    printf("Enter Number of Process:");
    scanf("%d",&Number_of_Process);
    printf("\nEnter Burst Time and Prior\n");
    for(i=0;i<Number_of_Process;i++)
    {
        printf("\nP[%d]\n",(i+1));
        printf("Enter Burst Time:");
        scanf("%d",&B_T[i]);
        printf("Enter Arrival Time:");
        scanf("%d",&A_T[i]);
        printf("Enter Prior:");
        scanf("%d",&Prior[i]);
        Process_no[i]=i+1;
    }
    for(i=0;i<Number_of_Process;i++)
    {
        flag=i;
        for(j=i+1;j<Number_of_Process;j++)
        {
            if(Prior[j]>Prior[flag])
            flag=j;
        }
        temp=Prior[i];
        Prior[i]=Prior[flag];
        Prior[flag]=temp;
        temp=B_T[i];
        B_T[i]=B_T[flag];
        B_T[flag]=temp;
        temp=Process_no[i];
        Process_no[i]=Process_no[flag];
        Process_no[flag]=temp;
    }
   AVERAGE_W_T[0]=0;  
    for(i=1;i<Number_of_Process;i++)
    {
        AVERAGE_W_T[i]=0;
        for(j=0;j<i;j++)
            AVERAGE_W_T[i]+=B_T[j];
        tot+=AVERAGE_W_T[i];
    }
    TOTAL_Avg_W_T=tot/Number_of_Process;  
    tot=0;
    printf("_______________________________________________________________");
    printf("\nProcess\t       B T      AVERAGE W T               AVERAGE T A T");
    for(i=0;i<Number_of_Process;i++)
    {
        AVERAGE_T_A_T[i]=B_T[i]+AVERAGE_W_T[i];  
        tot+=AVERAGE_T_A_T[i];
        printf("\nProcess %d \t %d\t \t   %d\t\t%d",Process_no[i],B_T[i],AVERAGE_W_T[i],AVERAGE_T_A_T[i]);
         
    }
        printf("\n_______________________________________________________________");
    TOTAL_Avg_T_A_T=tot/Number_of_Process;
    printf("\n\nTOTAL AVERAGE W T= %d",TOTAL_Avg_W_T);
    printf("\nTOTAL AVERAGE T A T= %d",TOTAL_Avg_T_A_T);
    return 0;
}

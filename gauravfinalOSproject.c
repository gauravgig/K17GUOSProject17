#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

int burstTime[20],AttivalTime[10],n,i,j,temp,st[10],ft[10],waitingTime[10],ta[10];
int totwt=0,totta=0;
float avgWtTime,ata;
char name[10][10],t[10];

int main()
{

    printf("Enter the number of process:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter Process Name\n");
        scanf("%s",name[i]);
        printf("enter Arrival Time\n");
        scanf("%d",&AttivalTime[i]);
        burstTime[i]=2*AttivalTime[i];
    }
    for(i=0;i<n;i++)
    {
       printf("BurstTime of %s : %d\n",name[i],burstTime[i]);
    }
    int p=0;
    getch();
    system("cls");
    printf("1)Longest job first \n2)Shortest job first \n");
    scanf("%d",&p);
    if(p==1)
    {
        longestJobFirst();
    }
    else if(p==2)
    {
        ShortJobFirst();
    }
    else{
        printf("Press correct option");
    }
}

 int longestJobFirst(){
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(burstTime[i]>burstTime[j])
            {
                temp=AttivalTime[i];
                AttivalTime[i]=AttivalTime[j];
                AttivalTime[j]=temp;
                temp=burstTime[i];
                burstTime[i]=burstTime[j];
                burstTime[j]=temp;
                strcpy(t,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],t);
            }
        }
    for(i=0; i<n; i++)
    {
        if(i==0)
            st[i]=AttivalTime[i];
        else
            st[i]=ft[i-1];
        waitingTime[i]=st[i]-AttivalTime[i];
        ft[i]=st[i]+burstTime[i];
        ta[i]=ft[i]-AttivalTime[i];
        totwt+=waitingTime[i];
        totta+=ta[i];
    }
    avgWtTime=(float)totwt/n;
    ata=(float)totta/n;
    printf("\nP_name\tArrival_time\tBurstTime\tWaitingtime\tTurnaround-time");
    for(i=0; i<n; i++)
        printf("\n%s\t\t%5d\t\t%5d\t\t%5d\t\t%5d",name[i],AttivalTime[i],burstTime[i],waitingTime[i],ta[i]);
    printf("\nAverage Waiting time is : %f",avgWtTime);
    printf("\nAverage Turnaroundtime is : %f",ata);
    getch();
}

int ShortJobFirst()
   {
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(burstTime[i]<burstTime[j])
            {
                temp=AttivalTime[i];
                AttivalTime[i]=AttivalTime[j];
                AttivalTime[j]=temp;
                temp=burstTime[i];
                burstTime[i]=burstTime[j];
                burstTime[j]=temp;
                strcpy(t,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],t);
            }
        }
    for(i=0; i<n; i++)
    {
        if(i==0)
            st[i]=AttivalTime[i];
        else
            st[i]=ft[i-1];
        waitingTime[i]=st[i]-AttivalTime[i];
        ft[i]=st[i]+burstTime[i];
        ta[i]=ft[i]-AttivalTime[i];
        totwt+=burstTime[i];
        totta+=ta[i];
    }
    avgWtTime=(float)totwt/n;
    ata=(float)totta/n;
    printf("\nProcess name\tArrival time\tExecution time\tWaiting time\tTurnaround-time");
    for(i=0; i<n; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d",name[i],AttivalTime[i],burstTime[i],waitingTime[i],ta[i]);
    printf("\nAverage Waiting time is:%f",avgWtTime);
    printf("\nAverage Turnaroundtime is:%f",ata);
    getch();
}

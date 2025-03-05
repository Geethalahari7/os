#include<stdio.h> 
int main() 
{ 
  int i,n,bt[20], wt[20], tat[20]; 
  float wtavg, tatavg; 
  printf("\nEnter no of processes:"); 
  scanf("%d", &n); 
  printf("enter the burst out times\n"); 
  for(i=0;i<n;i++) 
  { 
    printf("\nEnter the Burst Time of Process p[%d]: ", i); 
        scanf("%d", &bt[i]); 
  } 
  wtavg=wt[0]= 0; 
  tatavg= tat[0]= bt[0]; 
  for(i=1;i<n;i++) 
  { 
    wt[i] = wt[i-1] +bt[i-1]; 
    tat[i] = tat[i-1] +bt[i]; 
    wtavg = wtavg + wt[i]; 
    tatavg = tatavg + tat[i]; 
  } 
  printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n"); 
  for(i=0;i<n;i++) 
  printf("\n\t P%d \t\t %d \t\t %d \t\t %d\n", i, bt[i], wt[i], tat[i]); 
  printf("The Average Waiting Time is : %f\n", wtavg/n); 
  printf("The Average Turnaround Time is : %f\n", tatavg/n); 
}
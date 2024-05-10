#include<iostream>
using namespace std;

class demo
{
    public:
    string P[10];
    int at[10],bt[10],wt[10],ct[10],tat[10],pr[10];
    
    
        int n;
        
    
    void sort()
    {
        cout<<"Enter no of process";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<"\nEnter process name";
	        cin>>P[i];
	        cout<<"\nEnter Arrival time";
	        cin>>at[i];
	        cout<<"\nEnter Burst time";
	        cin>>bt[i];
            int temp1,temp2;
            string temp3;
            for(int i=0;i<n;i++)
            {
                for(int j=i;j<n;j++)
                {
                    if(at[i]>at[j])
                    {
                        temp1=at[i];
                        at[i]=at[j];
                        at[j]=temp1;

                         temp2=bt[i];
                        bt[i]=bt[j];
                        bt[j]=temp2;

                        temp3=P[i];
			            P[i]=P[j];
			            P[j]=temp3;

                    }
                }
            }
        }
    }
    void fcfs()
    {
        wt[0]=at[0];
		tat[0]=bt[0];
		ct[0]=wt[0]+bt[0];
		for(int i=1;i<n;i++)
		{
			wt[i]=tat[i-1]-at[i];
			ct[i]=wt[i]+bt[i];
			tat[i]=at[i]+ct[i];
		}
        			cout<<"\n \tYour Data\t \n";
	cout<<"wating completion turn around time\n";
	for(int i=0;i<n;i++)
	{
	
	cout<<wt[i]<<"\t";
	cout<<ct[i]<<"\t";
	cout<<tat[i]<<"\t";
	cout<<"\n";
    }
    }
};

int main()
{
    demo d1;
    d1.sort();
    d1.fcfs();
}













































































//ip 1
//0 5
//1 4 
//2 2
//6 3
//5 4






//i/p 2
// 1  4
// 0  2
// 2  6
// 3  5
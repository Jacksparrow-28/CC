#include<iostream>
#include<string>
#include<queue>
using namespace std;
class RR
{
	public:
	float n,AT[10],BT[10],CT[10],TAT[10],WT[10],RT[10],TimeSlice;
	RR()
	{
		// cout<<"\nEnter number of process: ";
		// cin>>n;
        // cout<<"\nEnter Time slice: ";
		// cin>>TimeSlice;

		n = 4;
		TimeSlice=2;
		AT[0] = 0;BT[0] = 5;
		AT[1] = 1;BT[1] = 4;
		AT[2] = 2;BT[2] = 2;
		AT[3] = 4;BT[3] = 1;


		for(int i=0;i<n;i++)
		{
			// cout<<"\nEnter AT,BT of process "<<i<<" :";
			// cin>>AT[i]>>BT[i];	
            CT[i] =0;
            TAT[i] = 0;
            WT[i] =0;
            RT[i] = BT[i];		
		}
		
	}

	void Sort()
	{
		string temps;
		float temp;
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				if(AT[i] > AT[j])
				{
					// temps = name[i];
					// name[i] = name[j];
					// name[j] = temps;

					temp = AT[i];
					AT[i] = AT[j];
					AT[j] = temp;

					temp = BT[i];
					BT[i] = BT[j];
					BT[j] = temp;
					
				}
			}
		}
	}

	void shedule2()
	{
		Sort();
		int counter=0,q=0,t=0,temp=0,i=0;
		queue<int> ReadyQue,RunningQueue;
		for(int j=0;j<n;j++)
		{
			if(AT[j]<=0)
			{
				ReadyQue.push(j);
			}
		}
		while(!ReadyQue.empty())
		{
			temp = ReadyQue.front();
			RunningQueue.push(temp);
			ReadyQue.pop();
			if(RT[temp]>=TimeSlice)
			{
				t = TimeSlice;
			}
			else
			{
				t = RT[temp];
			}
			RT[temp] = RT[temp] - t;
			q=q+t;
			CT[temp] = q;
			for(int j=(q-t)+1;j<n;j++)
			{
				if(AT[j]<=q)
				{
					ReadyQue.push(j);
				}
			}
			if(RT[temp]>0)
			{
				ReadyQue.push(temp);
			}
		}


	}




	void shedule()
	{
		Sort();
		int counter = 0,qe=0,t=0;
		int temp=0;
        queue<int> ReadyQue,RunningQueue;

        int i=0;

        for(int j=0;j<n;j++)
        {
            if(AT[j] <=qe)
            {
                ReadyQue.push(j);
            }
        }
		while(!ReadyQue.empty() )
		{
            // RT is equal to remaining time 
            temp = ReadyQue.front();
            RunningQueue.push(temp);

            if(RT[temp]>=TimeSlice)
            {
                t = TimeSlice;
            }
            else
            {
                t = RT[temp];
            }
            RT[temp] = RT[temp] - t;
            qe = qe + t;
            CT[temp] = qe;
            
            for(int j=(qe-t)+1;j<n;j++)
            {
                if(AT[j] <=qe)
                {
                    ReadyQue.push(j);
                }  
            }
            if(RT[temp]>0)
            {
                ReadyQue.push(temp);
            }
            ReadyQue.pop();
		}			
	}	

	void display()
	{
        float AVGWT=0,AVTAT=0;
		cout<<"\nProcess \t AT \t BT \t CT \t WT \t TAT\n";
		for(int i=0 ;i<n;i++)
		{
            TAT[i] = CT[i] - AT[i];
            WT[i] = TAT[i] - BT[i];
            AVGWT = AVGWT + WT[i];
            AVTAT = AVTAT + TAT[i];
			cout<<i+1<<" \t\t "<<AT[i]<<" \t "<<BT[i]<<" \t "<<CT[i]<<" \t "<<WT[i]<<" \t "<<TAT[i]<<" \n";
		}
        cout<<"\n\nAverage waiting time: "<<(AVGWT/n)<<" /"<<n<<" units";
        cout<<"\n\nAverage Turn around time: "<<(AVTAT/n);
	}

};
int main()
{
	RR p;
 	p.shedule2();
	p.display();

	return 0;
}
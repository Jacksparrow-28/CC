#include<iostream>

using namespace std;

bool is_present(int n,int frame[],int f)
{
    int flag=0;
    for(int i=0;i<f;i++)
    {
        if(frame[i]==n)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    return true;
    else 
    return false;
}

int list_rank(int frame[],int f)
{
    int min=frame[0];
    int idx=0;
    for(int i=1;i<f;i++)
    {
        if(frame[i]<min)
        {
            min=frame[i];
            idx=i;
        }
    }
    return idx;
}

int main()
{
    int s;
    cout<<"Enter the number of pages: ";
    cin>>s;
    int sequence[s];
    cout<<"Enter the name of pages: "<<endl;
    for(int i=0;i<s;i++)
    {
        cin>>sequence[i];
    }
    int f;
    cout<<"Enter the number of frames: ";
    cin>>f;
    int faults=f,hits=0,p=0;
    int frame[f], time[f]={0};
    for(int i=0;i<f;i++)
    {
        frame[i]=sequence[i];
        time[i]=i;
        cout<<"time["<<frame[i]<<"]"<<time[i]<<endl;
    }
    cout<<endl;
    for(int i=f;i<s;i++)
    {
        if(!is_present(sequence[i],frame,f))
        {
            cout<<sequence[i]<<endl;
            int ret=list_rank(frame,f);
            cout<<"Function value: "<<ret<<endl;
            cout<<"Old value at: "<<ret<<" is: "<<frame[ret]<<endl;
            frame[ret]=sequence[i];
            time[ret]=time[ret]+1;
            for(int i=0;i<f;i++)
            {
                cout<<"time["<<frame[i]<<"]"<<time[i]<<endl;
            }
            cout<<endl;
            faults++;

        }
        else 
        {
            hits++;
            for(int j=0;j<f;j++)
            {
                if(frame[j]==sequence[i])
                {
                    time[j]=time[j]+1;
                    break;
                }
            }
            for(int i=0;i<f;i++)
            {
                cout<<"time["<<frame[i]<<"]"<<time[i]<<endl;
            }
            cout<<endl;
            
        }
    }
    cout<<"faults: "<<faults<<endl;
    cout<<"Hits: "<<hits<<endl;


    return 0;
}
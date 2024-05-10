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
int search(int frame[],int f,int sequence[],int s,int j)
{
    int flag=0;
    int min=INT8_MAX;
    for(int i=0;i<f;i++)
    {
        flag=0;
        for(int k=f;k<j;k++)
        {
            if(frame[i]==sequence[k])
            {
                flag=1;
                if(i<min)
                {
                    min=i;
                }
            }
        }
        if(flag==0)
        {
            return i;
        }
    }
    return min;
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
    int faults=f,hits=0,p=0,max=0;
    int frame[f];
    for(int i=0;i<f;i++)
    {
        frame[i]=sequence[i];

    }
    for(int i=f;i<s;i++)
    {
        if(!is_present(sequence[i],frame,f))
        {
            frame[search(frame,f,sequence,s,i)]=sequence[i];
            faults++;
        }
        else 
        
            hits++;
    }
    cout<<"faults: "<<faults<<endl;
    cout<<"Hits: "<<hits<<endl;


    return 0;
}
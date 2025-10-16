#include<iostream>
using namespace std;
int main()
{
    int k,s[10],e[10],n=0,a=0;

    cout<<"\nEnter the no. of shops:\n";
    cin>>n;

    cout<<"\nEnter starting time:\n";
    for(int i=0;i<n;i++)
    {
        cin>>s[i];//starting time
    }
    cout<<endl;

    cout<<"\nEnter ending time:\n";
    for(int i=0;i<n;i++)
    {
        cin>>e[i];//ending time
    }
    cout<<endl;

    cout<<"\nEnter no. of People:\n";
    cin>>k;//people no.

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(e[i] > e[j])
            {
                int temp = e[i];
                e[i] = e[j];
                e[j] =temp;

                temp = s[i];
                s[i] = s[j];
                s[j]=temp;
            }
        }
    }
     int person[10];
     for(int i=0;i<k;i++)
     {
        person[i]=0;
     }

     for(int i=0;i<n;i++)
     {
        for(int j=0;j<k;j++)
        {
            if(s[i]>=person[j])
            {
                person[j] = e[i];
                a++;
                break;
            }
        }
     }

    cout<<"\nThe no. of shops visited: "<<a<<endl;
    return 0;
}

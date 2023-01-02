#include<bits/stdc++.h>
using namespace std;
int no_of_frames, no_of_pages, frames[10], pages[30], counter, flag1, flag2, i, j, pos, faults;

int findLRU(int ltu[], int n)
{
    int i, minimum = ltu[0], pos = 0;

    for(i = 1; i < n; ++i)
    {
        if(ltu[i] < minimum)
        {
            minimum = ltu[i];
            pos = i;
        }
    }
    return pos;
}

void LRU(int no_of_frames,int no_of_pages )
{
    int time[10], avail=0;;
    counter = 0,faults = 0;


    for(i = 0; i < no_of_frames; ++i)
    {
        frames[i] = -1;
    }

    cout<<"ref string\t page frames\n";
    for(i = 0; i < no_of_pages; ++i)
    {
        flag1 = flag2 = 0;

        for(j = 0; j < no_of_frames; ++j)
        {
            if(frames[j] == pages[i])
            {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                avail=0;
                break;
            }
        }

        if(flag1 == 0)
        {
            for(j = 0; j < no_of_frames; ++j)
            {
                if(frames[j] == -1)
                {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    avail=1;
                    break;
                }
            }
        }
        if(flag2 == 0)
        {
            pos = findLRU(time, no_of_frames);
            counter++;
            faults++;
            avail=1;
            frames[pos] = pages[i];
            time[pos] = counter;
        }
        cout<<endl;
        cout<<pages[i]<<"\t\t";
        if(avail!=0)
        {
            for(j = 0; j < no_of_frames; ++j)
            {

                cout<<frames[j]<<"\t";
            }
        }




    }
    cout<<"\n Total : "<<faults<<" page faults"<<endl;
    float percnt = (float)faults/no_of_pages*100.0;
    cout<<"Page Fault Rate: "<<percnt<<"%";


}


int main()
{

    cout<<"Enter number of frames: ";
    cin>>no_of_frames;
    cout<<"Enter number of pages: ";
    cin>>no_of_pages;
    cout<<"Enter reference string: ";
    for(i = 0; i < no_of_pages; ++i)
    {

        cin>>pages[i];
    }
    LRU(no_of_frames,no_of_pages);




    return 0;
}




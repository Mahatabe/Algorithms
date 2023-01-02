#include<bits/stdc++.h>
using namespace std;

bool cTable(int tFrame[], int nf, int page)
{
	for(int i=0; i<nf; i++)
    {
        if(page == tFrame[i])
        {
            return true;
        }
    }
	return false;
}

void pTable(int tFrame[], int nf)
{
	for(int i=0; i<nf; i++)
	{
		if(tFrame[i] == -1)
        {
            cout<<"    ";
        }
		else
        {
            cout<<tFrame[i]<<"   ";
        }
	}
}

int main()
{
    int n, nf;
    int pos = 0;
    int c = 0;
    cout<<"Number of memory page frames : ";
    cin>>nf;
    int tFrame[nf];
    for(int i=0;i<nf;i++)
    {
        tFrame[i]=-1;
    }
    cout<<"Number of page reference : ";
    cin>>n;
    int page[n];
    cout<<"Reference string : ";
    for(int i=0;i<n;i++)
    {
        cin>>page[i];
    }
    cout<<endl;
    cout<<"Reference string\t Page frames\n\n";
    for(int i=0;i<n;i++)
    {
        cout<<"\t"<<page[i]<<"\t\t  ";
        if(!cTable(tFrame,nf,page[i]))
        {
           tFrame[pos] = page[i];
           pos = (pos+1) % nf;
           pTable(tFrame,nf);
           cout<<"Page fault";
           cout<<endl;
           c++;
           continue;
        }
        pTable(tFrame,nf);
		cout<<endl;
    }
    cout<<"\nNumber of page fault : "<<c<<endl;
}

// 7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1

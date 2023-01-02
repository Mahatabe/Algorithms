#include<bits/stdc++.h>
#include<vector>
using namespace std;

void bucketSort(float a[])
{
    vector<float> c[10];
    int i,j,t;
    for(i=0;i<10;i++)
    {
       t=floor(a[i]*10);
       c[t].push_back(a[i]);
    }
    for(i=0;i<10;i++)
    {
        sort(c[i].begin(),c[i].end());
    }
    int index=0;
    for (i=0;i<10;i++)
    {
        for (int j=0;j<c[i].size();j++)
        {
          a[index++] = c[i][j];
        }
    }

    for(i=0;i<10;i++)
    {
        cout<< a[i]<< " ";
    }

}
int main()
{
    float a[]={0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434,0.1,0.2,0.56,0.69};
    bucketSort(a);
}

#include<bits/stdc++.h>
using namespace std;

int representative[50];

vector < pair < int, pair < int, int > > > Edges;
vector < pair < int, pair < int, int > > > MST;

int findset(int x)
{
    if(representative[x] == x)

    {
        return x;
    }

    return findset(representative[x]);
}

void unionset(int x, int y)
{
    int px,py;
    px = findset(x);
    py = findset(y);
    representative[px] = py;
}
void kruskal(int N,int E)
{

    int u,v,wt;
    int mstWt = 0,i = 0;

    for(int i=0; i<N; i++)
    {
        representative[i]=i;
    }

    sort(Edges.begin(),Edges.end());

    while(i<E)

    {

        u = Edges[i].second.first;
        v = Edges[i].second.second;
        wt = Edges[i].first;

        if( findset(u) != findset(v) )

        {
            unionset(u,v);
            MST.push_back(make_pair(wt,make_pair(u,v)));
        }

        i++;

    }

    cout<<endl<<"The edges of the MST :"<<endl;

    for(auto x: MST)

    {
        cout<<x.second.first<<" -> "<<x.second.second<<endl;
        mstWt+=x.first;
    }

    cout<<"\nWeight of the MST is "<<mstWt<<endl;



}

int main()

{
    int N,E,u,v,wt;

    cout<<"Enter no.of Nodes & Edges: ";
    cin>>N>>E;

    for(int i=0; i<E; i++)

    {
        cin>>u>>v>>wt;
        Edges.push_back(make_pair( wt,make_pair(u,v) ) );
    }

    kruskal(N,E);

}

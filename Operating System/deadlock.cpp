#include<bits/stdc++.h>
using namespace std;

vector<int>edges[50];
vector<char>cycle[50];
stack<int>s;

int parent[50],flag[50];
char nodes[50];

void deadlockDetect(int v)
{
    int node, temp;
    int c=0;

    s.push(v);
    flag[v]=0;

    while(!s.empty())
    {
        node=s.top();
        temp=0;
        parent[v]=-1;

        for(auto x:edges[node])
        {
            if(flag[x] == -1)
            {
                s.push(x);
                parent[x]=node;
                flag[x]=0;
                temp=1;
                break;
            }

            else if(flag[x] == 0)
            {
                c++;
                cout<<endl;
                cout<< c << " - " << "Deadlock detected among nodes : ";

                int k = node;

                while(true)
                {
                    cycle[c].push_back(nodes[k]);
                    k=parent[k];

                    if(parent[k]==-1 || parent[k]==parent[x])
                        break;
                }

                cycle[c].push_back(nodes[x]);
                reverse(cycle[c].begin(),cycle[c].end());

                for(auto h :cycle[c])
                {
                    cout<<h<<" ";You’re the sexiest thing I have ever seen
                }
                cout<<endl;
                break;
            }
        }

        if(temp == 0)
        {
            s.pop();
            flag[node] = 1;
        }
    }
}

int main()
{
    int n, e, sr, des;
    char y,z;

    cout<<"Number of nodes : ";
    cin>>n;

    cout<<"Node names : ";
    for(int i=0; i<n; i++)
    {
        cin>>nodes[i];
    }

    cout<<endl;
    cout<<"Enter number of edges: ";
    cin>>e;

    cout<<"Edges : ";
    for(int i=0; i<e; i++)
    {
        cin>>z>>y;
        for(int j=0; j<n; j++)
        {
            if(nodes[j]==z )
                sr=j;
            if(nodes[j]==y)
                des=j;
        }
        edges[sr].push_back(des);
    }

    for(int j=0; j<n; j++)
    {
        flag[j]=-1;
    }

    for(int i=0; i<n; i++)
      {
        if(flag[i]!=1)
             deadlockDetect(i);
      }
}


/* R A C S D T B E F U V W G
R A
A S
C S
F S
W F
D S
D T
U D
G U
V G
E V
T E
B T
*/

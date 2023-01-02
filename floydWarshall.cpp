#include <bits/stdc++.h>
using namespace std;
#define INF 9999
#define N 5

void printPath(int path[N][N], int v, int u)
{
	if (path[v][u] == v)
		return;

	printPath(path, v, path[v][u]);
	cout << path[v][u] << " ";

}

void printSolution(int cost[N][N], int path[N][N])
{
	for (int v = 0; v < N; v++)
	{
		for (int u = 0; u < N; u++)
		{
			if (u != v && path[v][u] != -1)
			{
				cout << "Shortest Path from " << v << " -> " << u << " is ("<< v << " ";
				printPath(path, v, u);
				cout << u << ")" << endl;
			}
		}
	}
}

void floydWarshall(int adjMatrix[N][N])
{

	int cost[N][N], path[N][N];

	for (int v = 0; v < N; v++)
	{
		for (int u = 0; u < N; u++)
		{
			cost[v][u] = adjMatrix[v][u];

			if (cost[v][u] != INF)

				path[v][u] = v;
			else

				path[v][u] = -1;

		}
	}

	for (int k = 0; k < N; k++)
	{
		for (int v = 0; v < N; v++)
		{
            for (int u = 0; u < N; u++)
            {
                if (cost[v][k] + cost[k][u] < cost[v][u])
                {
                    cost[v][u] = cost[v][k] + cost[k][u];
                    path[v][u] = path[k][u];
                }
            }

		}
	}

	cout<<"The least cost matrix:"<<endl;
	for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<cost[i][j]<<" ";
        cout<<endl;
    }
	printSolution(cost, path);
}

int main()
{
	int adjMatrix[N][N] =
                        { {0, 3, 8,INF, -4},
						{INF, 0, INF,1,7},
						{INF, 4,0,INF,INF},
						{2, INF,-5, 0,INF},
						{ INF, INF, INF,6,0 }
                        };

	floydWarshall(adjMatrix);

	return 0;
}

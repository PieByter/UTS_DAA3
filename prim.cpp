#include <cstring>
#include <iostream>
using namespace std;

#define INF 9999999

// number of vertices in graph
#define V 6

// create a 2d array of size 6x6 for adjacency matrix to represent graph

int G[V][V] = {{0, 10, 0, 0, 15, 0},
               {10, 0, 20, 13, 0, 0},
               {0, 20, 0, 5, 0, 12},
               {0, 13, 5, 0, 11, 21},
               {15, 0, 0, 11, 0, 16},
               {0, 0, 12, 21, 16, 0}};

int main()
{
    system("cls");
    cout << "+===================+\n";
    cout << "| Prim's Algorithms |\n";
    cout << "+===================+\n\n";
    /* Let us create following weighted graph*/
    cout << "         10        20       \n";
    cout << "    A ------- B ------- C   \n";
    cout << "    |         |       / |   \n";
    cout << "    |      13 |  5 /    |   \n";
    cout << "    |         | /       | 12\n";
    cout << " 15 |         D         |   \n";
    cout << "    |       /   \\       |  \n";
    cout << "    | 11 /      21 \\    |  \n";
    cout << "    | /               \\ |  \n";
    cout << "    E ----------------- F   \n";
    cout << "             16             \n";
    cout << "\nEdge Assumption :\n";
    cout << "   A = 0, B = 1, C = 2, D = 3, E = 4, F = 5\n\n";

    int no_edge = 0; // set number of edge to 0

    // create a array to track selected vertex
    // selected will become true otherwise false
    int selected[V];

    // set selected false initially
    memset(selected, false, sizeof(selected));

    // the number of egde in minimum spanning tree will be
    // always less than (V -1), where V is number of vertices in
    // graph

    // choose 0th vertex and make it true
    selected[0] = true;

    int x;              //  row number
    int y;              //  col number
    int a = 1, ans = 0; //  step & minimum cost
    // print for edge and weight
    cout << "Step"
         << "    "
         << "Edge"
         << "\t  "
         << "Weight" << endl;
    while (no_edge < V - 1)
    {
        // For every vertex in the set S, find the all adjacent vertices
        //  , calculate the distance from the vertex selected at step 1.
        //  if the vertex is already in the set S, discard it otherwise
        // choose another vertex nearest to selected vertex  at step 1.

        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && G[i][j])
                    { // not in selected and there is an edge
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        ans += G[x][y]; // total minimum cost weight
        cout << a++ << "       " << x << " -- " << y << "    " << G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
    }
    cout << "Minimum Cost Spanning Tree : " << ans;
    return 0;
}
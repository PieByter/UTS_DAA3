#include <bits/stdc++.h>
using namespace std;

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find function
    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    // Union function
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2])
            {
                parent[s2] = s1;
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

class Graph
{
    vector<vector<int>> edgelist;
    int V;

public:
    Graph(int V) { this->V = V; }

    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({w, x, y});
    }

    void kruskals_mst()
    {
        // Sort all edges
        sort(edgelist.begin(), edgelist.end());

        // Initialize the DSU
        DSU s(V);
        int ans = 0, i = 1;
        cout << "Following are the edges in the constructed MST\n";
        cout << "Step  Edge      Weight\n";
        for (auto edge : edgelist)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // Take this edge in MST if it does
            // not forms a cycle
            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;
                cout << i++ << "     " << x << " -- " << y << "    " << w
                     << endl;
            }
        }

        cout << "Minimum Cost Spanning Tree : " << ans;
    }
};

int main()
{
    system("cls");
    cout << "+======================+\n";
    cout << "| Kruskal's Algorithms |\n";
    cout << "+======================+\n\n";
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

    Graph g(9);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 15);
    g.addEdge(1, 2, 20);
    g.addEdge(1, 3, 13);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 5, 12);
    g.addEdge(3, 4, 11);
    g.addEdge(3, 5, 21);
    g.addEdge(4, 5, 16);
    // Function call
    g.kruskals_mst();
    return 0;
}
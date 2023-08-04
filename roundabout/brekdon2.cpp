// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V;
    map<int, vector<int>> adj;

    Graph(int);
    void addEdge(int, int);
    void DFS(int, vector<bool> &);
} *g;

// Constructor
Graph::Graph(int V)
{

    // No. of vertices
    this->V = V;

    // Dictionary of lists
    for (int i = 1; i <= V; i++)
        adj[i] = vector<int>();
}

// Function to add edge
// in the graph
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

// Function to perform DFS
void Graph::DFS(int s, vector<bool> &visited)
{

    // Create a stack for DFS
    stack<int> stack;

    // Push the current source node
    stack.push(s);
    while (!stack.empty())
    {

        // Pop a vertex from stack
        // and print it
        s = stack.top();
        stack.pop();

        // Traverse adjacent vertices
        // of the popped vertex s
        for (auto node : adj[s])
        {
            if (!visited[node])
            {

                // If adjacent is unvisited,
                // push it to the stack
                visited[node] = true;
                stack.push(node);
            }
        }
    }
}

// Function to return the count
// edges removed
void countRemovedEdges(int N, int M, int K)
{
    int C = 0;

    // Initially mark all vertices
    // as not visited
    vector<bool> visited(g->V + 1, false);

    for (int node = 1; node <= N; node++)
    {

        // If node is unvisited
        if (!visited[node])
        {

            // Increment Connected
            // component count by 1
            C = C + 1;

            // Perform DFS Traversal
            g->DFS(node, visited);

            // Print the result
            if (C <= K)
                cout << M - N + K << endl;
            else
                cout << -1 << endl;
        }
    }
}

// Driver Code
int main(int argc, char const *argv[])
{
    int N = 9, M = 8, K = 1;

    // Create Graph
    g = new Graph(N);

    // Given Edges
    g->addEdge(1, 2);
    g->addEdge(2, 3);
    g->addEdge(3, 4);

    // Function Call
    countRemovedEdges(N, M, K);
}

// This code is contributed by sanjeev2552

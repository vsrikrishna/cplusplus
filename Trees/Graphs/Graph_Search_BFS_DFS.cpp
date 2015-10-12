/*
BFS & DFS for graphs
07/29/2015

Explanation for algorithm complexity:
The operations of enqueuing and dequeuing take O(1) time, so the total time devoted to queue operations is O( V). 
Because the adjacency list of each vertex is scanned only when the vertex is dequeued, each adjacency list is 
scanned at most once. Since the sum of the lengths of all the adjacency lists is theta(E), the total time spent in 
scanning adjacency lists is O( E). The overhead for initialization is O( V), and thus the total running time of 
BFS is O( V + E).

Note:
1) You cannot cover all the nodes of a graph using BFS for one particular node
   If each node in a graph is to be traversed by a tree-based algorithm (such as DFS or BFS), 
   then the algorithm must be called at least once for each entirely distinct subgraph of the graph.
*/

#include<iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

// Graph class represents a directed graph using adjacency list representation
class Graph
{
	int V;    // No. of vertices
	vector<int> *adj;    // Pointer to an array containing adjacency lists
	bool *visited;
	void TopSortUtil(int n, bool visited[], vector<int>& stack);
public:
	Graph(int V);   // Constructor
	void addEdge(int v, int w);   // function to add an edge to graph
	void DFS(int v);    // DFS traversal of the vertices reachable from v
	void BFS(int s);  // prints BFS traversal from a given source s
	void TopologicalSort(); //prints Topological sort for a graph
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new vector<int>[V];
	// Mark all the vertices as not visited
	visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

}

void Graph::TopSortUtil(int n, bool visited[], vector<int>& stack){
	visited[n] = true;
	for (auto itr:adj[n]){
		if (!visited[itr])
			TopSortUtil(itr, visited, stack);
	}
	stack.push_back(n);
}

void Graph::TopologicalSort(){
	vector<int> stack;
	for (int i = 0; i < V; i++){
		visited[i] = false;
	}
	for (int i = 0; i < V; i++){
		if (!visited[i])
		  TopSortUtil(i,visited,stack);
	}
	cout <<"The Topological sort is:"<<endl;
	while (!stack.empty()){
		cout << stack.back() << " ";
		stack.pop_back();
	}
	cout << endl;
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
	cout << "Printing out vector "<<v<<" values" << endl;
	for (auto a : adj[v]){
		cout << a << " ";
	}
	cout << endl;
}

// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
void Graph::DFS(int v)
{	
	// Call the recursive helper function to print DFS traversal
	//DFSUtil(v, visited);
	// Mark the current node as visited and print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent to this vertex
	vector<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i){
		cout << endl;
		cout << "visited one, value is " << *i << endl;
		if (!visited[*i])
			DFS(*i);
	}

}

void Graph::BFS(int s)
{
	// Mark all the vertices as not visited
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Create a queue for BFS
	vector<int> queue;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		s = queue.front();
		cout << s << " ";
		queue.erase(queue.begin());

		// Get all adjacent vertices of the dequeued vertex s
		// If a adjacent has not been visited, then mark it visited
		// and enqueue it
		for ( auto i : adj[s])
		{
			if (!visited[i])
			{
				visited[i] = true;
				queue.push_back(i);
			}
		}
	}
}

int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	cout << "Adding Edge 0,1"<<endl;
	g.addEdge(0, 1);
	cout << "Adding Edge 0,2"<<endl;
	g.addEdge(0, 2);
	cout << "Adding Edge 1,2"<<endl;
	g.addEdge(1, 2);
	cout << "Adding Edge 2,0"<<endl;
	g.addEdge(2, 0);
	cout << "Adding Edge 2,3"<<endl;
	g.addEdge(2, 3);
	cout << "Adding Edge 3,3"<<endl;
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal (starting from vertex 2) \n";
	g.DFS(2);
	cout << endl;

	cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
	g.BFS(2);
	cout << endl;

	g.TopologicalSort();

	getchar();
	return 0;
}
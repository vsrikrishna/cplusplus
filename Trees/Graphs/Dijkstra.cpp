/*
10/28/2013
Coursera C++ Course 
Graph algorithms and graph representation are a critical tool in CS. We want to create a graph as an ADT (Abstract Data Type) using C++ classes. The basic problem will be to write Dijkstra’s algorithm as a class member function (method in OO speak). You should already know Dijkstra’s algorithm for the shortest path problem from prior experience, but it will be reviewed in class. It is the basis for many route calculations and optimizations programs. 

There are 2 basic implementations used for graphs – one is edge lists, and the other is connectivity matrices. You can decide which to use, but comment on your choice. 

Basic problem:  Write a set of constructors for declaring and initializing a graph. An edge will have a positive cost that is its distance. Have a procedure that produces a randomly generated set of edges with positive distances.  Assume the graphs are undirected. The random graph procedure should have edge density as a parameter and distance range as a parameter. So a graph whose density is 0.1 would have 10% of its edges picked at random and its edge distance would be selected at random from the distance range. The procedure should run through all possible undirected edges, say (i,j) and place the edge in the graph if a random probability calculation is less than the density. Compute for a set of randomly generated graphs an average shortest path.

Turn in:  Printout of program, 200 words on what you learned, and output showing the average path length calculation. Use densities: 20% and 40% on a graph of 50 nodes with a distance range of 1.0 to 10.0.   To get an average path length, compute the 49 paths:

1 to 2, 1 to 3, 1 to 4, …, 1 to 50. 

[In an instance where there is no path between 1 and n, omit that value from the average. This should be very rare for the chosen density and size in this homework.]

Keep in mind: good style – choice of identifiers, short functions, good documentation, correctness and efficiency. Cite any references in creating this program.

Tips:  Hand-simulate your algorithm on a small graph.

Things I learnt during this programming homework
This programming assignment was a good learning experience for me. Starting from graph theory concepts to using some basic data structures there were lot of skillsets which improved during the course of this HW. To be more specific, I will list my improvements in 2 areas: graph theory and programming concepts. 
Under graph theory my understanding of dijkstra’s shortest path algorithm, monte carlo simulation, building a graph using connectivity matrix or edge lists improved drastically. Some of these concepts like Monte Carlo simulation, edge lists or connectivity matrix graph implementation were new to me.  I was able to contrast and compare edge lists and connectivity matrix implementation for graph creation. Finally I picked edge lists implementation since it is easy and sufficient for spare graph scenario. It was good exposure to learn about graph theory and simultaneously implement these concepts using C++ programming language.

Under programming concepts, using vector, priority queue, heap data structures; using random functions for probability creation, overloading weak ordering comparator function in basic data structure (heap or priority queue) were highlighting skillsets I learnt. Basic C++ programming skills like using multiple constructors, deciding between class and struct usage, using constant keyword, commenting on functions or classes and using easy to understand variable names were valuable improvements. 

During the course of this assignment, I referenced several websites, amongst them wikepedia, cplusplus.com, stackoverflow were notable ones. HW2 Discussion forum was very useful. Inputs from peers in the forum was timely and to the point.
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

//Probability function to provide random value to compare with density
inline double prob(){
    return (rand()%100)/100.0;
}

// Edge structure which represents an edge between two vertexes. 
// tail represents one vertex
// head represents another vertex of an edge
// cost represents the length assigned to each edge
struct Edge {
    int tail;
    int head;
    double cost;
};

// Used to provide max & min weak order compartor function for elements
// Default usage would provide max weak ordering of elements
// Setting revparam variable to true would enable minimum element weak ordering
class edgeSort {
    bool reverse;
public:
    edgeSort(const bool& revparam = false){
        reverse = revparam;
    }
    inline bool operator () ( Edge &lhs, Edge &rhs) const { 
        return reverse ? (lhs.cost < rhs.cost) : (lhs.cost > rhs.cost); 
    }
};

// Use to generate an unconnected graph for n vertexes and given density value
// The methods in this class are used to run dijkstra's shortest path algorithm 
// Average shortest path calculated from starting node to all connected nodes 
// is one of the main functions of this class. Also helper methods to print graph
// connections and return neighbors for a given node are provided
//
// Adjacency list approach where edge carries cost/distance information is used 
// for graph creation in this class
class Graph{
    std::vector<std::vector<Edge> > edges;
public:
    void randomnFill(int n, double density, double startRange, double endRange);

    Graph(){
        randomnFill(0,0.0,0.0,0.0);
    };
    Graph(int n, double d, double sR, double eR){
        randomnFill(n, d, sR, eR);
    };
    Graph(const Graph& G); //copy constructor

    ~Graph(){
        //destructor to delete objects created using new
    };
    void printGraph(int n);
    double shortestPath(int);
    std::vector<Edge> returnNeighbors(int vertex);
};

// Helper function to fill an unconnected graph with nodes and edge costs
// based on number of nodes and density parameters
void Graph::randomnFill(int n, double density, double startRange, double endRange){
    edges.resize(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if( prob() < density ){
                Edge e; 
                //Insert ij edge into edges vector
                e.tail = i;
                e.head = j;
                //cost or distance of an edge should be between starting and ending range
                e.cost =  (rand()% static_cast<int>(endRange))/1.0 + startRange;
                edges[e.tail].push_back(e);
        
                //Insert ji edge into edges vector
                e.tail = j;
                e.head = i;
                edges[e.tail].push_back(e);
            }
        }
    }
}

// Print graph edges with costs for all the vertexes in a graph
void Graph::printGraph(int n){
    for(int i=0; i<n;i++){
        for(unsigned int j =0; j<edges[i].size();j++){
            std::cout << edges[i][j].tail << "---" << edges[i][j].head << ":" << edges[i][j].cost << "  "; 
        }
        std::cout << std::endl;
    }
}

// Method to find average shortest path from source(0)vertex to all other vertexes 
// in an unconnected graph. Dijkstra's algoroithm is used to calculate the shortest 
// path. The sum of all paths from source(0) vertex is calculated and is averaged over
// number of paths visited. Priority queue data structure is used to store elements 
// and default comparator function with max element weak order is changed to return 
// min element at top of the queue
double Graph::shortestPath(int num){

    std::vector<double> distance; //stores distance of each vertex from source
    std::vector<bool> visited;//stores information if a particular vertex is visited from source vertex
    std::priority_queue<Edge,std::vector<Edge>, edgeSort> myPQ; //priority queue used to store edges with minimum cost vertex at top
    
    //Initialization of vectors
    for(int i =0 ; i < num; i++){
        distance.push_back(1000.0); //Set distance of each node to a huge value initially
        visited.push_back(false); //initially all nodes are set to false since they are not visited yet
    }

    //Start with source(0) node for priority queue
    Edge source;
    source.head = 0;
    source.tail = 0;
    source.cost = 0.0;
   
    //distance from source to source is 0
    distance[0] = 0.0;
    
    //store source node into PQ
    myPQ.push(source);

    //Iterate through all nodes till Queue is empty
    while(!myPQ.empty()){
        Edge minEdge;   
        std::vector<Edge> neighbors;

        //find minimum element out of neighbors
        minEdge = myPQ.top();

        //Remove minimum element from PQ.
        myPQ.pop();

        //mark this node as visited
        visited[minEdge.head] = true;

        //get Neighbor for minimum element node
        neighbors = returnNeighbors(minEdge.head);

        //Iterate through neighbors and accumulate shortest distance
        double altCost;
        for(std::vector<Edge>::iterator eItr = neighbors.begin(); eItr!= neighbors.end(); eItr++){
            altCost = distance[minEdge.head] + eItr->cost;

            //If calculated distance is lesser than stored distance then update it
            if(altCost < distance[eItr->head] && !visited[eItr->head]){
                distance[eItr->head] = altCost;
                myPQ.push(*eItr);
            }
        }
    }

    //Calculate the shortest path sum over all nodes visited from source node
    double shortestPathSum = 0.0;
    for(unsigned i =0; i < distance.size(); i++){
        if(visited[i]){
            shortestPathSum+= distance[i];
        }
    }
    
    //Determine all nodes visited from source node
    int visitedNodes = 0;
    for(std::vector<bool>::iterator bItr = visited.begin(); bItr!= visited.end(); bItr++){
        if(*bItr){
            visitedNodes++;
        }
    }
    visitedNodes--; //Removing source(0) node from visitedNodes sum

    //Avoiding divide by zero error for shortest path calculation
    if(shortestPathSum == 0.0 || visitedNodes == 0){
        return 0.0;
    }
    
    //return average of shortest path sum over all visited nodes
    return shortestPathSum/visitedNodes;
}

// Return vector of neighboring edges of an input vertex
std::vector<Edge> Graph::returnNeighbors(int vertex){
    return edges[vertex];
}

// Monte Carlo method to generate randomn graphs for given nodeCount,density and 
// iteration value. The shortest path is calculated in each case and averaged over number of
// iterations.
double monteCarloSimulation(const int nodeCount, const double density, const double startRange, const double endRange, const int iteration){
    long double averagePath = 0.0;    
    
    for(int i=0; i< iteration; i++){
       Graph G(nodeCount, density, startRange, endRange);
       averagePath += G.shortestPath(nodeCount);
    }
    return averagePath/iteration;
}
int main(){
    std::cout<<"::::::::::::::::::::::::::: Starting Simulation :::::::::::::::::::::::::::" << std::endl;
    std::cout<<"Simulation density: 0.4, Average shortest path length: "<<monteCarloSimulation(50,0.4,1.0,10.0,10000)<<std::endl;
    std::cout<<"Simulation density: 0.2, Average shortest path length: "<<monteCarloSimulation(50,0.2,1.0,10.0,10000)<<std::endl;
    std::cout<<":::::::::::::::::::::::::::  Simulation Ended   :::::::::::::::::::::::::::" << std::endl;
    return 0;
}
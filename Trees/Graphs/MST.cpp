/*
11/04/2013
Coursera "C++ for C programmers" HW3
Trees are an important subcategory of graphs. Trees such as binary trees and red-black trees are important data structures used throughout computer science. Again it is hoped that this topic is mostly review for active participants in this class. 

This assignment requires the implementation of a minimum spanning tree (MST) algorithm for a weighted undirected graph (Graph). A spanning tree for a Graph g is a tree that reaches all the nodes of the graph. The cost for such a spanning tree is the sum of all the edge costs (weights) in the spanning tree’s edge set. Over all possible spanning trees, the MST is the one with the least total cost (it may not be unique).  

Two efficient methods will be explained in this week’s Module, namely Prim’s algorithm and Kruskal’s algorithm. Additionally, the assignment makes the following simplifying assumptions about the unweighted Graph:
Graph is connected. This assumption enables the following invariant: MST invariant states that the edge set for a MST must (i) consist of a set of (V-1) edges and (ii) no edge can create a cycle. 
Edge weights may be zero or non-negative. Non-negative edge weights are not a requirement for constructing a MST, but may simplify our implementation. 
Edge weights are NOT necessarily different
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <boost/lexical_cast.hpp>

//@brief: Probability function to provide random value to compare with density
//@output: probability of occurence
inline double prob(){
    return (rand()%100)/100.0;
}

//Edge structure which represents an edge between two vertexes. 
//tail represents one vertex of an edge
//head represents another vertex of an edge
//cost represents the length assigned to each edge
struct Edge {
    int tail;
    int head;
    double cost;
};

//@class edgeSort
//@brief: provides max & min weak order compartor function for elements
//        Default usage would provide max weak ordering of elements
//        Setting revparam variable to true would enable minimum element weak ordering
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

// @class Graph
// @brief: Use to generate an unconnected graph for n vertexes and given density value
//         The methods in this class are used to run dijkstra's shortest path algorithm 
//         Average shortest path calculated from starting node to all connected nodes 
//         is one of the main functions of this class. A collection of methods to print graph
//         connections and return neighbors for given node are provided.
//         Adjacency list approach where edge carries cost/distance information is used 
//         for graph creation in this class
class Graph{
    std::vector<std::vector<Edge> > adjList;
public:
    void randomnFill(int n, double density, double startRange, double endRange);
    
    //Constructors
    Graph(); //default constructor
    Graph(int n, double d, double sR, double eR){//constructor with input parameters
        randomnFill(n, d, sR, eR);
    };
    Graph(const Graph& G); //copy constructor
	Graph(std::string inFile);//graph constructor using data input from file

    //Destructor
    ~Graph(){
        //destructor to delete objects created using new
    };
    
    std::vector<std::vector<Edge> > getAdjList();
    void printGraph();
    double shortestPath();
    int primsMST();
    int kruskalMST();
    std::vector<Edge> getNeighbors(int vertex);
};

//@class ShortestPath
//@brief: A collection of methods to calculate shortest path
class ShortestPath{
public:
    //constructor
    ShortestPath(){ 
    }  
    double pathLength(Graph &G);
};

//@class Prim
//@brief: A collection of methods to calculate length of a MST using Prim's algorithm
class Prim{
public:
    //constructor.
	Prim(){
	}
    int MSTlength(Graph &G);
};

//@class Kruskal
//@brief: A collection of methods to calculate the length of a MST using Kruskal algorithm
class Kruskal{
    std::map<int,int> parentMap; //Map to store parent vertex for connected tree
public:
    //constructor
    Kruskal(Graph &G);
    
    int getRoot(int x);
    int MSTlength(Graph &G);
};

/* Graph class method implementation*/

//@brief: constructor to read input file as a string and construct Graph using file data
Graph::Graph(std::string inFile){
    std::ifstream inData;
    inData.open(inFile.c_str(), std::ifstream::in);
    if(!inData) { // file couldn't be opened
       std::cerr << "Error: file could not be opened" << std::endl;
       exit(1);
    }

    //get node count and resize adjacency list for node count
    std::string nodeCnt;
    getline(inData, nodeCnt);
    int num = boost::lexical_cast<int>(nodeCnt);
    adjList.resize(num);
    
    //get input from file line by line and store edge info into adjList vector data structure
    std::string line;
    Edge e;

    //parse through line to get tail, head and cost info
    while(getline(inData, line)){
        int tail,head;
        double cost;
        std::istringstream(line)>>tail>>head>>cost;
        //Insert edge into adjList vector
        e.tail = tail;
        e.head = head;
        e.cost = cost;
        adjList[e.tail].push_back(e);
    }
}

//@brief: Returns adjacency list vector
//@input: 
//@output: vector of vector of edges
std::vector<std::vector<Edge> > Graph::getAdjList(){
    return adjList;
}

//@brief: Output graph edge with costs for all the vertexes in a graph
void Graph::printGraph(){
    for(unsigned int i=0; i<adjList.size();i++){
        for(unsigned int j =0; j<adjList[i].size();j++){
            std::cout << adjList[i][j].tail << "---" << adjList[i][j].head << ":" << adjList[i][j].cost << "  "; 
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
}

//@brief:Helper function to fill an unconnected graph with edges with edge cost
//       based on number of nodes and density parameters
//@input: 
//       n - number of nodes
//       density - density of Graph
//       startRange - starting range of edge cost
//       endRange - ending range of edge cost
void Graph::randomnFill(int n, double density, double startRange, double endRange){
    adjList.resize(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if( prob() < density ){
                Edge e; 
                //Insert ij edge into adjList vector
                e.tail = i;
                e.head = j;
                //cost or distance of an edge should be between starting and ending range
                e.cost =  (rand()% static_cast<int>(endRange))/1.0 + startRange;
                adjList[e.tail].push_back(e);
        
                //Insert ji edge into adjList vector
                e.tail = j;
                e.head = i;
                adjList[e.tail].push_back(e);
            }
        }
    }
}

//@brief:Method to find average shortest path from source(0)vertex to all other vertexes 
//       in an unconnected graph. Dijkstra's algoroithm is used to calculate the shortest 
//       path. The sum of all paths from source(0) vertex is calculated and is averaged over
//       number of paths visited. Priority queue data structure is used to store elements 
//       and default comparator function with max element weak order is changed to return 
//       min element at top of the queue
//@input: 
//@output: shortest path length
double Graph::shortestPath(){
    ShortestPath SP;
    return SP.pathLength(*this);
}

//@brief: Minimum Spanning tree using Prim's algorithm
//@output: length of Prim's MST
int Graph::primsMST(){
    Prim P;
    return P.MSTlength(*this);
}

//@brief: Minimum Spanning tree using kruskal's algorithm
//@output: length of Prim's MST
int Graph::kruskalMST(){
    Kruskal K(*this);
    return K.MSTlength(*this);
}

//@brief: Return vector of neighboring edges of an input vertex
//@input: vertex in a graph
//@output: vector of neigbhor vertexes for input vertex
std::vector<Edge> Graph::getNeighbors(int vertex){
    return adjList[vertex];
}

/* ShortestPath class method implementation*/

//@brief: Find shortest path length
//@input: Graph G on which shortest path length is calculated
//@output: shortest path length of graph
double ShortestPath::pathLength(Graph &G){
    std::vector<double> distance; //stores distance of each vertex from source
    std::vector<bool> visited;//stores information if a particular vertex is reached from source vertex
    std::priority_queue<Edge,std::vector<Edge>, edgeSort> myPQ; //priority queue used to store edges with minimum cost vertex at top
    
    //Initialization of vectors
    for(unsigned int i =0 ; i < G.getAdjList().size(); i++){
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
        neighbors = G.getNeighbors(minEdge.head);

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
    visitedNodes--; //Removing zero node from visitedNodes sum

    //Avoiding divide by zero error for shortest path calculation
    if(shortestPathSum == 0.0 || visitedNodes == 0){
        return 0.0;
    }
    
    //return average of shortest path sum over all visited nodes
    return shortestPathSum/visitedNodes;

}

/* Prim class method implementation*/

//@brief: Calculate length of minimum spanning tree(MST) of an input graph G
//        The MST is constructed using prim's algorithm
int Prim::MSTlength(Graph &G){
    std::vector<double> distance; //stores distance information of minimum spanning tree vertex
    std::vector<bool> visited;//stores information if a particular vertex is visited or not
    std::priority_queue<Edge,std::vector<Edge>, edgeSort> myPQ; //priority queue used to store edges 
                                                                //with minimum cost vertex stored at top
    std::vector<int> finished;//stores finished set of vertexes

    //Initialization of distance, visited vectors
    for(unsigned int i =0 ; i < G.getAdjList().size(); i++){
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
    
   //store source node into priority queue
    myPQ.push(source);

    //Iterate through all nodes till Queue is empty
    while(finished.size()!= G.getAdjList().size()){
        Edge minEdge;   
        std::vector<Edge> neighbors;

        //find minimum element out of neighbors
        minEdge = myPQ.top();

        //Remove minimum element from PQ.
        myPQ.pop();
        
        //Store minimum vertex to set of finished vertex
        finished.push_back(minEdge.head);

        //mark this node as visited
        visited[minEdge.head] = true;

        //get Neighbor for minimum element node
        neighbors = G.getNeighbors(minEdge.head);

        //Iterate through neighbors and accumulate shortest distance
        double altCost;
        for(std::vector<Edge>::iterator eItr = neighbors.begin(); eItr!= neighbors.end(); eItr++){
            altCost = eItr->cost;

            //If calculated distance is lesser than stored distance then update it
            if(altCost < distance[eItr->head]&& !visited[eItr->head]){
                distance[eItr->head] = altCost;
                myPQ.push(*eItr);
            }
        }
    }
    
    //Print out minimum spanning tree
    std::cout<<"Prim's Minimum Spanning tree:" << std::endl;
    for(unsigned int i = 0; i < finished.size(); i++){
        std::cout<<finished[i]<<", ";
    }
    std::cout<<std::endl;

    //Calculate the shortest path sum over all nodes visited from source node
    double minimumTreeLength = 0.0;
    for(unsigned i =0; i < distance.size(); i++){
        if(visited[i]){
            minimumTreeLength+= distance[i];
        }
    }
    return static_cast<int>(minimumTreeLength);

}

/* Kruskal class method implementation*/

//Kruskal constructor to initialize parentMap for a given graph G
Kruskal::Kruskal(Graph &G){
    for(unsigned int i = 0; i < G.getAdjList().size(); i++){
        parentMap[i] = i;
    }
}

//@brief: returns root node for input node
//        Root node is used to prevent cycles in Kruskal algorithm
//@input: Vertex of a graph
//@output: root node of input node
int Kruskal::getRoot(int x){
    if(x != parentMap[x]){
        parentMap[x] = getRoot(parentMap[x]);
    }
    return parentMap[x];
}

//@brief: Calculate minimum spanning tree length for a given graph G
//input: Graph G whose MST should be calculated
//Output: Length of minimum spanning tree
int Kruskal::MSTlength(Graph &G){
    std::priority_queue<Edge,std::vector<Edge>, edgeSort> myPQ;//priority queue used to store edges with minimum element at top
    for(unsigned int i =0; i < G.getAdjList().size(); i++){
        for(unsigned int j =0; j < G.getAdjList()[i].size(); j++){
            myPQ.push(G.getAdjList()[i][j]);
        }
    }
    std::vector<Edge> minSpanEdges;//stores minimum spanning tree edges
    std::vector<int> vertexCovered;//stores vertex covered while forming MST
    Edge minEdge;//temporary edge to store minimum element from priority queue
       
    //Continue looping till priority queue is empty
        while(!myPQ.empty()){
            //Get minimum weight edge from PQ
            minEdge = myPQ.top();
       
            //Remove previous element from PQ
            myPQ.pop();
               
            int t = minEdge.tail, h = minEdge.head;
               
            //Get parent for tail and head nodes
            //If parents are not the same, add the edge into MST
                     int prt_t = getRoot(t), prt_h = getRoot(h);
            if(prt_t != prt_h){
                minSpanEdges.push_back(minEdge);
                parentMap[prt_h]=parentMap[prt_t];
            }
    }
       
    std::cout<<"Kruskal Algorithm Spanning Tree Edges"<<std::endl;
          std::cout<<"Edges   Weight"<<std::endl;
          
          //Print the edges of MST and calculate the total cost of the MST
    double cost = 0.0;
    for(std::vector<Edge>::iterator eItr = minSpanEdges.begin(); eItr!=minSpanEdges.end(); eItr++){
        std::cout<<eItr->tail<<"--"<<eItr->head<<"    (" << eItr->cost << ")"<<std::endl;
        cost+=eItr->cost; 
    }
    std::cout<<std::endl;
       
    return static_cast<int>(cost);
} 

//@brief: Monte Carlo method to generate randomn graphs for given node count with different density and 
//        iteration. The shortest path is calculated in each case and averaged over number of iterations.
//@input: 
//       nodeCount - Number of nodes
//       density - density on which edge cost is calculated
//       startRange - starting range of edge cost
//       endRange - ending range of edge cost
//       iteration - number of iterations to run the simulation
//@output: Shortest path length for given input constraints
inline double monteCarloSimulation(const int nodeCount, const double density, const double startRange, const double endRange, const int iteration){
    long double averagePath = 0.0;    
    
    //Iterate for i iterations, create Graph with given input constraints for each simulation
    //Calculate shortest path for each iteration
    for(int i=0; i< iteration; i++){
       Graph G(nodeCount, density, startRange, endRange);
       averagePath += G.shortestPath();
    }
    return averagePath/iteration;
}

int main(){
	Graph G("input.txt");
    int length = G.primsMST();
    std::cout << "Minimum spanning tree length using prim's algorithm is: " << length << std::endl;
    length = G.kruskalMST();
    std::cout << "Minimum spanning tree length using Kruskal's algorithm is: " << length << std::endl;
    return 0;
}
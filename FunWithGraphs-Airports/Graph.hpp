#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_
// FILE: Graph.hpp
// AUTHOR: Henrique Medeiros Dos Reis
// DATE: 4/28/2021
//    Definition file for Graph class
// 	  I decided to implement it using the idea of an adjacency list, the way I decided to use it is with a vector of vectors. This is similar to having a list of arrays. 
#include "Connection.hpp"
#include "Airports.hpp"
#include <vector>
#include <queue>

class Graph
{
private:
 	// a vector of vectors of the Connections to represent an adjacency list
    std::vector<std::vector<Connection>> _adjList;
public:
    // Graph Constructor, it requires the size of the Graph (the number of vertex) and the connections that are in them
    Graph(std::vector<Connection>  &connections, int N);
    //this method is used to print the route used in order to get to the destination with the shortest path
    // it requires a vector with the previous values, an integer i represiting where im visiting now, and the vector of the 
    // airports so that we can print the name instead of the number
    std::vector<Connection> merda(int i) {return _adjList[i];}
    void print_route(std::vector<int>  &prev, int i, std::vector<Airports> airports, int reversed);
    //method used to find the shortest path, it requires an integer that will represent where we are comming from, the number of
    //vertex, the airport number that we are going, and the vector of the airports so that we can print the name
    // instead of the number, and a last parameter that will represent weather we shoudl reverse when printint or not
    void findShortestPath(int from, int N, int to, std::vector<Airports> airports, int reversed);
};
#endif

#include "Graph.hpp"

using namespace std;
//these two variables will help us to keep acount of the destination throught methods and help with printing "->"
int destination;
bool first;

Graph::Graph(vector<Connection> &connections, int M)
{
	// resize the list so that it can hold all the elements of the vector connections 
    _adjList.resize(M);
    // add all the connections in the graph
   	for (Connection &connection: connections)
   	{
     	// put the connection in the end
    	_adjList[connection.from()].push_back(connection);
    }
}

/*
	tricks that will allow the usage of the priority queue from the STL library.
	The priortity queue requires what we will compare, the data structure that we will 
	compare and how 
	
	these two next "struct" are repsenting these criteria
*/
//the node behaves like an object, which is made of a vertex and the price 
struct Node 
{
    int vertex, price;
};
//the comp is only to allow us to compare two nodes
struct comp
{
    bool operator()(Node &first, Node &second) {return first.price > second.price;}
};
 
//this method is used to print the route used in order to get to the destination with the shortest path
// it requires a vector with the previous values, an integer i represiting where im visiting now, and the vector of the 
// airports so that we can print the name instead of the number
void
Graph::findShortestPath(int from, int N, int to, vector<Airports> airports, int reversed)
{	
	//initializes the priority queue with what we said above
	priority_queue<Node, vector<Node>, comp> min_heap;
	min_heap.push({from, 0});//the minimum distance in the priority queue is form itself and it is 0
 	int largeNumber =424242424;//just a large number to hold an impossible value for a flight ticket 
    // initializes the vector that will hold the distances 
    vector<int> distances(N, largeNumber);
 
    // distance from the from to itself is zero
    distances[from] = 0;
 
    //vector of int(1 or 0) to help to know where we are done already or no
    vector<int> done(N, 0);
    done[from] = 1;
 
    // were the previous vector was
    vector<int> prev(N, -1);
 
    // keep going until we are not empty 
    while (!min_heap.empty())
    {
        // Remove and return the best vertex
        Node node = min_heap.top();
        min_heap.pop();
 
        // store the vertex number for this particular node 
        int myVertex = node.vertex;
 
        // go through every connection that we hace in this list for this node 
        for (Connection myCon: _adjList[myVertex])
        {
        	//in case we havent visited this yet, and the distance of this vertex plus the price im paying for this connection
        	//are smaller than the distances (price) that we will pay
            if (!done[myCon.to()] && ((distances[myVertex] + myCon.price()) < distances[myCon.to()]))
            {	//go ahaed and update the needed information 
                distances[myCon.to()] = myCon.price() + distances[myVertex];
                prev[myCon.to()] = myVertex;
                min_heap.push({myCon.to(), distances[myCon.to()]});
            }
        }
        //this vertex was visited
        done[myVertex] = 1;
    }
    destination = to;//remember where im going
    first =1;//should print "->"
    //loop thourgh the size of the vector of vectors
    for (int i = 0; i < N; i++)
    {	//in case this index is the same from where i was comming from 
    	//the distances have been updtaded, and I have arrived where I want
        if ((i != from && distances[i] != largeNumber )&& ( i==to))
        {  //go ahead and send the output back
            cout<<"The cheapest itinerary would be $"<<distances[i]<<endl;
            cout<<"Airports used: ";
            print_route(prev, i, airports, reversed);
        }
    }
}
//method used to find the shortest path, it requires an integer that will represent where we are comming from, the number of
//vertex, the airport number that we are going, and the vector of the airports so that we can print the name
// instead of the number, and a last parameter that will represent weather we shoudl reverse when printint or not
void 
Graph::print_route(vector<int> &prev, int i, vector<Airports> airports, int reversed)
{
    if (i < 0)//if i is smaller than 0, the recursion is over
        return;
 	//solve from what came before me 
    print_route(prev, prev[i], airports, reversed);
    for(Airports air: airports)//loop through the list of airports to figure out the name of the airport from the number
    {	
    	if(reversed)//in case im reversed, print the arrow to the other side 
    	{
    		if(air.number() == i && i!= destination)//if this is the number of the airport i want, and im not the last element
    			cout << air.name() << "<-";
    	 	else if(air.number() ==i&& i==destination)//in case im the last element
    	 		cout<<air.name()<<endl;
    	}
    	else//same as before, but now with a "normal" arrow
    	{
			if(air.number() == i && i!= destination)
				cout << air.name() << "->";
			else if(air.number() ==i&& i==destination)
			 	cout<<air.name()<<endl;
    	}
    }
}
    

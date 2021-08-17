// FILE: main.cpp
// AUTHOR: Henrique Medeiros Dos Reis
// DATE: 4/28/2021
//    program that reads a file with airports and connections, then tells the best route 

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include "Graph.hpp"
#include "Connection.hpp"
#include "Airports.hpp"

using namespace std;
 
 
int main()
{

	string fileName;//strings that will hold the name of the files
	cout<<"Enter input file containing fight data: ";
	cin>>fileName;//get the string from the keyboard
	
	ifstream ifile(fileName);//open the file
	
	string depart;//string that will hold from where we are starting
	cout<<"Enter departing airport: ";
	cin>>depart;
	
	string arrive;//string that will hold where we are trying to go
	cout<<"Enter arriving airport: ";
	cin>>arrive;
	
	int uniqueAirports;//how many unique airports we will have
	ifile>>uniqueAirports;//get from inputfile
	vector<Airports> airports;//create a vector that will hold all the airports
	for(int i=0;i<uniqueAirports;i++)//loop as many times as the nubmer of airports
	{
		string name;//string that will hold the name of the airport
		ifile>>name;
		Airports newAirport = Airports(name, i);//create an airport with the name and index (number of the airport)
		airports.push_back(newAirport);//put in the airports vector
	}
	
	int nFlights;//how many flights we have
	ifile>>nFlights;
   
    vector<Connection> edges;//vector that will hold the edged of this graph "connections"
 	for(int i=0; i<nFlights; i++)
 	{
 		string firstFlight, secondFlight;//string that will hold frmo to where
 		ifile>>firstFlight;
 		ifile>>secondFlight;
 		int price;
 		ifile>>price;//integer that will hold the price
 		int from, to;
 		//"translate" the names of the airports to the airports number
 		for(Airports air: airports)
 		{
 			if(firstFlight==air.name())
 				from = air.number();
 			else if(secondFlight==air.name())
 				to = air.number();
 		}
 		Connection myCon = Connection(from, to, price);//create that connection
 		edges.push_back(myCon);//make this connection
 	}
	//contruct the graph based in those conections and the number of uniqueAirports
    Graph graph(edges, uniqueAirports);
 	
 	int from, to;
 	//translate the depart and arrive to integers, number of the aiport
 	for(Airports air: airports)
 	{
 		if(depart==air.name())
 			from = air.number();
 		else if(arrive==air.name())
 			to = air.number();
 	}
 	
 	//if the airport number that im comming from is smaller than the one im going, no adjustments need to be made
    if(from<=to)
    	graph.findShortestPath(from, uniqueAirports, to, airports,0);
    else//otherwise
    {	//since this is an undirected graph, it is exactly the same path, so just reverse them and print with  a different arrow
    	graph.findShortestPath(to, uniqueAirports, from, airports,1);
    }
 	cout<<"AA"<<endl;
 	for(int i=0; i<uniqueAirports; i++)
 	{
 		for(Connection c: graph.merda(i))
 			cout<<c;
 		cout<<"nextCon"<<endl;
 	}
    return 0;
}

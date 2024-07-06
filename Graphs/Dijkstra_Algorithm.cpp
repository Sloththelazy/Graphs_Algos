#include <vector>
#include <iostream>
using namespace std;
#include <queue>
//
// Created by Gulgulu Singh on 06/07/24.
//
class solution {
public:
    std::vector<int> dijkstra(int v , vector<vector<int>> adj[] , int S) {
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq ;
        vector<int> result(v ,INT32_MAX);

        result[S]= 0 ;
        pq.push({0 ,S}) ; // {distance , node}  we should store it this way because this aims at minimisizing the distance

        while (!pq.empty()) {
            int distance_source  = pq.top().first ;
            int source = pq.top().second ;
            pq.pop();

            for(auto& neighbour : adj[source]) {
                int neighbour_of_source = neighbour[0]; // change this before using to fit the function
                int neighbour_distance = neighbour[1];

                if(distance_source + neighbour_distance < result[neighbour_of_source]) {
                    pq.push({neighbour_of_source , distance_source + neighbour_distance}) ;
                    result[neighbour_of_source] = distance_source + neighbour_of_source ;
                }
            }

        }
    }
};
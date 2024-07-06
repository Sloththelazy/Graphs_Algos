//
// Created by Gulgulu Singh on 06/07/24.
//
#include<vector>
#include<set>
#include<iostream>
using namespace std;

class solution {
public:
    static vector<int> dijkstraAlgo (int V , vector<vector<int>> adj[] , int S) {
        set<pair<int,int>> st ;

        vector<int> result (V, INT32_MAX);
        result[S] = 0 ;
        st.insert({0 ,S});

        while(!st.empty()) {
            auto& it = *st.begin(); // *st.begin  will give us the smallest vaule
            int source = it.second ;
            int distance =  it.first;
            st.erase(it);

            for(auto& neighbour : adj[source]) {
                int node = neighbour[0];
                int distance_node = neighbour[1];
                if(distance + distance_node < result[node]) {
                    if(result[node] != INT32_MAX) {
                        st.erase({result[node] , node});
                    }
                    result[node] = distance + distance_node ;
                    st.insert({result[node], node});
                }
            }
        }

        return result;
    }
};
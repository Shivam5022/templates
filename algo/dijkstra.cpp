// made this as a lambda
// read algo properly before using

using pii = pair<int, int>;
const int Ds = 1e5;
vector<pair<int,int>> adj[Ds];  // stores node, weight
vector<int> minDistance(Ds);    // minimum distance from SOURCE
vector<int> path(Ds);           //stores penultimate vertex in shortest path from SOURCE
priority_queue<pii , vector<pii> , greater<pii> > PQ;  // stores {WEIGHT , NODE} pair
 
auto dijkstra = [&] (int source) {
    minDistance.assign(Ds, inf);
    path.assign(Ds, -1);
    PQ.push({0,source});      //weight , node
    minDistance[source] = 0;
    //PQ contains minimum distance of NODES from SOURCE
    while(!PQ.empty()){
        int dist = PQ.top().first;
        int node = PQ.top().second;
        PQ.pop();                
        if(dist != minDistance[node])continue; 
        for(auto it : adj[node]){
            int x = it.first;  //this is adjacent node 
            int y = it.second; //this is distance from 'node'
            // (y + dist) will be distance of 'x' from 'SOURCE'
            if(minDistance[x] > y + dist){
                minDistance[x] = y + dist;
                path[x] = node;
                PQ.push({minDistance[x] , x});  //push it in PQ if we got better answer. 
            }
        }
    }
};
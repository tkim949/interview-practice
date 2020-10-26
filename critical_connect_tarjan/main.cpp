#include <iostream>
#include <vector>
#include <set>

using namespace std;


//build graph!
void buildGraph(vector<vector<int>> & edges, vector<vector<int>> &graph) {

    for(const vector<int> & eg: edges) {
        graph[eg[0]].push_back(eg[1]);
        graph[eg[1]].push_back(eg[0]);
    }
}

void dfs(vector<bool> & visited, vector<int> &lowTime, vector<int> &visitTime,
         vector<vector<int>> &graph, int current, int parent, int time, set<int> & result) {
    // update visited, lowTime, visitedTime and time
    visited[current] = true;
    visitTime[current] = time;
    lowTime[current] = time;
    time++;

    //check all adjacent points of the current point!
    for(int adj: graph[current]) {
        //if that adjacent point is parent, skip it!
        if(adj == parent) continue;
        //if that ppoint is not yet visited!
        if(!visited[adj]) {
            dfs(visited, lowTime, visitTime, graph, adj, current, time, result);
            lowTime[current] = min(lowTime[current], lowTime[adj]);
            if(visitTime[current] < lowTime[adj]) { //if current visitTime is less than adjacent's lowTime, it's critical point!
                result.insert(current);
                //result.insert(adj);
            }
        } else { //if that point is already visited, then compare its lowTime with adjacent's visitTime
            lowTime[current] =min(lowTime[current], visitTime[adj]);
        }


    }

}
// this algo needs lowTime, visitTime so set all variables,
vector<int> findCriticalCnt(int numNodes, int numEdges, vector<vector<int>>& edges) {

    set<int> result; //later change to vector!
    vector<vector<int>> graph(numNodes);
    vector<bool> visited(numNodes, false);
    vector<int> lowTime(numNodes);
    vector<int> visitTime(numNodes);
    //first build graph and then check all graph with dfs
    buildGraph(edges, graph);
    dfs(visited, lowTime, visitTime, graph, 0, -1, 0, result);

    return vector<int>(result.begin(), result.end());

}



int main() {
    std::cout << "Hello, World!" << std::endl;

    int numNodes = 7;
    int numEdges = 7;
    vector<vector<int>> edges = { {0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 5}, {5, 6},{3, 4}};
    vector<int> ret = findCriticalCnt(numNodes, numEdges, edges);

    for(int i=0; i< ret.size(); i++) {
        cout<<ret[i]<<" ";
    }
    return 0;
}
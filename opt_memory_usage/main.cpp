#include <iostream>
#include <vector>
#include <map>

/*
 * input: foreground = [1, 7, 2, 4, 5, 6]
 *        background = [3, 1, 2]
 * K = 6
 * output: [(3,2), (4, 1), (5, -1)]
 */

using namespace std;

vector<vector<int>> optMemory(vector<int> a, vector<int> b, int target) {

    //set map and return vector
    map<int, int> tableA;
    vector<vector<int>> result;
   // input first one element and index
    for(int i=0; i<a.size(); i++) {
        tableA[a[i]] = i;
    }
   //use while loop for the case of there is exact target sum
   // inner loop run through the second one and check its element has complement in the map!
   while(result.size() == 0) {
       for (int j = 0; j < b.size(); j++) {

           if (tableA.find(target - b[j]) != tableA.end()) {
               result.push_back({tableA[target - b[j]], j});
           } else if (tableA.find(target) != tableA.end()) { //case a element is target itself
               result.push_back({tableA[target], -1});
           } else if (b[j] == target) { //case b element is target itself
               result.push_back({-1, j});
           }
       }
       if(result.size() == 0) target--; // if there is any targetsum, decrement target by 1.
   }

   return result;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int> A = {1, 7, 2, 4, 5, 6};
    vector<int> B = {3, 1, 2};
    int k= 6;
    vector<vector<int>> ret = optMemory(A, B, k);

    for(auto ele: ret){
        for(int i=0; i<ele.size(); i++) {
            cout<<ele[i]<<" ";
        }
        cout<<", ";
    }

    cout<<endl;

    vector<int> A1 = {1, 7, 2, 4, 5, 6};
    vector<int> B1 = {1, 1, 2};
    int k1= 10;
    vector<vector<int>> ret1 = optMemory(A1, B1, k1);

    for(auto ele: ret1){
        for(int i=0; i<ele.size(); i++) {
            cout<<ele[i]<<" ";
        }
        cout<<", ";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


class SlidingMatrix {

public:
    /*
    bool hasAllNum(vector<int> nums) {

        map<int, int> table;

        for(int i=1; i< 10; i++) {
            table[i] = 1;
        }

        for(int i=0; i< nums.size(); i++) {
            if(table.find(nums[i]) == table.end()) {
                return false;
            }
        }
        return true;
    }*/

    vector<bool> findMatrix(vector<vector<int>> arr) {

        vector<bool> result;
        for(int k=0; k < (arr[0].size()-2); k++) {
            set<int> numV;
            for(int j=k; j< k+3; j++) {
                //int i= 0;
                for(int i =0; i<3; i++) {

                  numV.insert(arr[i][j]);

                }

            }

            cout<<"K: "<<k<<endl;
            for(auto el: numV) {
                cout<< el<<" ";
            }
            cout<<endl;

            if(numV.size() == 9) result.push_back(true);
            else result.push_back(false);
            numV.clear();

        }
        return result;
    }

};


int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<vector<int>> two = {
            {1, 2, 3, 4, 5, 6, 7, 8},
            {4, 5, 6, 3, 4, 5, 4, 3},
            {7, 8, 9, 2, 3, 2, 1, 9}
    };
    SlidingMatrix sm;
    vector<bool> ret = sm.findMatrix(two);

    for(auto el: ret) {
        cout<< el<<" ";
    }
    cout<<endl;

    return 0;
}
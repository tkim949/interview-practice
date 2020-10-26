#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//time complexity: O(n*2^n), space complexity O(2^n)
class Subsets {

public:
    static vector<vector<int>> findSubsets(const vector<int> & nums) {
        vector<vector<int>> subsets;

        subsets.push_back(vector<int>()); //insert {}

        for(int i=0; i<nums.size(); i++) {

            int size = subsets.size(); //at first it is 1
            for(int j=0; j<size; j++) {

                vector<int> innerSet(subsets[j]); //at first it is {}
                innerSet.push_back(nums[i]); //index 0, it would be 1, then {1}
                subsets.push_back(innerSet);
            }
        }
        return subsets;
    }

};

//time complexity: O(n*2^n), space complexity O(2^n)
class SubsetWithDuplicates {
public:
    static vector<vector<int>> findSubsets(vector<int> & nums) {
       //needs to sorting!
       sort(nums.begin(), nums.end());

        vector<vector<int>> subsets;

        subsets.push_back(vector<int>()); //insert {}

        int startIdx =0;
        int endIdx = 0;

        for (int i=0; i< nums.size(); i++) {
            startIdx =0;
            int size = subsets.size(); //at first it is 1

            if(i>0 && nums[i] == nums[i-1]) {
                startIdx = endIdx +1; //this is previous endIdx, not this turn's one
            }


            endIdx = size-1;
            for (int j= startIdx; j <= endIdx; j++) {

                vector<int> innerSet(subsets[j]); //at first it is {}
                innerSet.push_back(nums[i]); //index 0, it would be 1, then {1}
                subsets.push_back(innerSet);
            }
        }
        return subsets;
    }

};

class Permutations {


public:
    static vector<vector<int>> findPermutations(const vector<int> & nums) {
        vector<vector<int>> result;
        queue<vector<int>> permutations;
        permutations.push(vector<int>()); //insert {}


        for(int i=0; i<nums.size(); i++) {

            int size = permutations.size(); //at first it start 1

            for(int j =0; j <size; j++) {
                vector<int> crtPermutation = permutations.front(); //we generates all subsets and use only the one whose size is the same as nums

                permutations.pop();

                for(int k=0; k <= crtPermutation.size(); k++) {
                    vector<int> newPermutation(crtPermutation);
                    //vector<int> newPermutation = crtPermutation;
                    newPermutation.insert(newPermutation.begin() + k, nums[i]); //find the exact place and add the number into that subset


                    if(newPermutation.size() == nums.size()) {
                        result.push_back(newPermutation);
                    } else {
                        permutations.push(newPermutation);
                    }
                }

            }
        }

     return result;
    }



};

void print(const vector<vector<int>> &result) {

    for(auto ele: result) {
        cout<<"{";
        for(auto num: ele) {
            cout<< num<<" ";
        }
        cout<<"} ";
    }


}
int main() {

    std::cout << "Basic Subsets lists" << std::endl;
    vector<vector<int>> result = Subsets::findSubsets(vector<int>{1, 3, 3});
    print(result);

    SubsetWithDuplicates sd;
    std::cout << "\nDuplicate Subsets lists" << std::endl;
    vector<int> vec= {1, 3, 3};
    vector<vector<int>> result2 = sd.findSubsets(vec);
    print(result2);

    std::cout<<"\nPermutations" <<endl;
    vector<vector<int>> result3 = Permutations::findPermutations(vector<int> {1, 3, 5});
    print(result3);

    return 0;
}
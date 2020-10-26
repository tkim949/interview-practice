#include <iostream>
#include <vector>

using namespace std;

class Subsets {
 public:
  static vector<vector<int>> findSubsets(const vector<int>& nums) {
    vector<vector<int>> subsets;
    // start by adding the empty subset
    subsets.push_back(vector<int>());
    for (auto currentNumber : nums) {
      // we will take all existing subsets and insert the current number in them to create new
      // subsets
      int n = subsets.size();
      for (int i = 0; i < n; i++) {
        // create a new subset from the existing subset and insert the current element to it
        vector<int> set(subsets[i]);
        set.push_back(currentNumber);
        subsets.push_back(set);
      }
    }
    return subsets;
  }
};

class SubsetWithDuplicates {
public:
    static vector<vector<int>> findSubsets(vector<int>& nums) {
      sort(nums.begin(), nums.end());  // sort the numbers to handle duplicates

      vector<vector<int>> subsets;
      subsets.push_back(vector<int>());
      int startIndex = 0, endIndex = 0;

      for (int i = 0; i < nums.size(); i++) {
        startIndex = 0;
        // if current and the previous elements are same, create new subsets only from the subsets
        // added in the previous step
        if (i > 0 && nums[i] == nums[i - 1]) {
          startIndex = endIndex + 1;
        }
        endIndex = subsets.size() - 1;
        for (int j = startIndex; j <= endIndex; j++) {
          // create a new subset from the existing subset and add the current element to it
          vector<int> set(subsets[j]);
          set.push_back(nums[i]);
          subsets.push_back(set);
        }
      }
      return subsets;
    }
};

void print(vector<vector<int>> result) {
    for (auto vec : result) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
  vector<vector<int>> result = Subsets::findSubsets(vector<int>{1, 3});
  cout << "\nTest1: Here is the list of subsets: " << endl;
  print(result);

  result = Subsets::findSubsets(vector<int>{1, 5, 3});
  cout << "\nTest2: Here is the list of subsets: " << endl;
  print(result);

  vector<int> vec = {1, 3, 3};
  vector<vector<int>> resultD = SubsetWithDuplicates::findSubsets(vec);
  cout << "\nTest1(Duplicate): Here is the list of subsets: " << endl;
  print(resultD);

  vec = {1, 5, 3, 3};
  resultD = SubsetWithDuplicates::findSubsets(vec);
  cout << "\nTest2(Duplicate): Here is the list of subsets: " << endl;
  print(resultD);
}




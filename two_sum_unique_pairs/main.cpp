#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <map>

using namespace std;


int findTwoSum(vector<int> nums, int target) {
   //3rd approach O(nlogn), spaceO(1)
   /*
   sort(nums.begin(), nums.end()); //using sorting

   int lastPairNum = INT_MIN;
   int left =0, right = nums.size() -1;
   int result = 0;

   while(left < right) {

       int currSum = nums[left] + nums[right];
       if(currSum == target) {
           if(lastPairNum != nums[right]) {
               result++;
           }
           lastPairNum = nums[right];
           left++;
           right--;
       }else if(currSum <target) {
           left++;
       } else {
           right--;
       }
   }
   return result; */

  //2nd approach, O(n);
    set<pair<int, int>> setTable;
    map<int, int> mapTable;
    int result;
    for(int i=0; i<nums.size(); i++) {
      if(mapTable.find(target-nums[i]) != mapTable.end()) {
          setTable.insert(pair<int,int>(target-nums[i], nums[i]));
      } else{
          mapTable[nums[i]] = i;
      }
    }

    return setTable.size();


  /* 1st approach ---- but map didn't handle the duplicate numbers, so we can use set instead!
    unordered_map<int, int> table;
    int result = 0;

    for(int i=0; i <nums.size(); i++) {

        if(table.find(target-nums[i]) != table.end()) {
            result++;
        }
        else{
            table[nums[i]] = 1;
        }

    }

    return result;
   */
}



int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int> nums ={1, 1, 2, 45, 46, 47};

    cout<<findTwoSum(nums, 47)<<endl;

    //cout<<ret<<endl;
    return 0;
}
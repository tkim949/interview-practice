#include <iostream>
#include <vector>

using namespace std;

class SubsetSum {

public:
    bool canPartition(const vector<int> &num, int sum) {
        int n = num.size();
        vector<vector<bool>> dp(n, vector<bool>(sum +1));
        //first column
        for(int i=0; i <n ; i++) {
            dp[i][0] = true;
        }
        //first row
        for(int s =1; s<= sum; s++) {
            dp[0][s] = (num[0] == s? true: false);
        }

        for(int i =1; i< num.size(); i++) {
            for(int s=1; s<=sum; s++) {
                if(dp[i-1][s]) {
                    dp[i][s] = dp[i-1][s];
                } else if (s >= num[i]) {
                    dp[i][s] = dp[i-1][s-num[i]];
                }
            }
        }

        return dp[num.size()-1][sum];
    }

};

class AdvancedSubset{

public:
    bool haveSubsetSum(const vector<int> &num, int sum) {
        int n = num.size();
        vector<bool> dp(sum +1);

        dp[0] = true; //set the basic case

        //if any number in the array is the same as the target sum, it is true
        for(int s=1; s<=sum; s++) {
            dp[s] = (num[0] == s ? true: false);
        }

        for(int i =1; i<n; i++ ) {
            for(int s = sum; s>=0; s--) {
                if(!dp[s] && s>= num[i]) {
                    dp[s] = dp[s - num[i]];
                }
            }
        }

        return dp[sum];
    }

};

int main() {
    std::cout << "DP programming - Subset Sum" << std::endl;
    SubsetSum ss;
    vector<int> num1 = { 1, 2, 3, 7};
    vector<int> num2 = { 1, 2, 7, 1, 5};
    vector<int> num3 = { 1, 3, 4, 8};
    cout<<"Test1: bottomup solution: "<<ss.canPartition(num1, 6) <<endl;
    cout<<"Test2: bottomup solution: "<<ss.canPartition(num2, 10) <<endl;
    cout<<"Test3: bottomup solution: "<<ss.canPartition(num3, 6) <<endl;

    AdvancedSubset as;
    cout<<"Test1: advanced bottomup solution: "<<as.haveSubsetSum(num1, 6) <<endl;
    cout<<"Test2: advanced bottomup solution: "<<as.haveSubsetSum(num2, 10) <<endl;
    cout<<"Test3: advanced bottomup solution: "<<as.haveSubsetSum(num3, 6) <<endl;
    return 0;
}
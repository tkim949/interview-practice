#include <iostream>
#include <vector>

using namespace std;
//time complexity O(2^n), space complexity O(n)
class PartitionSet {
public:
    bool canPartition(const vector<int> &num) {
        int totalSum =0;
        for(int i=0; i<num.size(); i++) {
            totalSum += num[i];
        }
        if(totalSum %2 !=0) return false;

        return this->recursiveCheck(num, totalSum/2, 0); //0 is index
    }
private:
    bool recursiveCheck(const vector<int> &num, int sum, int crtIdx) {
        //base case
        if(sum ==0) return true;

        if(num.empty() || crtIdx >= num.size()) return false;
        //if we choose this num for set
        if(num[crtIdx] <= sum) {
            if(recursiveCheck(num, sum- num[crtIdx], crtIdx+1)) {
                return true;
            }
        }
        //if we do not choose this num for set
        return recursiveCheck(num, sum, crtIdx+1);
    }

};

////time complexity O(n*s), space complexity O(n*s)
class PartitionSet_TopDown {

public:
    bool canPartition(const vector<int> &num) {
        int totalSum =0;
        for(int i=0; i<num.size(); i++) {
            totalSum += num[i];
        }
        if(totalSum %2 !=0) return false;

        vector<vector<int>> dp(num.size(), vector<int>(totalSum/2 +1, -1));
        return this->recursiveCheck(dp, num, totalSum/2, 0); //0 is index
    }
private:
    bool recursiveCheck(vector<vector<int>> &dp, const vector<int> &num, int sum, int crtIdx) {

        //base case
        if(sum == 0) return true;

        if(num.empty() || crtIdx >= num.size()) return false;

        if(dp[crtIdx][sum] == -1) {
            //choose the number
            if(num[crtIdx] <= sum) {
                if(recursiveCheck(dp, num, sum-num[crtIdx], crtIdx +1)) {
                    dp[crtIdx][sum] = 1;
                    return true;
                }
            }
            //not choose current number
            dp[crtIdx][sum]= recursiveCheck(dp, num, sum, crtIdx+1) ? 1: 0;
        }
        return dp[crtIdx][sum] == 1 ? true: false;
    }

};

//time complexity O(n*s), space complexity O(n*s)
class PartitionSet_bottomUp {

public:
    bool canPartition(const vector<int> &num) {
        int n =num.size();
        int totalSum = 0;
        for(int i=0; i< n; i++) {
            totalSum += num[i];
        }

        if(totalSum % 2 != 0) return false;

        int sum = totalSum/2;

        vector<vector<bool>> dp( n, vector<bool>(sum+1));

        for(int i=0; i<n; i++) {
            dp[i][0] = true; //first column
        }
        //with only one number, it can be true when it is equal to the sum.
        for(int s =1; s <= sum; s++) {
            dp[0][s] = (num[0] == s ? true: false); // first row
        }

        for(int i=1; i< n; i++ ){
            for(int s = 1; s<=sum; s++) {
                //if it already find the sum s,
                if(dp[i-1][s]) {
                    dp[i][s] = dp[i - 1][s];
                }
                else if(s >= num[i]) { //if there is still remaining num, try to find it.
                    dp[i][s] = dp[i-1][s- num[i]];
                }
            }
        }

        return dp[n-1][sum];
    }

};

int main() {
    std::cout << "DP programming - Equal Subset Sum Partition!" << std::endl;
    PartitionSet ps;
    vector<int> num1 = {1, 2, 3, 4};
    vector<int> num2 = {1, 1, 3, 4, 7};
    vector<int> num3 = {2, 3, 4, 6};
    cout<<"Test1-Basic Recursive: "<<ps.canPartition(num1)<<endl;
    cout<<"Test2-Basic Recursive: "<<ps.canPartition(num2)<<endl;
    cout<<"Test3-Basic Recursive: "<<ps.canPartition(num3)<<endl;
    PartitionSet_TopDown ps_td;
    cout<<"Test1-TopDown Recursive: "<<ps_td.canPartition(num1)<<endl;
    cout<<"Test2-TopDown Recursive: "<<ps_td.canPartition(num2)<<endl;
    cout<<"Test3-TopDown Recursive: "<<ps_td.canPartition(num3)<<endl;
    PartitionSet_bottomUp ps_bu;
    cout<<"Test1-bottomUp Recursive: "<<ps_bu.canPartition(num1)<<endl;
    cout<<"Test2-BottomUp Recursive: "<<ps_bu.canPartition(num2)<<endl;
    cout<<"Test3-BottomUp Recursive: "<<ps_bu.canPartition(num3)<<endl;
    return 0;
}
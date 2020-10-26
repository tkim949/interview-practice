#include <iostream>
#include <vector>

using namespace std;

class BFSubsetSum{

public:
    int countSubset(const vector<int> &num, int sum) {
       return this->countSubsetRecursive(num, sum, 0);
    }

private:
    int countSubsetRecursive(const vector<int> &num, int sum, int crtIdx) {

        //base case
        if(sum == 0) return 1; //under this condition, we finally got one possible subset!

        if(num.empty() || crtIdx >= num.size()) return 0;

        //case of selecting this number
        int count1 =0;
        if(num[crtIdx] <= sum) {
            count1 = countSubsetRecursive(num, sum-num[crtIdx], crtIdx+1);
        }
        //case of not selecting this number
        int count2 = countSubsetRecursive(num, sum, crtIdx+1);

        return count1 + count2;
    }
};

class TopDownSubsetSum {

public:
    int countSubset(const vector<int> &num, int sum) {
        vector<vector<int>> dp(num.size(), vector<int>(sum+1, -1));
        return this->countSubsetRecursive(dp, num, sum, 0);
    }

private:
    int countSubsetRecursive(vector<vector<int>> &dp, const vector<int> &num, int sum, int crtIdx) {

        if(sum == 0) return 1;

        if(num.empty() || crtIdx >= num.size()) return 0;

        if(dp[crtIdx][sum] == -1) {

            int count1 =0;
            if(num[crtIdx] <= sum) {
                count1 = countSubsetRecursive(dp, num, sum-num[crtIdx], crtIdx +1);
            }

            int count2 = countSubsetRecursive(dp, num, sum, crtIdx+1);

            dp[crtIdx][sum] = count1 + count2;
        }

        return dp[crtIdx][sum];
    }
};
//time complexity O(n*s), space O(n*s)
class BottomUpSubsetSum {


public:
    int countSubset(const vector<int> &num, int sum) {
        int n= num.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));

        for(int i=0; i<n; i++) {
            dp[i][0] =1; //first coloumn
        }

        for(int s =1; s<= sum; s++) {
            dp[0][s] =(num[0] == s ? 1: 0);
        }

        for(int i=1; i < num.size(); i++) {
            for(int s =1; s <= sum; s++) {
                dp[i][s] = dp[i-1][s];
                if(s>= num[i]) {
                    dp[i][s] += dp[i-1][s-num[i]];
                }
            }
        }
        return dp[num.size()-1][sum];
    }


};

//time complexity O(n*s), space complexity O(s)
class AdvancedBottomUp {

public:
    int countSubset(const vector<int> &num, int sum) {
        int n = num.size();
        vector<int> dp(sum+1);
        dp[0] =1;

        for(int s=1; s<=sum; s++) {
            dp[s]=(num[0] == s? 1:0);
        }

        for(int i=1; i<num.size(); i++) {
            for(int s=sum; s >=0; s--) {
                if(s >= num[i]) {
                    dp[s] += dp[s-num[i]];
                }
            }
        }
        return dp[sum];
    }
};

int main() {
    std::cout << "DP programming Subset Sum" << std::endl;
    BFSubsetSum bf;
    vector<int> num1 ={1, 1, 2, 3};
    vector<int> num2 ={1, 2, 7, 1, 5};
    cout<<"Test1-Brute Force SubsetSum: "<<bf.countSubset(num1,4)<<endl;
    cout<<"Test2-Brute Force SubsetSum: "<<bf.countSubset(num2,9)<<endl;

    TopDownSubsetSum td;
    cout<<"Test1-Top-Down SubsetSum: "<<td.countSubset(num1,4)<<endl;
    cout<<"Test2-Top-Down SubsetSum: "<<td.countSubset(num2,9)<<endl;

    BottomUpSubsetSum bu;
    cout<<"Test1-Bottom-up SubsetSum: "<<bu.countSubset(num1,4)<<endl;
    cout<<"Test2-Bottom-up SubsetSum: "<<bu.countSubset(num2,9)<<endl;

    AdvancedBottomUp ab;
    cout<<"Test1-Advanced-Bottom-up SubsetSum: "<<ab.countSubset(num1,4)<<endl;
    cout<<"Test2-Advanced-Bottom-up SubsetSum: "<<ab.countSubset(num2,9)<<endl;
    return 0;
}
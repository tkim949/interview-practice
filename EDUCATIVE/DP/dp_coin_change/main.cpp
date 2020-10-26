#include <iostream>
#include <vector>

using namespace std;

class CoinChange {

public:
    int waysOfChange(const vector<int> &denominations, int total) {
        return this->waysOfChangeRecursive(denominations, total, 0);//0 is index
    }

private:
    int waysOfChangeRecursive(const vector<int> &denominations, int total, int crtIdx) {
        //base case
        if(total == 0) return 1;

        if(denominations.empty() || crtIdx >= denominations.size()) {
            return 0;
        }
        //for the case to choose this coin
        int sum1 = 0;
        if (denominations[crtIdx] <= total) {
            sum1 = waysOfChangeRecursive(denominations, total-denominations[crtIdx], crtIdx);
        }
        //for the case of not choosing
        int sum2 = waysOfChangeRecursive(denominations, total, crtIdx +1);

        return sum1 + sum2;
    }

};

class TopDownCoinChange {

public:
    int waysOfChange(const vector<int> &denominations, int total) {
        vector<vector<int>> dp(denominations.size(), vector<int>(total+1));
        return this->waysOfChangeRecursive(dp, denominations, total, 0);//0 is index
    }

private:
    int waysOfChangeRecursive(vector<vector<int>> &dp, const vector<int> &denominations, int total, int crtIdx) {
        //base case
        if(total == 0) return 1;

        if(denominations.empty() || crtIdx >= denominations.size()) {
            return 0;
        }

        //if the dp already have a num, return it from the memory
        if(dp[crtIdx][total]) {
            return dp[crtIdx][total];
        }
        //for the case to choose this coin

        int sum1 = 0;
        if (denominations[crtIdx] <= total) {
            sum1 = waysOfChangeRecursive(dp, denominations, total-denominations[crtIdx], crtIdx);
        }
        //for the case of not choosing
        int sum2 = waysOfChangeRecursive(dp, denominations, total, crtIdx +1);

        dp[crtIdx][total] = sum1 +sum2;
        return dp[crtIdx][total];
    }

};

class BottomUpCoinChange {

public:
    int waysOfChange(const vector<int> &denominations, int total) {

        int n = denominations.size();
        vector<vector<int>> dp(n, vector<int>(total +1));

        for(int i= 0; i<n; i++) {
            dp[i][0] =1;
        }

        for(int i=0; i < n; i++) {
            for(int j=1; j<= total; j++) {
                if( i >0) {
                    dp[i][j] = dp[i-1][j]; //not choose this coin
                }
                if(j >= denominations[i]) { //choose this coin
                    dp[i][j] += dp[i][j-denominations[i]];
                }
            }
        }

       return dp[n-1][total];

    }

};

int main() {
    std::cout << "DP Programming - Coin Change" << std::endl;
    CoinChange cc;
    vector<int> denominations = {1, 2, 3};
    cout<<"Test: BF-Coin Change: "<<cc.waysOfChange(denominations, 5) <<endl;
    TopDownCoinChange td;
    cout<<"\nTest: TopDown-Coin Change: "<<td.waysOfChange(denominations, 5) <<endl;
    BottomUpCoinChange bu;
    cout<<"\nTest: BottomUp-Coin Change: "<<bu.waysOfChange(denominations, 5) <<endl;
    return 0;
}
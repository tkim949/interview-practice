#include <iostream>
#include <vector>

using namespace std;

class Knapsack {


public:
    int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity){

        return this->knapsackRecursive(profits, weights, capacity, 0);

    }

private:
    int knapsackRecursive(const vector<int> &profits, const vector<int> &weights, int capacity, int crtIdx)
    {
        //base case
        if(capacity <=0 || profits.empty() || weights.size() != profits.size() || crtIdx >= profits.size()) {
            return 0;
        }
        //choose current item
        int profit1 = 0;
        if(weights[crtIdx] <= capacity) {
            profit1 = profits[crtIdx] +
                     knapsackRecursive(profits, weights, capacity- weights[crtIdx], crtIdx);
        }
        //skip current item/not choosing
        int profit2 = knapsackRecursive(profits, weights, capacity, crtIdx +1);

        return max(profit1, profit2);
    }

};

class TopDownKnapsack {

public:
    int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
        vector<vector<int>> dp(profits.size(), vector<int>(capacity +1));
        return this->knapsackRecursive(dp, profits, weights, capacity, 0);
    }

private:
    int knapsackRecursive(vector<vector<int>> &dp, const vector<int> &profits,
                          const vector<int> &weights, int capacity, int crtIdx) {


        //base case
        if(capacity <=0 || profits.empty() || weights.size() != profits.size() || crtIdx >= profits.size()) {
            return 0;
        }

        if(!dp[crtIdx][capacity]) {

            int profit1 =0;
            if(weights[crtIdx] <= capacity) {
                profit1 = profits[crtIdx] +
                          knapsackRecursive(dp, profits, weights, capacity - weights[crtIdx], crtIdx);

            }
            int profit2 = knapsackRecursive(dp, profits, weights, capacity, crtIdx+1);

            dp[crtIdx][capacity] = max(profit1, profit2);

        }

        return dp[crtIdx][capacity];

    }
};

class BottomUpKnapsack {

public:
    int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
        //base checks
        if(capacity <= 0|| profits.empty() || weights.size() != profits.size()) {
            return 0;
        }

        int n = profits.size();
        vector<vector<int>> dp(n, vector<int>(capacity +1));

        for(int i=0; i<n; i++) {
            dp[i][0] =0; //first column
        }

        for(int i=0; i<n; i++) {
            for(int c=1; c<= capacity; c++) {
                int profit1 =0, profit2 =0;
                //when choosing this item again and again, so row is the same and only capacity change!
                if(weights[i] <= c) {
                    profit1 = profits[i] + dp[i][c-weights[i]];
                }
                if(i>0) { //when not choosing this item!
                    profit2 = dp[i-1][c];
                }

                dp[i][c] = profit1 > profit2 ? profit1 : profit2;
            }
        }
       return dp[n-1][capacity];

    }

};

int main() {
    std::cout << "DP programming - unbounded knapsack - using item over and over." << std::endl;
    //answer Test1 - 140, Test2- 105
    Knapsack ks; //Knapsack *ks = new Knapsack();
    vector<int> profits = {15, 50, 60, 90};
    vector<int> weights = {1, 3, 4, 5};
    cout<<"Test1- BF Knapsack: "<<ks.solveKnapsack(profits, weights, 8) <<endl;
    cout<<"Test2- BF Knapsack: "<<ks.solveKnapsack(profits, weights, 6) <<endl;

    TopDownKnapsack td;
    cout<<"\nTest1- Top-Down Knapsack: "<<td.solveKnapsack(profits, weights, 8) <<endl;
    cout<<"Test2- Top-Down Knapsack: "<<td.solveKnapsack(profits, weights, 6) <<endl;

    BottomUpKnapsack bu;
    cout<<"\nTest1- Bottom-Up Knapsack: "<<bu.solveKnapsack(profits, weights, 8) <<endl;
    cout<<"Test2- Bottom-Up Knapsack: "<<bu.solveKnapsack(profits, weights, 6) <<endl;


    return 0;
}
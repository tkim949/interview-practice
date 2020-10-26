#include <iostream>
#include <vector>

using namespace std;

//time complexity O(2^n) exponential, space complexity O(n)
class Knapsack {

public:
    int solveKnapsack(const vector<int> &profits, const vector<int> & weights, int capacity) {
        return this->knapsackRecursive(profits, weights, capacity, 0); //0 is index, the first index
    }

private:
    int knapsackRecursive(const vector<int> &profits, const vector<int> &weights, int capacity, int crtIdx) {
        //base check
        if(capacity <=0 || crtIdx >= profits.size())  return 0;

        int profit1 = 0;
        if(weights[crtIdx] <= capacity) {
            profit1 = profits[crtIdx] + knapsackRecursive(profits, weights, capacity-weights[crtIdx], crtIdx+1);
        }

        int profit2 = knapsackRecursive(profits, weights, capacity, crtIdx+1);
        return max(profit1, profit2);
    }
};


/*time complexity O(N*C), space complexity O(N*C) */
class Knapsack_topDown {

public:
    int solveKnapsack(const vector<int> &profits, const vector<int> & weights, int capacity) {
        vector<vector<int>> dp(profits.size(), vector<int>(capacity+1, -1));

        return this->knapsackRecursive(dp, profits, weights, capacity, 0); //0 is index, the first index
    }

private:
    int knapsackRecursive(vector<vector<int>> &dp, const vector<int> &profits,
                          const vector<int> &weights, int capacity, int crtIdx) {

        //base check
        if (capacity <= 0 || crtIdx >= profits.size()) return 0;

        if (dp[crtIdx][capacity] != -1) return dp[crtIdx][capacity];

        int profit1 = 0;
        if (weights[crtIdx] <= capacity) {
            profit1 = profits[crtIdx] + knapsackRecursive(dp, profits, weights, capacity - weights[crtIdx], crtIdx + 1);
        }

        int profit2 = knapsackRecursive(dp, profits, weights, capacity, crtIdx + 1);

        dp[crtIdx][capacity] = max(profit1, profit2);

        return dp[crtIdx][capacity];
    }
};

//time complexity O(N*C), space complexity O(N*C)
class Knapsack_bottomUp {
public:
    int solveKnapsack(const vector<int> &profits, const vector<int> & weights, int capacity) {

       if(capacity <= 0 || profits.empty() || weights.size() != profits.size()) return 0;

       int n = profits.size();
       vector<vector<int>> dp(n, vector<int>(capacity +1));

       for(int i =0; i<n; i++) dp[i][0] = 0; //

       for(int c=0; c <=capacity; c++) {
           if(weights[0] <= c) {
               dp[0][c] = profits[0];
           }
       }

       for(int i =1; i<n; i++) {

           for(int c=1; c<= capacity; c++) {
               int profit1 =0, profit2=0;

               if(weights[i] <= c) {
                   profit1 = profits[i] + dp[i-1][c-weights[i]];
               }
               profit2 = dp[i-1][c];

               dp[i][c] = max(profit1, profit2);
           }

       }
       return dp[n-1][capacity];
    }
};



int main() {
    std::cout << "Knapsack problem with 3 different solutions" << std::endl;
    Knapsack ks;
    vector<int> profits = {1, 6, 10, 16};
    vector<int> weights = {1, 2, 3, 5};
    cout<<"Total knapsack propit with basic recursive: "<<ks.solveKnapsack(profits, weights, 7)<<endl;
    Knapsack_topDown ks_td;
    cout<<"Total knapsack propit with Top_Down recursive: "<<ks_td.solveKnapsack(profits, weights, 7)<<endl;
    Knapsack_bottomUp ks_bu;
    cout<<"Total knapsack propit with Bottom_Up recursive: "<<ks_bu.solveKnapsack(profits, weights, 7)<<endl;

    return 0;
}
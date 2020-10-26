#include <iostream>
#include <vector>

using namespace std;

class Staircase {
public:
    int countWays(int n) {

        if(n == 0) return 1; //base case
        if(n == 1) return 1;
        if(n == 2) return 2;

        int take1Step = countWays(n-1);
        int take2Step = countWays(n-2);
        int take3Step = countWays(n-3);

        return take1Step + take2Step + take3Step;

    }

};

class TopDownStaircase {
public:
    int countWays(int n) {
        vector<int> dp(n+1, 0);
        return countWaysRecursive(dp, n);
    }

    int countWaysRecursive(vector<int> &dp, int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;

        if(dp[n] == 0) {
            int take1Step = countWaysRecursive(dp, n-1);
            int take2Step = countWaysRecursive(dp, n-2);
            int take3Step = countWaysRecursive(dp, n-3);

            dp[n] = take1Step + take2Step + take3Step;

        }

        return dp[n];
    }
};

class BottomUpStaircase {

public:
    int countWays(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for(int i=3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }

};

int main() {
    std::cout << "DP-programming Stair case with 1, 2, 3 steps!" << std::endl;
    Staircase sc;

    cout<<"Test1(3)-BF Staircase: " << sc.countWays(3) <<endl;
    cout<<"Test2(4)-BF Staircase: " << sc.countWays(4) <<endl;
    cout<<"Test3(5)-BF Staircase: " << sc.countWays(5) <<endl;

    TopDownStaircase td;

    cout<<"\nTest1(3)-TopDown Staircase: " << td.countWays(3) <<endl;
    cout<<"Test2(4)-TopDown Staircase: " << td.countWays(4) <<endl;
    cout<<"Test3(5)-TopDown Staircase: " << td.countWays(5) <<endl;

    BottomUpStaircase bu;

    cout<<"\nTest1(3)-BottomUp Staircase: " << bu.countWays(3) <<endl;
    cout<<"Test2(4)-BottomUp Staircase: " << bu.countWays(4) <<endl;
    cout<<"Test3(5)-BottomUp Staircase: " << bu.countWays(5) <<endl;

    return 0;
}
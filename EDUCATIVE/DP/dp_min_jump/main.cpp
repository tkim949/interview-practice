#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class BottomUpArrayJump {
public:
    int countMinJumps(const vector<int> &jumps) {

        vector<int> dp(jumps.size());
        dp[0] = 0;

        for(int i=1; i<jumps.size(); i++) {
            dp[i] = INT_MAX;
        }

        for(int start =0; start < jumps.size() -1; start++) {
            for(int end = start+1; end <= start + jumps[start] && end <jumps.size(); end++) {
                dp[end] = min(dp[end], dp[start] +1);
            }
        }

    return dp[jumps.size() -1];

    }

};


int main() {
    std::cout << "DP-programming - minimum steps to end in array!" << std::endl;
    BottomUpArrayJump aj;
    vector<int> jumps1 = {2, 1, 1, 1, 4};
    vector<int> jumps2 = {1, 1, 3, 6, 9, 3, 0, 1, 3};
    cout<<"Test1-BottomUp ArrayJump: "<< aj.countMinJumps(jumps1)<<endl;
    cout<<"Test2-BottomUp ArrayJump: "<< aj.countMinJumps(jumps2)<<endl;
    return 0;
}
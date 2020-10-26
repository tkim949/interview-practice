#include <iostream>
#include <vector>

using namespace std;


//time complexity- O(3^n), space complexity - O(n)
class StairWithFee {
public:
    int findMinFee(const vector<int> &fee) {
        return findMinFeeRecursive(fee, 0);
    }

private:
    int findMinFeeRecursive(const vector<int> &fee, int crtIdx) {
        if(crtIdx > fee.size() -1) {
            return 0;
        }

        int take1Step = findMinFeeRecursive(fee, crtIdx+1);
        int take2Step = findMinFeeRecursive(fee, crtIdx+2);
        int take3Step = findMinFeeRecursive(fee, crtIdx+3);

        int minFee = min(min(take1Step, take2Step), take3Step);

        return minFee + fee[crtIdx];
    }
};

/*  O(n) time complexity, O(n) space complexity  */
class TopDownStairWithFee {

public:
    int findMinFee(const vector<int> &fee) {
        vector<int> dp(fee.size(), 0);
        return findMinFeeRecursive(dp, fee, 0);
    }

private:
    int findMinFeeRecursive(vector<int> &dp, const vector<int> &fee, int crtIdx) {
        if(crtIdx > fee.size() -1) {
            return 0;
        }

        if(dp[crtIdx] == 0) {
            int take1Step = findMinFeeRecursive(dp, fee, crtIdx + 1);
            int take2Step = findMinFeeRecursive(dp, fee, crtIdx + 2);
            int take3Step = findMinFeeRecursive(dp, fee, crtIdx + 3);

            dp[crtIdx] = fee[crtIdx] + min(min(take1Step, take2Step), take3Step);
        }

        return dp[crtIdx];
    }


};

class BottomUpStairWithFee {

public:
    int findMinFee(const vector<int> &fee) {

        vector<int> dp(fee.size() +1);
        dp[0]=0;
        dp[1] = fee[0];
        dp[2] = fee[0]; //not sure???

        /*
        for(int i=2; i<fee.size(); i++) {
            dp[i+1] = min(fee[i] +dp[i], min(fee[i-1] +dp[i-1], fee[i-2] +dp[i-2]));
        }*/

       // dp[3] = fee[0];
        for(int i=3; i<fee.size()+1; i++) {
            dp[i] = min(fee[i-1] +dp[i-1], min(fee[i-2] +dp[i-2], fee[i-3] +dp[i-3]));
        }

       return dp[fee.size()];
    }

};

int main() {
    std::cout << "DP-Programming, Find number of jumps(1, 2, 3) that has minimum fees!" << std::endl;
    StairWithFee sf;
    vector<int> fee1={1, 2, 5, 2, 1, 2};
    vector<int> fee2={2, 3, 4, 5};
    cout<<"Test1-Stair With Fee: "<<sf.findMinFee(fee1)<<endl;
    cout<<"Test2-Stair With Fee: "<<sf.findMinFee(fee2)<<endl;

    TopDownStairWithFee td;
    cout<<"\nTest1-TopDown Stair With Fee: "<<td.findMinFee(fee1)<<endl;
    cout<<"Test2-TopDown Stair With Fee: "<<td.findMinFee(fee2)<<endl;

    BottomUpStairWithFee bu;
    cout<<"\nTest1-BottomUp Stair With Fee: "<<bu.findMinFee(fee1)<<endl;
    cout<<"Test2-BottomUp Stair With Fee: "<<bu.findMinFee(fee2)<<endl;
    return 0;
}
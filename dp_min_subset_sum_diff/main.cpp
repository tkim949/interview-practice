#include <iostream>
#include <vector>

using namespace std;

class BFMinDiffSubset {

public:
    int minSumDiff(const vector<int> &num) {

        return this->minSumDiffRecursive(num, 0, 0, 0); // index, sum1, sum2
    }

private:
    int minSumDiffRecursive(const vector<int> &num, int crtIdx, int sum1, int sum2) {

        //base case
        if(crtIdx == num.size()) return abs(sum1 - sum2);

        //include current num in the first set, which is sum1
        int diff1 = minSumDiffRecursive(num, crtIdx +1, sum1 + num[crtIdx], sum2);
        //include current num in the second set, which is sum2
        int diff2 = minSumDiffRecursive(num, crtIdx+1, sum1, sum2+num[crtIdx]);

        return min(diff1, diff2);
    }

};

class TopDownMinDiff {

public:
    int minSumDiff(const vector<int> &num) {
        int sum =0;
        for(int i=0; i< num.size(); i++) {
            sum += num[i];
        }

        vector<vector<int>> dp(num.size(), vector<int>(sum+1, -1));
        return this->minSumDiffRecursive(dp, num, 0, 0, 0);
    }

private:
    int minSumDiffRecursive(vector<vector<int>> & dp, const vector<int> & num, int crtIdx, int sum1, int sum2) {


        //base case
        if(crtIdx == num.size()) {
            return abs(sum1 - sum2);
        }

        if(dp[crtIdx][sum1] == -1) { //it means there is no prior answer/solution

            int diff1 = minSumDiffRecursive(dp, num, crtIdx+1, sum1 + num[crtIdx], sum2);//choose sum1 set
            int diff2 = minSumDiffRecursive(dp, num, crtIdx+1, sum1, sum2 + num[crtIdx]);//choose sum2 set

            dp[crtIdx][sum1] = min(diff1, diff2); //why should this minimum? because we want minimum
        }

        return dp[crtIdx][sum1];
    }
};

class BottomUpMinDiff {

public:
    int minSumDiff(const vector<int> &num){
        int sum =0;
        for(int i=0; i<num.size(); i++) {
            sum += num[i];
        }

        int  n=num.size();
        vector<vector<bool>> dp(n, vector<bool>((sum/2 +1), false)); //two set's most minimum difference should be 0, which half of total sum

        for(int i=0; i< n; i++) {
            dp[i][0] = true; //the first column
        }

        for(int s=0; s <= sum/2; s++) {
            dp[0][s] = (num[0]== s ? true: false); // first row, it should be true when the number is the same as the target sum.
        }

        for(int i=1; i<num.size(); i++) {
            for(int s=1; s<=sum; s++) {
                if(dp[i-1][s]) { //if the previous row of that column is true, it is true
                    dp[i][s] = dp[i-1][s];
                } else if (s >= num[i]) {//otherwise, if this new number is less than the sum
                    dp[i][s] = dp[i-1][s-num[i]];
                }
            }

        }
        //now check
        int sum1 =0;
        //find the lagest index in the last row, which is true
        for(int i=sum/2; i>=0; i--) {
            if(dp[n-1][i] == true) {
                sum1 =i; //i is sum! because this sum is half of totalsum, so the largest is closer to the half.
                break;
            }
        }
        int sum2 = sum -sum1;
        return abs(sum2 - sum1);
    }



};

int main() {
    std::cout << "DP-programming Minimum Subset Sum Difference." << std::endl;
    BFMinDiffSubset bf;
    vector<int> num1 = {1, 2, 3, 9};
    vector<int> num2 = {1, 2, 7, 1, 5};
    vector<int> num3 = {1, 3, 100, 4};
    cout<<"Test1: Brute Force solution Minimum Sum Difference: "<<bf.minSumDiff(num1)<<endl;
    cout<<"Test2: Brute Force solution Minimum Sum Difference: "<<bf.minSumDiff(num2)<<endl;
    cout<<"Test3: Brute Force solution Minimum Sum Difference: "<<bf.minSumDiff(num3)<<endl;

    TopDownMinDiff td;
    cout<<"Test1: Top-Down solution Minimum Sum Difference: "<<td.minSumDiff(num1)<<endl;
    cout<<"Test2: Top-Down solution Minimum Sum Difference: "<<td.minSumDiff(num2)<<endl;
    cout<<"Test3: Top-Down solution Minimum Sum Difference: "<<td.minSumDiff(num3)<<endl;

    BottomUpMinDiff bp;
    cout<<"Test1: Bottom-Up solution Minimum Sum Difference: "<<bp.minSumDiff(num1)<<endl;
    cout<<"Test2: Bottom_Up solution Minimum Sum Difference: "<<bp.minSumDiff(num2)<<endl;
    cout<<"Test3: Bottom_Up solution Minimum Sum Difference: "<<bp.minSumDiff(num3)<<endl;

    return 0;
}
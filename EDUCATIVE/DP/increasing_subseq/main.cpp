#include <iostream>
#include <vector>

using namespace std;

class LIS {

public:

    int findLISLength(const vector<int> &nums) {

        if(nums.size() == 0) return 0;

        vector<int> dp(nums.size(), 1);

        int maxLength = 1;

        for(int rt=1; rt < nums.size(); rt++) {
            for( int lf = 0; lf < rt; lf++) {
                /*
                if(nums[rt] > nums[lf] && dp[rt] <= dp[lf]) {
                    dp[rt] = dp[lf]+1;
                    maxLength = max(maxLength, dp[rt]);
                }*/
                if(nums[rt] > nums[lf]) {
                    dp[rt] = max(dp[lf] +1, dp[rt]);
                }
            }
            maxLength = maxLength > dp[rt] ? maxLength: dp[rt];
        }

     return maxLength;

    }


};

class MDSS {

public:
    int findMinimumDeletions(const vector<int> &nums) {
        //minimum number of deletion to make a sequence sorted
        //= total length - longest increasing sub-sequence

        return nums.size()- findLISLength(nums);
    }

private:
    int findLISLength(const vector<int> &nums) {

        vector<int> dp(nums.size(), 1);

        int maxLength = 1;

        for(int rt=1; rt < nums.size(); rt++) {
            for (int lf = 0; lf < rt; lf++) {
                /*
                if(nums[rt] > nums[lf] && dp[rt] <= dp[lf]) {
                    dp[rt] = dp[lf]+1;
                    maxLength = max(maxLength, dp[rt]);
                }*/
                if (nums[rt] > nums[lf]) {
                    dp[rt] = max(dp[lf] + 1, dp[rt]);
                }
            }
            maxLength = maxLength > dp[rt] ? maxLength : dp[rt];
        }
        return maxLength;

    }


};

class MSIS {

public:
    int findMSIS(const vector<int> &nums) {

        vector<int> dp(nums.begin(), nums.end());

        int maxSum = nums[0];

        for(int rt =1; rt <nums.size(); rt++) {
            for(int lf = 0; lf <rt; lf++) {
                if(nums[rt] >nums[lf]) {
                //if(nums[rt] >nums[lf] && dp[rt] <dp[lf] +nums[rt]) {
                    dp[rt] = max(dp[lf] + nums[rt], dp[rt]);
                }
            }
            maxSum = max(maxSum, dp[rt]);
        }
        return maxSum;
    }
};



int main() {
    std::cout << "Find Longest Increasing Sub-sequence Length." << std::endl;
    LIS * lis = new LIS();

    vector<int> nums = {4, 2, 3, 6, 10, 1, 12};
    cout<<"Test1(5): "<<lis->findLISLength(nums) <<endl;
    vector<int> nums2 = {-4, 10, 3, 7, 15};
    cout<<"Test2(4): "<<lis->findLISLength(nums2)<<endl;

    cout<<"\nFind Maximum Sum increasing Sub-sequence."<<endl;
    vector<int> nums3 = {1, 3, 8, 4, 14, 6, 14, 1, 9, 4, 13, 3, 11, 17, 29};
    MSIS *msis = new MSIS();
    cout<<"Test1 for maximum Sum(33): "<<msis->findMSIS(nums)<<endl;
    cout<<"Test2 for maximum Sum(25): "<<msis->findMSIS(nums2)<<endl;
    cout<<"Test3 for maximum Sum(82): "<<msis->findMSIS(nums3)<<endl;

    cout<<"\nFind minimum deletion to make a sequence ordered."<<endl;
    vector<int> nums4 = {3, 2, 1, 0};
    MDSS* mdss = new MDSS();
    cout<<"Test1(2): "<<mdss->findMinimumDeletions(nums)<<endl;
    cout<<"Test2(1): "<<mdss->findMinimumDeletions(nums2)<<endl;
    cout<<"Test3(3): "<<mdss->findMinimumDeletions(nums4)<<endl;


    delete lis;
    delete msis;
    delete mdss;
    return 0;
}
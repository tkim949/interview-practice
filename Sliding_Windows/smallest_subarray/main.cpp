#include <iostream>
#include <climits>
#include <vector>

using namespace std;


class MinSubArray {

public:
    static int findMinSubArray(int sum, const vector<int> & arr) {

        int crtSum =0;
        int minLength = INT_MAX;
        int start =0;

        for(int end =0; end < arr.size(); end++) {
            crtSum += arr[end];

            while(crtSum >= sum) {
                minLength = min(minLength, end-start+1);
                crtSum -= arr[start];
                start++;
            }
        }

        return minLength == INT_MAX ? 0: minLength;
    }

};






int main() {
    std::cout << "The Smallest contiguous Subarray whose sum is greater than or equal to the given sum." << std::endl;
     //easy one!
    MinSubArray msa;

    int result = msa.findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2});
    cout<<"Test1 (should be 2): "<<result<<endl;

    int result2 = msa.findMinSubArray(7, vector<int>{2, 1, 5, 2, 8});
    cout<<"Test2 (should be 1): "<<result2<<endl;

    int result3 = msa.findMinSubArray(8, vector<int>{3, 4, 1, 1, 6});
    cout<<"Test3 (should be 3): "<<result3<<endl;

    return 0;
}
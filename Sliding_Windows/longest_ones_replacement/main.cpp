#include <iostream>
#include <vector>

using namespace std;

class ReplaceOnes {

public:
    static int findLength(const vector<int>& arr, int k) {

        int start =0;
        int maxLength =0;
        int maxOneCnt =0;

        for(int end =0; end <arr.size(); end++) {

            if(arr[end] ==1) {
                maxOneCnt++;
            }
            while(end-start+1 - maxOneCnt > k) {
            //if(end-start+1 - maxOneCnt > k) {
                if(arr[start] == 1) {
                    maxOneCnt--;
                }
                start++;
            }

            maxLength = max(maxLength, end-start+1);

        }
        return maxLength;
    }

};

int main() {
    std::cout<<"Find the length of longest contiguous subarray having all 1's after k time of replacement!"  << std::endl;
    ReplaceOnes ro;
    cout<<"Test1 (6): "<<ro.findLength(vector<int>{0,1,1,0,0,0,1,1,0,1,1}, 2)<<endl;
    cout<<"Test2 (9): "<<ro.findLength(vector<int>{0,1,0,0,1,1,0,1,1,0,0,1,1}, 3)<<endl;
    return 0;
}
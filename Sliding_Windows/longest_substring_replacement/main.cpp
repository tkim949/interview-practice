#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class CharReplacement {

public:
    static int findLength(const string &str, int k) {
        int start =0;
        int maxLength =0;
        int maxRepeatCnt =0;

        unordered_map<char, int> chFrequencyMap;

        for(int end =0; end<str.size(); end++) {
            char right = str[end];
            chFrequencyMap[right]++;
            maxRepeatCnt = max(maxRepeatCnt, chFrequencyMap[right]); //in order to be longest, the letter should repeat!

            while(end-start+1 - maxRepeatCnt > k) {
            //if(end-start+1 - maxRepeatCnt > k) { //this should be the number that can be changed with other letter
                char left = str[start];
                chFrequencyMap[left]--;
                start++;

            }

            maxLength = max(maxLength, end-start+1);

        }
        return maxLength;
    }

};





int main() {
    std::cout << "Find the length of the longest substring having the same letters after given time of replacement!" << std::endl;
    CharReplacement chR;

    cout<<"Test1(5): "<<chR.findLength("aabccbb", 2) <<endl;
    cout<<"Test2(4): "<<chR.findLength("abbcb", 1) <<endl;
    cout<<"Test3(3): "<<chR.findLength("abccde", 1) <<endl;
    cout<<"Test4(5): "<<chR.findLength("aabcabe", 2) <<endl;





    return 0;
}
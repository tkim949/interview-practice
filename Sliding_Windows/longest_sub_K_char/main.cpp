#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class LongestSubstringKDistinct {

public:
    static int findLength(const string &str, int k) {
        int start = 0;
        int maxLength = 0;
        unordered_map<char, int> chFrequencyMap;

        for(int end =0; end <str.length(); end++) {
            char right = str[end];
            chFrequencyMap[right]++;

            while(chFrequencyMap.size() > k) {
                char left = str[start];
                chFrequencyMap[left]--;
                if(chFrequencyMap[left] == 0) {
                    chFrequencyMap.erase(left);
                }
                start++;
            }

            maxLength = max(maxLength, end-start+1);
        }

        return maxLength;
    }

};

class MaxFruitCount2Types {

public:
    static int findLength(const vector<char>& arr) {

        int start = 0;
        int maxLength =0;
        unordered_map<char, int> fruitFrequencyMap;

        for(int end = 0; end<arr.size(); end++ ) {
            fruitFrequencyMap[arr[end]]++;


            while (fruitFrequencyMap.size() > 2) {
                fruitFrequencyMap[arr[start]]--;
                if (fruitFrequencyMap[arr[start]] == 0) {
                    fruitFrequencyMap.erase(arr[start]);
                }
                start++;
            }
            maxLength = max(maxLength, end-start+1);
        }
        return maxLength;
    }
};




int main() {
    std::cout << "Find the length of the longest substring in it with no more than K distinct characters." << std::endl;
    LongestSubstringKDistinct subK;

    cout<<"Test1: (should be 4): "<<subK.findLength("araaci", 2)<<endl;
    cout<<"Test2: (should be 2): "<<subK.findLength("araaci", 1)<<endl;
    cout<<"Test3: (should be 5): "<<subK.findLength("cbbebi", 3)<<endl;

    cout<<"Maximum number of fruit in each basket that can have only one type of fruit with two basket."<<endl;
    MaxFruitCount2Types fruit;
    cout<<"Test1 for fruit basket(3): "<<fruit.findLength(vector<char>{'A','B','C','A','C'})<<endl;
    cout<<"Test2 for fruit basket(5): "<<fruit.findLength(vector<char>{'A','B','C','B', 'B','C'})<<endl;
    return 0;
}
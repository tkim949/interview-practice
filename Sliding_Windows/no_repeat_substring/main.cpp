#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class NoRepeatSubstring {
public:
    static int findLength(const string & str) {

        int start=0;
        int maxLength =0;
        unordered_map<char, int> chIdxMap;

        for(int end =0; end <str.size(); end++) {

            char right = str[end];

            if(chIdxMap.find(right) != chIdxMap.end()) {
                start = max(start, chIdxMap[right] +1);
            }
            chIdxMap[right] = end; //key == character of current, value = index num

            maxLength = max(maxLength, end-start+1);

        }
        return maxLength;

    }

};


int main() {
    std::cout << "Find the length of the longest substring!" << std::endl;
    NoRepeatSubstring nr;
    cout<<"Test1-(should be 3): "<<nr.findLength("aabccbb")<<endl;
    cout<<"Test2-(should be 2): "<<nr.findLength("abbbb")<<endl;
    cout<<"Test3-(should be 3): "<<nr.findLength("abccde")<<endl;

    return 0;
}
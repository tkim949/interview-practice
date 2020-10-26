#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

//1. set variable -- in order to check char, it need start and end, or left and right!
//2. we need to check the case when the str starts with vowels and ends with vowels with while loop
//3. now we know the start point and end point, which is not vowel
//4. check through using for loop from start+1 to end, so if it is vowel increment the num of current and check if it is max
//5. otherwise, just the current vowel str num is 0
//6. now we have the max vowel num and beginning part/start vowel num and the last part vowel num
//7. add them and return

//helper function which checks if char is vowel or not
bool is_vowel(char c) {
    unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
    return vowels.find(c) != vowels.end(); //if it is vowel return true!
}


int longest_vowel_string(string str) {
    //set variables
    int start = 0;
    int end = str.size() - 1;
    //check if there is any vowels in the beginning
    while (is_vowel(str[start]))
        start++;
    //check if there is any vowels at the ending
    while (is_vowel(str[end]))
        end--;

    //set max-vowel num and temp one
    int max_vowel_substr_len = 0;
    int cur_vowel_substr_len = 0;

    //use for loop for whole str, first check if it's vowel and if it is add it, otherwise, just set temp vowel num is 0
    for (int i = start+1; i < end; i++) {
        if (is_vowel(str[i])) {
            cur_vowel_substr_len++;
            max_vowel_substr_len = max(max_vowel_substr_len, cur_vowel_substr_len);
        }
        else
            cur_vowel_substr_len = 0;
    }
    return max_vowel_substr_len + start + (str.size() - 1 - end);
}


int main() {
    cout << longest_vowel_string("earthproblem") << endl;  // 3
    cout << longest_vowel_string("letsgosomewhere") << endl;  // 2
}
# include <string>
# include <iostream>
# include <unordered_map>
# include <vector>
# include <map>
# include <set>
using namespace std;

// Uses a hash map to get determine distinct chars
// Runtime: O(n^
/*
 * https://leetcode.com/discuss/interview-question/370157
 * Input: s = "pqpqs", k = 2
   Output: 7
   Explanation: ["pq", "pqp", "pqpq", "qp", "qpq", "pq", "qs"]
 */

// the number of subarrays with at most K distinct elements
int most_k_chars(string &s, int k) {
    if (s.size() == 0) {
        return 0;
    }
    unordered_map<char, int> table;

    int num = 0, left = 0;

    for (int i = 0; i < s.size(); i++) {
        table[s[i]]++;
        while (table.size() > k) {
            table[s[left]]--;
            if (table[s[left]] == 0) {
                table.erase(s[left]);
            }
            left++;
        }
        num += i - left + 1;
    }
    return num;
}

int exact_k_chars(string &s, int k) {
    return most_k_chars(s, k) - most_k_chars(s, k - 1);
}
//not good solution!!!!
int not_unique_chars(string s,int K){

    int res=0;

    for(int i=0; i<s.size();i++){
        int end=i;

        string substr="";

        map<char,int> keys;  //map doesn't allow duplicate keys!
        //set<char> chaKey;

        while(end<s.size()){
            substr+= s[end];
            keys[s[end]]++;
           // chaKey.insert(s[end]);

           // if(chaKey.size()>K){
            if(keys.size()>K){
                break;
            }
           // if(substr.size()>1 && chaKey.size()==K){
            if(substr.size()>1 && keys.size()==K){
                res++;
            }

            end++;
        }
    }

    return res;
}
//from geeksforgeeks this is the one ****** O(n^2)
int countKDist(string s, int K) {
     //set variables size and return
    int n = s.size();

    int result =0;

   // int charSet[26] = {0};
   // vector<int> charSet(26, 0);
    // outside for loop
    for(int i =0; i <n; i++) {
        //we need count of distinct character and array of char, with 0 value for all element.
        int distCharNum = 0;

        vector<int> charSet(26, 0);
       // memset(charSet, 0, sizeof(charSet));
       //inner loop, check distinct char count, update char array value for each char,
        for(int j=i; j<n; j++) {
            if(charSet[s[j] - 'a'] == 0) {
                distCharNum++;
            }

            charSet[s[j] - 'a']++;
          //
            if(distCharNum ==K)
                result++;
            if(distCharNum > K)
                break;
        }
    }

    return result;

}

int main() {
    string s1 = "pqpqs";
    cout << "Answer should be 7: " << exact_k_chars(s1, 2) << endl;
    cout << "Answer should be 7: " << not_unique_chars(s1, 2) << endl;
    cout << "Answer should be 7: " << countKDist(s1, 2) << endl;
    string s2 = "abcabc";
    cout << "Answer should be 10: " << exact_k_chars(s2, 3) << endl;
    cout << "Answer should be 10: " << not_unique_chars(s2, 3) << endl;
    cout << "Answer should be 10: " << countKDist(s2, 3) << endl;
    string s3 = "aababcghert";
    cout << "Answer should be ??: " << exact_k_chars(s3, 3) << endl;
    cout << "Answer should be ??: " << not_unique_chars(s3, 3) << endl;
    cout << "Answer should be ??: " << countKDist(s3, 3) << endl;
    string s4 = "aabab";
    cout << "Answer should be 0: " << exact_k_chars(s4, 3) << endl;
    cout << "Answer should be 0: " << not_unique_chars(s4, 3) << endl;
    cout << "Answer should be 0: " << countKDist(s4, 3) << endl;
}
/*
 int exact_k_chars(string &str, int k) {
    if (str.size() == 0) {
        return 0;
    }
    //subStringCount counts substrings with K distinct char
   // int substringCount = 0;
    //keeps track of the different combinations
    vector<string> substringList;
    unordered_map<char, int> distinct;
    //checks first to see if there are enough distinct chars to have substrings with K distinct chars
   // for (int i = 0; i < str.size(); i++) {
    //    distinct[str[i]]++;
   // }

    //This assumes that the condition of # of distinct chars > k
    if (distinct.size() >= k) {
       // distinct.clear();

        for (int i = 0; i < str.size(); i++) {
            string testStr = "";
            distinct[str[i]]++;
            testStr += str[i];
            //cout << "\n(I loop) size of hash map: " << distinct.size() << endl;

           // bool breakLoop = false;
            for (int j = i + 1; j < str.size() ; j++) { //&& breakLoop == false
                distinct[str[j]]++;
                //cout << "\n(J loop) size of hash map: " << distinct.size() << endl;
                testStr += str[j];
                if (distinct.size() > k) {
                   // breakLoop = true;
                   break;
                }
                else if (distinct.size() == k) {
                    substringList.push_back(testStr);
                   // substringCount++;
                    //cout << "\nSubstring Count: " << substringCount << endl;
                }
            }
            distinct.clear();
        }
    }

     This code prints out the combinations
    for (int counter = 0; counter < substringList.size(); counter++) {
        cout << "\nSubstring List: " << substringList[counter] << endl;
    }

//return (substringCount);
return substringList.size();
}
 *
 *
 int exact_k_chars2(string &str, int k) {
    if (str.size() == 0) {
        return 0;
    }
    vector<string> substringList;
    unordered_map<char, int> distinct;

    //This assumes that the condition of # of distinct chars > k
    //How can it is bigger than k?
    if (distinct.size() >= k) {

        for (int i = 0; i < str.size(); i++) {
            string testStr = "";
            distinct[str[i]]++;
            testStr += str[i];

            for (int j = i + 1; j < str.size() ; j++) {
                distinct[str[j]]++;
                testStr += str[j];

                if (distinct.size() > k) {
                   break;
                }
                else if (distinct.size() == k) {
                    substringList.push_back(testStr);
                }
            }
            distinct.clear();
        }
    }
    return substringList.size();
}

 */
#include <iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<cctype> //isdigit or isalpha
using namespace std;

//reverse given string in place!
class StringReversal {
public:
    string reverse(string str) {
        if(str.empty() || str == "") return str;

        int i = 0, j = str.length()-1;
        while(i<j) {
            swap(str[i], str[j]);
            i++;
            j--;
        }

        return str;
    }

};

//print duplicate character from a string!
class RepeatCharacter {
public:
    void repeat(string str) {

        unordered_map<char, int> table;

        for(char ch: str) {
            if(table.find(ch) != table.end()) {
                table[ch]++;
            }else {
                table[ch] =1;
            }
        }

        for(auto el: table) {
            if(el.second > 1) {
                cout<<"character: "<<el.first<<", count: "<<el.second<<endl;
            }
        }

    }
};

//if two string are anagram?
class AnagramCheck {
public:

    bool isAnagram(string str1, string str2) {

        unordered_map<char, int> table;

        int n = str1.size();
        int m = str2.size();
        if(n != m) return false;

        for(int i=0; i<n; i++) {
            table[str1[i]]++;
        }
        for(int j=0; j<m; j++) {
            table[str2[j]]--;
        }
        for(auto e: table) {
            if(e.second !=0) return false;
        }
        return true;
    }
};

class StringPermutation {

public:

    vector<string> permute(string str) {

        vector<string> res;
        backtrack(res, str, 0);
        return res;
    }

    void backtrack(vector<string> &res, string & str, int idx) {
        if(idx == str.size()) {
            res.push_back(str);
            return;
        }

        for(int j=idx; j < str.size(); j++) {
            swap(str[idx], str[j]);
            backtrack(res, str, idx+1);
            swap(str[idx], str[j]); //for backtrack!

        }
    }
};
bool is_digits(string str) {
    return all_of(str.begin(), str.end(), ::isdigit);
}
bool is_alphas(string str) {
    return all_of(str.begin(), str.end(), ::isalpha);
}




int main() {

    StringReversal sr;
    cout<<"1. reverse string 'spring': " <<sr.reverse("spring")<<endl;

    RepeatCharacter rc;
    cout<<"2. Repeat Character: "<<endl;
    rc.repeat("Programming");

    AnagramCheck ac;
    cout<<"3. Anagram check: "<<ac.isAnagram("anagram", "nagaram")<<endl;

    StringPermutation sp;
    vector<string> res = sp.permute("spir");

    cout<<"4. String Permutation(spir): "<<endl;
    for(auto e: res) {
        cout<<e<<" ";
    }
    cout<<endl;


    cout<<"5. Check digit or not: "<<is_digits("12345")<<endl;
    cout<<"use just isdigit: "<<isdigit('1')<<endl; //isdigit or isalpha used for char! not string!

    cout<<"6. Check alphabet or not: "<<is_alphas("great")<<endl;
    cout<<"use just isalpha: "<<isalpha('g')<<endl; //isdigit or isalpha used for char! not string!



    string str ="aaacodesigcnl";
    unordered_map<char, vector<int>> table;

    int i = 0;
    int size = str.length();

    for(int j=0; j<size; j++) {
        //table[str[j]].push_back(j);
        char ch = str[j];
        if(table.find(ch) != table.end()) {
            table[ch].push_back(j);
        } else table[ch] = vector<int> {j};
    }

    string temp = str;
    cout<<"before while: "<<temp<<endl;
    int k = 0;
    while(i < temp.size()) {
        char ch = temp[0];
        int start, end;
        if(table.find(ch) != table.end() && (table[ch].size() > 1)) {
            start = table[ch][0];
            cout<<"start: "<<start<<endl;
            end = table[ch].back();
            cout<<"end: "<<end<<endl;
            temp = temp.erase(start, end-start+1);
            i = end+1;

        } else
          i++;
    }
    //string sst=str.substr(0, 0) + str.substr(3);
    cout<<temp<<endl;


    return 0;
}
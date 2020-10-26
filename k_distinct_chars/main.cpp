#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

//https://leetcode.com/discuss/interview-question/370112
vector<string> kDistinctSubString(string s, int K) {

    //1.set return and map for storing word with count!
    vector<string> result;
    map<string, int> table;


    //2. create for loop and set char array for checking character uniqueness
    for(int i=0; i< s.size(); i++) {

        int charSet[256] = {0};
        int pos =i;
        string tempstr = "";

        //3. create while loop inside the for loop, which separate a unique word
        while(tempstr.size() <K && pos <s.size()) {
            int chaVal = int(s[pos]);

            if(charSet[chaVal] != 0) break; //check if it is disdicnt

            tempstr += s[pos];
            pos++;
            charSet[chaVal]++;
        }

        //4. after separating the substring, if it is not in the table, store it into return result.
        //5. store into map or update its size
        if(table.find(tempstr) == table.end() && tempstr.size() == K ) {
            result.push_back(tempstr);
        }
        table[tempstr]++;

    }
    //5. return
    return result;
}


vector<string> genKsubstr(string s,int K){
    //1. set return
    vector<string> res;
    map<string,int> table;

    for(int i=0;i<s.size();i++){

        int charset[256] = {0};
        int end = i;
        string substr = "";

        while(substr.size()<K && end<s.size()){
            int strVal = int(s[end]);

            if(charset[strVal]!=0){  //check if the character is distinct
                break;
            }
            substr+=s[end];
            end++;
            charset[strVal]++;
        }

       // auto val = words.find(substr);

        if((table.find(substr) == table.end()) && substr.size()==K){
            res.push_back(substr);
        }

        table[substr]++;
    }

    return res;
}

//this is not good for me!
vector <string> findSubstrings (string s, int K)
{
    if (K == 0)
        return {};

    unordered_map <char, int> counts;
    unordered_set <string> ret;

    for (int left = 0, right = 0; right < s.length (); right++)
    {
        counts [s [right]]++;

        if (right-left+1 < K)
            continue;
        if (right-left+1 > K)
        {
            //cout<<"1: "<<counts[s[left]]<<endl;
            //counts[s[left]]--;
            if (--counts [s [left]] == 0) //???? when there is two duplicate words, such as "aadra"
            {
               // cout<<"2: "<<counts[s[left]]<<endl;
                counts.erase (s [left]);
            }
           // cout<<"3: "<<counts[s[left]]<<endl;
            left++;
        }
        if (counts.size () == K)
            ret.insert (s.substr (left, right-left+1));
    }

    return vector <string> (ret.begin (), ret.end ());
}


int main()
{
    vector <string> ret;
    /*
    printf ("input1:\n");
    ret = findSubstrings ("abcabc", 3);
    for (auto r : ret)
        printf ("%s\n", r.c_str ());

    printf ("input1-2:\n");
    ret = genKsubstr ("abcabc", 3);
    for (auto r : ret)
        printf ("%s\n", r.c_str ());

    printf ("input2:\n");
    ret = findSubstrings ("abacab", 3);
    for (auto r : ret)
        printf ("%s\n", r.c_str ());

    printf ("input2-2:\n");
    ret = genKsubstr ("abacab", 3);
    for (auto r : ret)
        printf ("%s\n", r.c_str ());

    */
    printf ("input3:\n");
    ret = kDistinctSubString ("awaglknagawunagwkwagl", 4);
    for (auto r : ret)
        printf ("%s\n", r.c_str ());

    printf ("input3-2:\n");
    ret = genKsubstr ("awaglknagawunagwkwagl", 4);
    for (auto r : ret)
        printf ("%s\n", r.c_str ());


    return 0;
}


/*
    string subString = "";
    char c;
    int start;
    int end;

    while(end< s.size()) {
        c = s[end];

        //find duplicate
        if(counts.find(c) != counts.end()) {
            counts.erase(s[start]);
            start++;
            continue;
        }
        counts[c] = end;

        if(end-start+1 == K && counts.size() == K) {
            subString = s.substr(start, end-start+1);
            ret.insert(subString);
            counts.erase(s[start]);
            start++;
        }
        end++;
    }
}
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LCSubstring {

public:
    int findLCSLength(const string &s1, const string &s2) {

       vector<vector<int>> dp(s1.length() +1, vector<int>(s2.length() +1, 0));

       int maxLength = 0;

       for(int i =1; i <= s1.length(); i++) {
           for(int j=1; j<= s2.length(); j++) {
               if(s1[i-1] == s2[j-1]) {
                   dp[i][j] = 1+ dp[i-1][j-1];
                   maxLength = max(maxLength, dp[i][j]);
               }
           }
       }

      return maxLength;

    }

};

class LCSubsequence {


public:
    int findLCSLength(const string &s1, const string &s2) {

        vector<vector<int>> dp(s1.length() +1, vector<int>(s2.length()+1, 0));

        int maxLength =0;

        for(int i=1; i <= s1.length(); i++) {
            for(int j=1; j <= s2.length(); j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }

                maxLength = max(maxLength, dp[i][j]);
            }

        }
        return maxLength;
    }
};

class SCS {
// shortest common super sequence
public:
    int findSCSLength(const string &s1, const string &s2) {

        vector<vector<int>> dp(s1.length() +1, vector<int>(s2.length() +1));

        for(int i=0; i<=s1.length(); i++) {
            dp[i][0] =i;
        }
        for(int j=0; j<= s2.length(); j++) {
            dp[0][j] = j;
        }

        for(int i=1; i<= s1.length(); i++) {
            for(int j=1; j <= s2.length(); j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]); //???why???
                }
            }
        }

        return dp[s1.length()][s2.length()];
    }

};

class MDI {
// minimum deletion and insertion to transform
public:

    void findMDI(const string &s1, const string &s2) {
        int LCSLen = findLCSLength(s1, s2);

        cout<< "Minimum deletions needed: "<< (s1.length() - LCSLen) <<endl;
        cout<< "Minimum insertions needed: "<< (s2.length() - LCSLen) <<endl;
    }

private:
    int findLCSLength(const string &s1, const string &s2) {

        vector<vector<int>> dp(s1.length() +1, vector<int>(s2.length() +1, 0));
        int maxLength =0;

        for(int i=1; i<= s1.length(); i++) {
            for(int j=1; j<= s2.length(); j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1+ dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }

                maxLength = max(maxLength, dp[i][j]);
            }
        }
       return maxLength;

    }

};


int main() {
    std::cout << "Find longest common Substring Length!" << std::endl;
    LCSubstring str;

    cout<<"Test1: Find max substring length(2): "<<str.findLCSLength("abdca", "cbda") <<endl;
    cout<<"Test2: Find max substring length(3): "<<str.findLCSLength("passport", "ppsspt") <<endl;


    std::cout << "\nFind longest common Substring Length!" << std::endl;
    LCSubsequence seq;

    cout<<"Test1: Find max substring length(3): "<<seq.findLCSLength("abdca", "cbda") <<endl;
    cout<<"Test2: Find max substring length(5): "<<seq.findLCSLength("passport", "ppsspt") <<endl;

    cout<<"\nFind minimum deletion and insertion to transform the first string into the second string"<<endl;
    MDI *mdi = new MDI();
    cout<<"Test1: (1, 1)"<<endl;
    mdi->findMDI("abc", "fbc");
    cout<<"Test2: (2, 1)"<<endl;
    mdi->findMDI("abdca", "cbda");
    cout<<"Test3: (3, 1)"<<endl;
    mdi->findMDI("passport", "ppsspt");

    cout<<"\nFind shortest common super sequence of two strings."<<endl;
    SCS *scs = new SCS();
    cout<<"Test1 for SCS(5): "<<scs->findSCSLength("abcf", "bdcf")<<endl;
    cout<<"Test2 for SCS(15): "<<scs->findSCSLength("dynamic", "programming")<<endl;



    delete mdi;
    delete scs;
    return 0;
}
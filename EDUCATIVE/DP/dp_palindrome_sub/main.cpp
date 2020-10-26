
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LPS {

public:
  int findLPSLength(const string &st) {
    vector<vector<int>> dp(st.length(), vector<int>(st.length(), 0));
    // every sequence with one element is a palindrome of length 1
    for (int i = 0; i < st.length(); i++) {
      dp[i][i] = 1;
    }

    for (int startIndex = st.length() - 1; startIndex >= 0; startIndex--) {
      for (int endIndex = startIndex + 1; endIndex < st.length(); endIndex++) {
        // case 1: elements at the beginning and the end are the same
        if (st[startIndex] == st[endIndex]) {
          dp[startIndex][endIndex] = 2 + dp[startIndex + 1][endIndex - 1];
        } else { // case 2: skip one element either from the beginning or the end
          dp[startIndex][endIndex] =
              max(dp[startIndex + 1][endIndex], dp[startIndex][endIndex - 1]);
        }
      }
    }
    return dp[0][st.length() - 1];
  }

    int findTopDown(const string &st) {
        vector<vector<int>> dp(st.length(), vector<int>(st.length(), -1));
        return findLPSLengthRecursive(dp, st, 0, st.length() - 1);
    }

private:
    int findLPSLengthRecursive(vector<vector<int>> &dp, const string &st, int startIndex,
                               int endIndex) {
        if (startIndex > endIndex) {
            return 0;
        }

        // every sequence with one element is a palindrome of length 1
        if (startIndex == endIndex) {
            return 1;
        }

        if (dp[startIndex][endIndex] == -1) {
            // case 1: elements at the beginning and the end are the same
            if (st[startIndex] == st[endIndex]) {
                dp[startIndex][endIndex] = 2 + findLPSLengthRecursive(dp, st, startIndex + 1, endIndex - 1);
            } else {
                // case 2: skip one element either from the beginning or the end
                int c1 = findLPSLengthRecursive(dp, st, startIndex + 1, endIndex);
                int c2 = findLPSLengthRecursive(dp, st, startIndex, endIndex - 1);
                dp[startIndex][endIndex] = max(c1, c2);
            }
        }

        return dp[startIndex][endIndex];
    }
};

class LPString {

public:
    int findLPSLength(const string &st) {
        // dp[i][j] will be 'true' if the string from index 'i' to index 'j' is a palindrome
        vector<vector<bool>> dp(st.length(), vector<bool>(st.length()));

        // every string with one character is a palindrome
        for (int i = 0; i < st.length(); i++) {
            dp[i][i] = true;
        }

        int maxLength = 1;
        for (int startIndex = st.length() - 1; startIndex >= 0; startIndex--) {
            for (int endIndex = startIndex + 1; endIndex < st.length(); endIndex++) {
                if (st[startIndex] == st[endIndex]) {
                    // if it's a two character string or if the remaining string is a palindrome too
                    if (endIndex - startIndex == 1 || dp[startIndex + 1][endIndex - 1]) {
                        dp[startIndex][endIndex] = true;
                        maxLength = max(maxLength, endIndex - startIndex + 1);
                    }
                }
            }
        }

        return maxLength;
    }

    int findTopDown(const string &st) {
        vector<vector<int>> dp(st.length(), vector<int>(st.length(), -1));
        return findLPSLengthRecursive(dp, st, 0, st.length() - 1);
    }

private:
    int findLPSLengthRecursive(vector<vector<int>> &dp, const string &st, int startIndex, int endIndex) {

        if (startIndex > endIndex) {
            return 0;
        }

        // every string with one character is a palindrome
        if (startIndex == endIndex) {
            return 1;
        }

        if (dp[startIndex][endIndex] == -1) {
            int c1 = 0;
            // case 1: elements at the beginning and the end are the same
            if (st[startIndex] == st[endIndex]) {
                int remainingLength = endIndex - startIndex - 1;
                // if the remaining string is a palindrome too
                if (remainingLength == findLPSLengthRecursive(dp, st, startIndex + 1, endIndex - 1)) {
                    c1 = remainingLength + 2;
                }
            }

            // case 2: skip one character either from the beginning or the end
            int c2 = findLPSLengthRecursive(dp, st, startIndex + 1, endIndex);
            int c3 = findLPSLengthRecursive(dp, st, startIndex, endIndex - 1);
            dp[startIndex][endIndex] = max(c1, max(c2, c3));
        }

        return dp[startIndex][endIndex];
    }

};

class CPS {
public:
    int findCPS(const string &st) {
        // dp[i][j] will be 'true' if the string from index 'i' to index 'j' is a palindrome
        vector<vector<bool>> dp(st.length(), vector<bool>(st.length()));
        int count = 0;

        // every string with one character is a palindrome
        for (int i = 0; i < st.length(); i++) {
            dp[i][i] = true;
            count++;
        }

        for (int startIndex = st.length() - 1; startIndex >= 0; startIndex--) {
            for (int endIndex = startIndex + 1; endIndex < st.length(); endIndex++) {
                if (st[startIndex] == st[endIndex]) {
                    // if it's a two character string or if the remaining string is a palindrome too
                    if (endIndex - startIndex == 1 || dp[startIndex + 1][endIndex - 1]) {
                        dp[startIndex][endIndex] = true;
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

class MDSP {

public:
    int findMinimumDeletions(const string &st) {
        // subtracting the length of Longest Palindromic Subsequence from the length of
        // the input string to get minimum number of deletions
        return st.length() - findLPSLength(st);
    }

    int findLPSLength(const string &st) {
        // dp[i][j] stores the length of LPS from index 'i' to index 'j'
        vector<vector<int>> dp(st.length(), vector<int>(st.length()));

        // every sequence with one element is a palindrome of length 1
        for (int i = 0; i < st.length(); i++) {
            dp[i][i] = 1;
        }

        for (int startIndex = st.length() - 1; startIndex >= 0; startIndex--) {
            for (int endIndex = startIndex + 1; endIndex < st.length(); endIndex++) {
                // case 1: elements at the beginning and the end are the same
                if (st[startIndex] == st[endIndex]) {
                    dp[startIndex][endIndex] = 2 + dp[startIndex + 1][endIndex - 1];
                } else { // case 2: skip one element either from the beginning or the end
                    dp[startIndex][endIndex] =
                            max(dp[startIndex + 1][endIndex], dp[startIndex][endIndex - 1]);
                }
            }
        }
        return dp[0][st.length() - 1];
    }
};


class MPP {

public:
    int findMPPCuts(const string &st) {
        // isPalindrome[i][j] will be 'true' if the string from index 'i' to index 'j' is a palindrome
        vector<vector<bool>> isPalindrome(st.length(), vector<bool>(st.length(), false));

        // every string with one character is a palindrome
        for (int i = 0; i < st.length(); i++) {
            isPalindrome[i][i] = true;
        }

        // populate isPalindrome table
        for (int startIndex = st.length() - 1; startIndex >= 0; startIndex--) {
            for (int endIndex = startIndex + 1; endIndex < st.length(); endIndex++) {
                if (st[startIndex] == st[endIndex]) {
                    // if it's a two character string or if the remaining string is a palindrome too
                    if (endIndex - startIndex == 1 || isPalindrome[startIndex + 1][endIndex - 1]) {
                        isPalindrome[startIndex][endIndex] = true;
                    }
                }
            }
        }

        // now lets populate the second table, every index in 'cuts' stores the minimum cuts needed
        // for the substring from that index till the end
        vector<int> cuts(st.length(), 0);
        for (int startIndex = st.length() - 1; startIndex >= 0; startIndex--) {
            int minCuts = st.length(); // maximum cuts
            for (int endIndex = st.length() - 1; endIndex >= startIndex; endIndex--) {
                if (isPalindrome[startIndex][endIndex]) {
                    // we can cut here as we got a palindrome
                    // also we dont need any cut if the whole substring is a palindrome
                    minCuts = (endIndex == st.length() - 1) ? 0 : min(minCuts, 1 + cuts[endIndex + 1]);
                }
            }
            cuts[startIndex] = minCuts;
        }
        return cuts[0];
    }
};

int main(int argc, char *argv[]) {
  LPS *lps = new LPS();
  cout<<"Longest Palindromic Sub-sequence Bottom-up solution."<<endl;
  cout <<"Test1(5): "<< lps->findLPSLength("abdbca") << endl;
  cout <<"Test2(3): "<< lps->findLPSLength("cddpd") << endl;
  cout <<"Test3(1): "<< lps->findLPSLength("pqr") << endl;

    cout<<"\nLongest Palindromic Sub-sequence TopDwon solution."<<endl;
    cout <<"Test1(5): "<< lps->findTopDown("abdbca") << endl;
    cout <<"Test2(3): "<< lps->findTopDown("cddpd") << endl;
    cout <<"Test3(1): "<< lps->findTopDown("pqr") << endl;

    LPString *lpst = new LPString();
    cout<<"\nLongest Palindromic Sub-string Bottom-up solution."<<endl;
    cout <<"Test1(3): "<<lpst->findLPSLength("abdbca") << endl;
    cout <<"Test2(3): "<< lpst->findLPSLength("cdpdd") << endl;
    cout <<"Test3(1): "<< lpst->findLPSLength("pqr") << endl;
    cout <<"Test4(5): "<< lpst->findLPSLength("madam") << endl;

    cout<<"\nLongest Palindromic Sub-string Top Down solution."<<endl;
    cout <<"Test1(3): "<<lpst->findTopDown("abdbca") << endl;
    cout <<"Test2(3): "<< lpst->findTopDown("cdpdd") << endl;
    cout <<"Test3(1): "<< lpst->findTopDown("pqr") << endl;
    cout <<"Test4(5): "<< lpst->findTopDown("madam") << endl;

    CPS *cps = new CPS();
    cout<<"\nCount of palindromic substrings"<<endl;
    cout <<"Test1(7): "<< cps->findCPS("abdbca") << endl;
    cout <<"Test2(7): "<< cps->findCPS("cdpdd") << endl;
    cout <<"Test3(3): "<<cps->findCPS("pqr") << endl;

    cout<<"\nMinimum deletion in a string to make it a Palindrome."<<endl;
    MDSP *mdsp = new MDSP();
    cout <<"Test1(1): "<< mdsp->findMinimumDeletions("abdbca") << endl;
    cout <<"Test2(2): "<< mdsp->findMinimumDeletions("cddpd") << endl;
    cout <<"Test3(2): "<< mdsp->findMinimumDeletions("pqr") << endl;

    cout<<"\nMinimum number of cuts to make each piece panlindrome."<<endl;
    MPP *mpp = new MPP();
    cout <<"Test1(3): "<<mpp->findMPPCuts("abdbca") << endl;
    cout <<"Test2(2): "<< mpp->findMPPCuts("cdpdd") << endl;
    cout <<"Test3(2): "<< mpp->findMPPCuts("pqr") << endl;
    cout <<"Test4(2): "<< mpp->findMPPCuts("pqr") << endl;
    cout <<"Test5(0): "<< mpp->findMPPCuts("pp") << endl;
    cout <<"Test6(0): "<< mpp->findMPPCuts("madam") << endl;

    delete mpp;

    delete mdsp;

    delete cps;

    delete lps;

    delete lpst;
}
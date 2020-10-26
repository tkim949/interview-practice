#include <iostream>
#include <vector>
#include <set>
#include <cstdlib> //atoi
#include <cstring>

using namespace std;

set<int> primeList; // this is the prime number list

bool checkPrime(int n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 ==0) return false;
    for(int i =3; i <= n/2; i += 2) {
        if(n % i == 0)
            return false;
    }
    return true;

}

bool isPrimeN (int n, int i) {

    if(n < 2) return false;
    if(i == 1) return true;

    if(n%i == 0) return false;
    else return isPrimeN(n, i-1);


}

bool isPrimeNum(int num) {
    if(primeList.find(num) != primeList.end()) {
        return true;
    }

    //bool isPrime = checkPrime(num);
    bool isPrime = isPrimeN(num, num/2);
    if(isPrime) primeList.insert(num);
    return isPrime;
}
//if the question asks only counting
int dpFind(string &str) {

    int n = str.size();
    vector<int> dp(n+1, 0);
    dp[0]=1;

    const int mod = 1000000007;

    for(int i=1; i <=n; i++) {
        if(str[i-1] != '0') {
            int num = atoi(str.substr(i - 1, 1).c_str());
            if (isPrimeNum(num)){
                dp[i] += dp[i - 1];
            }
        }
        if(i-2 >= 0 && str[i-2] != '0') {
            int num2 = atoi(str.substr(i - 2, 2).c_str());
            if (isPrimeNum(num2)){
                dp[i] += (dp[i - 2] % mod);
                //dp[i] += dp[i - 2];
            }
        }
        if(i-3 >= 0 && str[i-3] != '0') {
            int num3 = atoi(str.substr(i - 3, 3).c_str());
            if (isPrimeNum(num3)){
                dp[i] += (dp[i - 3] % mod);
                //dp[i] += dp[i - 3];
            }
        }
    }

    return dp[n];
}

//if the question asks the whole set of answers!
void findAllSets(string str, vector<int> & tempRet, vector<vector<int>>& ways) {

    //cout<<"inside findPermutations:  "<<str<<endl;
    if(str.length() ==0) {
        ways.push_back(tempRet);
        return;
    }

    for (int i=0; i < str.length(); i++) {
        string strNum = str.substr(0, i+1);

        int num = atoi(strNum.c_str()); //atoi expect const char*, so use c_str()
        //cout<<"numbers after atoi: "<<num<<endl;
        bool checkNum = isPrimeNum(num);

        if(checkNum) {
            tempRet.push_back(num);
            findAllSets(str.substr(i+1), tempRet, ways);
            tempRet.pop_back(); //for backtracking!
            //tempRet.clear(); //for the new tempRet!
        }

    }

}

vector<vector<int>> findNumOfWays(string s) {
    //cout<<"inside findNumOfways:  "<<s<<endl;
    vector<vector<int>> ways;
    vector<int> innerResult;
    findAllSets(s, innerResult, ways);

    return ways;
}

void print(vector<vector<int>> res) {
    for(auto ele: res) {

        for(auto e: ele) {
            cout<<e<<" ";
        }
        cout<<endl;
    }

}


int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<vector<int>> result;
    string st = "3175";
    result = findNumOfWays(st);
    print(result);

    cout<<endl;

    /*
    vector<vector<int>> res2 = findNumOfWays("11373");
    print(res2);
     */


    int ret = dpFind(st);
    cout<<"The number of ways: "<<ret<<endl;
    return 0;
}
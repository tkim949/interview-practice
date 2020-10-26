#include <iostream>
#include <vector>

using namespace std;

class HouseTheif {

public:
    int findMaxSteal(const vector<int> &house) {
        return findMaxStealRecursive(house, 0);
    }

private:
    int findMaxStealRecursive(const vector<int> &house, int crtIdx) {

        if(crtIdx >= house.size()) return 0;

        int stealCrt = house[crtIdx] +findMaxStealRecursive(house, crtIdx +2);//skip the next house

        int skipCrt = findMaxStealRecursive(house, crtIdx+1);

        return max(stealCrt, skipCrt);
    }

};
/* O(n) time complexity */
class TopDownHouseTheif {
public:
    int findMaxSteal(const vector<int> &house) {
        vector<int> dp(house.size(), 0);
        return findMaxStealRecursive(dp, house, 0);
    }

private:
    int findMaxStealRecursive(vector<int> &dp, const vector<int> &house, int crtIdx) {

        if(crtIdx >= house.size()) return 0;

        if(dp[crtIdx] == 0) {
            int stealCrt = house[crtIdx] + findMaxStealRecursive(dp, house, crtIdx + 2);//skip the next house

            int skipCrt = findMaxStealRecursive(dp, house, crtIdx + 1);

            dp[crtIdx] =  max(stealCrt, skipCrt);

        }

        return dp[crtIdx];
    }

};

class BottomUpHouseThief {

public:
    int findMaxSteal(const vector<int> &house) {
        if(house.empty()) return 0;

        vector<int> dp(house.size() +1); // '+1' to handle the zero house
        dp[0] =0;
        dp[1] = house[0];

        for(int i=2; i<dp.size(); i++) {
            dp[i] = max(house[i-1] +dp[i-2], dp[i-1]); //??????
        }


       return dp[house.size()];
    }


};

class OptimizeHouseThief {
public:

    int findMaxSteal(const vector<int> &house) {

        if(house.empty()) return 0;

        int n1 =0, n2 = house[0], temp;

        for(int i=1; i<house.size(); i++) {
            temp = max(n1 + house[i], n2);
            n1 = n2;
            n2 = temp;
        }

        return n2;
    }
};

int main() {
    std::cout << "DP_Programming House Thief - no adjacent house!" << std::endl;
    HouseTheif ht;
    vector<int> house1 = {2, 5, 1, 3, 6, 2, 4};
    vector<int> house2 = {2, 10, 14, 8, 1};
    cout<<"Test1-BF House Thief: "<<ht.findMaxSteal(house1)<<endl;
    cout<<"Test2-BF House Thief: "<<ht.findMaxSteal(house2)<<endl;

    TopDownHouseTheif td;
    cout<<"\nTest1-TopDown House Thief: "<<td.findMaxSteal(house1)<<endl;
    cout<<"Test2-TopDown House Thief: "<<td.findMaxSteal(house2)<<endl;

    BottomUpHouseThief bu;
    cout<<"\nTest1-BottomUpHouse Thief: "<<bu.findMaxSteal(house1)<<endl;
    cout<<"Test2-BottomUp House Thief: "<<bu.findMaxSteal(house2)<<endl;

   OptimizeHouseThief oh;
    cout<<"\nTest1-Optimize House Thief: "<<oh.findMaxSteal(house1)<<endl;
    cout<<"Test2-Optimize House Thief: "<<oh.findMaxSteal(house2)<<endl;
    return 0;
}
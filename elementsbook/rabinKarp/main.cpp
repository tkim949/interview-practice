#include <iostream>

using namespace std;

int RabinKarp(const string &t, const string &s) {

    if(s.size() > t.size()) return -1;

    const int kBase = 26;

    int t_hash =0, s_hash=0;
    int power_s= 1;

    for(int i=0; i<s.size()-1; i++) power_s *= kBase;

    for(int i =0; i<s.size(); i++) {
       // power_s = i ? power_s * kBase: 1; //????
        t_hash = t_hash *kBase + t[i];
        s_hash = s_hash *kBase + s[i];
       // cout<<"first for loop i: "<<i<<", power_s= "<<power_s<<endl;
    }

    cout<<"t_hash after first loop: "<<t_hash<<endl;
    cout<<"s_hash after first loop: "<<s_hash<<endl;
    cout<<"power_s after first loop: "<<power_s<<endl;

    for(int i= 0 ; i <= t.size() -s.size(); i++) {
        if(t_hash == s_hash && t.compare(i, s.size(), s) == 0) {
            return i;
        }

        t_hash -= t[i]*power_s;
        t_hash = t_hash*kBase + t[i+s.size()];

        cout<<"i: "<<i<<",  t_hash end of each iteration: "<<t_hash<<" power_s: "<<power_s<<endl;

    }
    return -1;
    /*

    for(int i=s.size() ; i <t.size(); i++) {
        if(t_hash == s_hash && !t.compare(i - s.size(), s.size(), s)) {
            return i - s.size();
        }

        t_hash -= t[i - s.size()]*power_s;
        t_hash = t_hash*kBase + t[i];

        cout<<"i: "<<i<<",  t_hash end of each iteration: "<<t_hash<<" power_s: "<<power_s<<endl;

    }

    if(t_hash == s_hash && t.compare(t.size()-s.size(), s.size(), s) == 0) {
        return t.size() -s.size();
    } */

}

int main() {
    std::cout << "Hello, World!" << std::endl;

    string t = "GACGCCA";
    string s = "CCA";

    cout<<RabinKarp(t, s);

    return 0;
}
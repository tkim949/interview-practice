#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MergeArray{

public:

    string mergeArr(string a, string b) {

        string result;

        int aIdx = 0;
        int bIdx =0;
        int k = a.size() + b.size();


        while(k > 0) {

            if( aIdx < a.size() && bIdx < b.size()) {
                if(a[aIdx] < b[bIdx]) {
                    result += a[aIdx++];
                }else{
                    result += b[bIdx++];
                }
            }
            else if(aIdx >= a.size() && bIdx < b.size()) {
                result += b[bIdx++];
            }
            else if(aIdx < a.size() && bIdx >= b.size()) {
                result += a[aIdx++];
            }
            k--;
        }

       return result;

    }
};

class ConcatSum {

public:
    long long concatnationSum(vector<int> a) {

        long long result =0;
       for(int i =0; i<a.size(); i++) {

           for(int j =0; j<a.size(); j++) {

               string a1 = to_string(a[i]);
               string b1 = to_string(a[j]);
               string re = a1 + b1;

               //cout<< "\na[i]: "<<a[i] <<"a[j]: "<<a[j] <<"string: "<<re<<endl;
               result += atoi(re.c_str());

              //cout<<"i: "<<i<<" j:"<<j<<" result: "<<result<<endl;

           }
       }


        return result;


    }



};

int main() {
    std::cout << "From Code Signal Practice: merge Array" << std::endl;
    MergeArray ma;

    cout<<"Test1: "<<ma.mergeArr("super", "tower")<<endl;

    ConcatSum cs;

    cout<<"Test concatenate sum: "<<cs.concatnationSum({10, 2});

    return 0;
}
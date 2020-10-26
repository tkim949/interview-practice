#include <iostream>
#include <vector>

using namespace std;

vector<int> decToBinary(int n) {


    vector<int> res;

   // int i = 0;
    while(n>0) {

        int bi = n%2;

       res.push_back(bi);

        n = n/2;
       // i++;
    }

    //reverse(res.begin(), res.end());
   return res;
}

int main() {
    std::cout << "Convert Decimal to Binary, and show it reversed!" << std::endl;

    int n;

    cout<<"Please input a num: ";
    cin>>n;

    cout<<"Binary number of "<<n<<endl;

    vector<int> res= decToBinary(n);

    for(int i=0; i<res.size(); i++) {
        cout<<res[i];
    }
    return 0;
}
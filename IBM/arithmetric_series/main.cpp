#include <iostream>

using namespace std;

int arithmeticSeries(int s, int d, int n) {
    int res = 0;

    for(int i=0; i<n; i++) {

        res +=s;
        s +=d;
    }

    return res;
}

int main() {
    std::cout << "Arithmetric Series!" << std::endl;

    int start, diff, size;
    cout<<"\nPlease enter three numbers: start, difference, size: ";
    cin>>start>>diff>>size;

    int res= arithmeticSeries(start, diff, size);

    cout<<"The result: "<<res<<endl;

    string revStr;

    while(res >0) {
        int temp = res%10;
        revStr += to_string(temp);
        res /=10;
    }

    cout<<"The reverse of the result: "<<revStr<<endl;
    return 0;
}
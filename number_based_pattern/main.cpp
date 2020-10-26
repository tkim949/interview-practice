#include <iostream>

using namespace std;

void basicSquareIncrementPattern(int n){

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {

            cout<<i+1;
        }
        cout<<endl;
    }
}

void internalVarsitySquarePattern(int n) {

    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            if(i == 0|| i == n-1 || j ==0 || j ==2){
                cout<<3;
            }
            else{
                cout<<i;
            }
        }
        cout<<endl;
    }
}

void rightTriangleNumPattern(int n) {
    int k =1;

    for(int i =0; i<n; i++) {
        for(int j=0; j<n;j++) {
            if(j <= i) {
                cout<<k;
                k++;
            }
        }
        cout<<endl;
    }
}

void invertedRightTrianglePattern(int n) {
    int k =10;

    for(int i =n-1; i >=0; i--) {
        for(int j=0; j<n; j++) {
            if(j<=i) {
                cout<<k;
                k--;
            }
        }
        cout<<endl;
    }
}

void doubleIncrementTrianglePattern(int n) {

    int k =1;
    int cnt;
    for(int i =0; i<n; i++) {

         if(i<n/2) {
           cnt = k+1;
           for(int j=0; j <=i; j++) {
               k++;
               cout<<k;

           }
         } else {

             k = cnt;
             for(int j=0; j<n-i; j++) {
                 cout<<k;
                 k++;
             }

             cnt = cnt -(n-i) +1;
         }
         cout<<endl;
    }

}

void invertedDoubleIncrement(int n){

    int k= 1;

    for(int i=0; i<n; i++) {

        if(i<n/2) {
            k +=(i+1);
            int cnt =k;
            for(int j=0; j<=i; j++) {
                cout<<cnt;
                cnt--;

            }

        } else {
            for(int j=0; j<n-i; j++) {
                cout<<k;
                k--;
            }
        }


     cout<<endl;
    }
}

int main() {
    std::cout << "Number Based patterns" << std::endl;
    string numst;
    int num;
    cout<< "Please input your number: ";
    getline(cin, numst);
    num = atoi(numst.c_str());
   // basicSquareIncrementPattern(num);
   // internalVarsitySquarePattern(num);
    //rightTriangleNumPattern(num);
    //invertedRightTrianglePattern(num);
    //doubleIncrementTrianglePattern(num);
    invertedDoubleIncrement(num);
    return 0;
}
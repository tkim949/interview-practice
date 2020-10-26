#include <iostream>
#include <string>

using namespace std;

void squareStarPattern(int n) {
    cout<<"1. Basic Square Star Pattern"<<endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<'*';

        }
        cout<<endl;
    }
}

void hollowSquareStarPattern(int n) {
    cout<<"2. Hollow Square Star Pattern"<<endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {

            if(i==0 || i == n-1|| j ==0 || j == n-1) {
                cout << '*';
            }
            else {

                    cout<<' ';

            }

        }
        cout<<endl;
    }
}

void rhombusStarPattern(int n) {

    cout<<"3. Rhombus Square Star Pattern"<<endl;

    for(int i=0; i<n; i++) {
        for(int j =0; j<n+i; j++) {
            if(j >= i) {
                cout << '*';
            }
            else{
                cout <<' ';
            }
        }
        cout<<endl;
    }

}

void triangleStarPattern(int n) {
    cout<<"4. Trianle Star Pattern"<<endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(j<=i) {
                cout<<'*';
            }
        }
        cout<<endl;
    }
}

void pyramidStarPattern(int n) {
    cout<<"5. Pyramid Star Pattern"<<endl;
    int k = n/2;
    for(int i=0; i<n/2+1; i++) {
        for(int j=0; j<n; j++) {
            if(j>=k-i && j<= k+i) {
                cout<<'*';
            }
            else {
                cout<<' ';
            }
        }
       cout<<endl;

    }
}

void hollowPyramidStarPattern(int n) {

    cout<<"6. Hollow Pyramid Star Pattern"<<endl;
    int k=n/2;
    for(int i= 0; i<n/2 +1; i++) {
        for(int j =0; j< n; j++) {
            if( j==k-i || j == k+i || i == k) {
                cout<<'*';
            }
            else{
                cout<<' ';
            }
        }
        cout<<endl;
    }
}

void invertedPyramidStarPattern(int n) {

    cout<<"7. Inverted Pyramid Star pattern"<<endl;

    int k = n/2;
    for(int i=0; i<k+1; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i || j > n - 1 - i) {
                cout << ' ';
            } else {
                cout << '*';
            }
        }
        cout << endl;
    }
}

void halfDiamondStarPattern(int n) {


    int k = n/2;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(k >= i && (j >= k && j <= k+i)) {
                cout<<'*';
            } else if( k <i &&( j >= k && j <= 2*k-(i-k))){
                cout<<'*';

           }else{
                cout<<' ';
            }
        }
        cout<<endl;
    }
}

void diamondStarPattern(int n) {

    int k =n/2;

    for(int i =0; i <n; i++) {
        for(int j=0; j<n; j++) {
            if( i<= k &&( j>=k-i && j<= k+i) ) {
                cout<<'*';
            }else if(i>k &&(j>= i-k && j <= 2*k-(i-k))) {
                cout<<'*';
            }else{
                cout<<' ';
            }
        }
        cout<<endl;
    }

}

int main() {
    std::cout << "Patterns!" << std::endl;


    string numst;
    cout<<"Please enter the number: ";
    getline(cin, numst);
    int num = atoi(numst.c_str());
    //squareStarPattern(num);
    //hollowSquareStarPattern(num);
    //rhombusStarPattern(num);
    //triangleStarPattern(num);
    //pyramidStarPattern(num);
    //hollowPyramidStarPattern(num);
    //invertedPyramidStarPattern(num);
    //halfDiamondStarPattern(num);
    diamondStarPattern(num);
    return 0;
}
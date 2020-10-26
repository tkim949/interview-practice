#include <iostream>

using namespace std;

void basicMixed(int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            k++;
            if (j == n - 1) {
                cout << k;
            } else {
                cout << k << '*';
            }

        }
        cout << endl;
    }
}

void invertBasicMixed(int n) {
    int k = n*n +1;
    //int cnt = k;
    for(int i=0; i<n; i++) {
         k -= n;
         int cnt = k;
        for(int j=0;  j<n; j++) {

            if(j == n-1) {
                cout<<cnt;
            } else {
                cout<<cnt<<"*";
                cnt++;
            }
        }
        cout<<endl;
    }
}

void evenOddRowMixedP(int n) {
   cout<<"Even odd row patten"<<endl;
    int a=1;

    for(int i =0; i<n; i++) {

        if(i%2== 0) {
            //int k = a+n;

            for(int j=0; j<n-1; j++) {
                cout<<a++<<"*";
            }
            cout<<a++<<endl;
        }else {
            int k;
            if(n/2 ==0) k= a+n;
            else k = a+2*n;
            for(int j=0; j<n-1; j++) {
                cout<<k++<<"*";
            }
            cout<<k<<endl;
        }
    }

}

void invertEvenOddRowMixedP(int n) {

    cout<<"\nInverted even odd row mixedP"<<endl;
    //int a=0;

    for(int i =0; i<n; i++) {

        if(i%2 == 0) {
            int a = n +(i/2)*n;

            for(int j=0; j<n-1; j++) {
                cout<<a--<<"*";
            }
            cout<<a<<endl;

        }else {
            int k;
            if(n/2 ==0) k = 3*n + (i/2)*n;
            else k = 4*n + (i/2)*n;
            for(int j=0; j<n-1; j++) {
                cout<<k--<<"*";
            }
            cout<<k<<endl;
        }
    }

}
void firstLastMixedPa(int n) {

    int p =(n%2==0) ? n: n-1;

   for(int i=1; i<=n; i+=2) {
       //int k = i *n +1; //when i starts at 0
       int k = (i-1)*n +1; //when starts i = 1
       for(int j=0; j<n-1; j++) {
           cout<<k++<<"*";
           //k++;
       }
       cout<<k<<endl;

   }
   for(int i= p; i>0; i -=2) {
       int k = (i-1)*n +1;
       //int k = i*n +1;
       for(int j=0; j <n-1; j++) {
           cout<<k++<<"*";
          // k++;
       }
       cout<<k<<endl;
   }
}

void basicIncrementTriangleP(int n) {
    int k=1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            if(i == j) {
                cout<<k++;
            } else {
                cout<<k++<<"*";
            }
        }
        cout<<endl;
    }
}

void upsideIncrementTriangleP(int n) {

    cout<<"Upside down Increment Triangle Patten"<<endl;
    int k=0;
    for(int i =0; i<=n; i++) {
        k += i;
    }
    for(int i=0; i<n; i++) {
        k = k-n +i; //when n=4, k=10-4+1;
        int temp = k;
        for(int j=n; j>i; j--) {
            k++;
            if(j == n) {
                cout<<k;
            }else{
                cout<<"*"<<k;
            }
        }
        cout<<endl;
        k = temp;

    }
}

void basicDiamondP(int n) {

  cout<<"This is Diamond pattern, so it need odd number!"<<endl;

    for(int i=0; i<n; i++) {

        if(i<=(n/2)) {
            for(int j=0; j<=i; j++) {
                if(j == 0) {
                    cout<<i+1;
                } else {
                    cout<<"*"<<i+1;
                }
            }
        } else{

            for(int j =i; j<n; j++) {
                if(j==i) {
                    cout<<n-i;
                } else {
                    cout<<"*"<<n-i;
                }
            }
        }
        cout<<endl;
    }
}

void basicMirrorP(int n) {

    cout<<" This is mirror patten, so it make double one more pattern"<<endl;

    for(int i=1;i <= n; i++ ) {
        /* k=1;
        for(int j=0; j<i; j++) {
            cout<<i;
            if(k<i) {
                cout<<"*";
                k = k+1;
            }
        }*/
        for(int j=0; j<i; j++) {
            if(j==0) cout<<i;
            else cout<<"*"<<i;
        }
        cout<<endl;
    }
    for(int i =n; i>0; i--) {
        for(int j=0; j<i; j++) {
            if(j==0) cout<<i;
            else cout<<"*"<<i;
        }
        cout<<endl;
    }

}

void opBasicMirrorP(int n) {

    cout<<"Opposite mirror pattern"<<endl;
    for(int i =n; i>0; i--) {
        for(int j=0; j<i; j++) {
            if(j==0) cout<<i;
            else cout<<"*"<<i;
        }
        cout<<endl;
    }
    for(int i=1;i <= n; i++ ) {

        for(int j=0; j<i; j++) {
            if(j==0) cout<<i;
            else cout<<"*"<<i;
        }
        cout<<endl;
    }

}


int main() {
    std::cout << "Star and Number Mixed Patterns" << std::endl;
    int num;
    cout<<"Please Enter two numbers: ";
    cin>>num;


    //basicMixed(num);
    //invertBasicMixed(num);
    //evenOddRowMixedP(num);
    //firstLastMixedPa(num);
    //invertEvenOddRowMixedP(num);
    //basicIncrementTriangleP(num);
    //upsideIncrementTriangleP(num);
   // basicDiamondP(num);
    //basicMirrorP(num);
    opBasicMirrorP(num);
    return 0;
}
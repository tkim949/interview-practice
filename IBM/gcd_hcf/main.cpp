#include <iostream>
#include <numeric>

using namespace std;

int findGCDRecursive(int num1, int num2) {
    /*
    if(num1 < num2) {
        int tmp = num1;
        num1 = num2;
        num2 = tmp;
    }
     if(num1 % num2 ==0) {
        return num2;
     }else {
     return findGCDRecursive(num2, num1 % num2);
     }

     */

    if(num2 == 0)
        return num1;
    return findGCDRecursive(num2, num1 % num2);


}

int findGCDIterative(int num1, int num2) {

    while(num1 != num2) {

        if(num1 > num2)
            num1 -= num2;
        else
            num2 -= num1;
    }
    return num1;
}

int findTwoNumLCM(int num1, int num2) {
    int gcdNum = findGCDIterative(num1, num2);
    int result = 0;

    result = (num1 * num2)/gcdNum;

    return result;
}

int threeNumLCM(int num1, int num2, int num3) {

    int product = num1 * num2 * num3;

    for(int i =1; i<= product; i++) {

        if( i%num1 ==0 && i%num2 == 0 && i%num3 == 0) {
            return i;
            //break;
        }
    }
    return -1;
}

int threeNumHCF(int num1, int num2, int num3) {
    int product = num1 * num2 * num3;

    for(int i =2; i<=product; i++) {
        if(num1%i == 0 && num2%i ==0 && num3%i ==0) {
            return i;
        }
    }
    return 1;
}



int main() {

    cout<<"Find LCM Least Common Multiple of many numbers using accumulate"<<endl;
    int arr[] = {5, 6, 9, 12};

    int result = accumulate(arr, arr+4, 1, findTwoNumLCM);
    cout<<"LCM of multiple numbers {5, 6, 9, 12} = "<<result<<endl;


    /*
    cout<<"Please enter three numbers"<<endl;
    int n1, n2, n3;
    cin>>n1>>n2>>n3;
    cout<<"LCM of three numbers "<<n1<<", "<<n2<<", "<<n3<<", = "<<threeNumLCM(n1, n2, n3)<<endl;
    cout<<"HCF of three numbers "<<n1<<", "<<n2<<", "<<n3<<", = "<<threeNumHCF(n1, n2, n3)<<endl;
     */
    /*
    std::cout << "Find Great Common Divisor/Highest Common Factor of two numbers!" << std::endl;
    int a = 98, b= 56;
    cout<<"using Recursive: GCD of "<<a<<", "<<b<<" = "<<findGCDRecursive(a, b)<<endl;
    cout<<"using Iterative: GCD of "<<a<<", "<<b<<" = "<<findGCDIterative(a, b)<<endl;
     */
    return 0;
}
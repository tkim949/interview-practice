#include <iostream>
#include <string>
using namespace std;

int hexToDec(char num[]) {
     //first declare the length of char array and base and return value
    int n= strlen(num);
    int base =1;
    int temp =0;
    //go through the whole char array but from the last one!
    for(int i=n-1; i>=0; i--) {
        //there are two cases, first one is between 0 and 9, and second one is between A and F
        if(num[i] >= '0' && num[i] <= '9') {
            temp += (num[i] -48)*base; //0 ascii = 48
            base = base *16;
        }else if(num[i] >= 'A' && num[i] <= 'F') {
            temp += (num[i] -55) * base; //A ascii = 65, and this A should be 10, so in order to be 10, subtract 55
            base = base * 16;
        }
    }

    return temp;

}



int main() {
    std::cout << "Convert Hexadecimal to decimal Numbers" << std::endl;
    char num[] ="3F456A";
    cout<<"Before Converting: "<<num<<", After converting: "<<hexToDec(num)<<endl;
    return 0;
}
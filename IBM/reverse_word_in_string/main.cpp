#include <iostream>
//#include <stack>
#include <cstring>
//#include <bits/stdc++.h>


using namespace std;

string reverseWd(string st) {

    int n = st.size();

    int i = 1;
    int j= n-2;
    while(i < j) {
        char tem = st[i];
        st[i] = st[j];
        st[j]= tem;
        i++;
        j--;
    }
    return st;
}

string reverseWord(char str[]) {

   char* tok = strtok(str, " ");
   string result;

   while (tok != nullptr) {
       result += reverseWd(tok)+" ";
       tok = strtok(nullptr, " ");
   }
   result.pop_back(); // in order to get rid of the last " "

   return result;

}

int main() {
    std::cout << "Reverse Word in a String, except the first and last character" << std::endl;
    char str[] = "Geeks for Geeks";
    cout<<"Show the reverse one: " <<reverseWord(str)<<endl;

    return 0;
}
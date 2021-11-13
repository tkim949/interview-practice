#include <iostream>
#include <vector>

using namespace std;

int fruitPromo(vector<vector<string> > codeList, vector<string> cart) {
    //set variables
    int cartIdx = 0;
    int totalNum = 0;
    int count =0;

    //check the total num of the codeList
    for(auto ele: codeList) {
        totalNum += ele.size();
    }

    int i=0;
    //outer loop for the row of codeList
    while(i <codeList.size()) {

        vector<string> innerList = codeList[i];

        int j=0;
        //inner loop for the column of codeList and compare products between list and cart!
        while(j < innerList.size() && cartIdx <cart.size()) {

            if(innerList[j] == cart[cartIdx]) {
                j++;
                cartIdx++;
                count++;
            } else if(innerList[j] == "anything") {
                cartIdx++;
                j++;
                count++;
            } else{
                if(j==0) cartIdx++;  //Key points!!!
                else return 0; //it means customer canot get the promo false
            }
        }
      i++;
    }
    return totalNum == count;
}

int gotPromot(vector<vector<string>> codeList, vector<string> cart) {
    //set variables
    int cartIdx = 0;
    int totalNum =0;
    int count =0;
    int i =0;

    //Get the totalNum
    for(auto codeL : codeList) {
        totalNum += codeL.size(); //total number of fruits in the code list
    }
   //outer loop for the row of codeList
    while( i < codeList.size()) {

        vector<string> list = codeList[i];
        int j =0;

        while(j < list.size() && cartIdx < cart.size()) {
            if(list[j] == cart[cartIdx]) {
                j++;
                cartIdx++;
                count++;
            } else if (list[j] == "anything") {
                cartIdx++;
                j++;
                count++;

            } else {
                if (j==0) cartIdx++; //there is another fruit in the customer's cart.
                else return 0;
            }
        }
        i++;
    }
   return count == totalNum;
}

int main() {
    std::cout << "Fruit Promotion!" << std::endl;

    vector<vector<string>> codeList = {{"apple", "apple"}, {"banana", "anything", "banana"}};
    vector<string> cart = {"banana", "orange", "banana", "apple", "apple"};

    cout<<"Test1: "<<gotPromot(codeList, cart)<<endl;
    cout<<"Test1-1: "<<fruitPromo(codeList, cart)<<endl;

    vector<vector<string>> codeList2 = {{"apple", "apple"}, {"banana", "anything", "banana"}};
    vector<string> cart2 = { "orange", "apple", "apple","banana", "orange", "banana"};

    cout<<"Test2: "<<gotPromot(codeList2, cart2)<<endl;

    cout<<"Test2-1: "<<fruitPromo(codeList2, cart2)<<endl;
    return 0;
}
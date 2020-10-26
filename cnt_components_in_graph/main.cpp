#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;



vector<string> findProducts(vector<vector<string>> pList) {

    set<string> visited;
    vector<set<string>> groups;
   // set<string> visitedProd;
  //check
    for(vector<string> st: pList) {
        /*
        cout<<"\njust inside the 1st for loop"<<endl;
        for(int i =0; i< st.size(); i++) {
            cout<< st[i]<< ",";
        }*/

        set<string> visitedProd;

        for(string prod: st) {
            if(visited.find(prod) != visited.end()) {
                visitedProd.insert(prod);
            }else{
                visited.insert(prod);
            }
        }
        /*
        cout<<"\nCheck the visited under the first for loop"<<endl;
        for(auto el: visited) {
            cout<< el<< ",";
        }

        cout<<"\n\ncheck the visited product"<<endl;
        for(auto el: visitedProd) {
            cout<< el<< ",";
        }*/


        if(visitedProd.size() > 0) {
            cout<<"\n\never been here second for loop"<<endl;
            for(string vP: visitedProd) {
                for(set<string> gp: groups) {
                    if(gp.find(vP) != gp.end()) {
                        gp.insert(st.begin(), st.end());
                        //gp.merge(st);//append one set to another!
                        cout<<"inside the 2nd for loop to print group"<<endl;
                        for(auto el: gp) {
                            cout<< el<< ",";
                        }

                    }
                }
            }
        }else {
            groups.push_back(set<string>(st.begin(), st.end()));
        }
        //visitedProd.clear();
    }

    //find the maximum set!
    int maxLen = 0;
    set<string> result;
   // for(set<string>& nd: groups){
   cout<<"check the group after the for loop\n"<<endl;
    for(int i=0; i<groups.size(); i++){
        if(groups[i].size() > maxLen){
            maxLen = groups[i].size();
            result = groups[i];
        }
        for(auto el: groups[i]) {
            cout<<el<<", "<<endl;
        }
    }

    cout<<"\n\nresult print\n"<<endl;
    for(auto el: result) {
        cout<< el<< ",";
    }



    return vector<string>(result.begin(), result.end());


}

int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<vector<string>> lists = {{"product1", "product2", "product3"},
                                    {"product4", "product2"},
                                    {"product6", "product7" },
                                    {"product8", "product7"}};

    vector<string> products = findProducts(lists);

    for(int i =0; i< products.size(); i++) {
        cout<< products[i]<< ",";
    }
    return 0;
}
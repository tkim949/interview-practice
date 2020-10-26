#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;



vector<string> findProducts(vector<vector<string>> pList) {
    //set variable for visited and groups for products
    set<string> visited;
    vector<set<string>>  groups;

    //run through the given pList and check if the product is in the visited list and input productvisited list.
    for(vector<string> st: pList) {

        set<string> visitedProd;

        for(string prod: st) {
            if(visited.find(prod) != visited.end()) {
                visitedProd.insert(prod);
            }else{
                visited.insert(prod);
            }
        }
        //if visitedproduct list has any element, find the exact list in the groups and insert whole element into the list.
        if(visitedProd.size() > 0) {

            for(string vP: visitedProd) {
                for(set<string> & gp: groups) {
                    if(gp.find(vP) != gp.end()) {
                        //set<string> temp(st.begin(), st.end());
                        gp.insert(st.begin(), st.end());

                        break;

                    }
                }
            }
        }else { //otherwise, insert whole inner list into the group
            groups.push_back(set<string>(st.begin(), st.end()));
        }

    }

    //find the maximum set!
    int maxLen = 0;
    set<string> result;
    for(set<string>& nd: groups){
        if(nd.size() >maxLen) {
            maxLen = nd.size();
            result = nd;
        }

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
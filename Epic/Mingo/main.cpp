#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

/*
vector<vector<int>> find(vector<vector<int>> matrix, unordered_map<int,int> table, int i, int j) {

    int count = 0;
    vector<vector<int>> mingoes;
    vector<int> inner;

    for(int k = 0; k < 10; k++) {
        if(table.find(matrix[i][k]) == table.end()) break;
        else{
            inner.push_back(matrix[i][k]);
            count++;
        }
    }
    if(count ==10) mingoes.push_back(inner);

    inner.clear();
    count =0;
    for(int k = 0; k < 10; k++) {
        if(table.find(matrix[k][j]) == table.end()) break;
        else{
            inner.push_back(matrix[i][k]);
            count++;
        }
    }
    if(count ==10) mingoes.push_back(inner);
    inner.clear();
    count = 0;
    if(i == j) {
        for(int k = 0 ; k <10; k++) {
            if(table.find(matrix[k][k]) == table.end()) break;
            else{
                inner.push_back(matrix[k][k]);
                count++;
            }
        }
    }
    if(count ==10) mingoes.push_back(inner);
    inner.clear();
    count = 0;
    if(i + j == 9) {
        for(int k = 0 ; k <10; k++) {
            if(table.find(matrix[k][9-k]) == table.end()) break;
            else{
                inner.push_back(matrix[k][9-k]);
                count++;
            }
        }
    }
    if(count ==10) mingoes.push_back(inner);
    inner.clear();

    return mingoes;
}
*/


vector<int> getMingo(const vector<vector<int>> matrix, const vector<int> list) {

    unordered_map<int, vector<int>> table;

    int n= list.size();

    //fill the hash map table with matrix numbers and index of row and column, so we can find the number with O(1)
    int idx =0;
    for(int i=0; i <10; i++) {
        for (int j = 0; j < 10; j++) {
            table[matrix[i][j]] = vector<int>{i, j};
        }
    }

    //find the first matched number in the table so we can get the index number of the list
    while(table.find(list[idx]) == table.end()) {
        idx++;
    }

    int cntLD = 0;
    int cntRD = 0;

    //I assume this matrix is the same size of row and column
    int rowS = matrix.size();


    //use array for rows and columns to check if there is mingo
    int row[rowS];
    memset(row, 0, sizeof(row));
    int col[rowS];
    memset(col, 0, sizeof(col));


    for(int i =idx; i<n; i++) {
        //if there is no matching number just skip
        if(table.find(list[i]) == table.end()) {
            continue;
        }
        //if we find a matching number, find its row and column number from the table and update row and column array.
        else {

            row[table[list[i]][0]]++;
            col[table[list[i]][1]]++;
            //if any row and column element equals to size of matrix row, we return it because we find mingo!
            for(int k=0; k<rowS; k++) {
                if(row[k] == rowS || col[k] == rowS) {
                    //return with two numbers: first is 1 (found) 0(no) and second is index number(0 indexed)
                    return vector<int>{1, i};
                }
            }
            //this is the left up and right down diagonal mingo case
            if(table[list[i]][0] == table[list[i]][1]) cntLD++;
            //this is the right up and left down diagonal mingo case
            if(table[list[i]][0] + table[list[i]][1] == rowS-1) cntRD++;

            //if above two case's counting number equals to the size of matrix row, we return it.
            if(cntLD ==rowS || cntRD ==rowS) return vector<int>{1, i};
        }

    }

   return vector<int>{0, n};
}


int main() {
    std::cout << "Find Mingo" << std::endl;
    //vector<vector<int>> matrix(10, vector<int>(10, 0));
    vector<vector<int>> matrix(10, vector<int>(10));

    srand((unsigned)(time(NULL)));
    for(int i=0; i <10; i++) {
        for(int j=0; j<10; j++) {
            matrix[i][j] = rand() %100 + 1;

        }
    }

    vector<int> list(100);
    for(int i=0; i<100;i++) list[i]= i+1;

    vector<int> result;
    result = getMingo(matrix, list);

    if(result[0] ==1 ) {
        cout<<"We got mingo at: "<<result[1]<<endl;
    } else{
        cout<<"We don't have mingo this time."<<endl;
    }


    return 0;
}

/*
void fill_row(vector<int> &row) {

    generate(row.begin(), row.end(), [] () {
        return (rand() % 100) +1;
    });
}*/
//for_each(matrix.begin(), matrix.end(), fill_row);
/*
random_device ran_device;
mt19937 mt_engine {ran_device()};
uniform_int_distribution<int> dist {1, 100};
*/

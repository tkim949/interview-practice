#include <iostream>
#include <vector>

using namespace std;
//this will be given
class Node{
public:
        int val;
        vector<Node*> children;
        //default constructor
        Node() {}
        //constructor, when it has only value
        Node(int _val) {
            val = _val;
        }
        //constructor, when it has vale and children
        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
};

class Node2{
public:
    int value;
    vector<Node2*> children;

    Node2() {}
    Node2(int val){
        value = val;
    }
    Node2(int val, vector<Node2*> child) {
        value = val;
        children = child;
    }
};

double totalAve = INT_MIN;
Node2 * answer;

vector<double> dfs_2(Node2 * root) {
    if(!root) return {0,0};

    double crtVal = root->value;
    double count =1;

    for(auto child: root->children) {
        vector<double> temp = dfs_2(child);
        crtVal += temp[0];
        count += temp[1];

    }
    double crtAvg = crtVal/count;
    if(count>1 && crtAvg > totalAve) {
        totalAve = crtAvg;
        answer = root;
    }

    return {crtVal, count};
}

//set the Average and result Node as a global variable
double ansAve=INT_MIN;
Node *result;

//depth first search!
vector<double> dfs(Node *node){
        //boundary check!
        if(!node){
            return {0,0};
        }
        //get the temp average from children with recursive calls.
        double currVal=node->val;
        double count=1;
        for(auto child: node->children){
            vector<double> temp=dfs(child);
            count+=temp[1];
            currVal+=temp[0];
        }
        double tempavg=currVal/count;

        //only when the new average is bigger than current average, it replace the previous one!
        if(count>1 && tempavg>ansAve){
            ansAve=tempavg;
            result=node; //change result Node

        }
        return {currVal,count};
}

int max_avg_subtree(Node2 * root) {
    if(!root) return 0;

    dfs_2(root);
    return answer->value;
}

int maximumAverageSubtree(Node *root){
        if(!root){
            return 0;
        }
       // call dfs!
        dfs(root);
        return result->val;

}


int main() {
        Node *node0=new Node(20);
        Node *node1=new Node(12);
        Node *node2=new Node(18);
        Node *node3=new Node(11);
        Node *node4=new Node(2);
        Node *node5=new Node(3);
        Node *node6=new Node(15);
        Node *node7=new Node(8);
        node0->children={node1,node2};
        node1->children={node3,node4,node5};
        node2->children={node6,node7};
        int ans=maximumAverageSubtree(node0);
        cout << ans << endl;
    Node2 *node10=new Node2(20);
    Node2 *node11=new Node2(12);
    Node2 *node12=new Node2(18);
    Node2 *node13=new Node2(11);
    Node2 *node14=new Node2(2);
    Node2 *node15=new Node2(3);
    Node2 *node16=new Node2(15);
    Node2 *node17=new Node2(8);
    node10->children={node11,node12};
    node11->children={node13,node14,node15};
    node12->children={node16,node17};
        cout<< max_avg_subtree(node10)<<endl;
        return 0;
}
#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
public:
    int val = 0;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class LevelOrderTraversal {
public:
    static vector<vector<int>> traverse(TreeNode *root) {
        vector<vector<int>> result;
        if(root == nullptr) {
            return result;
        }
        // TODO: Write your code here
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            int n= que.size();
            vector<int> currentLevel;
            for(int i=0; i<n; i++ ){
                TreeNode* current = que.front();
                que.pop();
                currentLevel.push_back(current->val);
                if(current->left != nullptr) {
                    que.push(current->left);
                }
                if(current->right != nullptr) {
                    que.push(current->right);
                }
            }
            result.push_back(currentLevel);
        }
        return result;
    }
};

class ReverseLevelOrderTraversal {
public:
    static deque<vector<int>> traverse(TreeNode *root) {

        deque<vector<int>> result = deque<vector<int>>();
        if(root == nullptr) {
            return result;
        }
        // TODO: Write your code here
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {

            int size = que.size();
            vector<int> temp;
            for(int i=0; i<size; i++)
            {
                TreeNode* current = que.front();
                temp.push_back(current->val);
                que.pop();

                if(current->left) que.push(current->left);
                if(current->right) que.push(current->right);

            }

            result.push_front(temp);


        }
        return result;
    }
};

class ZigzagTraversal {
public:
    static vector<vector<int>> traverse(TreeNode *root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        // TODO: Write your code here
        queue<TreeNode*> que;
        que.push(root);
        bool leftToRight = true;

        while(!que.empty()) {


            int size = que.size();
            vector<int> currentLevel(size); //need to add size!

            for(int i=0; i<size; i++) {
                TreeNode* current = que.front();
                que.pop();
                if(leftToRight == true) currentLevel[i] = current->val;
                else currentLevel[size-1-i] = current->val;


                if(current->left != nullptr) que.push(current->left);
                if(current->right != nullptr) que.push(current->right);
            }
            result.push_back(currentLevel);
            leftToRight = !leftToRight;
        }
        return result;
    }
};

class LevelAverage {
public:
    static vector<double> findLevelAverages(TreeNode *root) {
        vector<double> result;
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode *> queue;
        queue.push(root);

        while (!queue.empty()) {

            int levelSize = queue.size();
            double levelSum = 0;

            for (int i = 0; i < levelSize; i++) {
                TreeNode *currentNode = queue.front();
                queue.pop();
                // add the node's value to the running sum
                levelSum += currentNode->val;
                // insert the children of current node to the queue
                if (currentNode->left != nullptr) {
                    queue.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    queue.push(currentNode->right);
                }
            }
            // append the current level's average to the result array
            result.push_back(levelSum / levelSize);
        }

        return result;
    }
};

class MaximumBinaryTreeDepth {
public:
    static int findDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode *> queue;
        queue.push(root);
        int maximumTreeDepth = 0;
        while (!queue.empty()) {
            maximumTreeDepth++;
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode *currentNode = queue.front();
                queue.pop();
                // insert the children of current node in the queue
                if (currentNode->left != nullptr) {
                    queue.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    queue.push(currentNode->right);
                }
            }
        }

        return maximumTreeDepth;
    }
};

class MinimumBinaryTreeDepth {
public:
    static int findDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode *> queue;
        queue.push(root);
        int minimumTreeDepth = 0;

        while (!queue.empty()) {
            minimumTreeDepth++;

            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode *currentNode = queue.front();
                queue.pop();

                if(currentNode->left == nullptr && currentNode->right == nullptr) {
                    return minimumTreeDepth;
                }
                // insert the children of current node in the queue
                if (currentNode->left != nullptr) {
                    queue.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    queue.push(currentNode->right);
                }
            }
        }

        return minimumTreeDepth;
    }
};

class LevelOrderSuccessor {
public:
    static TreeNode *findSuccessor(TreeNode *root, int key) {
        // TODO: Write your code here
        if(root == nullptr) return nullptr;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {

                TreeNode *currentNode = que.front();
                que.pop();
                /*
                if(current->left) que.push(current->left);
                if(current->right) que.push(current->right);

                if(current->val == key) break; */

                if (currentNode->left != nullptr) {
                    que.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    que.push(currentNode->right);
                }

                // break if we have found the key
                if (currentNode->val == key) {
                    break;
                }

        }

        return que.front();//because current is alredy poped from the que, so the front is now the successor of current
    }
};

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);

    vector<vector<int>> result = LevelOrderTraversal::traverse(root);
    cout << "Level order traversal"<< endl;
    for (auto vec : result) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    auto result2 = ReverseLevelOrderTraversal::traverse(root);

    cout << "\nReverse level order traversal: "<<endl;
    for (auto que : result2) {
        for (auto num : que) {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << "\nTree Maximum Depth: " << MaximumBinaryTreeDepth::findDepth(root) << endl;
    cout << "\nTree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;

    root->right->left->left = new TreeNode(20);
    root->right->left->right = new TreeNode(17);
    vector<vector<int>> resultZZ = ZigzagTraversal::traverse(root);
    cout << "\nZigzag traversal: "<<endl;
    for (auto vec : resultZZ) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout<<endl;
    }

    vector<double> resultAve = LevelAverage::findLevelAverages(root);
    cout << "\nLevel averages are: "<<endl;
    for (auto num : resultAve) {
        cout << num << " "<<endl;
    }

    cout << "\nTree Maximum Depth: " << MaximumBinaryTreeDepth::findDepth(root) << endl;
    cout << "\nTree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;

    TreeNode *res = LevelOrderSuccessor::findSuccessor(root, 12);

    if (res != nullptr) {
        cout << "\nSuccessor of 12: "<<res->val << " " << endl;
    }

    res = LevelOrderSuccessor::findSuccessor(root, 9);
    if (res!= nullptr) {
        cout << "Successor of 9: "<<res->val << " " << endl;
    }

}
/*
 * Level order traversal:
 * 12
 * 7 1
 * 9 10 5
 *
 */
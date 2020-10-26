#include <iostream>
#include <vector>

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

class TreePathSum {
public:
    static bool hasPath(TreeNode *root, int sum) {
        if (root == nullptr) {
            return false;
        }

        // if the current node is a leaf and its value is equal to the sum, we've found a path
        if (root->val == sum && root->left == nullptr && root->right == nullptr) {
            return true;
        }

        // recursively call to traverse the left and right sub-tree
        // return true if any of the two recursive call return true
        return hasPath(root->left, sum - root->val) || hasPath(root->right, sum - root->val);
    }
};

class FindAllTreePaths {
public:
    static vector<vector<int>> findPaths(TreeNode *root, int sum) {
        vector<vector<int>> allPaths;
        vector<int> currentPath;
        findPathsRecursive(root, sum, currentPath, allPaths);
        return allPaths;
    }

private:
    static void findPathsRecursive(TreeNode *currentNode, int sum, vector<int> &currentPath,
                                   vector<vector<int>> &allPaths) {
        if (currentNode == nullptr) {
            return;
        }

        // add the current node to the path
        currentPath.push_back(currentNode->val);

        // if the current node is a leaf and its value is equal to sum, save the current path
        if (currentNode->val == sum && currentNode->left == nullptr && currentNode->right == nullptr) {
            allPaths.push_back(vector<int>(currentPath));
        } else {
            // traverse the left sub-tree
            findPathsRecursive(currentNode->left, sum - currentNode->val, currentPath, allPaths);
            // traverse the right sub-tree
            findPathsRecursive(currentNode->right, sum - currentNode->val, currentPath, allPaths);
        }

        // remove the current node from the path to backtrack,
        // we need to remove the current node while we are going up the recursive call stack.
        currentPath.pop_back();
    }
};

class SumOfPathNumbers {
public:
    static int findSumOfPathNumbers(TreeNode *root) {
        return findRootToLeafPathNumbers(root, 0);
    }

private:
    static int findRootToLeafPathNumbers(TreeNode *currentNode, int pathSum) {
        if (currentNode == nullptr) {
            return 0;
        }

        // calculate the path number of the current node
        pathSum = 10 * pathSum + currentNode->val;

        // if the current node is a leaf, return the current path sum.
        if (currentNode->left == nullptr && currentNode->right == nullptr) {
            return pathSum;
        }
        // traverse the left and the right sub-tree
        return findRootToLeafPathNumbers(currentNode->left, pathSum) +
               findRootToLeafPathNumbers(currentNode->right, pathSum);
    }
};

class CountAllPathSum {
public:
    static int countPaths(TreeNode *root, int S) {
        vector<int> currentPath;
        return countPathsRecursive(root, S, currentPath);
    }

private:
    //int pathCount = 0;

    static int countPathsRecursive(TreeNode *currentNode, int S, vector<int> &currentPath) {
        if (currentNode == nullptr) {
            return 0;
        }

        // add the current node to the path
        currentPath.push_back(currentNode->val);
        int pathCount = 0;
        int pathSum = 0;
        // find the sums of all sub-paths in the current path list
        for (vector<int>::reverse_iterator itr = currentPath.rbegin(); itr != currentPath.rend();
             ++itr) {
            pathSum += *itr;
            // if the sum of any sub-path is equal to 'S' we increment our path count.
            if (pathSum == S) {
                pathCount++;
            }
        }

        // traverse the left sub-tree
        pathCount += countPathsRecursive(currentNode->left, S, currentPath);
        // traverse the right sub-tree
        pathCount += countPathsRecursive(currentNode->right, S, currentPath);

        // remove the current node from the path to backtrack,
        // we need to remove the current node while we are going up the recursive call stack.
        currentPath.pop_back();

        return pathCount;
    }
};

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    cout << "Tree has path: " << TreePathSum::hasPath(root, 23) << endl;
    cout << "Tree has path: " << TreePathSum::hasPath(root, 16) << endl;

    int sum = 23;
    vector<vector<int>> resultP = FindAllTreePaths::findPaths(root, sum);
    cout << "\nTree paths with sum " << sum << ": " << endl;
    for (auto vec : resultP) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << "\nTotal Sum of Path Numbers: " << SumOfPathNumbers::findSumOfPathNumbers(root) << endl;

    CountAllPathSum allp;
    cout << "\n[PAthCount]Tree has path: " << allp.countPaths(root, 23) << endl;

}

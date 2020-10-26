#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
/*
 * Given an unsorted array containing numbers, find the smallest missing positive number in it.
 * Input: [-3, 1, 5, 4, 2]
 * Output: 3
 * Explanation: The smallest missing positive number is '3'
 */

class FirstMissingPositive {
public:
    static int findNumber(vector<int> &nums) {
        int i = 0;
        while (i < nums.size()) {
            //cout<<"i: "<<i<<", nums[i]: "<<nums[i]<<" ";
            if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
                //cout<<"inside i: "<<i<<", nums[i]: "<<nums[i]<<" ";
                swap(nums, i, nums[i] - 1);
            } else { //this is the main point!!!! i is only updated for this case!
                i++;
            }
        }

        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return nums.size() + 1;//if the array has all numbers correctly such as {1, 2, 3} answer would be 4
    }

private:
    static void swap(vector<int> &arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
};
/*
 * Given an unsorted array containing numbers and a number ‘k’, find the first ‘k’ missing positive numbers in the array.
 * Input: [3, -1, 4, 5, 5], k=3
 * Output: [1, 2, 6]
 * Explanation: The smallest missing positive numbers are 1, 2 and 6.
 */

class FirstKMissingPositive {
public:
    static vector<int> findNumbers(vector<int> &nums, int k) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
                swap(nums, i, nums[i] - 1);
            } else {
                i++;
            }
        }

        vector<int> missingNumbers;
        unordered_set<int> extraNumbers;
        for (i = 0; i < nums.size() && missingNumbers.size() < k; i++) {
            if (nums[i] != i + 1) {
                missingNumbers.push_back(i + 1);
                extraNumbers.insert(nums[i]);
            }
        }

        // add the remaining missing numbers
        for (i = 1; missingNumbers.size() < k; i++) {
            int candidateNumber = i + nums.size();
            // ignore if the array contains the candidate number
            if (extraNumbers.find(candidateNumber) == extraNumbers.end()) {
                missingNumbers.push_back(candidateNumber);
            }
        }

        return missingNumbers;
    }

private:
    static void swap(vector<int> &arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
};

/* Find corrupt pair!
 * We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’.
 * The array originally contained all the numbers from 1 to ‘n’, but due to a data error,
 * one of the numbers got duplicated which also resulted in one number going missing.
 * Find both these numbers.
 * Input: [3, 1, 2, 5, 2]
 * Output: [2, 4]
 * Explanation: '2' is duplicated and '4' is missing.
 */

class FindCorruptNums {
public:
    static vector<int> findNumbers(vector<int> &nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums, i, nums[i] - 1);
            } else {
                i++;
            }
        }

        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return vector<int>{nums[i], i + 1};
            }
        }

        return vector<int>{-1, -1};
    }

private:
    static void swap(vector<int> &arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
};

/* <findMissingNumber>
 * We are given an array containing ‘n’ distinct numbers taken from the range 0 to ‘n’.
 * Since the array has only ‘n’ numbers out of the total ‘n+1’ numbers, find the missing number.
 * Input: [4, 0, 3, 1]
 * Output: 2
 * <findNumbers>
 * We are given an unsorted array containing numbers taken from the range 1 to ‘n’.
 * The array can have duplicates, which means some numbers will be missing. Find all those missing numbers.
 * Input: [2, 3, 1, 8, 2, 3, 5, 1]
 * Output: 4, 6, 7
 * Explanation: The array should have all numbers from 1 to 8, due to duplicates 4, 6, and 7 are missing.
 */

class MissingNumber {
public:
    static int findMissingNumber(vector<int> &nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] < nums.size() && nums[i] != nums[nums[i]]) {
                swap(nums, i, nums[i]);
            } else {
                i++;
            }
        }

        // find the first number missing from its index, that will be our required number
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                return i;
            }
        }

        return nums.size();
    }

    static vector<int> findNumbers(vector<int> &nums) {
        int i=0;
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i] -1]) {
                swap(nums, i, nums[i] -1);
            } else {
                i++;
            }
        }

        vector<int> missingNumbers;
        // TODO: Write your code here
        for (i=0; i< nums.size(); i++) {
            if (nums[i] != i+1) {
                missingNumbers.push_back(i+1);
            }
        }
        return missingNumbers;
    }

private:
    static void swap(vector<int> &arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
};

/* <FindDuplicate>
 * We are given an unsorted array containing ‘n+1’ numbers taken from the range 1 to ‘n’.
 * The array has only one duplicate but it can be repeated multiple times.
 * Find that duplicate number without using any extra space.
 * You are, however, allowed to modify the input array.
 * Input: [1, 4, 4, 3, 2]
 * Output: 4
 *
 *
 *
 */

class FindDuplicate {
public:
    static int findNumber(vector<int> &nums) {
        // TODO: Write your code here
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != nums[nums[i] -1]) {
                swap(nums, i, nums[i]-1);
            }else {
                i++;
            }
        }

        for(int i=0; i<nums.size(); i++ ){
            if(nums[i] != i+1) {
                return nums[i];
            }
        }

        return -1;
    }
    static vector<int> findDNumbers(vector<int> &nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums, i, nums[i] - 1);
            } else {
                i++;
            }
        }

        vector<int> duplicateNumbers;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                duplicateNumbers.push_back(nums[i]);
            }
        }

        return duplicateNumbers;
    }

private:

    static void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

};

void print(vector<int> & vet) {

    for (auto num : vet) {
        cout << num << " ";
    }
    cout<<endl;
}

int main() {
    /*
    std::cout << "Find the smallest missing positive number" << std::endl;
    vector<int> v1 = {-3, 1, 5, 4, 2};
    cout <<"Test1: " <<FirstMissingPositive::findNumber(v1) << endl;

    v1 = {3, 1, 2};
    cout << "Test2(4): "<<FirstMissingPositive::findNumber(v1) << endl;

    v1 = {-4, -2, -3};
    cout << "Test3: "<< FirstMissingPositive::findNumber(v1) << endl;

    cout<<"\nGiven an unsorted array containing numbers and a number ‘k’,";
    cout<<" find the first ‘k’ missing positive numbers in the array."<<endl;
    vector<int> v2 = {3, -1, 4, 5, 5};
    vector<int> missingNumbers = FirstKMissingPositive::findNumbers(v2, 3);
    cout << "Test1: Missing numbers: ";
    print(missingNumbers);

    v2 = {2, 3, 4};
    missingNumbers = FirstKMissingPositive::findNumbers(v2, 3);
    cout << "Test2: Missing numbers: ";
    print(missingNumbers);

    v2 = {-2, -3, 4};
    missingNumbers = FirstKMissingPositive::findNumbers(v2, 2);
    cout << "Test3: Missing numbers: ";
    print(missingNumbers);

    cout<<"\nFind currupt pair!"<<endl;
    vector<int> v3 = {3, 1, 2, 5, 2};
    vector<int> nums = FindCorruptNums::findNumbers(v3);
    cout << "Test1: " << nums[0] << ", " << nums[1] << endl;

    v3 = {3, 1, 2, 3, 6, 4};
    nums = FindCorruptNums::findNumbers(v3);
    cout << "Test2: " << nums[0] << ", " << nums[1] << endl;
    */
    cout<<"\nFind a missing number."<<endl;
    vector<int> v4 = {4, 0, 3, 1};
    cout << "Test1: "<< MissingNumber::findMissingNumber(v4) << endl;
    v4 = {8, 3, 5, 2, 4, 6, 0, 1};
    cout << "Test2: "<<MissingNumber::findMissingNumber(v4) << endl;

    /*
    cout<<"\nFind all missing numbers" <<endl;
    vector<int> v5 = {2, 3, 1, 8, 2, 3, 5, 1};
    vector<int> missing = MissingNumber::findNumbers(v5);
    cout << "Test1 All Missing numbers: ";
     print(missing);

    v5 = {2, 4, 1, 2};
    missing = MissingNumber::findNumbers(v5);
    cout << "Test2 All Missing numbers: ";
    print(missing);

    v5 = {2, 3, 2, 1};
    missing = MissingNumber::findNumbers(v5);
    cout << "Test3 All Missing numbers: ";
    print(missing);

    cout<<"\nFind A Duplicate Number"<<endl;
    vector<int> v6 = {1, 4, 4, 3, 2};
    cout << FindDuplicate::findNumber(v6) << endl;

    v6 = {2, 1, 3, 3, 5, 4};
    cout << FindDuplicate::findNumber(v6) << endl;

    v6 = {2, 4, 1, 4, 4};
    cout << FindDuplicate::findNumber(v6) << endl;

    cout<<"\nFind All Duplicate numbers"<<endl;
    vector<int> v7 = {3, 4, 4, 5, 5};
    vector<int> duplicates = FindDuplicate::findDNumbers(v7);
    cout << "Duplicates are: ";
    print(duplicates);

    v7 = {5, 4, 7, 2, 3, 5, 3};
    duplicates = FindDuplicate::findDNumbers(v7);
    cout << "Duplicates are: ";
    print(duplicates);
    */
    return 0;
}
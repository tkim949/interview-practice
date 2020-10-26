#include <iostream>

using namespace std;

class HappyNum {

public:
    static bool find(int num) {
        int slow = num, fast =num;

        do {
            cout<<"Slow"<<endl;
            slow = findSqSum(slow);
            cout<<"Fast"<<endl;
            fast = findSqSum(findSqSum(fast));
        } while(slow != fast);

        return slow == 1;
    }

private:
    static int findSqSum(int num) {
        int sum =0;
        cout<<"Num: "<<num;
        while(num>0) {
            int digit = num%10;
            sum += digit*digit;
            cout<<" inner sum: "<<sum<<" ";
            num /=10;
        }
        cout<<"  Sum: "<<sum<<endl;
        return sum;
    }



};

int main() {
    std::cout << "Happy Number" << std::endl;
    cout<< HappyNum::find(23) <<endl;
    cout<< HappyNum::find() <<endl;

    return 0;
}
// constructing priority queues
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater

using namespace std;

int cnt_ropes_cost(vector<int> ropes) {
    //it returns the minimum cost!
    //set the variables and return
    //int result =0;

    //1. set priority queue and convert the ropes to it and return
    priority_queue<int, vector<int>, greater<int>> pri_ropes(ropes.begin(), ropes.end());
    int cost =0; //temp rope cost!

    //run through the pri-queue using while loop, until it is empty
    while(!pri_ropes.empty()) {
        //set first ans second minimum
        int min_rope1 = pri_ropes.top();
        int min_rope2 =0;
        pri_ropes.pop();

        if(!pri_ropes.empty()) {
            min_rope2 = pri_ropes.top();
            pri_ropes.pop();
        }
        //add them/make a new rope and update total cost
        int newRope = min_rope1 + min_rope2;
        cost += newRope;

        //insert new rope into the queue
        if(pri_ropes.size() != 0)
            pri_ropes.push(newRope);
    }
    return cost;
}




int ConnectRopes(std::vector<int> vecInput)
{
    int result = 0;
   //priority queue stores the higher value first, so if we want the lower value, we change it with "greater"
    std::priority_queue<int, std::vector<int>, std::greater<int> >
        connectEdges(vecInput.begin(), vecInput.end());

    int interimResult = 0;
    while (!connectEdges.empty())
    {
        int minFirst = connectEdges.top();
        int minSecond = 0;
        connectEdges.pop();

        if (!connectEdges.empty())
        {
            minSecond = connectEdges.top();
            connectEdges.pop();
        }
        int addUp = minFirst+minSecond;
        interimResult += addUp;

        if(connectEdges.size() != 0)
            connectEdges.push(addUp);

    }
    return interimResult;
}
int main()
{
    std::vector<int> vecIn = {2,2,3,3};// { 1, 2, 5, 10, 35, 89 }; //{8, 4, 6, 12};//
    std::cout<<"Test1: "<< ConnectRopes(vecIn)<<endl;
    cout<<"Test1-1: "<<cnt_ropes_cost(vecIn)<<endl;

    vector<int> vect1 = {20, 4, 8, 2};
    cout<<"Test2: "<<ConnectRopes(vect1) <<endl;
    cout<<"Test1-2: "<<cnt_ropes_cost(vect1)<<endl;
    return 0;
}
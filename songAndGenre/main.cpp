#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string,vector<string>> songsAndGenre(unordered_map<string,vector<string>>& users,
                                                    unordered_map<string,vector<string>>& genres) {


    //1. create song -> genre
    unordered_map<string, string> songToGenre;

    for(auto ele: genres) {
        for(string song: ele.second) {
            songToGenre[song] = ele.first;
        }
    }

    //2. create user -> genre
    unordered_map<string, unordered_map<string, int>> userToGenre;

    for(auto person: users) {
        unordered_map<string, int> temp;
        for(string song: person.second) {
            temp[songToGenre[song]]++;
        }
        userToGenre[person.first] = temp;
        temp.clear();
    }
    //3. check most frequent genre per user
    unordered_map<string, vector<string>> result;
    for(auto person: userToGenre) {
        int maxFreq =0;
        for(auto ele: person.second)
           maxFreq = max(maxFreq, ele.second);
        for(auto ele: person.second) {
            if(ele.second == maxFreq)
                result[person.first].push_back(ele.first);
        }
    }
    return result;
    /*
    //1. create song->genre
    unordered_map<string, string> stg;  //songtogenre map
    for (auto i:genres)
        for (string s:i.second)
            stg[s] = i.first;
   //2. create user -> genre
    unordered_map<string, unordered_map<string, int>> utg; //user to genre freq map
    for (auto i:users) {
        unordered_map<string, int> tm; //temp map
        for (string s:i.second)
            tm[stg[s]]++;
        utg[i.first] = tm;
        tm.clear();
    }
   //3. set return and check the most frequent genre per user!
    unordered_map<string, vector<string>> ans;
    for (auto i:utg) {
        int mxf = 0; //max freq
        for (auto j:i.second)
            mxf = max(mxf, j.second);
        for (auto j:i.second) {
            if (j.second == mxf)
                ans[i.first].push_back(j.first);
        }
    }
    return ans;
     */
}

unordered_map<string,vector<string>> songsAndGenre2(unordered_map<string,vector<string>>& users,
                                                       unordered_map<string,vector<string>>& genres){
    unordered_map<string,string> songToGenre;
    unordered_map<string,unordered_map<string,int>> userToGenre;
    unordered_map<string,vector<string>> result;
    unordered_map<string,int> max;

    for(auto genre:genres)
    {
        for(auto song: genre.second)
        {
            songToGenre[song] = genre.first;
        }
    }

    for(auto user:users)
    {
        for(auto item:user.second)
        {
            userToGenre[user.first][songToGenre[item]]++;
            auto tempMax = userToGenre.at(user.first).at(songToGenre[item]);
            max[user.first] = std::max(tempMax,max[user.first]);
        }
    }

    for(auto user:userToGenre)
    {
        for(auto genre:user.second)
        {
            if(genre.second==max.at(user.first))
            {
                result[user.first].push_back(genre.first);
            }
        }
    }

    return result;
}


int main() {
    unordered_map<string,vector<string>> users;
    users["David"] = {"song1", "song2", "song3", "song4", "song8"};
    users["Emma"] = {"song5", "song6", "song7"};

    unordered_map<string,vector<string>> songs;
    songs["Rock"] = {"song1", "song3"};
    songs["Dubstep"] = {"song7"};
    songs["Techno"] = {"song2", "song4"};
    songs["Pop"] = {"song5", "song6"};
    songs["Jazz"] = {"song8", "song9"};

    auto result = songsAndGenre2(users,songs);
    for(auto x: result)
    {
        cout<<x.first<<" : ";
        for(auto song:x.second)
        {
            cout<<song<<" ";
        }
        cout<<endl;
    }

    users.clear();
    songs.clear();

    users["David"] = {"song1", "song2"};
    users["Emma"] = {"song3", "song4"};

    result = songsAndGenre2(users,songs);
    for(auto x: result)
    {
        cout<<x.first<<" : ";
        for(auto song:x.second)
        {
            cout<<song<<" ";
        }
        cout<<endl;
    }

}
/*
Emma : Pop
David : Rock Techno
Emma :
David :
 */
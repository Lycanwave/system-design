#include<bits/stdc++.h>

using namespace std;

class ISubscriber{

public:
    virtual void notify(string message) = 0;
};

class User:public ISubscriber{

private: 
    int userId;
public:
    User(int userId){
        this->userId = userId;
    }

    void notify(string message){
        cout<<message<<" to "<<this->userId<<endl;
    }
};

class Group{

private:
    list<ISubscriber*> users;
public:
    void subscribe(ISubscriber* user){
        users.push_back(user);
    }
    void unsubscribe(ISubscriber* user){
        users.remove(user);
        user->notify("deleted");
    }

    void notify(string message){
        for(auto it:users){
            it->notify(message);
        }
    }
};


int main(){

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    Group *group = new Group();

    User* user1 = new User(1);
    User* user2 = new User(2);
    User* user3 = new User(3); 

    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    group->notify("sent");

    group->unsubscribe(user3);

    group->notify("new message");



    
    return 0;
}

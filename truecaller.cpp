#include<bits/stdc++.h>

using namespace std;

//CLASS USER

class User{

public:
	string firstName;
	string lastName;
	string phnNumber;

	User(){}

	User(string firstName,string lastName,string phnNumber){
		this->firstName = firstName;
		this->lastName = lastName;
		this->phnNumber = phnNumber;
	}
};

//TRIE

struct Node{
	unordered_map<char,pair<Node*,vector<User>>> m;

	bool containsKey(char ch){
		return m.count(ch);
	}

	Node* getNode(char ch){
		return m[ch].first;
	}

	vector<User> getNumberList(char ch){
		return m[ch].second;
	}

	void setNumber(char ch,User user){
		m[ch].second.push_back(user);
	}

	void setNode(char ch,Node* newNode,User user){
		m[ch].first = newNode;
		m[ch].second.push_back(user);
	}

};

class Trie{
	Node* root;
	static Trie* trie;
	static mutex mtx;
	Trie(){
		root = new Node();
	}

	void insertionOperations(string words,User user){
		Node* node = root;
		for(int i=0;i<words.length();i++){

			if(node->containsKey(words[i])){
				node->setNumber(words[i],user);
			}else{
				node->setNode(words[i],new Node,user);
			}
			node = node->getNode(words[i]);
		}
	}

public:

	static Trie* getInstance();

	void insert(User user){
		insertionOperations(user.firstName,user);
		insertionOperations(user.phnNumber,user);
	}

	vector<User> getNumber(string words){
		Node* node = root;
		vector<User> list;
		for(int i=0;i<words.length();i++){
			if(!node->containsKey(words[i])){
				return {};
			}
			list = node->getNumberList(words[i]);
			node = node->getNode(words[i]);
		}
		return list;
	}
};

Trie* Trie::trie = nullptr;
mutex Trie::mtx;
Trie* Trie::getInstance(){
	if(trie == nullptr){
		mtx.lock();
		if(trie == nullptr){
			trie = new Trie();
		}
		mtx.unlock();
	}

	return trie;
}


//SEARCHING INTERFACE

class SearchUser{
public:
	Trie* trie = Trie::getInstance();
	virtual vector<User> search(string name) = 0;
};

//SEARCHING TYPES EXTENDABLE

class SearchUsingName : public SearchUser{

public:
	vector<User> search(string name){
		return trie->getNumber(name);
		// cout<<"search Name"<<endl;
		// return {};
	}
};

class SearchUsingNumber : public SearchUser{

public:
	vector<User> search(string name){
		return trie->getNumber(name);
	}
};

class SearchUsingBoth : public SearchUser{

public:
	vector<User> search(string name){
		return trie->getNumber(name);
	}
};

//MAIN CLASS

class TrueCaller{
vector<User> users;
Trie *trie = Trie::getInstance();
public:

	void addUser(User user){
		trie->insert(user);
		users.push_back(user);
	}

	vector<User> searchUser(string name){
		if(!name.length())
			return users;
		SearchUser* searchList = new SearchUsingBoth();
		return searchList->search(name);
	}


};

int main(){

	 #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif



   	TrueCaller * trueCaller = new TrueCaller();
   	trueCaller->addUser(User("rohit" , "kumar" , "123456789"));
   	trueCaller->addUser(User("rohi" , "kumar" , "123456788"));
   	trueCaller->addUser(User("ronit" , "kumar" , "123456787"));
   	trueCaller->addUser(User("mohit" , "kumar" , "123456786"));
   	trueCaller->addUser(User("check" , "please" , "123456789"));

   	vector<User> list = trueCaller->searchUser("r");

   	for(auto it:list){
   		cout<<it.firstName<<" - "<<it.lastName<<" - "<<it.phnNumber<<endl;
   	}

}

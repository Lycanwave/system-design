#include<bits/stdc++.h>

using namespace std;

enum BALL{
	WIDE_BALL,
	NO_BALL,
	FREE_HIT,
};

enum WICKET{
	WICKET,
	LBW,
	CATCH_OUT,
	RUN_OUT,
};


class Admin{
	string name;
public:
	Admin(string name){
		this->name = name;
	}

	string getName(){
		return name;
	}
};

class Commentator{
	string name;
public:
	Commentator(string name){
		this->name = name;
	}

	string getName(){
		return name;
	}
};

class Commentry{

public:

	void getComment(Commentator* commentator,string message){
		cout<<"Commentry by: "<<commentator->getName()<<endl;
		cout<<message<<endl;
	}
};

class Player{
	string name;
	double age;
	string teamName;
	string expertise;
public:
	Player(string name , double age,string teamName,string expertise){
		this->name = name;
		this->age = age;
		this->teamName = teamName;
		this->expertise = expertise;
	}


	string getName(){
		return name;
	}

	double getAge(){
		return age;
	}

	string getTeamName(){
		return teamName;
	}

	string getExpertise(){
		return expertise;
	}
};


class Team{

	vector<Player*> players;
	string teamName;
public:

	Team(vector<Player*> players , string teamName){
		this->players = players;
		this->teamName = teamName;
	}

	void getTeamInfo(){
		cout<<"Team: "<<teamName<<endl;
		for(int i=0;i<players.size();i++){
			cout<<"Name: "<<players[i]->getName()<<" Expertise: "<<players[i]->getExpertise()<<endl;
		}
	}

};


class MatchFormat{

public:

	virtual void calculateScore() = 0;
	virtual void scoreCard() = 0;
	virtual int totalOver() = 0;
};

class Ttwenty : public MatchFormat{

public:
	void calculateScore(){
		cout<<"calculate Socre function"<<endl;
	}

	void scoreCard(){
		cout<<"Score card"<<endl;
	}

	int totalOver(){
		return 20;
	}

};

class OneDay : public MatchFormat{

public:
	void calculateScore(){
		cout<<"calculate Socre function"<<endl;
	}

	void scoreCard(){
		cout<<"Score card"<<endl;
	}

	int totalOver(){
		return 50;
	}

};

class Test : public MatchFormat{

public:
	void calculateScore(){
		cout<<"calculate Socre function"<<endl;
	}

	void scoreCard(){
		cout<<"Score card"<<endl;
	}

	int totalOver(){
		return 90;
	}


};



int main(){

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    vector<Player*> team1_Players;
   	for(int i=0;i<11;i++){
   		string playerName = "Player1:" + to_string(i);
   		double age = i;
   		string expertise = "batsman";
   		team1_Players.push_back(new Player(playerName,age,"IND",expertise));
   	}
   	vector<Player*> team2_Players;
   	for(int i=0;i<11;i++){
   		string playerName = "Player1:" + to_string(i);
   		double age = i;
   		string expertise = "batsman";
   		team2_Players.push_back(new Player(playerName,age,"AUS",expertise));
   	}

   	Team* team1 = new Team(team1_Players,"INDIA");
   	Team* team2 = new Team(team2_Players,"AUSTRALIA");

   	team1->getTeamInfo();
   	team2->getTeamInfo();

   	MatchFormat* matchFormat = new OneDay();
   	cout<<matchFormat->totalOver()<<endl;

   	Commentator* commentator1 = new Commentator("Akash");
   	Commentator* commentator2 = new Commentator("Sourav");

   	Commentry* commentry = new Commentry();

   	
   	commentry->getComment(commentator1,"aaaa");
  	commentry->getComment(commentator2,"bbbb");
  	commentry->getComment(commentator1,"cccc");
  	commentry->getComment(commentator2,"dddd");
  
    return 0;
}  

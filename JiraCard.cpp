#include<bits/stdc++.h>

using namespace std;


class StatusHandler{

protected:
    StatusHandler* statusHandler;

public:
    StatusHandler(StatusHandler* statusHandler) : statusHandler(statusHandler) {}
    virtual void printStatus(string cardId) = 0; 
};


class OpenStatus : public StatusHandler{

public:
    OpenStatus(StatusHandler* statusHandler) : StatusHandler(statusHandler) {}

    void printStatus(string cardId){
        cout<<"Card is Open: "<<cardId<<endl;

        if(statusHandler)
        statusHandler->printStatus(cardId);
    }
};

class StatusProgress : public StatusHandler{

public:
    StatusProgress(StatusHandler* statusHandler) : StatusHandler(statusHandler) {}

    void printStatus(string cardId){
        cout<<"Card is in progress: "<<cardId<<endl;

        if(statusHandler)
        statusHandler->printStatus(cardId);
    }
};

class PRraised : public StatusHandler{

public:
    PRraised(StatusHandler* statusHandler) : StatusHandler(statusHandler) {}

    void printStatus(string cardId){
        cout<<"Pr raised for the Card: "<<cardId<<endl;

        if(statusHandler)
        statusHandler->printStatus(cardId);
    }
};

class Resolved : public StatusHandler{

public:
    Resolved(StatusHandler* statusHandler) : StatusHandler(statusHandler) {}

    void printStatus(string cardId){
        cout<<"Card is Resolved: "<<cardId<<endl;

        if(statusHandler)
        statusHandler->printStatus(cardId);
    }
};

class TechQA : public StatusHandler{

public:
    TechQA(StatusHandler* statusHandler) : StatusHandler(statusHandler) {}

    void printStatus(string cardId){
        cout<<"TECH-QA done for the Card: "<<cardId<<endl;

        if(statusHandler)
        statusHandler->printStatus(cardId);
    }
};

class Closed : public StatusHandler{

public:
    Closed(StatusHandler* statusHandler) : StatusHandler(statusHandler) {}

    void printStatus(string cardId){
        cout<<"Card is Closed: "<<cardId<<endl;
    }
};

class ReOpen : public StatusHandler{

public:
    ReOpen(StatusHandler* statusHandler) : StatusHandler(statusHandler) {}

    void printStatus(string cardId){
        cout<<"Card is Re-Opened: "<<cardId<<endl;

        if(statusHandler)
        statusHandler->printStatus(cardId);
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    string cardId = "CMP-112233";
    // StatusHandler* closed = new Closed(nullptr);
    StatusHandler* reOpen = new ReOpen(nullptr);
    StatusHandler* techQA = new TechQA(reOpen);
    StatusHandler* resolved = new Resolved(techQA);
    StatusHandler* pRraised = new PRraised(resolved);
    StatusHandler* statusProgress = new StatusProgress(pRraised);
    StatusHandler* open = new OpenStatus(statusProgress);

    open->printStatus(cardId);
    
    return 0 ;
}

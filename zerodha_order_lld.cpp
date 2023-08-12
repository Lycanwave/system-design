#include<bits/stdc++.h>

using namespace std;


enum class TXN_TYPE{
    BUY,
    SELL
};

enum class ORDER_TYPE{
    MARKET,
    LIMIT
};

enum class EXCH{
    NSE,
    BSE
};

enum class ORDER_STATUS{
    OPEN,
    PARTIALLY_DONE,
    DONE,
    CANCELLED,
};

///////////////////////////////////////////////
//////////// Stocks Details ///////////////////
///////////////////////////////////////////////


class Stock{
    EXCH exch;
    string name;
    double price;

public:
    Stock(string pName,double pPrice,EXCH pExch) : name(pName) , price(pPrice) , exch(pExch){}

    string stocksName(){
        return name;
    }
};

///////////////////////////////////////////////
///////////// Order Details ///////////////////
///////////////////////////////////////////////

class Order {
    TXN_TYPE txnType;
    ORDER_TYPE orderType;
    EXCH exch;
    int qty;
    double price;
    Stock* stock;
    //transaction.
    //ORDER_TYPE status.
    //time.

public:
    Order( TXN_TYPE pTxnType,
    ORDER_TYPE pOrderType,
    EXCH pExch,
    int pQty,
    double pPrice,
    Stock* pStock
    ) : txnType(pTxnType) , orderType(pOrderType) , exch(pExch), qty(pQty) ,price(pPrice),stock(pStock) {}


    TXN_TYPE getTxnType(){
        return txnType;
    }

    string stocksName(){
        return stock->stocksName();
    }
};



///////////////////////////////////////////////
//////////// User Details ///////////////////
///////////////////////////////////////////////



class User {
    string userId;
    //funds.
    //watchlists.
    //portfolio.
public:

    User(string pUserId) : userId(pUserId){}
};


class System{
    static unordered_map<string,User*> users;
public:
    static void AddUser(string userId,User* user);
    static User* getUser(string userId);
};

unordered_map<string,User*> System::users;

void System::AddUser(string userId,User* user){
    users[userId] = user;
}

User* System::getUser(string userId){
    return users[userId];
}



class ExchConnector{
    ExchConnector(){}
    static ExchConnector* exchConnectorInstance;
    static mutex mtx;
public:
    static ExchConnector* getExchConnectorInstance();
    static void sendDataToExch(string userId, Order* order);
};

ExchConnector* ExchConnector::exchConnectorInstance = nullptr;
mutex ExchConnector::mtx;

ExchConnector* ExchConnector::getExchConnectorInstance(){
    if(exchConnectorInstance == nullptr){
        mtx.lock();
        if(exchConnectorInstance == nullptr)
        exchConnectorInstance = new ExchConnector();
        mtx.unlock();
    }
    

    return exchConnectorInstance;
}


void ExchConnector::sendDataToExch(string userId, Order* order){
    cout<<"Order sent to Exchange"<<endl;
}


class OrderValidator{
public:
    bool ValidateOrder(string userId,Order* order){
        User* user = System::getUser(userId);
        if(order->getTxnType() == TXN_TYPE::BUY){
            cout<<"Checking if user has FUNDS to BUY"<<endl;
        }else{
            cout<<"Checking if user has STOCKS to SELL"<<endl;
        }

        cout<<"Assuming user has made valid order request"<<endl;

        return true;
    }
};


class OrderExecutioner {
public:
     void PlaceOrder(string userId,Order* order){
        ExchConnector* exchConnector = ExchConnector::getExchConnectorInstance();
        exchConnector->sendDataToExch(userId,order);
     }
};


class OrderManager {
    OrderValidator* validator;
    OrderExecutioner* executioner;

public:

    OrderManager(){
        validator = new OrderValidator();
        executioner = new OrderExecutioner();
    }

    void PlaceOrder(string userId,Order* order){

        if(validator->ValidateOrder(userId,order)){
            executioner->PlaceOrder(userId,order);
        }else{
            cout<<"Not enough Funds to Place Order: "<<order->stocksName()<<" stocks"<<endl;
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

    User* user = new User("rohit");

    Stock* stock = new Stock("TCS",1000,EXCH::NSE);

    Order* order = new Order(TXN_TYPE::BUY,ORDER_TYPE::LIMIT,EXCH::NSE,2,1100,stock);

    OrderManager* orderManager = new OrderManager();
    orderManager->PlaceOrder("Rohit",order);

    return 0;
}

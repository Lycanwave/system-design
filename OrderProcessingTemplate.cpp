#include<bits/stdc++.h>

using namespace std;

class OrderProcessingTemplate{

public:

    void processOrder(){
        verifyOrder();
        assignDeliveryAgent();
        trackDelivery();
    }

    virtual void verifyOrder() = 0;
    virtual void assignDeliveryAgent() = 0;
    virtual void trackDelivery() = 0;
};

class LocalOrderProcessor : public OrderProcessingTemplate{

public:
    
    void verifyOrder(){
        cout<<"Verifying Local order ..."<<endl;
    }

    void assignDeliveryAgent(){
        cout<<"assignDeliveryAgent Local order ..."<<endl;
    }

    void trackDelivery(){
        cout<<"trackDelivery Local order ..."<<endl;
    }
};

class InternationalOrderProcessor : public OrderProcessingTemplate{

public:

    void verifyOrder(){
        cout<<"Verifying International order ..."<<endl;
    }

    void assignDeliveryAgent(){
        cout<<"assignDeliveryAgent International order ..."<<endl;
    }

    void trackDelivery(){
        cout<<"trackDelivery International order ..."<<endl;
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    OrderProcessingTemplate* localOrder = new LocalOrderProcessor();
    OrderProcessingTemplate* internationalOrder = new InternationalOrderProcessor();

    cout<<"Processing LocalOrder : "<<endl;
    localOrder->processOrder();
    cout<<endl;

    cout<<"Processing International Order: "<<endl;
    internationalOrder->processOrder();
    cout<<endl;

    
    return 0;
}

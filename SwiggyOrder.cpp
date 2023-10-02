#include<bits/stdc++.h>

using namespace std;

class OrderHandler{

protected:
    OrderHandler* nextHandler;

public:
    OrderHandler(OrderHandler* nextHandler) : nextHandler(nextHandler) {}

    virtual void processOrder(string order) = 0;
};

class OrderValidationHandler : public OrderHandler{

public:
    OrderValidationHandler(OrderHandler* nextHandler) : OrderHandler(nextHandler) {}

    void processOrder(string order){
        cout<<"OrderValidationHandler: "<<order<<endl;

        if(nextHandler)
            nextHandler->processOrder(order);
    }
};

class PaymentProcessHandler : public OrderHandler{

public:
    PaymentProcessHandler(OrderHandler* nextHandler) : OrderHandler(nextHandler) {}

    void processOrder(string order){
        cout<<"PaymentProcessHandler: "<<order<<endl;

        if(nextHandler)
            nextHandler->processOrder(order);
    }
};

class OrderPreparationHandler : public OrderHandler{

public:
    OrderPreparationHandler(OrderHandler* nextHandler) : OrderHandler(nextHandler) {}

    void processOrder(string order){
        cout<<"OrderPreparationHandler: "<<order<<endl;

        if(nextHandler)
            nextHandler->processOrder(order);
    }
};

class DeliveryAssignmentHandler : public OrderHandler{

public:
    DeliveryAssignmentHandler(OrderHandler* nextHandler) : OrderHandler(nextHandler) {}

    void processOrder(string order){
        cout<<"DeliveryAssignmentHandler: "<<order<<endl;

        if(nextHandler)
            nextHandler->processOrder(order);
    }
};

class OrderTrackingHandler : public OrderHandler{

public:
    OrderTrackingHandler(OrderHandler* nextHandler) : OrderHandler(nextHandler) {}

    void processOrder(string order){
        cout<<"OrderTrackingHandler: "<<order<<endl;

        if(nextHandler)
            nextHandler->processOrder(order);
    }
};


int main(){

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    // OrderHandler* orderHandler = new OrderValidationHandler(
    //                                 new PaymentProcessHandler(
    //                                     new OrderPreparationHandler(
    //                                         new DeliveryAssignmentHandler(
    //                                             new OrderTrackingHandler(nullptr)))));

    string orderId = "5e79c65af3e02c85090ca688";

    OrderHandler* orderTrackingHandler = new OrderTrackingHandler(nullptr);
    OrderHandler* deliveryAssignmentHandler = new DeliveryAssignmentHandler(orderTrackingHandler);
    OrderHandler* orderPreparationHandler = new OrderPreparationHandler(deliveryAssignmentHandler);
    OrderHandler* paymentProcessHandler = new PaymentProcessHandler(orderPreparationHandler);
    OrderHandler* orderValidationHandler = new OrderValidationHandler(paymentProcessHandler); 

    orderValidationHandler->processOrder(orderId);

    
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

class PaymentStrategy{

public:

    virtual void processPayment(double amount) = 0;
    virtual ~PaymentStrategy(){};
};


class CreditCardStrategy : public PaymentStrategy{

public:

    void processPayment(double amount){
        cout<<"CreditCard deduction amount: "<<amount<<endl;
    }
};


class PaypalStrategy : public PaymentStrategy{

public:

    void processPayment(double amount){
        cout<<"Paypal deduction amount: "<<amount<<endl;
    }
};

class CryptoStrategy : public PaymentStrategy{

public:

    void processPayment(double amount){
        cout<<"Crypto deduction amount: "<<amount<<endl;
    }
};

class PaymentStrategyFactory{

public:

    static PaymentStrategy* createPaymentStrategy(string paymentMethod){

        if(paymentMethod == "CreditCard")
            return new CreditCardStrategy();
        else if (paymentMethod == "PayPal")
            return new PaypalStrategy();
        else if (paymentMethod == "Crypto")
            return new CryptoStrategy();
        else
            return new CreditCardStrategy();   
    }
};

class PaymentProcessor{
private:
    PaymentStrategy* paymentStrategy;

public:

    PaymentProcessor() : paymentStrategy(nullptr) {}

    void setPaymentStrategy(string payment){
        paymentStrategy = PaymentStrategyFactory::createPaymentStrategy(payment);
    }

    void processPayment(double amount){
        if(paymentStrategy)
            paymentStrategy->processPayment(amount);
        else
            cout<<"Payment Strategy to be added"<<endl;
    }

    ~PaymentProcessor(){
        if(paymentStrategy){
            delete paymentStrategy;
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

    PaymentProcessor* paymentProcessor = new PaymentProcessor();
    paymentProcessor->setPaymentStrategy("PayPal");
    paymentProcessor->processPayment(10.00);
    
    return 0;
}

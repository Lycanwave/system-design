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

class PaymentProcessor{
private:
    PaymentStrategy* paymentStrategy;

public:

    PaymentProcessor() : paymentStrategy(nullptr) {}

    void setPaymentStrategy(PaymentStrategy* paymentStrategy){
        this->paymentStrategy = paymentStrategy;
    }

    void processPayment(double amount){
        paymentStrategy->processPayment(amount);
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
    paymentProcessor->setPaymentStrategy(new PaypalStrategy());
    paymentProcessor->processPayment(10.00);
    
    return 0;
}

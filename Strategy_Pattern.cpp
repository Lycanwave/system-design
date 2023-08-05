#include<bits/stdc++.h>

using namespace std;

class DiscountStrategy{
    
public:

    virtual void getDiscount() = 0;
};

class CashbackDiscount : public DiscountStrategy {

public:

    void getDiscount() {
        cout<<"5% cashback"<<endl;
    }
};

class FlatDiscount : public DiscountStrategy {

public:

    void getDiscount(){
        cout<<"Falt Discount of 500"<<endl;
    }
};

class CouponDiscount : public DiscountStrategy {

public:

    void getDiscount(){
        cout<<"Coupon Discount"<<endl;
    }
};

class NoDiscount : public DiscountStrategy {

public:

    void getDiscount(){
        cout<<"No Discount"<<endl;
    }
};

class ApplyDiscount {

    DiscountStrategy* discountStrategy;

public:
    ApplyDiscount(DiscountStrategy* itemForDiscount){
        discountStrategy = itemForDiscount;
    }



    void showCouponStatus(){

        discountStrategy->getDiscount();
    }

};


int main(){

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    ApplyDiscount* applyDiscount = new ApplyDiscount(new FlatDiscount());
    applyDiscount->showCouponStatus();
    
    return 0;
}

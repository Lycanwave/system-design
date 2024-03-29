#include<bits/stdc++.h>

using namespace std;

class BronzeCreditCard;
class SilverCreditCard;
class GoldCreditCard;

class OfferVisitor{

public:
    virtual void visit(BronzeCreditCard* bronzeCreditCard) = 0;

    virtual void visit(SilverCreditCard* silverCreditCard) = 0;

    virtual void visit(GoldCreditCard* goldCreditCard) = 0;
};

// CREDIR CARD



public:
    virtual void accept(OfferVisitor* visitor) = 0;
};

class BronzeCreditCard : public CreditCard{

public:
  void accept(OfferVisitor* visitor){
    visitor->visit(this);
  }
};

class SilverCreditCard : public CreditCard{

public:
  void accept(OfferVisitor* visitor){
    visitor->visit(this);
  }
};

class GoldCreditCard : public CreditCard{

public:
  void accept(OfferVisitor* visitor){
    visitor->visit(this);
  }
};

// BILLS

class PhoneBillOfferVisitor : public OfferVisitor{

public:
  void visit(BronzeCreditCard* bronzeCreditCard){
    cout<<"phone Bronze 10 off"<<endl;
  }

  void visit(SilverCreditCard* silverCreditCard){
    cout<<"phone silver 20 off"<<endl;
  }

  void visit(GoldCreditCard* goldCreditCard){
    cout<<"phone gold 30 off"<<endl;
  }
};

class ShoppingBillOfferVisitor : public OfferVisitor{

public:
  void visit(BronzeCreditCard* bronzeCreditCard){
    cout<<"shop bronze 10 off"<<endl;
  }

  void visit(SilverCreditCard* silverCreditCard){
    cout<<"shop silver 20 off"<<endl;
  }

  void visit(GoldCreditCard* goldCreditCard){
    cout<<"shop gold 30 off"<<endl;
  }
};

class TravelBillOfferVisitor : public OfferVisitor{

public:
  void visit(BronzeCreditCard* bronzeCreditCard){
    cout<<"travel bronze 10 off"<<endl;
  }

  void visit(SilverCreditCard* silverCreditCard){
    cout<<"travel silver 20 off"<<endl;
  }

  void visit(GoldCreditCard* goldCreditCard){
    cout<<"travel gold 30 off"<<endl;
  }
};

int main(){

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    CreditCard* bronzeCreditCard = new BronzeCreditCard();
    CreditCard* silverCreditCard = new SilverCreditCard();
    CreditCard* goldCreditCard = new GoldCreditCard();

    OfferVisitor* phoneBillOfferVisitor = new PhoneBillOfferVisitor();
    bronzeCreditCard->accept(phoneBillOfferVisitor);
    silverCreditCard->accept(phoneBillOfferVisitor);
    goldCreditCard->accept(phoneBillOfferVisitor);

}

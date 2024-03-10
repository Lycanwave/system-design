#include<bits/stdc++.h>

using namespace std;

class PackageState;

 // Package

class Package {

	PackageState* packageState;
public:

	Package();

	void nextState();
	void previousState();
	void displayInfo();
	void setState(PackageState* packageState);
};

class PackageState{

public: 

	virtual void nextState(Package* pkg) = 0;

    virtual void previousState(Package* pkg) = 0;

    virtual void displayInfo(Package* pkg) = 0;
};

// Order States

class OrderState : public PackageState{
public:

	void nextState(Package* pkg);
    void previousState(Package* pkg);
    void displayInfo(Package* pkg);

};

class ShippingState : public PackageState{

public:

	void nextState(Package* pkg);
    void previousState(Package* pkg);
    void displayInfo(Package* pkg);

};

class OutForDeliveryState : public PackageState{

public:

	void nextState(Package* pkg);
    void previousState(Package* pkg);
    void displayInfo(Package* pkg);

};



class DeliveredState : public PackageState{

public:

	void nextState(Package* pkg);
    void previousState(Package* pkg);
    void displayInfo(Package* pkg);

};


Package::Package(){
	packageState = new OrderState();
}

void Package::nextState(){
	packageState->nextState(this);
}

void Package::previousState(){
	packageState->previousState(this);
}

void Package::displayInfo()	{
	packageState->displayInfo(this);
}

void Package::setState(PackageState* packageState) {
	this->packageState = packageState;
}




// Order State Implementations

void OrderState::nextState(Package* pkg) {
    pkg->setState(new ShippingState());
}

void OrderState::previousState(Package* pkg) {
    cout << "No Previous State" << endl;
}

void OrderState::displayInfo(Package* pkg) {
    cout << "Package Ordered" << endl;
}

void ShippingState::nextState(Package* pkg) {
    pkg->setState(new OutForDeliveryState());
}

void ShippingState::previousState(Package* pkg) {
    pkg->setState(new OrderState());
}

void ShippingState::displayInfo(Package* pkg) {
    cout << "Shipping state" << endl;
}

void OutForDeliveryState::nextState(Package* pkg) {
    pkg->setState(new DeliveredState());
}

void OutForDeliveryState::previousState(Package* pkg) {
    pkg->setState(new ShippingState());
}

void OutForDeliveryState::displayInfo(Package* pkg) {
    cout << "Out for Delivery " << endl;
}

void DeliveredState::nextState(Package* pkg) {
    cout << "No further state" << endl;
}

void DeliveredState::previousState(Package* pkg) {
    pkg->setState(new OutForDeliveryState());
}

void DeliveredState::displayInfo(Package* pkg) {
    cout << "Order Delivered" << endl;
}


int main(){

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

   	Package* package = new Package();

   	package->displayInfo();
   	package->nextState();

   	package->displayInfo();
   	package->nextState();

   	package->displayInfo();
   	package->nextState();

   	package->displayInfo();
   	package->nextState();

}

#include<bits/stdc++.h>

using namespace std;



class Vehicle {

public: 
    virtual void createVehicle() = 0;
};


class Car:public Vehicle{
public:
    void createVehicle();
};

class Bike : public Vehicle{
public: 
    void createVehicle();
};

void Bike::createVehicle(){
    cout<<"Bike Created"<<endl;
}

void Car::createVehicle(){
    cout<<"Car Created"<<endl;
}

class VehicleFactory{
     public:
        //static because - Don't have to create object to access the function 
        static Vehicle* getVehicle(string vehicleType);
};

Vehicle* VehicleFactory::getVehicle(string vehicleType){
    Vehicle* vehicle;
     if(vehicleType == "car"){
        vehicle = new Car();
    }else if(vehicleType == "bike"){
        vehicle = new Bike();
    }

    return vehicle;
}

int main(){

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    string vehicleType = "car";
    // cin>>vehicleType;

    Vehicle *vehicle = VehicleFactory::getVehicle(vehicleType);   

    // cout<<vehicleType<<endl;

    vehicle->createVehicle();
    
    return 0;
}

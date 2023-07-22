#include<bits/stdc++.h>

using namespace std;

class Payment{

public:
    virtual double calculateCost(double hours) = 0;
};

class CarPayment : public Payment{

public:

    double calculateCost(double hours){
        return hours * 2;
    }
};

class BikePayment : public Payment{

public:

    double calculateCost(double hours){
        return hours * 1;
    }
};

class HandicappedPayment : public Payment{

public:

    double calculateCost(double hours){
        return 0;
    }
};

class Vehicle{
protected:
     Payment *payment;
     std::chrono::time_point<std::chrono::system_clock> parkedTime;

 public:
    virtual string getType() = 0;
    virtual double calculateCost(double hours){
        return payment->calculateCost(hours);
    }

    void setParkedTime(){
        parkedTime = std::chrono::system_clock::now();
    }

    std::chrono::time_point<std::chrono::system_clock> getParkedTime(){
        return  parkedTime;
    }
};


class Car : public Vehicle{

public:
    Car(){
        payment = new CarPayment();
        
    }
    string getType(){
        return "Car";
    }
};


class Bike : public Vehicle{

public:
    Bike(){
        payment = new BikePayment();
    }

    string getType(){
        return "Bike";
    }
};

class HandicappedVehicle : public Vehicle{

public:
    HandicappedVehicle(){
        payment = new HandicappedPayment();
    }

    string getType(){
        return "Handicapped";
    }
};

class ParkingLot{

private:
    vector<vector<vector<Vehicle*>>> spots;
    int floors;
    int rows;
    int spotsPerRow;

public: 

    ParkingLot(int floor,int row,int spotsPerRow){
        this->floors = floor;
        this->rows = row;
        this->spotsPerRow = spotsPerRow;

        spots.resize(floor);

        for(int i=0;i<floor;i++){
            spots[i].resize(rows);
            for(int j=0;j<rows;j++){
                spots[i][j].resize(spotsPerRow);
            }
        }
    }

    bool park(Vehicle* v,int floors,int row,int spot){

        if(spots[floors][row][spot] == nullptr){
            spots[floors][row][spot] = v;
            cout << v->getType() << " parked successfully at floor " << floors << ", row " << row << ", spot " << spot << "." << endl;
           return true;
        }else{
            cout<<" Spot already occupied "<<endl;
            return false;
        }

        return false;
    }


    int availableSpots(int floor){

        int count=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<spotsPerRow;j++){
                if(spots[floor][i][j] == nullptr)
                    count++;
            }
        }

        return count;
    }

    int handicappedSpots(int floor){

         int count=0;
         for(int i=0;i<rows;i++){
            for(int j=0;j<spotsPerRow;j++){
                // if(dynamic_cast<HandicappedVehicle*> (spots[floor][i][j] != nullptr))
                //     count++;

                if(spots[floor][i][j]!=nullptr && spots[floor][i][j]->getType() == "Handicapped")
                    count++;
            }
         }

         return count;
    }

    double calculateHoursParked(Vehicle *v){

        for(int i=0;i<floors;i++){
            for(int j=0;j<rows;j++){
                for(int k=0;k<spotsPerRow;k++){

                    if(spots[i][j][k] == v){
                        auto now = std::chrono::system_clock::now();
                        auto parkedTime = spots[i][j][k]->getParkedTime();
                        auto duration = std::chrono::duration_cast<std::chrono::hours>(now - parkedTime);

                        return duration.count();
                    }
                }
            }
        }

        return 0;
    }

    bool leave(Vehicle* v){
          for (int i = 0; i < floors; i++) {
            for (int j = 0; j < rows; j++) {
                for (int k = 0; k < spotsPerRow; k++) {

                    if(spots[i][j][k] == v){
                        double hours = calculateHoursParked(v);
                        double cost = v->calculateCost(hours);
                        spots[i][j][k] = nullptr;
                        cout<<v->getType()<<" left succecssfully. Total cost: "<<cost<<endl;
                        return true;
                    }
                }
            }
        }

        cout<<v->getType()<<" not found"<<endl;

        return false;
    }

};


int main(){

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    ParkingLot lot(3, 10, 20);
    Car car1, car2;
    Bike bike1, bike2;
    HandicappedVehicle hv1;

    car1.setParkedTime();
    lot.park(&car1, 0, 0, 0);
    car2.setParkedTime();
    lot.park(&car2, 0, 0, 1);
    bike1.setParkedTime();
    lot.park(&bike1, 0, 0, 2);
    hv1.setParkedTime();
    lot.park(&hv1, 2, 9, 19);

    cout << "Available spots on floor 0: " << lot.availableSpots(0) << endl;
    cout << "Handicapped spots on floor 2: " << lot.handicappedSpots(2) << endl;

    // this_thread::sleep_for(chrono::milliseconds(5000));
    lot.leave(&car1);
    lot.leave(&bike2);

    cout << "Available spots on floor 0: " << lot.availableSpots(0) << endl;


    
    return 0;
}

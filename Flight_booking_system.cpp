#include<bits/stdc++.h>

using namespace std;

enum FlightStatus {
	DEPARTED,
	ARRIVED,
	ONBOARDING,
	ON_AIR
};

enum BookingStatus{
	BOOKING_INITIATED,
	BOOKING_FAILED,
	PAYMENT_INITIATED,
	PAYMENT_CONFIRMED,
	RESCHEDULE_INITIATED,
	RESCHEDULE_CONFIRMED,
	CANCELLATION_REQUEST,
	CANCELLED,
	BOOKED,
};




// USER

class User{
	string name;
	string email;
	string 
public:

}

// FLIGHT

class Flight{

private:
	string flightName;
	string flightNumber;
	string source;
	string destination;
	int duration;
	vector<vector<bool>> seats;
public:
};

// FLIGHT BRAND

class Boeing : public Flight{

public:
};

class Airbus : public Flight{

public:
};

//FLIGHT TYPE IN AIRBUS PLANE

class SmallSizeAirbusPlane : public Airbus{

public:
	// 6 * 10
	SmallSizeAirbusPlane(){
		this->seats.resize(6,vector<bool>(10,0));
	}

	SmallSizeAirbusPlane(int row,int col){
		this->seats.resize(row,vector<bool>(col,0));
	}
};

class MediumSizeAirbusPlane : public Airbus{

public:
	// 6 * 10
	MediumSizeAirbusPlane(){
		this->seats.resize(6,vector<bool>(10,0));
	}

	MediumSizeAirbusPlane(int row,int col){
		this->seats.resize(row,vector<bool>(col,0));
	}
};

class LargeSizeAirbusPlane : public Airbus{

public:
	// 9 * 15
	LargeSizeAirbusPlane(){
		this->seats.resize(9,vector<bool>(15,0));
	}

	LargeSizeAirbusPlane(int row,int col){
		this->seats.resize(row,vector<bool>(col,0));
	}
};

//FLIGHT TYPE IN BOEING PLANE

class SmallSizeBoeingPlane : public Boeing{

public:
	// 6 * 10
	SmallSizeBoeingPlane(){
		this->seats.resize(6,vector<bool>(10,0));
	}

	SmallSizeBoeingPlane(int row,int col){
		this->seats.resize(row,vector<bool>(col,0));
	}
};

class MediumSizeBoeingPlane : public Boeing{

public:
	// 6 * 10
	MediumSizeBoeingPlane(){
		this->seats.resize(6,vector<bool>(10,0));
	}

	MediumSizeBoeingPlane(int row,int col){
		this->seats.resize(row,vector<bool>(col,0));
	}
};

class LargeSizeBoeingPlane : public Boeing{

public:
	// 9 * 15
	LargeSizeBoeingPlane(){
		this->seats.resize(9,vector<bool>(15,0));
	}

	LargeSizeBoeingPlane(int row,int col){
		this->seats.resize(row,vector<bool>(col,0));
	}
};

// BOOKING DETAILS

class BookingDetails{
	string age;
	string pnr;
	string name;
	int duration;
	double price;
	string email;
	string seatNo;
	string source;
	string flightName;
	string destination;
	string flightNumber;
	BookingStatus bookingStatus;	
public:

	printDetail(){
		cout<<"Name: "<<name<<endl;
		cout<<"Age: "<<age<<endl;
		cout<<"E-mail: "<<email<<endl;
		cout<<"Duration: "<<duration<<endl;
		cout<<"PNR: "<<pnr<<endl;
		cout<<"Price: "<<price<<endl;
		cout<<"Source: "<<source<<endl;
		cout<<"Destination: "<<destination<<endl;
		cout<<"Flight No: "<<flightNumber<<endl
		cout<<"Flight Name: "<<flightName<<endl;
		cout<<"Booking Status: "<<bookingStatus<<endl;
	}

	setBookingStatus(BookingStatus bookingStatus){
		this->bookingStatus = bookingStatus;
	}

}

// BOOKING

class Booking{
public:
	virtual void execute(BookingDetails* bookingDetails) = 0;
};

class Book : public Booking{
public:
	void execute(BookingDetails* bookingDetails){
		bookingDetails->setBookingStatus(BookingStatus::BOOKING_INITIATED);
		bookingDetails->printDetail();
	}
};

class Cancel : public Booking{
public:
	void execute(BookingDetails* bookingDetails){
		bookingDetails->setBookingStatus(BookingStatus::CANCELLATION_REQUEST);
		bookingDetails->printDetail();
	}
};

class Reschedule : public Booking{
public:
	void execute(BookingDetails* bookingDetails){
		bookingDetails->setBookingStatus(BookingStatus::RESCHEDULE_INITIATED);
		bookingDetails->printDetail();
	}
};

// BOOKING MANAGER

// TWO OPTIONS :- 
// 1 -> USE FACTORY METHOD.
// 2 -> DIRECTLY USE THE CLASS.
class BookingManger{
	Booking* booking;
public:
	void bookingMgr(BookingDetails* bookingDetails,string requestType){

		if(requestType == "booking")
			return new Book();
		else if(requestType == "cancel")
			return new Cancel();
		else
			return new Reschedule();
	}
};

int main(){

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif


   
    return 0;
}  

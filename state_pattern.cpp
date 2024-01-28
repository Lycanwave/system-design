#include<bits/stdc++.h>

using namespace std;

// STATE DESIGN PATTERN

class MobileAlertState {

public:
	virtual void alert() = 0;
};

class Vibration : public MobileAlertState{

public:

	void alert(){
		cout<<"Vibration"<<endl;
	}
};

class Silent : public MobileAlertState{

public:

	void alert(){
		cout<<"Silent"<<endl;
	}
};

// CONTEXT

class AlertStateContext{

private:
	MobileAlertState *mobileAlertState;

public:
	AlertStateContext(){
		mobileAlertState = new Vibration();
	}

	void setState(MobileAlertState* state){
		mobileAlertState = state;
	}

	void alert(){
		mobileAlertState->alert();
	}
};

int main(){

	 #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

   	AlertStateContext stateContext;
   	stateContext.alert();
   	stateContext.alert();
   	stateContext.setState(new Silent());
   	stateContext.alert();


}

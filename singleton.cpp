#include<bits/stdc++.h>

using namespace std;

class Logger{
    static int counter;
    static Logger* loggerInstance;

    //Using mutex to make it compatible with multiThreading.
    static mutex mtx;

    //making copy constructor private.
    Logger(const Logger &);

    //making  equal to operator overloading private 
    //It will help in not assigning or makeing the copy
    //of the instance.
    Logger operator=(const Logger &);


    Logger();

public:
    
    static Logger* getLogger();

    void Log(string message){
        cout<<message<<endl;
    }
};

int Logger::counter=0;
Logger* Logger::loggerInstance = nullptr;
mutex Logger::mtx;

Logger::Logger(){
    counter++;
    cout<<"New Instance created. No of instances"<<counter<<endl;
}

Logger *Logger::getLogger(){

    //Here the Logger Instance fails when we use multiThreading.
    //To Safeguard it from creating more then one instance during multiThreading 
    //We will use MUTEX 

    //Here we have used double check 
    //one before applying the lock and 
    //another after applying the lock
    //because lock is very expensive

    if(loggerInstance == nullptr){
         mtx.lock();
        if(loggerInstance == nullptr){
            loggerInstance = new Logger();
        }
        mtx.unlock();
    }
   

    return loggerInstance;
}



void user1Logs(){
    Logger* logger1 = Logger::getLogger();
    logger1->Log("This message is from Logger 1");
}


void user2Logs(){
    Logger* logger2 = Logger::getLogger();
    logger2->Log("This message is from Logger 2");
}


int main(){

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    ///////////////////////////////////////
    ///This case Fails at multiThreading///
    ///////////////////////////////////////

    // Logger* logger1 = Logger::getLogger();
    // logger1->Log("This message is from Logger 1");
    // Logger* logger2 = Logger::getLogger();
    // logger2->Log("This message is from Logger 2");

    ///////////////////////////////////////
    ///example - Fails at multiThreading///
    ///////////////////////////////////////

    thread t1(user1Logs);
    thread t2(user2Logs);

    t1.join();
    t2.join();

    
    return 0;
}

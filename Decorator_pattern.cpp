#include<bits/stdc++.h>

using namespace std;

//UML Diagram - https://media.geeksforgeeks.org/wp-content/uploads/uml-1.jpg

//For better understanding of code follow UML diagram (in the top (below using namespace std) and bottom of this page );

class Pizza {

public:

    virtual string getDescription() = 0;
    virtual int getCost() = 0;
};

// Base of the Pizza.
// Types : PeppyPaneer , FarmHouse, Margherita, ChickenFiesta

class PeppyPaneer : public Pizza {

public:

    string getDescription(){
        return "PeppyPaneer Pizza";
    }

    int getCost(){
        return 120;
    }

};

class FarmHouse : public Pizza {

public:

    string getDescription(){
        return "FarmHouse Pizza";
    }

    int getCost(){
        return 110;
    }

};


class MargeritaPizza : public Pizza {

public:

    string getDescription(){
        return "Margerita Pizza";
    }

    int getCost(){
        return 100;
    }

};

class ChickenFiesta : public Pizza {

public:

    string getDescription(){
        return "ChickenFiesta Pizza";
    }

    int getCost(){
        return 130;
    }

};



//Decorator


class PizzaDecorator : public Pizza {

protected:
    Pizza* pizza;

public:

    PizzaDecorator(Pizza* basePizza) : pizza(basePizza) {}

    string getDescription(){
        return pizza->getDescription();
    }

    int getCost(){
        return pizza->getCost();
    }

};


//Toppings

class FreshTomato : public PizzaDecorator {

public:

    FreshTomato(Pizza *basePizza) : PizzaDecorator(basePizza) {}

    string getDescription(){
        return pizza -> getDescription() + " Tomato added";
    }

    int getCost(){
        return pizza->getCost() + 30;
    }

};

class Paneer : public PizzaDecorator {

public:

    Paneer(Pizza *basePizza) : PizzaDecorator(basePizza) {}

    string getDescription(){
        return pizza -> getDescription() + " Paneer added";
    }

    int getCost(){
        return pizza->getCost() + 50;
    }

};

class Jalapeno : public PizzaDecorator {

public:

    Jalapeno(Pizza *basePizza) : PizzaDecorator(basePizza) {}

    string getDescription(){
        return pizza -> getDescription() + " Jalapeno added";
    }

    int getCost(){
        return pizza->getCost() + 70;
    }

};

class Barbeque : public PizzaDecorator {

public:

    Barbeque(Pizza *basePizza) : PizzaDecorator(basePizza) {}

    string getDescription(){
        return pizza -> getDescription() + " Barbeque added";
    }

    int getCost(){
        return pizza->getCost() + 90;
    }

};




int main(){

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    //Type 1 

    Pizza *pizza = new MargeritaPizza();
    cout<<"Base of Pizza: "<<pizza->getDescription()<<endl;
    cout<<"Cost of Base Pizza: "<<pizza->getCost()<<endl;

    Pizza *toppings = new FreshTomato(pizza);
    toppings = new Paneer(toppings);
    toppings = new Jalapeno(toppings);
    toppings = new Barbeque(toppings);
    cout<<"Toppings name: "<<toppings->getDescription()<<endl;
    cout<<"Total Price: "<<toppings->getCost()<<endl;

    cout<<endl<<endl;

    //Type 2

    Pizza *pizza1 = new FarmHouse();
    cout<<"Base of Pizza: "<<pizza1->getDescription()<<endl;
    cout<<"Cost of Base Pizza: "<<pizza1->getCost()<<endl;

    Pizza *toppings1 = new FreshTomato(pizza1);
    toppings1 = new Paneer(toppings1);
    toppings1 = new Jalapeno(toppings1);
    toppings1 = new Barbeque(toppings1);
    cout<<"Toppings name: "<<toppings1->getDescription()<<endl;
    cout<<"Total Price: "<<toppings1->getCost()<<endl;



    
    return 0;
}

//UML Diagram - https://media.geeksforgeeks.org/wp-content/uploads/uml-1.jpg

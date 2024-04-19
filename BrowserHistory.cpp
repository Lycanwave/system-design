#include<bits/stdc++.h>

using namespace std;

// Forward declaration of ListIterator
template<typename T>
class ListIterator;

template<typename T>
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual T next() = 0;
};

template<typename T>
class BrowserHistory {
    vector<T> urls;

public:
    BrowserHistory() {}

    void push(T url) {
        urls.push_back(url);
    }

    T pop() {
        T data = urls.back();
        urls.pop_back();
        return data;
    }

    std::list<T> getUrls() {
        return urls;
    }

    T getAtIndex(int index) {
        return urls[index];
    }

    int size() {
        return urls.size();
    }

    Iterator<T>* createIterator();
};

template<typename T>
class ListIterator : public Iterator<T> {
    BrowserHistory<T>& browserHistory;
    int index;

public:
    ListIterator(BrowserHistory<T>& browserHistory) : browserHistory(browserHistory), index(0) {}

    bool hasNext() override {
        return index < browserHistory.size();
    }

    T next() override {
        return browserHistory.getAtIndex(index++);
    }
};

template<typename T>
Iterator<T>* BrowserHistory<T>::createIterator() {
    return new ListIterator<T>(*this);
}




int main(){

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    BrowserHistory<string> browserHistory;
    browserHistory.push("ab");
    browserHistory.push("bc");
    browserHistory.push("cd");

    Iterator<std::string>* it = browserHistory.createIterator();
    while (it->hasNext()) {
      cout << it->next() << endl;
    }

}

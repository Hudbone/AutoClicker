#ifndef AUTOCLICKERVER1_0_AUTOCLICKER_H
#define AUTOCLICKERVER1_0_AUTOCLICKER_H
#include <iostream>
using namespace std;

class AutoClicker {
    friend ostream& operator<<(ostream&, const AutoClicker&);
private:
    int xPos;
    int yPos;
    int ms;
    bool active;
public:
    int GetMS() const;
    void SetMS(int);
    void SetActive(bool);
    bool GetActive() const;
    void SetxPos(int);
    void SetyPos(int);
    int GetxPos() const;
    int GetyPos() const;
    AutoClicker();
    void click();
};


#endif

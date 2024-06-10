#ifndef TEST3_PRODUKT_H
#define TEST3_PRODUKT_H

#include <string>

using namespace std;

class Produkt{
public:
    Produkt(int setId, string setTitel);
    virtual string toString();
    string getTitel();
    void setTitel(string s);
protected:
    int id;
    string titel;
};
ostream& operator << (ostream &o, Produkt p);

class Dvd: public Produkt{
public:
    Dvd(int setId, string setTitel, int setLaufzeit);
    string toString() override;
private:
    int laufzeit;
};
ostream& operator << (ostream &o, Dvd d);

class Bluray: public Produkt{
public:
    Bluray(int setId, string setTitel, int setNumTracks, string setAufloesung);
    string toString() override;
private:
    int numTracks;
    string aufloesung;
};
ostream& operator << (ostream &o, Bluray b);

#endif

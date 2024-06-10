#ifndef TEST3_KUNDE_H
#define TEST3_KUNDE_H

#include <string>

using namespace std;

class Kunde{
public:
    Kunde(int setId, string setName, string setVorname, string setAdresse, int setHausnummer, int setPostleitzahl, string setOrt);
    string toString();
private:
    int id;
    string name;
    string vorname;
    string adresse;
    int hausnummer;
    int postleitzahl;
    string ort;
};
ostream& operator << (ostream &o, Kunde k);

#endif

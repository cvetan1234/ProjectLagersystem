#include "Kunde.h"

Kunde::Kunde(int setId, string setName, string setVorname, string setAdresse, int setHausnummer, int setPostleitzahl, string setOrt): id(setId), name(setName), vorname(setVorname), adresse(setAdresse), hausnummer(setHausnummer), postleitzahl(setPostleitzahl), ort(setOrt){}

//return string representation
string Kunde::toString(){
    return "Kunde " + to_string(id) + " " + name + " " + vorname + " " + adresse + " " + to_string(hausnummer) + " " + to_string(postleitzahl) + " " + ort;
}

ostream& operator << ( ostream &o, Kunde k) { //overload the output operator
    o << k.toString();
    return o;
}

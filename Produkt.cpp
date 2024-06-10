#include "Produkt.h"

Produkt::Produkt(int setId, string setTitel): id(setId), titel(setTitel){}

string Produkt::toString(){
    return "Produkt " + to_string(id) + " " + titel; //return string representation
}

string Produkt::getTitel(){
    return titel;
}

void Produkt::setTitel(string s){
    titel = s;
}

ostream& operator << (ostream &o, Produkt p) { //overload the output operator
    o << p.toString();
    return o;
}

Dvd::Dvd(int setId, string setTitel, int setLaufzeit): Produkt(setId, setTitel), laufzeit(setLaufzeit){}

string Dvd::toString(){
    return "DVD " + to_string(id) + " " + titel + " " + to_string(laufzeit); //string representation
}

ostream& operator << (ostream &o, Dvd d) { //overload the output operator
    o << d.toString();
    return o;
}

Bluray::Bluray(int setId, string setTitel, int setNumTracks, string setAufloesung): Produkt(setId, setTitel), numTracks(setNumTracks), aufloesung(setAufloesung){}

string Bluray::toString(){
    return "Bluray " + to_string(id) + " " + titel + " " + to_string(numTracks) + " " + aufloesung; //string representation
}

ostream& operator << (ostream &o, Bluray b) { //overload the output operator
    o << b.toString();
    return o;
}

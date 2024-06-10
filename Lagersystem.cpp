#include <iostream>

#include "Lagersystem.h"

Lagersystem::Lagersystem(){}

void Lagersystem::addKunde(int id, string name, string vorname, string adresse, int hausnummer, int postleitzahl, string ort){
    Kunde k(id, name, vorname, adresse, hausnummer, postleitzahl, ort);
    shared_ptr<Kunde> ptr = make_shared<Kunde>(k); //create the object dynamically
    kundenList.insert({id, ptr});
}

void Lagersystem::addDvd(int id, string titel, int laufzeit){
    Dvd d(id, titel, laufzeit);
    shared_ptr<Dvd> ptr = make_shared<Dvd>(d); //create the object dynamically
    produktkatalog.insert({id, ptr});
}

void Lagersystem::addBluray(int id, string titel, int numTracks, string aufloesung){
    Bluray b(id, titel, numTracks, aufloesung);
    shared_ptr<Bluray> ptr = make_shared<Bluray>(b); //create the object dynamically
    produktkatalog.insert({id, ptr});
}

void Lagersystem::addLagerbestand(int id, int anzahl){
    lagerbestand.insert({id, anzahl});
}

void Lagersystem::printKunden(){
    for (auto it = kundenList.begin(); it != kundenList.end(); it++) {
        cout << (it->second)->toString() << endl; //iterate through the map and call print function of each object
    }
}

void Lagersystem::printProduktkatalog(){
    for (auto it = produktkatalog.begin(); it != produktkatalog.end(); it++) {
        cout << (it->second)->toString() << endl; //iterate through the map and call print function of each object
    }
}

void Lagersystem::printLagerbestand() {
    for (auto it = lagerbestand.begin(); it != lagerbestand.end(); it++) {
        auto productIt = produktkatalog.find(it->first);
        shared_ptr<Produkt> product = productIt->second;
        cout << "Lager " << it->first << " " << it->second << " " << product->getTitel() << endl; //print also the name of the product
    }
}

string Lagersystem::toStringAll(){
    string s;
    for (auto it = kundenList.begin(); it != kundenList.end(); it++) {
        s += (it->second)->toString() + "\n"; //call each elements toString function
    }
    for (auto it = produktkatalog.begin(); it != produktkatalog.end(); it++) {
        shared_ptr<Produkt> p = it->second;
        p->setTitel(addRemoveSpaces(p->getTitel(), 0)); //add underlines in the title
        s += p->toString() + "\n";
        p->setTitel(addRemoveSpaces(p->getTitel(), 1)); //restore the object (change the underlines back to spaces)
    }
    for (auto it = lagerbestand.begin(); it != lagerbestand.end(); it++) {
        s += "Lager " + to_string(it->first) + " " + to_string(it->second) + "\n";
    }
    return s;
}

map<int, shared_ptr<Kunde>> Lagersystem::getKundenList(){ //store the clients in a map, where the id of the object is the key
    return kundenList;
}

map<int, shared_ptr<Produkt>> Lagersystem::getProduktkatalog(){ //store the products in a map, where the id of the product is the key
    return produktkatalog;
}

map<int, int> Lagersystem::getLagerbestand(){ //the id of the stored product is the key, the number of products is the value
    return lagerbestand;
}

string Lagersystem::addRemoveSpaces(string s, bool b) { //function to change the spaces to underlines and back
    if (b) {
        for (int n = 0; n < s.length(); n++) {
            if (s[n] == '_') {
                s[n] = ' ';
            }
        }
    } else {
        for (int n = 0; n < s.length(); n++) {
            if (s[n] == ' ') {
                s[n] = '_';
            }
        }
    }
    return s;
}

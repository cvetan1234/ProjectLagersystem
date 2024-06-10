#ifndef TEST3_LAGERSYSTEM_H
#define TEST3_LAGERSYSTEM_H

#include <memory>
#include <map>

class Lagersystem{
public:
    Lagersystem();
    void addKunde(int id, string name, string vorname, string adresse, int hausnummer, int postleitzahl, string ort);
    void addDvd(int id, string titel, int laufzeit);
    void addBluray(int id, string titel, int numTracks, string aufloesung);
    void addLagerbestand(int id, int anzahl);
    void printKunden();
    void printProduktkatalog();
    void printLagerbestand();
    string toStringAll();
    map<int, shared_ptr<Kunde>> getKundenList();
    map<int, shared_ptr<Produkt>> getProduktkatalog();
    map<int, int> getLagerbestand();
private:
    map<int, shared_ptr<Kunde>> kundenList;
    map<int, shared_ptr<Produkt>> produktkatalog;
    map<int, int> lagerbestand;
    string addRemoveSpaces(string s, bool b);
};

#endif

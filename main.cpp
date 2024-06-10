#include "Kunde.cpp"
#include "Produkt.cpp"
#include "Exceptions.cpp"
#include "Lagersystem.cpp"
#include "FileStore.cpp"

int main() {
    Lagersystem l;
    FileStore r(l);
    r.readFile("acme.load");
    l.printKunden();
    l.printProduktkatalog();
    l.printLagerbestand();
    r.exportFile("export.txt");
    return 0;
}

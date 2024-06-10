#include <fstream>
#include <sstream>

#include "FileStore.h"

FileStore::FileStore(Lagersystem& setLagersystem): l(setLagersystem){};

void FileStore::readFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Error opening file: " + filename);
    }

    string line;

    while (getline(file, line)) {
        if (!line.empty()) {
            try {
                string type;
                type = divideByFirstSpace(line).at(0); //find  the type of the object

                if (type == "Kunde") {
                    parseKunde(divideByFirstSpace(line).at(1)); //give the string without the object type to the parse function
                } else if (type == "DVD") {
                    parseDvd(divideByFirstSpace(line).at(1));
                } else if (type == "Bluray") {
                    parseBluray(divideByFirstSpace(line).at(1));
                } else if (type == "Lager") {
                    parseLagerbestand(divideByFirstSpace(line).at(1));
                }
            }catch(IdOutOfRangeException e){
                cerr << e.what() << "; Line: " + line << endl; //catch the exceptions and print the errors
            }catch(IdDuplicateException e){
                cerr << e.what() << "; Line: " + line << endl;
            }catch(InvalidArgumentsException e){
                cerr << e.what() << "; Line: " + line << endl;
            }catch(NonExistendProduktException e){
                cerr << e.what() << "; Line: " + line << endl;
            }catch(exception e){
                cerr << "Other exception" << "; Line: " + line << endl;
            }
        }
    }
    file.close();
}

void FileStore::exportFile(string fileName){
    ofstream expFile(fileName);
    expFile << l.toStringAll(); //export the file, using the toStringAll method of Lagersystem
    expFile.close();
}

void FileStore::parseKunde(string s){
    vector<string> splitS = splitString(s);
    map<int, shared_ptr<Kunde>> kundenList = l.getKundenList();
    int id;
    try {
        id = stoi(splitS.at(0)); //check if the id can be converted to int
    }catch (exception e){
        throw IdOutOfRangeException();
    }
    if (kundenList.find(id) != kundenList.end()){
        throw IdDuplicateException(); //check if the id is already in the map
    }
    try {
        l.addKunde(id, splitS.at(1), splitS.at(2), splitS.at(3), stoi(splitS.at(4)),
                   stoi(splitS.at(5)), splitS.at(6)); //check if the arguments are of the correct datatypes, the correct number; add the object to the map
    }catch (exception e){
        throw InvalidArgumentsException();
    }
}

void FileStore::parseDvd(string s){
    vector<string> splitS = splitString(s);
    splitS.at(1) = addRemoveSpaces(splitS.at(1), 1); //replace the underlines in the title with spaces
    map<int, shared_ptr<Produkt>> produktkatalog = l.getProduktkatalog();
    int id;
    try {
        id = stoi(splitS.at(0)); //check if the id can be converted to int
    }catch (exception e){
        throw IdOutOfRangeException();
    }
    if (produktkatalog.find(id) != produktkatalog.end()){
        throw IdDuplicateException(); //check if the id is already in the map
    }
    try {
        l.addDvd(id, splitS.at(1), stoi(splitS.at(2))); //check if the arguments are of the correct datatypes, the correct number; add the object to the map
    }catch (exception e){
        throw InvalidArgumentsException();
    }
}

void FileStore::parseBluray(string s){
    vector<string> splitS = splitString(s);
    splitS.at(1) = addRemoveSpaces(splitS.at(1), 1); //replace the underlines in the title with spaces
    map<int, shared_ptr<Produkt>> produktkatalog = l.getProduktkatalog();
    int id;
    try {
        id = stoi(splitS.at(0)); //check if the id can be converted to int
    }catch (exception e){
        throw IdOutOfRangeException();
    }
    if (produktkatalog.find(id) != produktkatalog.end()){
        throw IdDuplicateException(); //check if the id is already in the map
    }
    try {
        l.addBluray(id, splitS.at(1), stoi(splitS.at(2)), splitS.at(3)); //check if the arguments are of the correct datatypes, the correct number; add the object to the map
    }catch (exception e){
        throw InvalidArgumentsException();
    }
}

void FileStore::parseLagerbestand(string s){
    vector<string> splitS = splitString(s);
    map<int, int> lagerbestand = l.getLagerbestand();
    map<int, shared_ptr<Produkt>> produktkatalog = l.getProduktkatalog();
    int id;
    try {
        id = stoi(splitS.at(0)); //check if the id can be converted to int
    }catch (exception e){
        throw IdOutOfRangeException();
    }
    if (lagerbestand.find(id) != lagerbestand.end()){
        throw IdDuplicateException(); //check if the id is already in the map
    }
    if (produktkatalog.find(id) == produktkatalog.end()){
        throw NonExistendProduktException(); //check if product with such id existst (throw exception if it does not exist)
    }
    try {
        l.addLagerbestand(id, stoi(splitS.at(1))); //check if the arguments are of the correct datatypes, the correct number; add to the map
    }catch (exception e){
        throw InvalidArgumentsException();
    }
}

vector<string> FileStore::splitString(const string& str) {
    istringstream iss(str);
    vector<string> words;
    string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

vector<string> FileStore::divideByFirstSpace(const string& input) {
    vector<string> v;
    size_t spacePos = input.find(' ');
    if (spacePos != string::npos) {
        v.push_back(input.substr(0, spacePos));
    }
    if (spacePos != string::npos && spacePos < input.length() - 1) {
        v.push_back(input.substr(spacePos + 1));
    }
    return v;
}

string FileStore::addRemoveSpaces(string s, bool b) {
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


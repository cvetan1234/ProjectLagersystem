#ifndef TEST3_FILESTORE_H
#define TEST3_FILESTORE_H

#include <vector>

class FileStore{
public:
    FileStore(Lagersystem& setLagersystem);
    void readFile(const string& filename);
    void exportFile(string fileName);
private:
    Lagersystem& l;
    void parseKunde(string s);
    void parseDvd(string s);
    void parseBluray(string s);
    void parseLagerbestand(string s);
    vector<string> splitString(const string& str);
    vector<string> divideByFirstSpace(const string& input);
    string addRemoveSpaces(string s, bool b);
};

#endif

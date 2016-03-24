#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char *prodFile = "produse.csv";
const char *paletFile = "paleti.csv";

void makeProduct(string line, short &prodId, string &prodName, short &prodCategory, short &prodPrice) {

    short pos = 0, length = line.size() - 1;
    while (line[pos] != ',') {
        prodId = prodId * 10 + short(line[pos++] - '0');
    }

    ++pos;
    while (line[pos] != ',') {
        prodName += line[pos++];
    }

    ++pos;
    while (line[pos] != ',') {
        prodCategory = 10 * prodCategory + short(line[pos++] - '0');
    }

    ++pos;
    while (pos < length) {
        prodPrice = 10 * prodPrice + short(line[pos++] - '0');
    }
}

void parseProducts(const char *fileName) {
    string s = "";
    ifstream products(fileName);

    getline(products, s);
    while (getline(products, s)) {
        string prodName = "";
        short prodId = 0, prodCategory = 0, prodPrice = 0;
        makeProduct(s, prodId, prodName, prodCategory, prodPrice); 
    }

    products.close();
}

void makePalet(string line, string &paletId, short &prodType,short &nItems, short &slot) {
    short pos = 0, length = line.size();
    while (line[pos] != ',') {
        paletId += line[pos++];
    }

    ++pos;
    while (line[pos] != ',') {
        prodType = 10 * prodType + short(line[pos++] - '0');
    }

    ++pos;
    while (line[pos] != ',') {
        nItems = 10 * nItems + short(line[pos++] - '0');
    }

    ++pos;
    while (pos < length) {
        slot = 10 * slot + short(line[pos++] - '0');
    }
}

void parsePalets(const char *fileName) {
    string s = "";
    ifstream palets(fileName);

    string paletId = "";
    short prodType = 0, nItems = 0, slot = 0;

    palets >> s;
    while (palets >> s) {
        paletId = "";
        prodType = nItems = slot = 0;
        makePalet(s, paletId, prodType, nItems, slot);
    }

    palets.close();
}

int main() {
    parsePalets(paletFile);
    parseProducts(prodFile);
    return 0;
}
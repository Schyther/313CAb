#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ofstream g("bon.out");


void segmentation(string line, long long &id_bon, int &id_produs)
{
    long long nr_long = 0;

    int l = line.size();
    int it = 0;

    while(it < l)
    {
        while(line[it] >= '0' && line[it] <= '9')
        {
            id_bon = id_bon * 10 + int(line[it] - '0');
            it++;
        }
        it++;
        while(line[it] >= '0' && line[it] <= '9')
        {
            id_produs = id_produs * 10 + int(line[it] - '0');
            it++;
        }

    }
}

void parseBonuri(char *fileName)
{
    ifstream f(fileName);

    string line;

    f >> line;

    while (f >> line)
    {
        long long id_bon = 0;
        int id_produs = 0;
        segmentation(line, id_bon, id_produs);

        g << id_bon << " " << id_produs << '\n';
    }

    f.close();
}

int main()
{
    parseBonuri("bonuri.csv");

    g.close();
}

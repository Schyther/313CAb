#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ofstream g("cat.out");


void segmentation(string line, int &id, string &name)
{
    long long nr_long = 0;

    int l = line.size();
    int it = 0;

    while(it < l)
    {
        while(line[it] >= '0' && line[it] <= '9')
        {
            id = id * 10 + int(line[it] - '0');
            it++;
        }
        it++;
        while(it < l)
        {
        	name += line[it];
            it++;
        }

    }
}

void parseCategorii(char *fileName)
{
    ifstream f(fileName);

    string line;

    f >> line;

    while (f >> line)
    {
        int id = 0;
        string name = "";
        segmentation(line, id, name);

        g << id << " " << name << '\n';
    }

    f.close();
}

int main()
{
    parseCategorii("categorii.csv");

    g.close();
}

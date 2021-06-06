#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <vector>

using namespace std;

struct edge{
    size_t left, right, width;
}

vector<int> lead;

int main(){
    setlocale(LC_ALL, "RUS");
    ifstream fin("input.txt");

    int egdes, tops;
    fin >> tops;
    /.fin >> edges;
    return 0;
}


bool compare(const edge& fobj, const edge& sobj){
    return fobj.width < sobj.width;
}


#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
 
using namespace std;
 
struct graph
{
    int x, y, w;
};
 
bool cmp(const graph& a, const graph& b)
{
    return a.w < b.w;
}
 
vector <int> leader;
 
int getLeader(int x)
{
    if (x == leader[x])
        return x;
 
    return leader[x] = getLeader(leader[x]);   
}
 
bool unite(int x, int y)
{
    x = getLeader(x);
    y = getLeader(y);
 
    if (x == y)
        return false;
 
    leader[x] = y;
    return true;
}

vector <graph> kruskal(vector <graph> &obj, int n, int m)
{
     sort(obj.begin(), obj.end(), cmp);

     leader.resize(n);
     for (int i = 0; i < n; i++)
         leader[i] = i;

     vector <graph> ans;

     for (int i = 0; i < m; i++)
     {
         int x = obj[i].x, y = obj[i].y;

         if (unite(x, y))
             ans.push_back(obj[i]);
     }

     return ans;
}
 
int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream fin("input.txt");

    int n, m;
    fin >> n;
    fin >> m;
    m *= 2;

    vector <graph> e(m);

    int i = 0;
    while (!fin.eof())
    {
        int num;
        fin >> num;
        while (fin.peek() != '\n')
        {
            e[i].x = num;
            fin >> e[i].y;
            fin >> e[i].w;
            e[i].x--;
            e[i].y--;
            i++;

            if (fin.eof())
                break;
        }
    }
    fin.close();
 
    vector <graph> ans = kruskal(e, n, m);

    int sum = 0;
    for (unsigned i = 0; i < ans.size(); i++)
        sum += ans[i].w;
    cout << sum << endl;
    cout << "Минимальное оставное дерево: " << endl;

    for (unsigned i = 0; i < ans.size(); i++)
    {
        cout << ans[i].x + 1 << "--" << ans[i].y + 1 << endl;
    }
    
    return 0;
}
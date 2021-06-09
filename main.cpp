#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

struct edge
{
    int left, right, width;
};

bool cmp(const edge& fobj, const edge& sobj)
{
    return fobj.width < sobj.width;
}

vector <int> lead;

int getLead(int left)
{
    if (left == lead[left])
        return left;

    return lead[left] = getLead(lead[left]);
}

bool unite(int left, int right)
{
    left = getLead(left);
    right = getLead(right);

    if (left == right)
        return false;

    lead[left] = right;
    return true;
}

vector <edge> kruskal(vector <edge>& obj, int tops, int edges)
{
    sort(obj.begin(), obj.end(), cmp);

    lead.resize(tops);
    for (int i = 0; i < tops; i++)
        lead[i] = i;

    vector <edge> ans;

    for (int i = 0; i < edges; i++)
    {
        int left = obj[i].left, right = obj[i].right;

        if (unite(left, right))
            ans.push_back(obj[i]);
    }

    return ans;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    ifstream file("input.txt");

    int tops, edges;
    file >> tops;
    file >> edges;
    edges *= 2;

    vector <edge> e(edges);

    int i = 0;
    while (!file.eof())
    {
        int num;
        file >> num;
        while (file.peek() != '\n')
        {
            e[i].left = num;
            file >> e[i].right;
            file >> e[i].width;
            i++;

            if (file.eof())
                break;
        }
    }
    file.close();

    vector <edge> ans = kruskal(e, tops, edges);

    int sum = 0;
    for (size_t i = 0; i < ans.size(); i++)
        sum += ans[i].width;
    cout << sum << endl;
    cout << "min ost tree: " << endl;

    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i].left  << "--" << ans[i].right  << endl;
    }

    return 0;
}
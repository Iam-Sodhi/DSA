#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Given a weights and values of n items, we need to put these items in a knapsack of capacity w to get the maximum total value in the knapsack
// Unlike 0/1 knapsack, you are allowed to break the item.
class item
{
public:
    int value;
    int weight;
};
bool cmp(pair<double, item> a, pair<double, item> b)
{
    return a.first > b.first;
}
double fractionalKnapsack(vector<item> arr, int w, int n)
{

    vector<pair<double, item>> v;
    for (int i = 0; i < n; i++)
    {
        double perunitValue = (1.0 * arr[i].value) / arr[i].weight;
        v.push_back({perunitValue, arr[i]});
    }

    // lets firsly sort the arr in descending order wrt values per unit weight
    sort(v.begin(), v.end(), cmp);
    double totalValue = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second.weight > w) // here only a fraction value can be added
        {
            totalValue += (v[i].first) * w;
            w = 0;
        }
        else // here put the all value
        {
            totalValue += v[i].second.value;
            w = w - v[i].second.weight;
        }
    }
    return totalValue;
}
int main()
{
    int n = 3;
    int w = 50;
    // int values[] = {60, 100, 120};
    // int weights[] = {10, 20, 30};
    vector<item> items= {{60,10},{100,20},{120,30}};
    // for (int i = 0; i < n; i++)
    // {
    //     items[i].value = values[i];
    //     items[i].weight = weights[i];
    // }

    cout << "The maximum value is " << fractionalKnapsack(items, w,n);
    return 0;
}
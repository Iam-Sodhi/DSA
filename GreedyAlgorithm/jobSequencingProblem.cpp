#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Given a set of n jobs where each job has a deadline and profit associated with it .
// Each job takes 1 unit time to complete and only one job can be scheduled at a time. We earn profit from a job only when it is completed by its deadline
// Find the number of jobs done and the maximum profit
// NOTE: jobs will be given in the form (job_id,deadline, profit) associatted with that job
class job
{
public:
    int id;
    int deadline;
    int profit;
};
bool cmp(job a, job b)
{
    return a.profit > b.profit;
}
int main()
{
    int n = 4;
    vector<job> a = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};

    // our greedy approach tells us that firstly do the job having maximum profit
    // lets sort them in descending order wrt profit
    sort(a.begin(), a.end(), cmp);

    // Let's find the max deadline
    int maxDeadline = INT8_MIN;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, a[i].deadline);
    }
    // lets make a array for schedule for deadline
    vector<int> Darr(maxDeadline + 1, -1); // it is of size n+1 we will do indexing form 1
    int num_jobs = 0;
    int max_profit = 0;
    for (int i = 0; i < n; i++)
    {
        int currProfit = a[i].profit;
        int currId = a[i].id;
        int currDead = a[i].deadline;

        for (int k = currDead; k > 0; k--) // start form right side(curr deadline) as it is common sense
        {
            {
                if (Darr[k] == -1)
                {
                    max_profit += currProfit;
                    num_jobs++;
                    Darr[k] = currId;
                    break; // Remember to break now as no need to look for days before deadline
                }
                // else means it can't be done as on its deadline we have done another job
            }
        }
    }
    cout << "The maximum profit is " << max_profit << endl;
    cout << "The total number of jobs is " << num_jobs << endl;
    return 0;
}

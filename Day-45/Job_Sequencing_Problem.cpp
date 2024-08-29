/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

bool comparator(Job a, Job b)
{
    return a.dead < b.dead;
}

struct cmp
{
    bool operator()(Job a, Job b)
    {
        return a.profit < b.profit;  // Max heap (greater profit first)
    }
};

class Solution 
{
    public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
       sort(arr, arr + n, comparator);
       
       priority_queue<Job, vector<Job>, cmp> pq;
       
       int maxProfit = 0;
        int jobsDone = 0;

        // Iterate over the sorted jobs
        for (int i = n - 1; i >= 0; i--)
        {
            int slotsAvailable;

            if (i == 0)
            {
                slotsAvailable = arr[i].dead;
            }
            else
            {
                slotsAvailable = arr[i].dead - arr[i - 1].dead;
            }

            pq.push(arr[i]);

            while (slotsAvailable > 0 && !pq.empty())
            {
                Job job = pq.top();
                pq.pop();
                maxProfit += job.profit;
                jobsDone++;
                slotsAvailable--;
            }
        }
        return {jobsDone, maxProfit};
    } 
};

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        //declaring hashmap to store element frequencies
        unordered_map<int, int> mp;
        
        //counting frequency of each element
        for (int x : nums)
        {
            mp[x]++;
        }

        // priority_queue<Type, Container, Comparison>...(min-heap)
        //using pair to store {frequency, element} from hashmap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto n : mp)
        {
            //push {frequency, element} in min-heap
            pq.push({n.second, n.first});

            //if size exceeds k, remove smallest frequency element
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        //storing final size of priority queue
        int actual_size = pq.size();
        vector<int> ans(actual_size);

        //extracting elements from priority queue
        for (int i = 0; i < actual_size; i++)
        {
            ans[i] = pq.top().second; //.second because in priority_queue second is our actual element
            pq.pop();
        }

        return ans;
    }
};

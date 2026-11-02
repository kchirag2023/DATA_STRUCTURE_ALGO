// Pushed: 2026-11-02 18:54:38 UTC
// Difficulty: Medium
// Runtime: 43 ms
// Memory: 47.7 MB


class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        // Using unordered_map to store frequencies of any characters
        std::unordered_map<char, int> mp;
        for (char ch : tasks) {
            mp[ch]++;
        }
        
        // Max heap to store frequencies
        std::priority_queue<int> pq;
        for (auto& entry : mp) {
            pq.push(entry.second);
        }
        
        int time = 0;
        
        while (!pq.empty()) {
            std::vector<int> temp;
            
            // Execute up to n + 1 tasks in each cycle
            for (int i = 1; i <= n + 1; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            
            // Push remaining frequencies back into the max heap
            for (int f : temp) {
                if (f > 0) {
                    pq.push(f);
                }
            }
            
            // If the heap is empty, only add the actual tasks executed in this cycle
            // Otherwise, add the full cycle length (n + 1) including idle time
            if (pq.empty()) {
                time += temp.size();
            } else {
                time += n + 1;
            }
        }
        
        return time;
    }
};
// Brut force Solution

class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        int max_platforms = 1;

        // Sorting arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        // Using nested for-loop
        for (int i = 0; i < n; i++) {
            int countPf = 1;  // Each train needs at least one platform

            for (int j = 0; j < i; j++) {
                if (arr[i] <= dep[j]) {
                    countPf++; // Increase platform count if train overlaps
                }
            }
            max_platforms = max(max_platforms, countPf);
        }

        return max_platforms;
    }
};




// Optimal solution

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
     sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 0, j = 0;  // Two pointers
    int platforms_needed = 0, max_platforms = 0;

    // Step 2: Process the events in order
    while (i < arr.size() && j < dep.size()) {
        if (arr[i] <= dep[j]) {  // A train arrives
            platforms_needed++;
            max_platforms = max(max_platforms, platforms_needed);
            i++;  // Move to the next arrival
        } else {  // A train departs
            platforms_needed--;
            j++;  // Move to the next departure
        }
    }

    return max_platforms;  // Minimum number of platforms required
    }
};

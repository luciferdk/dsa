class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;  // Initialize the maximum altitude
        int currentAltitude = 0;  // Start at altitude 0
        
        for (int g : gain) {
            currentAltitude += g;  // Update the current altitude
            if (currentAltitude > maxAltitude) {
                maxAltitude = currentAltitude;  // Update the maximum altitude if necessary
            }
        }
        
        return maxAltitude;
    }
};

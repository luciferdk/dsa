class Solution {
public:
    
    int maximumPopulation(vector<vector<int>>& logs) {
        // Define a year range large enough to cover all possible years.
        int years[101] = {0};  // Since the range is 1950 to 2050 (101 years)

        // Apply the difference array approach
        for (const auto& log : logs) {
            years[log[0] - 1950]++;     // Increment population at birth year
            years[log[1] - 1950]--;     // Decrement population at death year
        }

        // Find the year with the maximum population
        int maxPopulation = 0, maxYear = 1950, currentPopulation = 0;
        for (int i = 0; i < 101; ++i) {
            currentPopulation += years[i]; //updating population count
            if (currentPopulation > maxPopulation) {//Check greater or not
                maxPopulation = currentPopulation;  //Tranfer currentPopulation value to maxPopulation
                maxYear = 1950 + i; //convert index back to the actual year
            }
        }

        return maxYear;
    }
};


/* #include <stdio.h>
 
 
 void drive () {
     int years[8]={0,1,2,1,0,1,1};
    int maxPopulation = 0;
    int currentPopulation = 0 ;
    int maxYear = 1950;
    
for (int i = 0; i < 8; ++i) {
    currentPopulation += years[i];  // Update population count
    if (currentPopulation > maxPopulation) {  
        maxPopulation = currentPopulation;  
        maxYear = 1950 + i;  // Convert index back to actual year  
    }
}

// Print the results
    printf("Maximum Population: %d\n", maxPopulation);
    printf("Year with Maximum Population: %d\n", maxYear);
    
 }
// Driver code
int main()
{

drive();
    return 0;
} */
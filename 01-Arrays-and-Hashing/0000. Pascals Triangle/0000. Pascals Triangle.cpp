1
2class Solution {
3public:
4    std::vector<std::vector<int>> generate(int numRows) {
5        std::vector<std::vector<int>> triangle;
6        
7        for (int i = 0; i < numRows; i++) {
8            // Allocate space for the current row (row 'i' has 'i + 1' elements)
9            // and initialize all elements to 1.
10            std::vector<int> row(i + 1, 1);
11            
12            // Fill the inner elements (excluding the first and last elements)
13            for (int j = 1; j < i; j++) {
14                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
15            }
16            
17            // Push the completed row into our main triangle vector
18            triangle.push_back(row);
19        }
20        
21        return triangle;
22    }
23};
24
class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.length();
        int i = 0;
        while (i < n) {
            int j = i; 
            while (j < n && title[j] != ' ') {
                title[j] = tolower(static_cast<unsigned char>(title[j]));
                j++;
            }            
            if (j - i > 2) {
                title[i] = toupper(static_cast<unsigned char>(title[i]));
            }
            i = j + 1;
        }
        return title;
    }
};

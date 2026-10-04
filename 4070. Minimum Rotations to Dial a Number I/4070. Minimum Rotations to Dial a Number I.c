1int minRotations(char* s) {
2    int t_rotations=0;
3    int present = 0;
4    for(int i=0; s[i] != '\0'; i++){
5        int target = s[i] - '0';
6        int dif = abs(target - present);
7        t_rotations += (dif<10-dif) ? dif:(10-dif);
8        present = target;
9    }
10    return t_rotations;
11}
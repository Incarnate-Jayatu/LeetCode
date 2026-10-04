int minRotations(char* s) {
    int t_rotations=0;
    int present = 0;
    for(int i=0; s[i] != '\0'; i++){
        int target = s[i] - '0';
        int dif = abs(target - present);
        t_rotations += (dif<10-dif) ? dif:(10-dif);
        present = target;
    }
    return t_rotations;
}

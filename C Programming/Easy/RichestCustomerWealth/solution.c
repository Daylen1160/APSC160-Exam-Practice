int richestCustomerWealth(int NUMROWS, int NUMCOLS, int accounts[][NUMCOLS]) {
    int richestWealth = -1;
    for (int i = 0; i < NUMROWS; i++) {
        int currentWealth = 0;
        for (int j = 0; j < NUMCOLS; j++) {
            currentWealth += accounts[i][j];
        }
        if (i == 0 || currentWealth > richestWealth) {
            richestWealth = currentWealth;
        }
    }
    return richestWealth;   
}
/**
 * @file solution.h
 * @brief Richest Customer Wealth Solution
 * @author Daylen Chun
 */

int richestCustomerWealth(int NUMROWS, int NUMCOLS, int accounts[][NUMCOLS]);

/**
 * @brief Find the richest customer's wealth from a 2D array of accounts
 * @param[in] NUMROWS    Number of customers (rows)
 * @param[in] NUMCOLS    Number of accounts per customer (columns)
 * @param[in] accounts   2D array representing the wealth of each customer in each account
 * @return The maximum wealth among all customers
 */
int richestCustomerWealth(int NUMROWS, int NUMCOLS, int accounts[][NUMCOLS]) {
    int richestWealth = -1;
    for (int i = 0; i < NUMROWS; i++) {
        int currentWealth = 0;
        for (int j = 0; j < NUMCOLS; j++) {
            currentWealth += accounts[i][j];
        }
        if (currentWealth > richestWealth) {
            richestWealth = currentWealth;
        }
    }
    return richestWealth;
}
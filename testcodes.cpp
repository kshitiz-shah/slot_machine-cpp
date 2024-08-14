#include <iostream>
#include <vector>
#include <map>
#include <random>

using namespace std;

vector<vector<char>> slot_machine(int ROWS, int COLUMNS, map<char, int> symbols) {
    vector<char> all_symbols;
    for (auto& symbol_count : symbols) {
        for (int i = 0; i < symbol_count.second; ++i) {
            all_symbols.push_back(symbol_count.first);
        }
    }
    
    vector<vector<char>> cols;
    for (int i = 0; i < COLUMNS; ++i) {
        vector<char> column;
        vector<char> current_symbols = all_symbols;
        for (int j = 0; j < ROWS; ++j) {
            int index = rand() % current_symbols.size();
            char value = current_symbols[index];
            current_symbols.erase(current_symbols.begin() + index);
            column.push_back(value);
        }
        cols.push_back(column);
    }
    
    return cols;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    map<char, int> symbols = {
        {'A', 2},
        {'B', 3},
        {'C', 1}
    };

    int ROWS = 3;
    int COLUMNS = 3;

    vector<vector<char>> grid = slot_machine(ROWS, COLUMNS, symbols);

    cout << "Random 3x3 Grid:" << endl;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

void print_array(const int arr[], int arr_size);
int lowest_cost(const int game[], int game_size);

int main() {
    int game_1[] = { 0, 3, 80, 6, 57, 10 };
    int game_1_size = sizeof(game_1) / sizeof(*game_1);

    cout << "Game 1: ";
    print_array(game_1, game_1_size);
    cout << "Lowest cost of game 1: " << lowest_cost(game_1, game_1_size) << "\n\n";

    int game_2[] = { 0, 7, 100, 101, 1000, 69, 43, 2 };
    int game_2_size = sizeof(game_2) / sizeof(*game_2);

    cout << "Game 2: ";
    print_array(game_2, game_2_size);
    cout << "Lowest cost of game 2: " << lowest_cost(game_2, game_2_size) << "\n\n";

    int game_3[] = { 0, 1, 100, 1 };
    int game_3_size = sizeof(game_3) / sizeof(*game_3);

    cout << "Game 3: ";
    print_array(game_3, game_3_size);
    cout << "Lowest cost of game 3: " << lowest_cost(game_3, game_3_size) << '\n';

    return 0;
}

void print_array(const int arr[], int arr_size) {
    cout << '[';

    for (int i = 0; i < arr_size; i++) {
        cout << arr[i];

        if (i != arr_size - 1) {
            cout << ", ";
        }
    }

    cout << "]\n";
}

int lowest_cost(const int game[], int game_size) {
    if (game_size <= 3) {
        return game[game_size - 1];
    } else {
        int one_step = lowest_cost(game, game_size - 1);
        int two_steps = lowest_cost(game, game_size - 2);

        if (one_step < two_steps) {
            return one_step + game[game_size - 1];
        } else {
            return two_steps + game[game_size - 1];
        }
    }
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

const int GRID_SIZE = 20;
const int INITIAL_ANTS = 100;
const int INITIAL_DOODLEBUGS = 5;
const int MOVE_UP = 0;
const int MOVE_DOWN = 1;
const int MOVE_LEFT = 2;
const int MOVE_RIGHT = 3;
const int ANT_BREED_INTERVAL = 3;
const int DOODLEBUG_BREED_INTERVAL = 8;
const int DOODLEBUG_STARVE_INTERVAL = 3;
const char EMPTY_SPACE_CHAR = '-';
const char ANT_CHAR = 'o';
const char DOODLEBUG_CHAR = 'X';
const char TYPE_ANT = 'A';
const char TYPE_DOODLEBUG = 'D';

struct Position {
    int row;
    int col;
};

class World;

class Organism {
public:
    Organism(const Position& pos);
    Organism();
    virtual ~Organism();
    Position get_position() const;
    void set_position(const Position& pos);
    virtual char get_type() const = 0;
    virtual void move(World& world) = 0;
    virtual void breed(World& world) = 0;
    virtual void starve(World& world) = 0;
    void die(World& world) const;
    virtual void print(ostream& outs) const = 0;
    friend ostream& operator <<(ostream& outs, const Organism& organism);

private:
    Position position;
};

class Ant : public Organism {
public:
    Ant(const Position& pos);
    Ant();
    virtual ~Ant();
    virtual char get_type() const;
    virtual void move(World& world);
    virtual void breed(World& world);
    virtual void starve(World& world);
    virtual void print(ostream& outs) const;

private:
    int breed_timer;
};

class Doodlebug : public Organism {
public:
    Doodlebug(const Position& pos);
    Doodlebug();
    virtual ~Doodlebug();
    virtual char get_type() const;
    virtual void move(World& world);
    virtual void breed(World& world);
    virtual void starve(World& world);
    virtual void print(ostream& outs) const;

private:
    int breed_timer;
    int starve_timer;
    vector<Position> find_adjacent_ants(World& world);
};

class World {
public:
    World();
    ~World();
    bool is_cell_available(const Position& pos) const;
    vector<Position> get_available_adjacent_cells(const Position& curr_pos) const;
    void simulate_one_time_step();
    Organism* get_organism(const Position& pos) const;
    void set_organism(const Position& pos, Organism* organism_ptr);
    void move_organism(const Position& curr_pos, const Position& next_pos);
    void remove_organism(const Organism* organism_ptr);
    void display() const;
private:
    Organism* grid[GRID_SIZE][GRID_SIZE];
};

ostream& operator <<(ostream& outs, const Position& pos);

int main() {
    srand(time(0));

    World world;
    int time = 0;

    cout << "Welcome to my two-dimensional predator-prey simulation!\n";

    while (true) {
        cout << "\nWorld snapshot at time = " << time << ":\n\n";
        world.display();
        cout << "\nPress ENTER to continue";
        cin.get();
        world.simulate_one_time_step();
        time++;
    }

    return 0;
}

Organism::Organism(const Position& pos) : position(pos) {}

Organism::Organism() {}

Organism::~Organism() {}

Position Organism::get_position() const {
    return position;
}

void Organism::set_position(const Position& pos) {
    position.row = pos.row;
    position.col = pos.col;
}

void Organism::die(World& world) const {
    world.remove_organism(this);
}

ostream& operator <<(ostream& outs, const Organism& organism) {
    organism.print(outs);

    return outs;
}

Ant::Ant(const Position& pos) : Organism(pos), breed_timer(0) {}

Ant::Ant() : Organism(), breed_timer(0) {}

Ant::~Ant() {}

char Ant::get_type() const {
    return TYPE_ANT;
}

void Ant::move(World& world) {
    int direction = rand() % 4;
    Position curr_pos = get_position();
    Position next_pos = curr_pos;

    switch (direction) {
        case MOVE_UP:
            next_pos.row--;
            break;
        case MOVE_DOWN:
            next_pos.row++;
            break;
        case MOVE_LEFT:
            next_pos.col--;
            break;
        case MOVE_RIGHT:
            next_pos.col++;
            break;
        default:
            break;
    }

    if (world.is_cell_available(next_pos)) {
        world.move_organism(curr_pos, next_pos);
    }

    breed_timer++;
}

void Ant::breed(World& world) {
    if (breed_timer < ANT_BREED_INTERVAL) {
        return;
    }

    Position curr_pos = get_position();
    vector<Position> available_adjacent_cells = world.get_available_adjacent_cells(curr_pos);

    if (!available_adjacent_cells.empty()) {
        int random_pick = rand() % available_adjacent_cells.size();
        Position new_ant_pos = available_adjacent_cells[random_pick];

        world.set_organism(new_ant_pos, new Ant);
    }

    breed_timer = 0;
}

void Ant::starve(World& world) {}

void Ant::print(ostream& outs) const {
    outs << ANT_CHAR;
}

Doodlebug::Doodlebug(const Position& pos) : Organism(pos), breed_timer(0), starve_timer(0) {}

Doodlebug::Doodlebug() : Organism(), breed_timer(0), starve_timer(0) {}

Doodlebug::~Doodlebug() {}

char Doodlebug::get_type() const {
    return TYPE_DOODLEBUG;
}

void Doodlebug::move(World& world) {
    Position curr_pos = get_position();
    vector<Position> adjacent_ants = find_adjacent_ants(world);

    if (!adjacent_ants.empty()) {
        int random_pick = rand() % adjacent_ants.size();
        Position target_ant_pos = adjacent_ants[random_pick];

        world.get_organism(target_ant_pos)->die(world);
        world.move_organism(curr_pos, target_ant_pos);
        breed_timer++;
        starve_timer = 0;
    } else {
        int direction = rand() % 4;
        Position next_pos = curr_pos;

        switch (direction) {
            case MOVE_UP:
                next_pos.row--;
                break;
            case MOVE_DOWN:
                next_pos.row++;
                break;
            case MOVE_LEFT:
                next_pos.col--;
                break;
            case MOVE_RIGHT:
                next_pos.col++;
                break;
            default:
                break;
        }

        if (world.is_cell_available(next_pos)) {
            world.move_organism(curr_pos, next_pos);
        }

        breed_timer++;
        starve_timer++;
    }
}

void Doodlebug::breed(World& world) {
    if (breed_timer < DOODLEBUG_BREED_INTERVAL) {
        return;
    }

    Position curr_pos = get_position();
    vector<Position> available_adjacent_cells = world.get_available_adjacent_cells(curr_pos);

    if (!available_adjacent_cells.empty()) {
        int random_pick = rand() % available_adjacent_cells.size();
        Position new_doodlebug_pos = available_adjacent_cells[random_pick];

        world.set_organism(new_doodlebug_pos, new Doodlebug);
    }

    breed_timer = 0;
}

void Doodlebug::starve(World& world) {
    if (starve_timer < DOODLEBUG_STARVE_INTERVAL) {
        return;
    }

    die(world);
}

void Doodlebug::print(ostream& outs) const {
    outs << DOODLEBUG_CHAR;
}

vector<Position> Doodlebug::find_adjacent_ants(World& world) {
    Position curr_pos = get_position();
    vector<Position> adjacent_ants;
    vector<Position> candidates = {
            {curr_pos.row - 1, curr_pos.col},
            {curr_pos.row + 1, curr_pos.col},
            {curr_pos.row, curr_pos.col - 1},
            {curr_pos.row, curr_pos.col + 1}
    };

    for (Position pos: candidates) {
        Organism* organism_ptr = world.get_organism(pos);

        if ((organism_ptr != nullptr) && (organism_ptr->get_type() == TYPE_ANT)) {
            adjacent_ants.push_back(pos);
        }
    }

    return adjacent_ants;
}

World::World() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = nullptr;
        }
    }

    for (int i = 0; i < INITIAL_DOODLEBUGS; i++) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;

        while (grid[row][col] != nullptr) {
            row = rand() % GRID_SIZE;
            col = rand() % GRID_SIZE;
        }

        grid[row][col] = new Doodlebug({row, col});
    }

    for (int i = 0; i < INITIAL_ANTS; i++) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;

        while (grid[row][col] != nullptr) {
            row = rand() % GRID_SIZE;
            col = rand() % GRID_SIZE;
        }

        grid[row][col] = new Ant({row, col});
    }
}

World::~World() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != nullptr) {
                delete grid[i][j];
            }
        }
    }
}

bool World::is_cell_available(const Position& pos) const {
    return (0 <= pos.row) && (pos.row < GRID_SIZE) && (0 <= pos.col) && (pos.col < GRID_SIZE) && (grid[pos.row][pos.col] == nullptr);
}

vector<Position> World::get_available_adjacent_cells(const Position& curr_pos) const {
    vector<Position> available_adjacent_cells;
    vector<Position> candidates = {
            {curr_pos.row - 1, curr_pos.col},
            {curr_pos.row + 1, curr_pos.col},
            {curr_pos.row, curr_pos.col - 1},
            {curr_pos.row, curr_pos.col + 1}
    };

    for (Position pos: candidates) {
        if (is_cell_available(pos)) {
            available_adjacent_cells.push_back(pos);
        }
    }

    return available_adjacent_cells;
}

void World::simulate_one_time_step() {
    vector<Organism*> ants;
    vector<Organism*> doodlebugs;

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if ((grid[i][j] != nullptr) && (grid[i][j]->get_type() == TYPE_DOODLEBUG)) {
                doodlebugs.push_back(grid[i][j]);
            }
        }
    }

    for (Organism* doodlebug_ptr: doodlebugs) {
        doodlebug_ptr->move(*this);
    }

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if ((grid[i][j] != nullptr) && (grid[i][j]->get_type() == TYPE_ANT)) {
                ants.push_back(grid[i][j]);
            }
        }
    }

    for (Organism* ant_ptr: ants) {
        ant_ptr->move(*this);
    }

    for (Organism* doodlebug_ptr: doodlebugs) {
        doodlebug_ptr->breed(*this);
    }

    for (Organism* doodlebug_ptr: doodlebugs) {
        doodlebug_ptr->starve(*this);
    }

    for (Organism* ant_ptr: ants) {
        ant_ptr->breed(*this);
    }
}

Organism* World::get_organism(const Position& pos) const {
    if ((0 <= pos.row) && (pos.row < GRID_SIZE) && (0 <= pos.col) && (pos.col < GRID_SIZE)) {
        return grid[pos.row][pos.col];
    } else {
        return nullptr;
    }
}

void World::set_organism(const Position& pos, Organism* organism_ptr) {
    grid[pos.row][pos.col] = organism_ptr;
    organism_ptr->set_position(pos);
}

void World::move_organism(const Position& curr_pos, const Position& next_pos) {
    grid[next_pos.row][next_pos.col] = grid[curr_pos.row][curr_pos.col];
    grid[next_pos.row][next_pos.col]->set_position(next_pos);
    grid[curr_pos.row][curr_pos.col] = nullptr;
}

void World::remove_organism(const Organism *organism_ptr) {
    Position pos = organism_ptr->get_position();
    grid[pos.row][pos.col] = nullptr;
    delete organism_ptr;
}

void World::display() const {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == nullptr) {
                cout << EMPTY_SPACE_CHAR;
            } else {
                cout << *grid[i][j];
            }

            cout << ' ';
        }

        cout << '\n';
    }
}

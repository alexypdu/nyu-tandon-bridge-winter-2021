#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

template <class T>
class DLList;

template <class T>
class DLListNode {
public:
    DLListNode(const T& data = T(), DLListNode<T>* prev = nullptr, DLListNode<T>* next = nullptr);
    T& get_data();
    DLListNode<T>* get_prev();
    DLListNode<T>* get_next();
    friend class DLList<T>;
private:
    T data;
    DLListNode<T>* prev;
    DLListNode<T>* next;
};

template <class T>
class DLList {
public:
    DLList();
    virtual ~DLList();
    DLList(const DLList<T>& rhs);
    DLList& operator =(const DLList<T>& rhs);
    bool is_empty() const;
    void clear();
    T remove_node(DLListNode<T>* target);
    T pop_front();
    T pop_back();
    void insert_after(const T& data, DLListNode<T>* target);
    void push_front(const T& data);
    void push_back(const T& data);
    int get_size() const;
    DLListNode<T>* get_begin() const;
    DLListNode<T>* get_end() const;
private:
    int size;
    DLListNode<T>* head;
    DLListNode<T>* tail;
};

class Employee {
public:
    Employee();
    Employee(int id, double pay_rate, string name);
    int get_id() const;
    double get_pay_rate() const;
    string get_name() const;
    double get_total_pay() const;
    void add_total_pay(int hours);
    friend bool operator <(const Employee& employee1, const Employee& employee2);
    friend ostream& operator <<(ostream& outs, const Employee& employee);

private:
    int id;
    double pay_rate;
    string name;
    double total_pay;
};

void open_input_file(ifstream& in_file);
void store_employees(DLList<Employee>& employee_list, ifstream& employees_file);
void update_total_pay(DLList<Employee>& employee_list, ifstream& payroll_file);
void fill_employee_vector(DLList<Employee>& employee_list, vector<Employee>& employees);
void print_payroll(const vector<Employee>& employees);

int main() {
    DLList<Employee> employee_list;
    vector<Employee> employees;
    ifstream employees_file;
    ifstream payroll_file;

    cout << "Open the employees file.\n";
    open_input_file(employees_file);
    cout << "Read and store employees...\n\n";
    store_employees(employee_list, employees_file);
    cout << "Open the payroll file.\n";
    open_input_file(payroll_file);
    cout << "Update payroll information...\n\n";
    update_total_pay(employee_list, payroll_file);
    fill_employee_vector(employee_list, employees);
    sort(employees.begin(), employees.end());
    print_payroll(employees);

    return 0;
}

template <class T>
DLListNode<T>::DLListNode(const T& data, DLListNode<T>* prev, DLListNode<T>* next) : data(data), prev(prev), next(next) {}

template <class T>
T& DLListNode<T>::get_data() {
    return data;
}

template <class T>
DLListNode<T>* DLListNode<T>::get_prev() {
    return prev;
}

template <class T>
DLListNode<T>* DLListNode<T>::get_next() {
    return next;
}

template <class T>
DLList<T>::DLList() {
    size = 0;
    head = new DLListNode<T>;
    tail = new DLListNode<T>;
    head->next = tail;
    tail->prev = head;
}

template <class T>
DLList<T>::~DLList() {
    clear();
    delete head;
    delete tail;
}

template <class T>
DLList<T>::DLList(const DLList<T> &rhs) {
    size = 0;
    head = new DLListNode<T>;
    tail = new DLListNode<T>;
    head->next = tail;
    tail->prev = head;
    *this = rhs;
}

template <class T>
DLList<T>& DLList<T>::operator =(const DLList<T>& rhs) {
    if (this == &rhs){
        return *this;
    }

    clear();

    for (DLListNode<T>* temp = rhs.head->next; temp != rhs.tail; temp = temp->next) {
        push_back(temp->data);
    }

    return *this;
}

template <class T>
bool DLList<T>::is_empty() const {
    return size == 0;
}

template <class T>
void DLList<T>::clear() {
    while (!is_empty()) {
        remove_node(head->next);
    }
}

template <class T>
T DLList<T>::remove_node(DLListNode<T>* target) {
    T data = target->data;
    target->prev->next = target->next;
    target->next->prev = target->prev;
    size--;
    delete target;

    return data;
}

template <class T>
T DLList<T>::pop_front() {
    if (!is_empty()) {
        return remove_node(head->next);
    }
}

template <class T>
T DLList<T>::pop_back() {
    if (!is_empty()) {
        return remove_node(tail->prev);
    }
}

template <class T>
void DLList<T>::insert_after(const T& data, DLListNode<T>* target) {
    DLListNode<T>* temp = new DLListNode<T>(data, target, target->next);
    target->next = temp;
    temp->next->prev = temp;
    size++;
}

template <class T>
void DLList<T>::push_front(const T &data) {
    insert_after(data, head);
}

template <class T>
void DLList<T>::push_back(const T &data) {
    insert_after(data, tail->prev);
}

template <class T>
int DLList<T>::get_size() const {
    return size;
}

template <class T>
DLListNode<T>* DLList<T>::get_begin() const {
    return head->next;
}

template <class T>
DLListNode<T>* DLList<T>::get_end() const {
    return tail;
}

Employee::Employee() : id(0), pay_rate(0), name(""), total_pay(0) {}
Employee::Employee(int id, double pay_rate, string name) : id(id), pay_rate(pay_rate), name(name), total_pay(0) {}

int Employee::get_id() const {
    return id;
}

double Employee::get_pay_rate() const {
    return pay_rate;
}

string Employee::get_name() const {
    return name;
}

double Employee::get_total_pay() const {
    return total_pay;
}

void Employee::add_total_pay(int hours) {
    total_pay += pay_rate * static_cast<double>(hours);
}

bool operator <(const Employee& employee1, const Employee& employee2) {
    return employee1.get_total_pay() > employee2.get_total_pay();
}

ostream& operator <<(ostream& outs, const Employee& employee) {
    outs << employee.get_name() << ", $" << employee.get_total_pay() << endl;
    return outs;
}

void open_input_file(ifstream& in_file) {
    string file_name;

    cout << "Please enter the file name: ";
    cin >> file_name;
    in_file.open(file_name);

    while (in_file.fail()) {
        cout << "Bad file name!\n"
             << "Please enter the file name: ";
        cin >> file_name;
        in_file.open(file_name);
    }
}

void store_employees(DLList<Employee>& employee_list, ifstream& employees_file) {
    int id;
    double pay_rate;
    string name;

    while (employees_file >> id >> pay_rate) {
        employees_file.ignore(1, ' ');
        getline(employees_file, name);
        employee_list.push_back(Employee(id, pay_rate, name));
    }
}

void update_total_pay(DLList<Employee>& employee_list, ifstream& payroll_file) {
    int id;
    int hours;

    while (payroll_file >> id >> hours) {
        for (DLListNode<Employee>* temp = employee_list.get_begin(); temp != employee_list.get_end(); temp = temp->get_next()) {
            if (temp->get_data().get_id() == id) {
                temp->get_data().add_total_pay(hours);
                break;
            }
        }
    }
}

void fill_employee_vector(DLList<Employee>& employee_list, vector<Employee>& employees) {
    for (DLListNode<Employee>* temp = employee_list.get_begin(); temp != employee_list.get_end(); temp = temp->get_next()) {
        employees.push_back(temp->get_data());
    }
}

void print_payroll(const vector<Employee>& employees) {
    cout << "*********Payroll Information********\n";

    for (const Employee& employee: employees) {
        cout << employee;
    }

    cout << "*********End payroll**************\n";
}

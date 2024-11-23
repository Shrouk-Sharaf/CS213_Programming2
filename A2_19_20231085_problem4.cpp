#include <iostream>
#include <string>
using namespace std;

template <class T>
class Set {
private:
    T* items;        // Dynamic array to store items
    int size;        // Current number of elements in the set
    int capacity;    // Maximum capacity of the array

    void resize() {
        T* temp = new T[capacity * 2];
        for (int i = 0; i < size; i++) {
            temp[i] = items[i];
        }
        delete[] items;
        items = temp;
        capacity *= 2;
    }

public:
    Set() {
        items = new T[10];
        size = 0;
        capacity = 10;
    }

    ~Set() {
        delete[] items;
    }

    void add(const T& item) {
        if (!contains(item)) {
            if (size == capacity) {
                resize();
            }
            items[size++] = item;
        }
    }

    void remove(const T& item) {
        for (int i = 0; i < size; i++) {
            if (items[i] == item) {
                for (int j = i; j < size - 1; j++) {
                    items[j] = items[j + 1];
                }
                size--;
                return;
            }
        }
    }

    int count() const {
        return size;
    }

    bool contains(const T& item) const {
        for (int i = 0; i < size; i++) {
            if (items[i] == item) {
                return true;
            }
        }
        return false;
    }

    T* toArray() const {
        if (size == 0) {
            return nullptr;
        }
        T* result = new T[size];
        for (int i = 0; i < size; i++) {
            result[i] = items[i];
        }
        return result;
    }
};

// Function to display the menu
void displayMenu() {
    cout << "\n--- Set Operations Menu ---\n";
    cout << "1. Add an item\n";
    cout << "2. Remove an item\n";
    cout << "3. Check if an item exists\n";
    cout << "4. Display all items\n";
    cout << "5. Display the count of items\n";
    cout << "6. Exit\n";
    cout << "Choose an option:\n";
}

template <typename T>
void handleSet() {
    Set<T> set;
    while (true) {
        displayMenu();
        int choice;
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input! Please enter a number between 1 and 6.\n";
            cin.clear();
            while (cin.get() != '\n');
            continue;
        }

        if (choice == 1) {
            T item;
            cout << "Enter the item to add:\n";
            cin >> item;
            set.add(item);
            cout << "Item added successfully.\n";

        }
        else if (choice == 2) {
            T item;
            cout << "Enter the item to remove:\n";
            cin >> item;
            set.remove(item);
            cout << "Item removed if it existed in the set.\n";

        }
        else if (choice == 3) {
            T item;
            cout << "Enter the item to check:\n";
            cin >> item;
            if (set.contains(item)) {
                cout << "Item exists in the set.\n";
            }
            else {
                cout << "Item does not exist in the set.\n";
            }

        }
        else if (choice == 4) {
            T* items = set.toArray();
            if (items != nullptr) {
                cout << "Items in the set:\n";
                for (int i = 0; i < set.count(); ++i) {
                    cout << items[i] << " ";
                }
                cout << endl;
                delete[] items;
            }
            else {
                cout << "The set is currently empty.\n";
            }

        }
        else if (choice == 5) {
            cout << "Number of items in the set: " << set.count() << endl;
        }
        else if (choice == 6) {
            cout << "Exiting to main menu!\n";
            break;
        }
    }
}

int main() {
    while (true) {
        cout << "\n--- Select Data Type ---\n";
        cout << "1. Integer\n";
        cout << "2. Float\n";
        cout << "3. String\n";
        cout << "4. Exit\n";
        cout << "Choose a data type:\n";
        int dataTypeChoice;
        cin >> dataTypeChoice;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number between 1 and 4.\n";
            cin.clear();
            while (cin.get() != '\n');
            continue;
        }

        if (dataTypeChoice == 1) {
            cout << "You selected Integer Set.\n";
            handleSet<int>();
        }
        else if (dataTypeChoice == 2) {
            cout << "You selected Float Set.\n";
            handleSet<float>();
        }
        else if (dataTypeChoice == 3) {
            cout << "You selected String Set.\n";
            handleSet<string>();
        }
        else if (dataTypeChoice == 4) {
            cout << "Exiting the program!\n";
            break;
        }
    }
}

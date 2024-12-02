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

    void quickSort(T* arr, int low, int high) {
        if (low < high) {
            T pivot = arr[high];
            int i = low - 1;
            for (int j = low; j < high; j++) {
                if (arr[j] < pivot) {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }
            swap(arr[i + 1], arr[high]);
            int pivotIndex = i + 1;

            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    T* toArray() {
        if (size == 0) {
            return nullptr;
        }
        T* sortedItems = new T[size];
        for (int i = 0; i < size; i++) {
            sortedItems[i] = items[i];
        }
        quickSort(sortedItems, 0, size - 1);
        return sortedItems;
    }
};

class CustomClass {
private:
    int Value;
public:
    CustomClass() : Value(0) {} // Default constructor
    CustomClass(int value) : Value(value) {}

    bool operator==(const CustomClass& other) const {
        return Value == other.Value;
    }
    bool operator!=(const CustomClass& other) const {
        return Value != other.Value;
    }
    bool operator<(const CustomClass& other) const {
        return Value < other.Value;
    }

    friend ostream& operator<<(ostream& os, const CustomClass& obj) {
        os << obj.Value;
        return os;
    }
};

int main() {
    // Test Set<string>
    cout << "Test Set<string>" << endl;
    Set<string> stringSet;

    stringSet.add("cherry");
    stringSet.add("apple");
    stringSet.add("banana");
    stringSet.add("apple");

    cout << "Count: " << stringSet.count() << endl;
    cout << "Contains 'apple': " << (stringSet.contains("apple") ? "Yes" : "No") << endl;

    stringSet.remove("banana");

    cout << "Count after removing 'banana': " << stringSet.count() << endl;

    string* stringArray = stringSet.toArray();
    for (int i = 0; i < stringSet.count(); i++) {
        cout << stringArray[i] << " ";
    }
    cout << endl;

    delete[] stringArray;

    // Test Set<int>
    cout << "Test Set<int>" << endl;
    Set<int> intSet;
    intSet.add(5);
    intSet.add(3);
    intSet.add(8);
    intSet.add(3);
    intSet.add(1);
    intSet.add(6);

    cout << "Count: " << intSet.count() << endl;
    cout << "Contains 3: " << (intSet.contains(3) ? "Yes" : "No") << endl;

    intSet.remove(3);

    cout << "Count after removing 3: " << intSet.count() << endl;

    int* intArray = intSet.toArray();
    for (int i = 0; i < intSet.count(); i++) {
        cout << intArray[i] << " ";
    }
    cout << endl;

    delete[] intArray;

    // Test Set<CustomClass>
    cout << "Test Set<CustomClass>" << endl;
    Set<CustomClass> customSet;
    customSet.add(CustomClass(5));
    customSet.add(CustomClass(3));
    customSet.add(CustomClass(8));
    customSet.add(CustomClass(3));
    customSet.add(CustomClass(1));
    customSet.add(CustomClass(6));

    cout << "Count: " << customSet.count() << endl;

    CustomClass* customArray = customSet.toArray();
    for (int i = 0; i < customSet.count(); i++) {
        cout << customArray[i] << " ";
    }
    cout << endl;

    delete[] customArray;
}

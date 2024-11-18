#include <iostream>
using namespace std;

template <class T>
class Set {
private:
    T* items;        // Dynamic array to store items
    int size;        // Current number of elements in the set
    int capacity;    // Maximum capacity of the array

    void resize(){
        T* temp = new T[capacity * 2];
        for (int i = 0; i < size; i++){
            temp[i] = items[i];
        }
        delete[] items;
        items = temp;
        capacity *= 2;
    }

public:
    Set(){
        items = new T[10];
        size = 0;
        capacity = 10;
    }
    ~Set(){
        delete[] items;
    }
    void add(const T& item){
        if (!contains(item)){
            if (size == capacity){
                resize();
            }
            items[size] = item;
            size++;
        }
    }
    void remove(const T& item){
        for (int i = 0; i < size; i++){
            if (items[i] == item){
                for (int j = i; j < size - 1; j++){
                    items[j] = items[j + 1];
                }
                size--;
                return;
            }
        }
    }
    int count() const{
        return size;
    }
    bool contains(const T& item) const{
        for (int i = 0; i < size; i++){
            if (items[i] == item){
                return true;
            }
        }
        return false;
    }
    T* toArray() const{
        if (size == 0){
            return nullptr;
        }
        T* result = new T[size];
        for (int i = 0; i < size; i++){
            result[i] = items[i];
        }
        return result;
    }
};

int main() {
    Set<int> intSet;

    intSet.add(1);
    intSet.add(2);
    intSet.add(2); // Duplicate, should not be added
    intSet.add(3);

    cout << "Set contains 2? " << (intSet.contains(2) ? "Yes" : "No") << endl;

    intSet.remove(2);
    cout << "Set contains 2 after removal? " << (intSet.contains(2) ? "Yes" : "No") << endl;

    cout << "Set contains 3? " << (intSet.contains(3) ? "Yes" : "No") << endl;
    intSet.remove(3);
    cout << "Set contains 3 after removal? " << (intSet.contains(3) ? "Yes" : "No") << endl;

    intSet.add(4);
    intSet.add(8);
    intSet.add(4);
    intSet.add(6);

    int* items = intSet.toArray();
    if (items != nullptr) {
        cout << "Items in the set after adding and removing operations:\n";
        for (int i = 0; i < intSet.count(); ++i) {
            cout << items[i] << " ";
        }
        cout << endl;
        delete[] items;
    } else {
        cout << "Set is empty." << endl;
    }

    return 0;
}

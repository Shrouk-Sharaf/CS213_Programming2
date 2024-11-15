#include <fstream>
#include <iostream>
using namespace std;

class LabelGenerator {
protected:
    string prefix; // This holds the prefix string
    int idx;       // This is the current index number that will be added to the prefix
public:
    // Constructor that sets up the prefix and the initial index value
    LabelGenerator(const string& prefix, int index = 1) : prefix(prefix), idx(index) {}

    // Method to produce the next label by combining the prefix and the current index
    virtual string nextLabel() {
        return prefix + to_string(idx++); // Combines the prefix with the index converted to string and increments the index
    }

    // Method to update the starting index for label generation
    void setIndex(int newIndex) {
        idx = newIndex;
    }
};

// This derived class produces labels using captions sourced from a designated file
class FileLabelGenerator : public LabelGenerator {
private:
    ifstream file; // This is the stream used to read captions from the file
public:
    // Constructor that opens the specified file and initializes the base class with prefix and index
    FileLabelGenerator(const string& p, int i, const string& filename) : LabelGenerator(p, i), file(filename) {
        if (!file.is_open()) { // Verifies that the file was opened successfully
            cerr << "Error: Unable to open file!" << endl;
            exit(1); // Terminates the program if the file cannot be opened
        }
    }

    // Overrides the nextLabel method to incorporate a line from the file into the generated label
    string nextLabel() override {
        string labelFromFile;
        if (getline(file, labelFromFile)) { // Attempts to read the next line from the file
            return LabelGenerator::nextLabel() + " " + labelFromFile; // Combines the file line with the label
        }
        return ""; // Returns an empty string if there are no more lines to read
    }

    // Destructor ensures that the file is closed if it remains open
    ~FileLabelGenerator() {
        if (file.is_open()) {
            file.close();
        }
    }
};

int main() {
    // Variables for user-defined label prefix and starting index
    string UserPrfx;
    int Start_idx, Stop_idx;

    cout << "Enter the label prefix:\n";
    cin >> UserPrfx;
    cout << "Do you want to start with the default index (1)? (Y/N)\n";
    char choose;
    cin >> choose;
    if (choose == 'Y' || choose == 'y'){
        Start_idx = 1;
        Stop_idx = 3; // Default stopping index
    }
    else {
        cout << "Enter the starting index:\n";
        cin >> Start_idx;
        cout << "Enter the stopping index:\n";
        cin >> Stop_idx;
    }

    UserPrfx += " ";  // Appending a space after the prefix for better formatting

    // Instantiate a LabelGenerator using the user-defined prefix and starting index
    LabelGenerator userLabels(UserPrfx, Start_idx);

    // Generate and display number of sequential labels based on user input
    cout << "Generated labels: ";
    for (int i = Start_idx; i <= Stop_idx; i++) { // Loop to include Stop_idx
        cout << userLabels.nextLabel();
        if (i < Stop_idx) cout << ", "; // Prevents a trailing comma
    }

    cout << endl;

    // Create a FileLabelGenerator with user-defined prefix, starting index, and filename
    cout << "Enter the filename to read captions from:\n";
    string File;
    cin >> File;
    cout << "Enter the label prefix for the file:\n";
    string userFilePrefix;
    cin >> userFilePrefix;

    userFilePrefix += " ";  // Appending a space after the prefix for better formatting

    FileLabelGenerator fileLabels(userFilePrefix, 1, File);

    // Set the starting index for the FileLabelGenerator
    fileLabels.setIndex(1);
    cout << "Labels with captions from file:\n";

    // Generate and display labels until all lines in the file have been processed
    string label;
    while (!(label = fileLabels.nextLabel()).empty()) {
        cout << label << endl;
    }
}
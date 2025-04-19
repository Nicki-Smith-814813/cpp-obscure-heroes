//****************************************************
//Author.....: Nicki Smith
//Assignment.: Obscure Superheroes Database
//Description: Just look at the README.md please :] 
//****************************************************

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <algorithm> 

using namespace std;

// --- Constants ---
const int MAX_HEROES = 100;
int heroCount = 5;

// --- Colors for terminal output ---
enum Color { RED = 31, GREEN = 32, YELLOW = 33, BLUE = 34, CYAN = 36 };

// --- Superhero Data Arrays ---
string names[MAX_HEROES];
string powers[MAX_HEROES];
string weaknesses[MAX_HEROES];
int metadata[MAX_HEROES][2]; // [0] - Year Introduced, [1] - Universe (1 = Marvel, 2 = DC, 3 = Other)
int popularity[MAX_HEROES];

// --- Function to Colorize Output ---
string colorize(string text, Color color) {
    return "\033[1;" + to_string(color) + "m" + text + "\033[0m";
}

// --- Superhero Database Functions ---
void searchByName(string name);
void findByPower(string power);
void sortByName();
void sortByPopularity();
void displayAll(bool uppercase);
void addHero();
void randomHero();

// --- Main Function ---
int main() {
    // Initial data
    names[0] = "Squirrel Girl"; powers[0] = "Control Squirrels"; weaknesses[0] = "Time Limits"; metadata[0][0] = 1992; metadata[0][1] = 1; popularity[0] = 75;
    names[1] = "Arm-Fall-Off-Boy"; powers[1] = "Detachable Limbs"; weaknesses[1] = "Heavy Objects"; metadata[1][0] = 1989; metadata[1][1] = 2; popularity[1] = 60;
    names[2] = "The Tick"; powers[2] = "Super Strength"; weaknesses[2] = "Poor Judgment"; metadata[2][0] = 1986; metadata[2][1] = 3; popularity[2] = 80;
    names[3] = "Doctor Light"; powers[3] = "Light Manipulation"; weaknesses[3] = "Strong Emotions"; metadata[3][0] = 1961; metadata[3][1] = 2; popularity[3] = 50;
    names[4] = "Zonko"; powers[4] = "Gravity Manipulation"; weaknesses[4] = "Focused Energy"; metadata[4][0] = 2010; metadata[4][1] = 3; popularity[4] = 40;

    int choice;
    do {
        cout << "\n--- Superhero Database Menu ---\n";
        cout << "1. Search for a superhero by name\n";
        cout << "2. Find superheroes by power\n";
        cout << "3. Sort superheroes alphabetically\n";
        cout << "4. Sort superheroes by popularity\n";
        cout << "5. Display all superheroes\n";
        cout << "6. Add a new superhero\n";
        cout << "7. Generate a random superhero\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character left in the buffer

        string input;
        switch(choice) {
            case 1:
                cout << "Enter superhero name to search: ";
                getline(cin, input);
                searchByName(input);
                break;
            case 2:
                cout << "Enter superpower to search for: ";
                getline(cin, input);
                findByPower(input);
                break;
            case 3:
                sortByName();
                break;
            case 4:
                sortByPopularity();
                break;
            case 5:
                cout << "Display all superheroes in (1) Uppercase or (2) Lowercase: ";
                int formatChoice;
                cin >> formatChoice;
                displayAll(formatChoice == 1);
                break;
            case 6:
                addHero();
                break;
            case 7:
                randomHero();
                break;
            case 8:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 8);

    return 0;
}

// Search for a superhero by name (case-insensitive)
void searchByName(string name) {
    bool found = false;
    for (int i = 0; i < heroCount; i++) {
        string tempName = names[i];
        string tempSearch = name;
        for (char& c : tempName) c = tolower(c);
        for (char& c : tempSearch) c = tolower(c);

        if (tempName.find(tempSearch) != string::npos) {
            cout << colorize("\nSuperhero Found!\n", GREEN);
            cout << colorize("Name: ", CYAN) << names[i] << endl;
            cout << colorize("Power: ", CYAN) << powers[i] << endl;
            cout << colorize("Weakness: ", CYAN) << weaknesses[i] << endl;
            cout << colorize("Year Introduced: ", CYAN) << metadata[i][0] << endl;
            string universe = (metadata[i][1] == 1) ? "Marvel" : (metadata[i][1] == 2) ? "DC" : "Other";
            cout << colorize("Universe: ", CYAN) << universe << endl;
            cout << colorize("Popularity: ", CYAN) << popularity[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << colorize("No superhero found with that name.\n", RED);
    }
}

// Find superheroes by their power
void findByPower(string power) {
    bool found = false;
    for (int i = 0; i < heroCount; i++) {
        string tempPower = powers[i];
        string tempSearch = power;
        for (char& c : tempPower) c = tolower(c);
        for (char& c : tempSearch) c = tolower(c);

        if (tempPower.find(tempSearch) != string::npos) {
            cout << colorize(names[i], BLUE) << " - " << powers[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << colorize("No superheroes found with that power.\n", RED);
    }
}

// Sort superheroes alphabetically
void sortByName() {
    for (int i = 0; i < heroCount - 1; i++) {
        for (int j = i + 1; j < heroCount; j++) {
            if (names[i] > names[j]) {
                swap(names[i], names[j]);
                swap(powers[i], powers[j]);
                swap(weaknesses[i], weaknesses[j]);
                swap(metadata[i][0], metadata[j][0]);
                swap(metadata[i][1], metadata[j][1]);
                swap(popularity[i], popularity[j]);
            }
        }
    }
    cout << colorize("Heroes sorted alphabetically!\n", GREEN);
    displayAll(false);
}

// Sort superheroes by popularity (highest to lowest)
void sortByPopularity() {
    for (int i = 0; i < heroCount - 1; i++) {
        for (int j = i + 1; j < heroCount; j++) {
            if (popularity[i] < popularity[j]) {
                swap(names[i], names[j]);
                swap(powers[i], powers[j]);
                swap(weaknesses[i], weaknesses[j]);
                swap(metadata[i][0], metadata[j][0]);
                swap(metadata[i][1], metadata[j][1]);
                swap(popularity[i], popularity[j]);
            }
        }
    }
    cout << colorize("Heroes sorted by popularity!\n", GREEN);
    displayAll(false);
}

// Display all superheroes
void displayAll(bool uppercase) {
    cout << colorize("\n--- Superhero List ---\n", YELLOW);

    // Step 1: Find the maximum lengths for each column
    int maxNameLen = 4; // "Name" length
    int maxPowerLen = 5; // "Power" length
    int maxWeaknessLen = 8; // "Weakness" length

    for (int i = 0; i < heroCount; i++) {
        if (names[i].length() > maxNameLen) maxNameLen = names[i].length();
        if (powers[i].length() > maxPowerLen) maxPowerLen = powers[i].length();
        if (weaknesses[i].length() > maxWeaknessLen) maxWeaknessLen = weaknesses[i].length();
    }

    // Optional: Set a maximum cap so columns don't get crazy wide
    if (maxNameLen > 20) maxNameLen = 20;
    if (maxPowerLen > 30) maxPowerLen = 30;
    if (maxWeaknessLen > 30) maxWeaknessLen = 30;

    // Step 2: Print headers dynamically
    cout << left
    << setw(maxNameLen + 15) << colorize("Name", CYAN)
    << setw(maxPowerLen + 15) << colorize("Power", CYAN)
    << setw(maxWeaknessLen + 12) << colorize("Weakness", CYAN)
    << setw(22) << colorize("Year", CYAN)
    << setw(24) << colorize("Universe", CYAN)
    << setw(15) << colorize("Popularity", CYAN)
    << endl;


    // Print separator line
    cout << colorize(string(maxNameLen + maxPowerLen + maxWeaknessLen + 46, '-'), YELLOW) << endl;

    // Step 3: Print each hero
    for (int i = 0; i < heroCount; i++) {
        string outputName = names[i];
        string outputPower = powers[i];
        string outputWeakness = weaknesses[i];

        if (outputName.length() > maxNameLen) outputName = outputName.substr(0, maxNameLen - 1) + ".";
        if (outputPower.length() > maxPowerLen) outputPower = outputPower.substr(0, maxPowerLen - 1) + ".";
        if (outputWeakness.length() > maxWeaknessLen) outputWeakness = outputWeakness.substr(0, maxWeaknessLen - 1) + ".";

        if (uppercase) {
            for (char& c : outputName) c = toupper(c);
            for (char& c : outputPower) c = toupper(c);
            for (char& c : outputWeakness) c = toupper(c);
        } else {
            for (char& c : outputName) c = tolower(c);
            for (char& c : outputPower) c = tolower(c);
            for (char& c : outputWeakness) c = tolower(c);
        }

        string universe = (metadata[i][1] == 1) ? "Marvel" : (metadata[i][1] == 2) ? "DC" : "Other";

        cout << left
             << setw(maxNameLen + 2) << outputName
             << setw(maxPowerLen + 2) << outputPower
             << setw(maxWeaknessLen + 5) << outputWeakness
             << setw(16) << metadata[i][0]
             << setw(16) << universe
             << setw(16) << popularity[i]
             << endl;
    }
}




// Add a new superhero dynamically
void addHero() {
    if (heroCount >= MAX_HEROES) {
        cout << colorize("Database full! Cannot add more heroes.\n", RED);
        return;
    }

    cout << "Enter superhero name: ";
    getline(cin, names[heroCount]);

    cout << "Enter superpower: ";
    getline(cin, powers[heroCount]);

    cout << "Enter weakness: ";
    getline(cin, weaknesses[heroCount]);

    cout << "Enter year introduced: ";
    cin >> metadata[heroCount][0];
    cin.ignore();

    cout << "Enter universe (1=Marvel, 2=DC, 3=Other): ";
    cin >> metadata[heroCount][1];
    cin.ignore();

    cout << "Enter popularity (1-100): ";
    cin >> popularity[heroCount];
    cin.ignore();

    heroCount++;
    cout << colorize("Hero added successfully!\n", GREEN);
}

// Generate a random superhero
void randomHero() {
    srand(time(0));
    int index = rand() % heroCount;
    cout << colorize("\nRandom Hero:\n", YELLOW);
    cout << colorize("Name: ", CYAN) << names[index] << endl;
    cout << colorize("Power: ", CYAN) << powers[index] << endl;
    cout << colorize("Weakness: ", CYAN) << weaknesses[index] << endl;
    cout << colorize("Year Introduced: ", CYAN) << metadata[index][0] << endl;
    string universe = (metadata[index][1] == 1) ? "Marvel" : (metadata[index][1] == 2) ? "DC" : "Other";
    cout << colorize("Universe: ", CYAN) << universe << endl;
    cout << colorize("Popularity: ", CYAN) << popularity[index] << endl;
}

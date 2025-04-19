## Superhero Database Program
Description
The Superhero Database Program is a C++ console-based application that allows you to store, search, and manage a collection of superheroes. Each superhero has the following attributes:

Name

Superpower

Weakness

Year Introduced

Comic Universe (Marvel, DC, or Other)

Popularity

This program provides functionalities to search, sort, and display superheroes in various formats, as well as adding new superheroes dynamically. It includes features such as case-insensitive search, sorting by name or popularity, and even generating a random superhero.

Bonus Features:
Add a New Superhero: Dynamically add a new superhero to the database.

Random Superhero Generator: Display a random superhero from the database.

Popularity Sorting: Sort superheroes by their popularity score.

Formatted Display: Display superhero details in uppercase or lowercase.

Alphabetical Sorting: Sort superheroes alphabetically by name.

Features:
Search by Name: Search superheroes by their name, case-insensitive.

Search by Power: Find superheroes with a specific power.

Sort by Name: Sort superheroes alphabetically.

Sort by Popularity: Sort superheroes based on their popularity score.

Display All: View a list of all superheroes with their attributes.

Add New Superhero: Add a new superhero to the database.

Generate Random Superhero: Get a random superhero from the list.

## How to Compile and Run
Clone the repository or download the files to your local machine.

Navigate to the directory where the superhero_database.cpp file is located.

Open a terminal/command prompt and compile the program using g++ (or any other C++ compiler):

g++ superhero_database.cpp -o superhero_database

Run the executable:
./superhero_database

Sample Menu
Upon running the program, you will be presented with the following menu options:

--- Superhero Database Menu ---
1. Search for a superhero by name
2. Find superheroes by power
3. Sort superheroes alphabetically
4. Sort superheroes by popularity
5. Display all superheroes
6. Add a new superhero
7. Generate a random superhero
8. Exit
You can choose any option by entering the corresponding number.

Example Output
Displaying all superheroes:
bash
Copy
Edit
--- Superhero List ---
Name                 Power               Weakness            Year      Universe     Popularity
---------------------------------------------------------------------------------------------
Squirrel Girl        Control Squirrels   Time Limits         1992      Marvel       75
Arm-Fall-Off-Boy    Detachable Limbs    Heavy Objects       1989      DC           60
The Tick            Super Strength      Poor Judgment       1986      Other        80
Doctor Light        Light Manipulation  Strong Emotions     1961      DC           50
Zonko               Gravity Manipulation Focused Energy    2010      Other        40
Searching by Name:

Enter superhero name to search: Squirrel Girl
Superhero Found!
Name: Squirrel Girl
Power: Control Squirrels
Weakness: Time Limits
Year Introduced: 1992
Universe: Marvel
Popularity: 75
Sorting by Popularity:


Heroes sorted by popularity!
Adding a New Superhero:

Enter superhero name: NewHero
Enter superpower: Invisibility
Enter weakness: Light Sensitivity
Enter year introduced: 2023
Enter universe (1=Marvel, 2=DC, 3=Other): 1
Enter popularity (1-100): 90
Hero added successfully!
File Structure
superhero_database.cpp: Main program file.

README.md: Documentation file (this one).

License
This project is open-source and free to use. Feel free to make improvements or fork the repository for your own use.

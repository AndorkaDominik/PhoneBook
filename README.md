# Phone Book Application

This C++ project is developed as part of a university homework assignment. The program is designed to manage phone book data, including functionalities for adding, modifying, deleting, and saving contact information.

## Overview

This C++ application manages a phone book with functionalities to add, modify, delete, and save contact information. It supports operations such as loading data from a file and saving data to a file. The application uses classes to represent a person (`Szemely`), a phone book (`Telefonkonyv`), and file handling operations (`FajlKezelo`).

## Classes

### `Szemely`

Represents a person with the following attributes:
- Name (`nev`)
- Nickname (`becenev`)
- Address (`cim`)
- Work phone number (`munkahelyiTel`)
- Private phone number (`privatTel`)

**Methods:**
- Constructor to initialize all attributes
- Getters and setters for each attribute
- `print()` to display person's information

### `Telefonkonyv`

Represents a phone book that can store up to 100 people. Provides methods for:
- Adding a person (`adatokFelvetele`)
- Retrieving and displaying all contacts (`adatokLekerese`)
- Searching for a person by name (`keresesNevAlapjan`)
- Modifying a person's information (`adatokModositasa`)
- Deleting a person (`adatokTorlese`)
- Saving contacts to a file (`adatokMentes`)

### `FajlKezelo`

Handles file operations for the phone book. Provides static methods for:
- Loading contacts from a file (`adatokBetoltese`)
- Saving contacts to a file (`adatokMentes`)

## Functions

### `menu(Telefonkonyv& tk)`

Displays a menu to interact with the phone book. Provides options to:
1. Retrieve and display all contacts
2. Add a new contact
3. Modify an existing contact
4. Delete a contact
5. Save all contacts to a file
0. Exit the application

## Notes
- Ensure that the data file (telefonkonyv.txt) exists in the same directory as the executable if you want to load data.
- The phone book can store up to 100 contacts.

> [!Warning]
> ## License
> This project is for educational purposes and is licensed under the AGPL-3.0 License.

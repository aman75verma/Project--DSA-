# Student Database Management System

This C++ program is a simple **Student Database Management System** that allows you to manage student records. It demonstrates the use of **file handling**, **object-oriented programming (OOP)**, and **basic data structures** like vectors. The program stores student data in a file (`students.dat`) and provides a menu-driven interface for performing various operations.

---

## Functionality

The program provides the following functionalities:

1. **Add New Student**:  
   Add a new student record with details such as:
   - Student code (unique identifier)
   - Name and surname
   - Gender (M/F)
   - Enrollment year
   - Grade (0-20)

2. **Search by Code**:  
   Search for a student using their unique student code.

3. **Search by Name**:  
   Search for students by their name or surname (partial matches are supported).

4. **Delete Student**:  
   Delete a student record using their student code.

5. **Update Student**:  
   Update the details of an existing student (e.g., name, surname, gender, year, or grade).

6. **List All Students**:  
   Display all the student records stored in the database.

7. **Save and Load Data**:  
   The program automatically saves student data to a file (`students.dat`) and loads it when the program starts.

---

## Concepts and Methods Used

### 1. **File Handling**
   - The program uses `ifstream` and `ofstream` to read from and write to a file (`students.dat`).
   - Data is stored in a structured format (CSV-like) for easy retrieval and updating.

### 2. **Object-Oriented Programming (OOP)**
   - **Class**: `StudentDatabase` encapsulates all the functionality for managing student records.
   - **Struct**: `Student` represents a single student record with attributes like code, name, surname, gender, year, and grade.
   - **Methods**: The class includes methods for adding, searching, updating, deleting, and listing students.

### 3. **Data Structures**
   - **Vector**: A `vector<Student>` is used to store and manage student records in memory.

### 4. **Input Validation**
   - The program ensures that grades are within the valid range (0-20).
   - It checks for duplicate student codes when adding new students.

### 5. **Menu-Driven Interface**
   - A simple text-based menu allows users to interact with the program and perform operations.

---

## How to Use

1. **Compile the Code**:  
   Use a C++ compiler (e.g., `g++`) to compile the code:
   ```bash
   g++ student_database.cpp -o student_database

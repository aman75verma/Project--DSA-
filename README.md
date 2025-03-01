# Student Database Management System 

This C++ program is a **Student Database Management System** enhanced with **Data Structures and Algorithms (DSA)**. It allows you to manage student records efficiently using advanced data structures and algorithms.

---

## Functionality

1. **Add New Student**:  
   Add a new student record with details like code, name, surname, gender, year, and grade.

2. **Search by Code**:  
   Use a **hash table** for O(1) lookup of students by their unique code.

3. **Search by Name**:  
   Search for students by their name or surname (partial matches supported).

4. **Delete Student**:  
   Delete a student record by their code.

5. **Update Student**:  
   Update the details of an existing student.

6. **List All Students**:  
   Display all student records.

7. **Sort Students by Grade**:  
   Use **QuickSort** to sort students by their grades in ascending order.

8. **Find Top Performers**:  
   Use a **priority queue (min-heap)** to find the top N students with the highest grades.

---

## Concepts and Methods Used

### 1. **Data Structures**
   - **Vector**: To store and manage student records.
   - **Hash Table**: For O(1) lookup of students by their codes.
   - **Priority Queue (Min-Heap)**: To find the top N performers efficiently.

### 2. **Algorithms**
   - **QuickSort**: To sort students by their grades.
   - **Binary Search**: For faster searching (if implemented on sorted data).
   - **Heap Operations**: To maintain and extract top performers.

### 3. **File Handling**
   - Data is stored in `students.dat` for persistence.

### 4. **Menu-Driven Interface**
   - A simple text-based menu for user interaction.

---

## How to Use

1. **Compile the Code**:  
   Use a C++ compiler (e.g., `g++`):
   ```bash
   g++ student_database.cpp -o student_database

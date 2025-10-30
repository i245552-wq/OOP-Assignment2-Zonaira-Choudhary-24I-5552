# 📘 DSA Assignment — Stack, Queue & Linked List Implementations (C++)

## 🧑‍🎓 Course Information
**Course:** Data Structures and Algorithms  
**Language:** C++  
**Submitted by:** Zonaira Choudhary  
**Institution:** FAST-NUCES, Islamabad  
**Semester:** 3rd — BS FinTech  
**Instructor:** Sir Abdulwahab Tahir  
**Date:** 30th October 2025

---

## 📖 Overview
This repository contains **five C++ programs** implementing different data structures and recursion-based operations.  
Each question demonstrates core DSA concepts such as **recursion**, **linked lists**, **queues**, and **stacks** (both array-based and linked-list-based).

---

## 🧩 Contents
| Question | Topic | Data Structure / Concept |
|-----------|--------|--------------------------|
| Q1 | Recursive Functions | Array manipulation & pattern printing |
| Q2 | Inheritance & Polymorphism | Abstract classes + Singly Linked List |
| Q3 | Library System | Doubly Linked List |
| Q4 | Ticket Queue Simulation | Array-based Queue |
| Q5 | Stack Operations | Array-based and Linked List-based Stacks |

---

## 🧮 Question-wise Summary

### 🧠 **Q1 – Recursion**
- **Part A:** Recursive function `changeLocation()` swaps array elements between two positions `b1` and `b2`.
- **Part B:** Recursive and iterative pattern printing using decreasing and increasing sequences.

🔹 **Concepts Used:**
- Recursion (Base and Recursive case)
- Array traversal
- Pattern generation

---

### 🌊 **Q2 – Abstract Class with Singly Linked List**
Implements an abstract class `Feature` with two derived classes:
- `LandFeature`
- `WaterFeature`

Stores features in a **Singly Linked List** supporting:
- Insertion at end
- Deletion by ID
- Reversing list
- Polymorphic `analyze()` function

🔹 **Concepts Used:**
- Abstract classes and inheritance  
- Polymorphism (Runtime using `virtual` methods)  
- Dynamic memory management  
- Linked list traversal and reversal  

---

### 📚 **Q3 – Library Management System**
Uses a **Doubly Linked List** to manage a library’s collection of books.  
Supports:
- Add at beginning, end, or specific position  
- Delete book by ID  
- Display forward and backward  

🔹 **Concepts Used:**
- Doubly linked list nodes with `next` and `prev` pointers  
- Bidirectional traversal  
- Dynamic insertion and deletion  

---

### 🎟️ **Q4 – Ticket Queue System**
Implements a **Queue** for managing customer ticket purchases.  
Each customer has:
- `ID`, `Name`, and `Tickets`

Supports:
- Enqueue (Add customer)
- Dequeue (Serve customer)
- Display current queue

🔹 **Concepts Used:**
- Array-based circular queue logic  
- Front and rear pointer management  
- Queue overflow and underflow handling  

---

### 🧱 **Q5 – Stack Implementations and Pattern Reversal**
Implements **two stack types**:
1. **Array-based stack**
2. **Linked list-based stack**

Used for:
- Reversing a portion of an array (`ChangeLocation`)
- Printing patterns iteratively (`PrintPattern`)

#### 🔍 Algorithm Analysis
| Operation | Array Stack | Linked List Stack | Remarks |
|------------|--------------|------------------|----------|
| Push | O(1) | O(1) | Array slightly faster (contiguous memory) |
| Pop | O(1) | O(1) | Both constant time |
| Memory | Fixed | Dynamic | Linked list uses extra memory |
| Flexibility | Limited (fixed size) | Unlimited | Linked list better for dynamic data |

**Conclusion:**  
Both have constant-time operations, but array stacks are faster; linked list stacks offer flexibility and avoid overflow.

---

## ⚙️ How to Compile & Run
```bash
# Compile using g++
g++ q1.cpp -o q1
./q1

g++ q2.cpp -o q2
./q2

g++ q3.cpp -o q3
./q3

g++ q4.cpp -o q4
./q4

g++ q5.cpp -o q5
./q5

Library Management System
Project Description
A simple, robust console-based Library Management System developed in C++ to demonstrate core Object-Oriented Programming (OOP) principles. It allows managing different types of library items such as books and magazines, tracking their availability, and handling check-outs and returns.

Project Objectives
Demonstrate practical application of C++ and OOP.
Manage library inventory efficiently using dynamic polymorphism and inheritance.
Provide a clean and modular code architecture.

OOP Concepts Applied
Classes and Objects: Defined LibraryItem, Book, and Magazine classes and instantiated them in the main program.
Encapsulation: Hidden internal data using private and protected access modifiers, exposing safe interfaces via getters and setters.
Constructors & Destructors: Initialized object states cleanly and managed memory with virtual destructors.
Inheritance: Book and Magazine inherit properties and methods from the base class LibraryItem.
Polymorphism: Implemented pure virtual functions (displayInfo) overridden in derived classes, allowing dynamic behavior through base class pointers.
Function Overloading: Overloaded the checkOut() method to support both standard check-outs and custom duration check-outs.

Compiling and Running Instructions
Make sure you have a C++ compiler installed (like GCC, Clang, or MSVC).
Open your terminal or command prompt in the project directory.
Compile the source code using the following command:```bash
g++ main.cpp -o library_system

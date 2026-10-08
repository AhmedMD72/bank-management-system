# Bank Management System

A console-based Bank Management System developed in C++ as an Object-Oriented Programming project.

The project simulates basic banking operations for customers and administrators while applying OOP concepts and separating the system into multiple components.

## Features

### Customer
- Customer login
- Withdraw money
- Deposit money
- Transfer money between accounts
- View transaction history
- View and update account information

### Admin
- Admin login
- Create customer accounts
- Display all customers
- Search for an account
- Delete customer accounts

## Concepts Used

- Object-Oriented Programming
- Inheritance
- Encapsulation
- Composition
- References
- STL Vector
- Optional
- JSON file handling
- File I/O

## Technologies

- C++17
- nlohmann/json
- JSON
- Git / GitHub

## Project Structure

```text
bank-management-system/
├── include/
├── src/
├── data/
├── main.cpp
├── README.md
└── .gitignore
```

## Build and Run

### 1. Clone the Repository

```bash
git clone https://github.com/AhmedMD72/bank-management-system.git
cd bank-management-system
```

### 2. Build the Project

Make sure you have a C++17-compatible compiler such as GCC installed.

```bash
g++ -std=c++17 main.cpp src/*.cpp -Iinclude -o main
```

### 3. Run the Program

On Linux or macOS:

```bash
./main
```

On Windows using MinGW:

```bash
main.exe
```

## Data Storage

The system uses JSON files to store customer and administrator data.

The data files are located inside the:

```text
data/
```

directory.

Customer balances, personal information, and transaction history are stored persistently, so changes remain available after the program is closed.

## Notes

- The project uses sample data for testing.
- Customer and administrator information is stored using JSON files.
- The project was developed to practice C++ Object-Oriented Programming and multi-file project organization.
- The project is currently console-based.

## Author

Developed by Ahmed Medhat.
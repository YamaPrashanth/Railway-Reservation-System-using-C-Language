# Railway Reservation System using C Language

A console-based Railway Reservation System developed using the C programming language.  
This project simulates the basic functionalities of a railway ticket booking system such as user authentication, train listing, ticket reservation, and ticket cancellation.

The project is mainly designed for beginners to understand:

- File Handling in C
- Linked List Data Structure
- User Authentication System
- Dynamic Memory Allocation
- Menu-Driven Programming

# Project Overview

The Railway Reservation System allows users to:

- Create a new account using Sign-Up
- Login securely using Sign-In
- View available trains
- Reserve train tickets
- Cancel booked tickets
- Track available seats dynamically

Train records are stored using a **Singly Linked List**, while user credentials are stored using **File Handling**.

# Train Management

Default train details are loaded automatically when the program starts.

Users can:

- View train list
- Check seat availability
- Reserve seats
- Cancel seats

# Ticket Reservation
- User enters train number
- User enters required seats
- Seats are reduced after successful booking
- Prevents overbooking
  
# Ticket Cancellation
- User can cancel reserved seats
- Seat count is restored automatically

# Technologies Used
| Technology	| Purpose |
| ------------------------- | ------------------------ |
| C Language |	Core Programming |
| Linked List |	Train Data Storage |
| File Handling |	Login Credential Storage |
| Structures |	Organizing Data |
| Dynamic Memory Allocation |	Creating Train Nodes |

# Program Flow
## MENU-1
1. Sign-Up
2. Sign-In
## Sign-Up Process
- User enters username
- System checks uniqueness
- User creates strong password
- Credentials stored in file
- Redirected to Sign-In
## Sign-In Process
- User enters username/password
- Credentials verified from file
- Access granted if matched
## MENU-2
- R. Reserve Ticket
- C. Cancel Ticket
- B. Train List
- Q. Quit
# How to Run the Project
## Step 1: Compile the Program
- Linux / Mac
-- gcc railway.c -o railway
- Windows
-- gcc railway.c -o railway.exe
## Step 2: Run the Program
- Linux / Mac
-- ./railway
- Windows
-- railway.exe
# Sample Output
# Main Menu
## ------------------MENU-1------------------
1. Sign-Up
2. Sign-In

## Choose:
Train List

## Default Train Details

| Train No | Train Name         | Source | Destination | Available Seats |
|-----------|-------------------|--------|-------------|------------------|
| 12701     | Hussain Sagar Exp | HYD    | MUM         | 5                |
| 12702     | Godavari Exp      | HYD    | VSKP        | 5                |
| 12703     | Charminar Exp     | HYD    | CHN         | 5                |

# Features

## User Authentication
- New users can register using Sign-Up
- Existing users can login using Sign-In
- Username uniqueness checking
- Maximum login attempt restriction

## Strong Password Validation
The system accepts only strong passwords containing:

- Minimum 8 characters
- Uppercase letter
- Lowercase letter
- Number
- Special character

Example:

```txt
Train@123

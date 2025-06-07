# Banking System (C++)

## Overview
This is a command-line banking application developed in C++ that simulates real-world banking operations. It supports a multi-role system, including **Admin**, **Employee**, and **Customer**, allowing for comprehensive account management, secure transactions, and thorough auditing.

## Features

### Admin Panel
The Admin panel provides robust control and oversight functionalities:
* **View Total Bank Balance:** Get an aggregated view of all funds.
* **Track Account Status:** Monitor the number of live (active) and closed accounts.
* **Audit All Transactions:** Review a complete record of every transaction performed within the system.
* **Manage Employees:** Control employee IDs and maintain the overall employee list.

### Employee Panel
Designed for bank staff, the Employee panel offers operational capabilities:
* **Employee ID Management:** Create and delete employee accounts.
* **Password Management:** Facilitate password changes and recovery for employee accounts, including OTP (One-Time Password) verification for security.
* **Customer Account Operations:** Perform various banking operations on behalf of customers (e.g., account opening, balance inquiries, transactions).

### Customer (Banking Panel)
The primary interface for bank customers, offering essential self-service banking features:
* **Account Management:** Open new bank accounts and request account closures.
* **Transaction Capabilities:** Deposit funds, withdraw money, and transfer money between accounts.
* **Financial Overview:** View current account balance and access a detailed transaction history for each account.
* **History Maintenance:** All transactions are logged and maintained for individual accounts, ensuring a complete record.

## Architecture
The system is structured using Object-Oriented Programming (OOP) principles, with a clear inheritance hierarchy to manage different user roles and their respective permissions:

* **`Admin_Panel` class:** Serves as the base class, encapsulating core administrative tasks and global system tracking functionalities.
* **`Employee_Panel` class:** Inherits from `Admin_Panel`, extending its capabilities to include employee-specific management and operations.
* **`Banking_Panel` class:** Inherits from `Employee_Panel`, providing the customer-facing functionalities and managing individual banking operations.

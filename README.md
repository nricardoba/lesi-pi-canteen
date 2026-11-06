# PI Project - Meal Ticket and Employee Management

## Description

This project, developed for the Imperative Programming course at IPCA, is a C application for managing cafeteria operations including employees, weekly menus, and meal tickets. It provides a terminal-based interactive interface for creating, listing, and persisting data across sessions using text files.

## Features

- **Employee Management:** Add new employees (with ID, name, tax ID, and phone number), list all employees in a formatted table, and check for duplicate IDs.
- **Menu Management:** Create weekly menus with four meal options per day (fish, meat, diet, and vegetarian) including calorie counts, and list all menus in a detailed table.
- **Meal Ticket Management:** Manage meal tickets associated with employees and menu entries.
- **File Persistence:** Read from and write to text files (`employees.txt`, `menus.txt`) using semicolon-delimited formats.
- **Terminal Interface:** Interactive menus with input validation for all operations.

## Project Structure

| File            | Description                                                                |
| --------------- | -------------------------------------------------------------------------- |
| `main.c`        | Entry point, main loop, menus, and CRUD operations for employees and menus |
| `helpers.h`     | Header file with struct definitions, constants, and function prototypes    |
| `helpers.c`     | Utility functions (input reading, duplicate checking, display helpers)     |
| `employees.txt` | Employee data file (semicolon-delimited)                                   |
| `menus.txt`     | Weekly menu data file (semicolon-delimited)                                |
| `makefile`      | Build automation                                                           |

The application reads and writes `employees.txt` and `menus.txt` in the current working directory. These replace the previous Portuguese filenames; the semicolon-delimited record formats are unchanged.

## Data Structures

- **`employee_data`** - Employee record: ID, name, tax ID, phone number.
- **`menu_entry`** - Menu entry: day of the week, date, four dish options (fish, meat, diet, vegetarian) each with calorie count.
- **`meal_ticket`** - Meal ticket: ID, day of the week, selected dish.

## Building

To build and run the project, use the provided `makefile`:

```sh
make
```

## Grade

This project received a grade of **19 out of 20**.

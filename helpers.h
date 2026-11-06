/**
 * @file helpers.h
 * @author Ricardo Araújo (a21150@alunos.ipca.pt)
 * @brief Project header
 * @version 0.2
 * @date 24-12-2024
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 50
#define MAX_EMPLOYEES 100
#define MAX_MENU_ENTRIES 7
#define MAX_MEAL_TICKETS 200

typedef struct {
    int id;
    char name[MAX_TEXT_LENGTH];
    int tax_id;
    int phone_number;
} employee_data;

typedef struct {
    char day_of_week[MAX_TEXT_LENGTH];
    int day;
    int month;
    int year;
    char fish[MAX_TEXT_LENGTH];
    int fish_calories;
    char meat[MAX_TEXT_LENGTH];
    int meat_calories;
    char diet[MAX_TEXT_LENGTH];
    int diet_calories;
    char vegetarian[MAX_TEXT_LENGTH];
    int vegetarian_calories;
} menu_entry;

typedef struct {
    int id;
    char day_of_week[MAX_TEXT_LENGTH];
    char dish[MAX_TEXT_LENGTH];
} meal_ticket;

// Main functions
int main_menu();
int employee_menu();
int weekly_menu();
int meal_ticket_menu();

// Employees
int load_employees(employee_data employees[MAX_EMPLOYEES], int employee_count);
void save_employees(employee_data employees[MAX_EMPLOYEES], int employee_count);
int add_employee(employee_data employees[MAX_EMPLOYEES], int employee_count);
void list_employees(employee_data employees[MAX_EMPLOYEES], int employee_count);

// Menus
int load_menus(menu_entry menus[MAX_MENU_ENTRIES], int menu_count);
void save_menus(menu_entry menus[MAX_MENU_ENTRIES], int menu_count);
int add_menu(menu_entry menus[MAX_MENU_ENTRIES], int menu_count);
void list_menus(menu_entry menus[MAX_MENU_ENTRIES], int menu_count);

// Helper functions
int read_integer(char prompt[]);
float read_float(char prompt[]);
void read_string(char prompt[], char response[]);
bool employee_exists(employee_data employees[MAX_EMPLOYEES], int employee_count,
                     int id);
void pause_screen();
void print_separator(int width);

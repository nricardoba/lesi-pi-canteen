/**
 * @file main.c
 * @author Ricardo Araújo (a21150@alunos.ipca.pt)
 * @brief Meal ticket and employee management project
 * @version 0.2
 * @date 24-12-2024
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "helpers.h"

int main() {
    employee_data employees[MAX_EMPLOYEES];
    menu_entry menus[MAX_MENU_ENTRIES];
    meal_ticket tickets[MAX_MEAL_TICKETS];
    int employee_count = 0, menu_count = 0, ticket_count = 0;
    int option, submenu_option;
    bool finished = false, submenu_finished;

    while (!finished) {
        submenu_finished = false;
        option = main_menu();

        if (option == 1) {
            while (!submenu_finished) {
                submenu_option = employee_menu();
                switch (submenu_option) {
                case 1:
                    employee_count = load_employees(employees, employee_count);
                    break;
                case 2:
                    save_employees(employees, employee_count);
                    break;
                case 3:
                    employee_count = add_employee(employees, employee_count);
                    break;
                case 4:
                    list_employees(employees, employee_count);
                    break;
                default:
                    submenu_finished = true;
                }
                if (submenu_option != 0)
                    pause_screen();
            }
        } else if (option == 2) {
            while (!submenu_finished) {
                submenu_option = weekly_menu();
                switch (submenu_option) {
                case 1:
                    menu_count = load_menus(menus, menu_count);
                    break;
                case 2:
                    save_menus(menus, menu_count);
                    break;
                case 3:
                    menu_count = add_menu(menus, menu_count);
                    break;
                case 4:
                    list_menus(menus, menu_count);
                    break;
                default:
                    submenu_finished = true;
                }
                if (submenu_option != 0)
                    pause_screen();
            }
        } else if (option == 3) {
            while (!submenu_finished) {
                submenu_option = meal_ticket_menu();
                switch (submenu_option) {
                case 1:
                    menu_count = load_menus(menus, menu_count);
                    break;
                case 2:
                    save_menus(menus, menu_count);
                    break;
                case 3:
                    menu_count = add_menu(menus, menu_count);
                    break;
                case 4:
                    list_menus(menus, menu_count);
                    break;
                default:
                    submenu_finished = true;
                }
                if (submenu_option != 0)
                    pause_screen();
            }
        } else {
            printf("Program terminated!\n\n");
            finished = true;
        }
    }

    return 0;
}

int main_menu() {
    int option;
    bool match = false;

    while (!match) {
        system("clear");
        printf("M E N U\n");

        printf(" 1 - Employees\n");
        printf(" 2 - Menus\n");
        printf(" 3 - Meal tickets\n");
        printf(" 0 - Exit\n");

        printf(" Option: ");
        scanf("%d", &option);
        printf("\n");

        if (option >= 0 && option <= 3)
            match = true;
        else {
            printf("Invalid operation");
            pause_screen();
        }
    }

    return option;
}
int employee_menu() {
    int option;
    bool match = false;

    while (!match) {
        system("clear");
        printf("EMPLOYEES\n");

        printf(" 1 - Load employee data from file\n");
        printf(" 2 - Save employee data to file\n");
        printf(" 3 - Add employee\n");
        printf(" 4 - List all employees\n");
        printf(" 0 - Go back\n");

        printf(" Option: ");
        scanf("%d", &option);
        printf("\n");

        if (option >= 0 && option <= 4)
            match = true;
        else {
            printf("Invalid operation");
            pause_screen();
        }
    }

    return option;
}
int weekly_menu() {
    int option;
    bool match = false;

    while (!match) {
        system("clear");
        printf("MENUS\n");

        printf(" 1 - Load menu data from file\n");
        printf(" 2 - Save menu data to file\n");
        printf(" 3 - Add menu\n");
        printf(" 4 - List all menus\n");
        printf(" 0 - Go back\n");

        printf(" Option: ");
        scanf("%d", &option);
        printf("\n");

        if (option >= 0 && option <= 4)
            match = true;
        else {
            printf("Invalid operation");
            pause_screen();
        }
    }

    return option;
}
int meal_ticket_menu() {
    int option;
    bool match = false;

    while (!match) {
        system("clear");
        printf("MEAL TICKETS\n");

        printf(" 1 - Load meal ticket data from file\n");
        printf(" 2 - Save meal ticket data to file\n");
        printf(" 3 - Add meal ticket\n");
        printf(" 4 - List all meal tickets\n");
        printf(" 0 - Go back\n");

        printf(" Option: ");
        scanf("%d", &option);
        printf("\n");

        if (option >= 0 && option <= 4)
            match = true;
        else {
            printf("Invalid operation");
            pause_screen();
        }
    }

    return option;
}

// EMPLOYEES
int load_employees(employee_data employees[MAX_EMPLOYEES], int employee_count) {
    FILE *fp;
    fp = fopen("employees.txt", "rt");

    bool match = false;
    if (fp != NULL) {
        do {
            if (employee_count < MAX_EMPLOYEES) {
                fscanf(fp, "%d;%[^;];%d;%d\n", &employees[employee_count].id,
                       employees[employee_count].name,
                       &employees[employee_count].tax_id,
                       &employees[employee_count].phone_number);
                if (!employee_exists(employees, employee_count,
                                     employees[employee_count].id))
                    employee_count++;
                else
                    match = true;
            }
        } while (!feof(fp));
        fclose(fp);
    }

    if (!match)
        printf("Data loaded successfully!");
    else
        printf("ERROR: Duplicate IDs are not allowed");

    return employee_count;
}
void save_employees(employee_data employees[MAX_EMPLOYEES],
                    int employee_count) {
    FILE *fp;
    fp = fopen("employees.txt", "wt");

    if (fp != NULL) {
        for (int i = 0; i < employee_count; i++) {
            fprintf(fp, "%d;%s;%d;%d\n", employees[i].id, employees[i].name,
                    employees[i].tax_id, employees[i].phone_number);
        }
        fclose(fp);
    }

    printf("Data saved!");
}
int add_employee(employee_data employees[MAX_EMPLOYEES], int employee_count) {
    if (employee_count < MAX_EMPLOYEES) {
        employees[employee_count].id = read_integer("ID: ");
        if (!employee_exists(employees, employee_count,
                             employees[employee_count].id)) {
            read_string("Name: ", employees[employee_count].name);
            employees[employee_count].tax_id = read_integer("Tax ID: ");
            employees[employee_count].phone_number = read_integer("Phone: ");
            employee_count++;
        } else
            printf("\nERROR: Duplicate IDs are not allowed!");
    } else
        printf("Maximum number of employees reached!");

    return employee_count;
}
void list_employees(employee_data employees[MAX_EMPLOYEES],
                    int employee_count) {
    if (employee_count <= 0) {
        printf("No employees yet!");
        return;
    }

    int widths[3] = {5, 25, 12};
    int column_counts[3] = {1, 1, 2};
    int separator_width = 0;

    for (int i = 0; i < 3; i++)
        separator_width +=
            ((widths[i] + 2) * column_counts[i]) + column_counts[i];
    separator_width--;

    int first_part, second_part, third_part;
    char buffer[12];

    print_separator(separator_width);
    printf("| %-*s ", widths[0], "ID");
    printf("| %-*s ", widths[1], "Name");
    printf("| %-*s ", widths[2], "Tax ID");
    printf("| %-*s |\n", widths[2], "Phone");
    print_separator(separator_width);
    for (int i = 0; i < employee_count; i++) {
        printf("| %*d ", widths[0], employees[i].id);
        printf("| %-*s ", widths[1], employees[i].name);

        first_part = employees[i].tax_id / 1000000;
        second_part = (employees[i].tax_id / 1000) % 1000;
        third_part = employees[i].tax_id % 1000;
        snprintf(buffer, sizeof(buffer), "%d %d %d", first_part, second_part,
                 third_part);
        printf("| %*s ", widths[2], buffer);

        first_part = employees[i].phone_number / 1000000;
        second_part = (employees[i].phone_number / 1000) % 1000;
        third_part = employees[i].phone_number % 1000;
        snprintf(buffer, sizeof(buffer), "%d %d %d", first_part, second_part,
                 third_part);
        printf("| %*s |\n", widths[2], buffer);
    }
    print_separator(separator_width);
}

// MENUS
int load_menus(menu_entry menus[MAX_MENU_ENTRIES], int menu_count) {
    FILE *fp;
    fp = fopen("menus.txt", "rt");

    menu_count = 0;
    if (fp != NULL) {
        do {
            if (menu_count < MAX_MENU_ENTRIES) {
                fscanf(fp,
                       "%[^;];%d.%d.%d;%[^;];%d;%[^;];%d;%[^;];%d;%[^;];%d\n",
                       menus[menu_count].day_of_week, &menus[menu_count].day,
                       &menus[menu_count].month, &menus[menu_count].year,
                       menus[menu_count].fish, &menus[menu_count].fish_calories,
                       menus[menu_count].meat, &menus[menu_count].meat_calories,
                       menus[menu_count].diet, &menus[menu_count].diet_calories,
                       menus[menu_count].vegetarian,
                       &menus[menu_count].vegetarian_calories);
                menu_count++;
            }
        } while (!feof(fp));
        fclose(fp);
    }

    printf("Data loaded successfully!");

    return menu_count;
}
void save_menus(menu_entry menus[MAX_MENU_ENTRIES], int menu_count) {
    FILE *fp;
    fp = fopen("menus.txt", "wt");

    if (fp != NULL) {
        for (int i = 0; i < menu_count; i++) {
            fprintf(fp, "%s;%d.%d.%d;%s;%d;%s;%d;%s;%d;%s;%d\n",
                    menus[i].day_of_week, menus[i].day, menus[i].month,
                    menus[i].year, menus[i].fish, menus[i].fish_calories,
                    menus[i].meat, menus[i].meat_calories, menus[i].diet,
                    menus[i].diet_calories, menus[i].vegetarian,
                    menus[i].vegetarian_calories);
        }
        fclose(fp);
    }

    printf("Data saved!");
}
int add_menu(menu_entry menus[MAX_MENU_ENTRIES], int menu_count) {
    if (menu_count < MAX_MENU_ENTRIES) {
        int month_days[MAX_MENU_ENTRIES] = {6, 7, 8, 9, 10, 11, 12};
        char weekdays[MAX_MENU_ENTRIES][MAX_TEXT_LENGTH] = {
            "Monday", "Tuesday",  "Wednesday", "Thursday",
            "Friday", "Saturday", "Sunday"};

        strcpy(menus[menu_count].day_of_week, weekdays[menu_count]);
        printf("%s ", menus[menu_count].day_of_week);

        menus[menu_count].day = month_days[menu_count];
        menus[menu_count].month = 1;
        menus[menu_count].year = 2025;
        printf("( %d.%d.%d )\n", menus[menu_count].day, menus[menu_count].month,
               menus[menu_count].year);

        read_string("\n  Fish dish: ", menus[menu_count].fish);
        menus[menu_count].fish_calories = read_integer("  Calories: ");

        read_string("\n  Meat dish: ", menus[menu_count].meat);
        menus[menu_count].meat_calories = read_integer("  Calories: ");

        read_string("\n  Diet dish: ", menus[menu_count].diet);
        menus[menu_count].diet_calories = read_integer("  Calories: ");

        read_string("\n  Vegetarian dish: ", menus[menu_count].vegetarian);
        menus[menu_count].vegetarian_calories = read_integer("  Calories: ");

        menu_count++;
    } else
        printf("The weekly menus are complete!");

    return menu_count;
}
void list_menus(menu_entry menus[MAX_MENU_ENTRIES], int menu_count) {
    if (menu_count <= 0) {
        printf("No menus for the week yet!");
        return;
    }

    int widths[3] = {10, 19, 5};
    int column_counts[3] = {2, 4, 4};
    int separator_width = 0;

    for (int i = 0; i < 3; i++)
        separator_width +=
            ((widths[i] + 2) * column_counts[i]) + column_counts[i];
    separator_width--;

    char buffer[12];

    print_separator(separator_width);
    printf("| %-*s ", widths[0], "Weekday");
    printf("| %-*s ", widths[0], "Date");
    printf("| %-*s ", widths[1], "Fish");
    printf("| %-*s ", widths[2], "cal");
    printf("| %-*s ", widths[1], "Meat");
    printf("| %-*s ", widths[2], "cal");
    printf("| %-*s ", widths[1], "Diet");
    printf("| %-*s ", widths[2], "cal");
    printf("| %-*s ", widths[1], "Vegetarian");
    printf("| %-*s |\n", widths[2], "cal");
    print_separator(separator_width);
    for (int i = 0; i < menu_count; i++) {
        printf("| %-*s ", widths[0], menus[i].day_of_week);

        snprintf(buffer, sizeof(buffer), "%d.%d.%d", menus[i].day,
                 menus[i].month, menus[i].year);
        printf("| %*s ", widths[0], buffer);

        printf("| %-*s ", widths[1], menus[i].fish);
        printf("| %*d ", widths[2], menus[i].fish_calories);

        printf("| %-*s ", widths[1], menus[i].meat);
        printf("| %*d ", widths[2], menus[i].meat_calories);

        printf("| %-*s ", widths[1], menus[i].diet);
        printf("| %*d ", widths[2], menus[i].diet_calories);

        printf("| %-*s ", widths[1], menus[i].vegetarian);
        printf("| %*d |\n", widths[2], menus[i].vegetarian_calories);
    }
    print_separator(separator_width);
}

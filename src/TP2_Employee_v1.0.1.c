/*
 ============================================================================
 Name        : TP2_Employee.c
 Author      : Rodrigo G. Katz
 Version     : 1.0.0
 Description : Trabajo Práctico Número 2

 c.baus@sistemas-utnfra.com.ar
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "employees.h"

#define QTY_EMPLOYEES 5
#define QTY_SECTORS 5

int main(void) {
	setbuf(stdout, NULL);

	int initFlag = 0;
	int hireFlag = 0;
	int modsFlag = 0;
	int fireFlag = 0;

	Employee employees[QTY_EMPLOYEES];
	initFlag = initEmployees(employees, QTY_EMPLOYEES);
	Sector sectors[QTY_SECTORS] = {
			{500, "IT"},
			{501, "HR"},
			{502, "Legal"},
			{503, "Finances"},
			{504, "Sales"}
	};

	int employeeId = 10000;
	char exit = 'n';
	char exitReport = 'n';

	do {
		switch (menu()) {
			case 1:
				if(initFlag == 1){
					printMessage("Hiring Employee...");
					hireFlag = addEmployee(employees, QTY_EMPLOYEES, &employeeId, sectors, QTY_SECTORS);
					if(hireFlag){
						printMessage("New employee hired");
					} else {
						printMessage("The employee could not be hired");
					}
				} else {
					printMessage("There is a initialization issue. Please contact support team to fix it");
				}
				break;
			case 2:
				if(hireFlag){
					printMessage("Modifying Employee Conditions...");
					modsFlag = modifyEmployee(employees, QTY_EMPLOYEES, sectors, QTY_SECTORS);
					if(modsFlag){
						printMessage("Updated employee hiring conditions");
					} else {
						printMessage("Employee hiring conditions could not be updated");
					}
				} else {
					printMessage("There should be at least one hired employee in order to modify its hiring conditions");
				}
				break;
			case 3:
				if(hireFlag){
					printMessage("Firing Employee...");
					fireFlag = removeEmployee(employees, QTY_EMPLOYEES, sectors, QTY_SECTORS);
					if(fireFlag){
						printMessage("Employee firing process finished");
					} else {
						printMessage("Employee firing process could not be done");
					}
				} else {
					printMessage("There should be at least one hired employee in order to fire one");
				}
				break;
			case 4:
				if(hireFlag){
					printMessage("Employees reports menu");
					printEmployees(employees, QTY_EMPLOYEES, sectors, QTY_SECTORS);
					do {
						switch(reportMenu()){
						case 1:
							printMessage("Sorting employee list by Last Name & sector asc");
							printSortedEmployees(employees, QTY_EMPLOYEES, sectors, QTY_SECTORS, 1, 1);
							break;
						case 2:
							printMessage("Sorting employee list by Salary asc");
							printSortedEmployees(employees, QTY_EMPLOYEES, sectors, QTY_SECTORS, 2, 1);
							break;
						case 3:
							printMessage("Sorting employee list by Name desc");
							printSortedEmployees(employees, QTY_EMPLOYEES, sectors, QTY_SECTORS, 3, 0);
							break;
						case 4:
							printMessage("Sorting employee list by Hiring Year asc");
							printSortedEmployees(employees, QTY_EMPLOYEES, sectors, QTY_SECTORS, 4, 1);
							break;
						case 5:
							printMessage("Sorting employee list by Name & Salary desc");
							printSortedEmployees(employees, QTY_EMPLOYEES, sectors, QTY_SECTORS, 5, 0);
							break;
						case 6:
							printMessage("Employees report");
							printEmployeeReport(employees, QTY_EMPLOYEES);
							break;
						case 0:
							printMessage("Leaving report sub menu");
							exitReport = 'y';
							break;
						default:
							printMessage("Invalid option. Please try again.");
							fflush(stdin);
							break;
						}
					} while (exitReport != 'y');
				} else {
					printMessage("There should be at least one hired employee to make reports");
				}
				break;
			case 0:
				printMessage("Bye! Thanks for using Employees Manager App");
				exit = 'y';
				break;
			default:
				printMessage("Invalid option. Please try again.");
				fflush(stdin);
				break;
		}


	} while (exit != 'y');


	return EXIT_SUCCESS;
}

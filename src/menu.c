/*
 * menu.c
 *
 *  Created on: Apr 26, 2021
 *      Author: rodrigok
 */
#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

int menu(){
	int optionToReturn = 0;

	printf("\n\tMenu");
	printf("\n\t1- Hire employee");
	printf("\n\t2- Modify employee conditions");
	printf("\n\t3- Fire employee");
	printf("\n\t4- Employees report");
	printf("\n\t0- Exit");

	printf("\n\tOption: ");
    fflush(stdin);
	scanf("%i", &optionToReturn);
	return optionToReturn;
}

int reportMenu(){
	int optionToReturn = 0;

	printf("\n\tReports");
	printf("\n\t1- Sort employee list by Last Name & sector");
	printf("\n\t2- Sort employee list by Salary");
	printf("\n\t3- Sort employee list by Name");
	printf("\n\t4- Sort employee list by Hiring Year");
	printf("\n\t5- Sort employee list by Name & Salary");
	printf("\n\t6- Employees report"); //Total y promediode los salarios. Cuantos empleados superan el salario promedio
	printf("\n\t0- Exit report menu");

	printf("\n\tOption: ");
    fflush(stdin);
	scanf("%i", &optionToReturn);
	return optionToReturn;
}

void printMessage(char* message){
	printf("\n\t%s\n", message);
}

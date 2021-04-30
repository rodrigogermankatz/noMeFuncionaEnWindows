/*
 * commons.c
 *
 *  Created on: Apr 27, 2021
 *      Author: rodrigok
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "employees.h"
#include "commons.h"


int initEmployees(Employee eList[], int eLength){
	int toReturn = 0;
	if(eList != NULL && eLength > 0){
		for(int i = 0; i < eLength; i++){
			eList[i].isEmpty = 1;
		}
		toReturn = 1;
	}
	return toReturn;
}

int addEmployee(Employee eList[], int eLength, int* employeeId, Sector sList[], int sLength){
	int toReturn = 0;
	int index;
	Employee newEmployee;

	char name[51];
	char lastName[51];
	int sector;
	float salary;
	int flagName;
	int flagLastName;
	int flagSector;
	int flagSalary;

	if(eList != NULL && sList != NULL && eLength > 0 && sLength > 0){
		index = searchEmployeeStorageSpace(eList, eLength);
		if(index == -1){
			printf("\n\tNo space found to allocate the new Employee");
		} else {

			printf("\n\tFile Id: %d\n", *employeeId);

			flagName = getString(name, "Name: ", "Employee name must have between 2 & 50 characters", 2, 50, 3);
			flagLastName = getString(lastName, "Last name: ", "Employee last name must have between 2 & 50 characters", 2, 50, 3);
			printSectors(sList, sLength);
			flagSector = getInt(&sector, "Sector: ", "Employee sector must be between 500 & 504", 500, 504, 3);
			flagSalary = getFloat(&salary, "Salary: ", "Employee salary range between 50000.00 & 5000000.00", 50000.00, 5000000.00, 3);


			if(flagName && flagLastName && flagSector && flagSalary){
				newEmployee.fileId = *employeeId;
				strcpy(newEmployee.name, name);
				strcpy(newEmployee.lastName, lastName);
				newEmployee.sector.id = sector;
				newEmployee.salary = salary;

				newEmployee.isEmpty = 0;
				eList[index] = newEmployee;

				(*employeeId)++;
				toReturn = 1;
			} else {
				printf("\n\tEmployee could not be created");
			}
		}
	}
	return toReturn;
}

int searchEmployeeStorageSpace(Employee eList[], int eLength){
	int index = -1;
	if(eList != NULL && eLength > 0){
		for(int i = 0; i < eLength; i++){
			if(eList[i].isEmpty){
				index = i;
				break;
			}
		}
	}
	return index;
}

int findEmployeeById(Employee eList[], int eLength, int employeeId){
	int index = -1;

	if(eList != NULL && eLength > 0){
		for(int i = 0; i < eLength; i++){
			if(eList[i].isEmpty == 0 && eList[i].fileId == employeeId){
				index = i;
				break;
			}
		}
	}

	return index;
}

int modifyEmployee(Employee eList[], int eLength, Sector sList[], int sLength){
	int toReturn = 0;
	int flagEmployeeId = 0;
	int employeeId;
	int index;
	char confirm;
	Employee modifiedEmployee;

	char name[51];
	char lastName[51];
	int sector;
	float salary;

	int flagName;
	int flagLastName;
	int flagSector;
	int flagSalary;

	if(eList != NULL && sLength > 0 && sList != NULL && sLength > 0){
		printEmployees(eList, eLength, sList, sLength);
		flagEmployeeId = getInt(&employeeId, "ID: ", "Employee ID must be between 10000 & 50000", 10000, 50000, 3);
		index = findEmployeeById(eList, eLength, employeeId);

		if(index >= 0){
			printf("\n\tDo you want to modify %s, %s hiring conditions? y/n: ", eList[index].lastName, eList[index].name);
            fflush(stdin);
			scanf("%c", &confirm);
			if(confirm == 'y' || confirm == 'Y'){
				flagName = getString(name, "Name: ", "Employee name must have between 2 & 50 characters", 2, 50, 3);
				flagLastName = getString(lastName, "Last name: ", "Employee last name must have between 2 & 50 characters", 2, 50, 3);
				printSectors(sList, sLength);
				flagSector = getInt(&sector, "Sector: ", "Employee sector must be between 500 & 504", 500, 504, 3);
				flagSalary = getFloat(&salary, "Salary: ", "Employee salary range between 50000.00 & 5000000.00", 50000.00, 5000000.00, 3);

				if(flagName && flagLastName && flagSector && flagSalary){
					modifiedEmployee.fileId = employeeId;
					strcpy(modifiedEmployee.name, name);
					strcpy(modifiedEmployee.lastName, lastName);
					modifiedEmployee.sector.id = sector;
					modifiedEmployee.salary = salary;

					modifiedEmployee.isEmpty = 0;
					eList[index] = modifiedEmployee;

					printf("\n\tEmployee modified\n\n");
					toReturn = 1;
				} else {
					printf("\n\tEmployee cannot be modified");
				}


			} else {
				printf("\n\tThe employee has another chance to make it right!");
			}
		} else {
			printf("\n\tEmployee hiring conditions won't be modified");
		}
	}

	return toReturn;
}

int removeEmployee(Employee eList[], int eLength, Sector sList[], int sLength){
	int toReturn = 0;
	int flagEmployeeId = 0;
	int employeeId;
	int index;
	char confirm;

	if(eList != NULL && eLength > 0){
		printEmployees(eList, eLength, sList, sLength);
		flagEmployeeId = getInt(&employeeId, "ID: ", "Employee ID must be between 10000 & 50000", 10000, 50000, 3);
		index = findEmployeeById(eList, eLength, employeeId);

		if(index >= 0 && flagEmployeeId){
			printf("\n\tDo you want to fire %s, %s? y/n: ", eList[index].lastName, eList[index].name);
            fflush(stdin);
			scanf("%c", &confirm);
			if(confirm == 'y' || confirm == 'Y'){
				printf("\n\tEmployee fired\n\n");
				eList[index].isEmpty = 1;
				toReturn = 1;
			} else {
				printf("\n\tThe employee has another chance to make it right!");
			}
		} else {
			printf("\n\tThe employee with index %d does not exist...", index);
		}
	}

	return toReturn;
}

int printEmployees(Employee eList[], int eLength, Sector sList[], int sLength){
	int toReturn = 0;
	int count = 0;
	if(eList != NULL && eLength > 0 && sList != NULL && sLength > 0){
		printf("\n\tEmployee list");
		printf("\n\t---------------------------------------------------------------------------");
		printf("\n\tIndex           ID        Salary         Sector     Full Name");
		printf("\n\t---------------------------------------------------------------------------\n");
		for(int i = 0; i < eLength; i++){
			if(eList[i].isEmpty == 0){
				printEmployee(i + 1 , eList[i], eList, eLength, sList, sLength);
				count++;
			}
		}
		if(count < 1){
			printf("\tThere are no employees to be printed...");
		} else {
			toReturn = 1;
		}
		printf("\n\t---------------------------------------------------------------------------\n\n");
	}
	return toReturn;
}

int printSortedEmployees(Employee eList[], int eLength, Sector sList[], int sLength, int criteria, int order){
	int toReturn = 0;
	Employee auxEmployee;
	if(eList != NULL && eLength > 0 && sList != NULL && sLength > 0 && criteria > 0 && criteria < 6 && order >= 0 && order <= 1){
		switch (criteria) {
			case 1:
				for(int i = 0; i < eLength - 1; i++){
					for(int j = i + 1; j < eLength; j++){
						if((eList[i].lastName < eList[j].lastName) || (eList[i].lastName == eList[j].lastName && eList[i].sector.description > eList[j].sector.description)){
							auxEmployee = eList[i];
							eList[i] = eList[j];
							eList[j] = auxEmployee;
						}
					}
				}
				printEmployees(eList, eLength, sList, sLength);
				break;
			case 2:
				for(int i = 0; i < eLength - 1; i++){
					for(int j = i + 1; j < eLength; j++){
						if(eList[i].salary < eList[j].salary){
							auxEmployee = eList[i];
							eList[i] = eList[j];
							eList[j] = auxEmployee;
						}
					}
				}
				printEmployees(eList, eLength, sList, sLength);
				break;
			case 3:
				for(int i = 0; i < eLength - 1; i++){
					for(int j = i + 1; j < eLength; j++){
						if(eList[i].name[0] > eList[j].name[0]){
							auxEmployee = eList[i];
							eList[i] = eList[j];
							eList[j] = auxEmployee;
						}
					}
				}
				printEmployees(eList, eLength, sList, sLength);
				break;
			case 4:
				for(int i = 0; i < eLength - 1; i++){
					for(int j = i + 1; j < eLength; j++){
						if(eList[i].name[0] > eList[j].name[0]){
							auxEmployee = eList[i];
							eList[i] = eList[j];
							eList[j] = auxEmployee;
						}
					}
				}
				printEmployees(eList, eLength, sList, sLength);
				break;
			case 5:
				for(int i = 0; i < eLength - 1; i++){
					for(int j = i + 1; j < eLength; j++){
						if((eList[i].name < eList[j].name) || (eList[i].name == eList[j].name && eList[i].salary > eList[j].salary)){
							auxEmployee = eList[i];
							eList[i] = eList[j];
							eList[j] = auxEmployee;
						}
					}
				}
				printEmployees(eList, eLength, sList, sLength);
				break;
			default:
				printf("\n\tThe criteria to sort is not right");
				break;
		}
	} else {
		printf("\n\tThere is an issue with the sorting parameters. Please contact support team to fix it");
	}
	return toReturn;
}

int printEmployeeReport(Employee eList[], int eLength){
	int toReturn = 0;
	float total = 0.0;
	float average = 0.0;
	int count = 0;
	int countAboveAvg = 0;
	if(eList != NULL && eLength > 0){
		for(int i = 0; i < eLength; i++){
			if(eList[i].isEmpty == 0){
				total +=  eList[i].salary;
				count++;
			}
		}
		average = (float) total / count;
		for(int i = 0; i < eLength; i++){
			if(eList[i].isEmpty == 0 && eList[i].salary > average){
				countAboveAvg++;
			}
		}
		printf("\n\t------------------------------------------------------------------------------");
		printf("\n\tTotal sum of all wages   Average wages   Employees that exceed average salarys");
		printf("\n\t------------------------------------------------------------------------------");
		printf("\n\t%5.2f                   %.2f           %d/%d", total, average, countAboveAvg, count);
		printf("\n\t------------------------------------------------------------------------------\n\n");
	}
	return toReturn;
}

void printEmployee(int index, Employee oneEmployee, Employee eList[], int eLength, Sector sList[], int sLength){
	char sector[51];
	char fullName[100] = "";
	for(int s = 0; s < sLength; s++){
		if(oneEmployee.sector.id == sList[s].id){
			strcpy(sector, sList[s].description);
			break;
		}
	}

	strcat(fullName, oneEmployee.lastName);
	strcat(fullName,  ", ");
	strcat(fullName, oneEmployee.name);
	strlwr(fullName);

	fullName[0] = toupper(fullName[0]);
	for(int i = 0; fullName[i] != '\0'; i++){
		if(fullName[i] == ' '){
			fullName[i+1] = toupper(fullName[i+1]);
		}
	}

	printf("\t%5d        %5d     %7.2f       %8s     %s\n", index, oneEmployee.fileId, oneEmployee.salary, sector, fullName);
}

int printSectors(Sector sList[], int sLength){
	int toReturn = 0;
	if(sList != NULL && sLength > 0){
		printf("\n\tAvailable Sectors");
		printf("\n\t--------------------------------");
		printf("\n\tIndex        ID      Description");
		printf("\n\t--------------------------------\n");
		for(int i = 0; i < sLength; i++){
			printSector(i + 1 , sList[i]);
		}
		printf("\t--------------------------------\n\n");
		toReturn = 1;
	}
	return toReturn;
}

void printSector(int index, Sector oneSector){
	printf("\t%5d     %5d      %s\n", index, oneSector.id, oneSector.description);
}

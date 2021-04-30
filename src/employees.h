/*
 * employees.h
 *
 *  Created on: Apr 27, 2021
 *      Author: rodrigok
 */

#ifndef EMPLOYEES_H_
#define EMPLOYEES_H_

typedef struct {
	int id;
	char description[50];
} Sector;

typedef struct {
	int fileId;
	char name[50];
	char lastName[50];
	float salary;
	Sector sector;
	int isEmpty;
} Employee;

/**
 * @fn int initEmployees(Employee[], int)
 * @brief
 *
 * @param eList
 * @param eLength
 * @return
 */
int initEmployees(Employee eList[], int eLength);

/**
 * @fn int addEmployee(Employee[], int, int*, Sector[], int)
 * @brief
 *
 * @param eList
 * @param eLength
 * @param employeeId
 * @param sList
 * @param sLength
 * @return
 */
int addEmployee(Employee eList[], int eLength, int* employeeId, Sector sList[], int sLength);

/**
 * @fn int searchEmployeeStorageSpace(Employee[], int)
 * @brief
 *
 * @param eList
 * @param eLength
 * @return
 */
int searchEmployeeStorageSpace(Employee eList[], int eLength);

/**
 * @fn int findEmployeeById(Employee[], int, int)
 * @brief
 *
 * @param eList
 * @param eLength
 * @param eFileNumber
 * @return
 */
int findEmployeeById(Employee eList[], int eLength, int eFileNumber);

/**
 * @fn int modifyEmployee(Employee[], int, Sector[], int)
 * @brief
 *
 * @param eList
 * @param eLength
 * @param sList
 * @param sLength
 * @return
 */
int modifyEmployee(Employee eList[], int eLength, Sector sList[], int sLength);

/**
 * @fn int removeEmployee(Employee[], int, int*, Sector[], int)
 * @brief
 *
 * @param eList
 * @param eLength
 * @param employeeId
 * @param sList
 * @param sLength
 * @return
 */
int removeEmployee(Employee eList[], int eLength, Sector sList[], int sLength);

/**
 * @fn int sortEmployees(Employee[], int, Sector[], int)
 * @brief
 *
 * @param eList
 * @param eLength
 * @param sList
 * @param sLength
 * @return
 */
int sortEmployees(Employee eList[], int eLength, Sector sList[], int sLength);

/**
 * @fn int printEmployees(Employee[], int, Sector[], int)
 * @brief
 *
 * @param eList
 * @param eLength
 * @param sList
 * @param sLength
 * @return
 */
int printEmployees(Employee eList[], int eLength, Sector sList[], int sLength);

/**
 * @fn int printSortedEmployees(Employee[], int, Sector[], int, int, int)
 * @brief
 *
 * @param eList
 * @param eLength
 * @param sList
 * @param sLength
 * @param criteria menu option
 * @param order 1 asc / 0 desc
 * @return
 */
int printSortedEmployees(Employee eList[], int eLength, Sector sList[], int sLength, int criteria, int order);

/**
 * @fn int printEmployeeReport(Employee[], int)
 * @brief
 *
 * @param eList
 * @param eLength
 * @return
 */
int printEmployeeReport(Employee eList[], int eLength);

/**
 * @fn void printEmployee(int, Employee, Employee[], int, Sector[], int)
 * @brief
 *
 * @param index
 * @param oneEmployee
 * @param eList
 * @param eLength
 * @param sList
 * @param sLength
 */
void printEmployee(int index, Employee oneEmployee, Employee eList[], int eLength, Sector sList[], int sLength);

/**
 * @fn int printSectors(Sector[], int)
 * @brief
 *
 * @param sList
 * @param sLength
 * @return
 */
int printSectors(Sector sList[], int sLength);

/**
 * @fn void printSector(Sector)
 * @brief
 *
 * @param oneSector
 */
void printSector(int index, Sector oneSector);


#endif /* EMPLOYEES_H_ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedListLib.h"

void addListElem(listElement *start){
    
    listElement * new;
    new = (listElement *)malloc(sizeof(listElement));
    if (new == NULL) {
        printf("can't reserve storage.\n"); 
        return;
    }

    listElement * currElem = start;
    while (currElem->nextElem != NULL) currElem = currElem->nextElem;// get last elem in list
    currElem->nextElem = new; // add new to the end of list
    new->nextElem = NULL;
    
    /* fill data in new element */
    printf("Please enter last name: \n");
    scanf("%s",new->lastName);
    printf("Please enter first name: \n");
    scanf("%s",new->firstName);
    printf("Please enter age: \n");
    scanf("%d",&(new->age));
    printf("end of function\n");
}

void printList(listElement *start){
    if (start->nextElem == NULL) printf ("\n>> list is empty\n\n");
    else{
        int i = 0;
        listElement *currElem = start;
        printf("\n>> current list:\n\n");
            do {
                currElem = currElem->nextElem;
                printf("%d.)",i); i++;
                printf("\tlast Name: %s\n",currElem->lastName);
                printf("\tfirst Name: %s\n",currElem->firstName);
                printf("\tage : %d\n",currElem->age);
            } while (currElem->nextElem != NULL);
    printf("\n");
    }
}

void delListElem(listElement *start){

    printf("\n>> delListElem fcn is tbd.\n\n");

}

void delList(listElement *start){

    printf("\n>> getLenOfList fcn is tbd.\n\n");

}

int getLenOfList(listElement *start){ // we use this for save list fcn

    int counter = 0;
    listElement * currElem = start;
    while (currElem->nextElem != NULL) {// get last elem in list
        currElem = currElem->nextElem; counter++;
        }
    return counter;
}

void saveList(listElement *start){

	char filename[50];
	printf("\n >> saving data...\n\n");
	printf("filename without extension: ");
	scanf("%s",filename);
	strcat(filename, ".txt"); // adding .txt to file name
	
	FILE * fPtr;
    fPtr = fopen(filename, "w");

    if (fPtr == NULL) {
        printf("can't open file.\n"); 
        return;
    }
    fprintf(fPtr, "%d\n", getLenOfList(start));
    
    listElement * currElem = start;
    while (currElem->nextElem != NULL){
        currElem = currElem->nextElem;
        fprintf(fPtr, "%s %s %d\n", currElem->lastName, currElem->firstName, currElem->age);
    }

    printf("\n >> data saved.\n\n");
    fclose(fPtr);
}

void loadList(listElement *start){
	
	char filename[50];
    int len = 0;
	printf("\nloading data...\n\n");
	printf("availible data: \n----------------\n");
	system("dir /b *.txt"); // dir /b *.txt for windows | print availible *.txt files in current location
	printf("\nfilename without extension: ");
	scanf("%s",filename);
	strcat(filename, ".txt"); // adding .txt to file name
	
	FILE * fPtr;
	fPtr = fopen(filename, "r");

    if (fPtr == NULL) {
        printf("can't open file.\n");
        return;
    }

    fscanf(fPtr,"%d", &len);
    listElement * currElem = start;
    while (currElem->nextElem != NULL) currElem = currElem->nextElem;
    
    for (int i = 0; i < len; i++){
        listElement * new;
        new = (listElement *)malloc(sizeof(listElement));

        if (new == NULL) {
        printf("can't reserve storage.\n"); 
        return;
        }

        fscanf(fPtr, "%s %s %d\n", new->lastName, new->firstName, &(new->age));
        currElem->nextElem = new;
        new->nextElem = NULL;
        currElem = currElem->nextElem;
    }	
    
	fclose(fPtr);
	printf("loading data will be append to current list...\n");
	printList(start); // show loaded list
}

void exitFcn(listElement *start){

    printf("\n>> exitFcn fcn is tbd.\n\n");

}

void sortList(listElement *start){
	
	printf("\n>>sortList fcn is tbd.\n\n");
    
}

void stringToLower(char *string) {
	
    printf("\n>>stringToLower fcn is tbd.\n\n");

}
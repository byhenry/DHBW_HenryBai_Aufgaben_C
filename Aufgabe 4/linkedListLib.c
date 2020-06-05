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

    if(start->nextElem == NULL) printf("\n>> list is empty\n\n");
    else{

        int idxToDel = 0;

        printList(start);
        printf("please enter index of list element to delete... \n");
        scanf("%d", &idxToDel);

        if(getLenOfList(start)-1 < idxToDel){
            printf("can't delete element with idx %d. list idx ends at %d\n", idxToDel, getLenOfList(start)-1);
            return;
        }
                
        listElement * currElem = start;
        listElement * delElem;
        
        for(int i = 0; i < idxToDel; i++) currElem = currElem->nextElem;
        delElem = currElem->nextElem;
        currElem->nextElem = currElem->nextElem->nextElem;

        free(delElem);
        system("cls");
    }
}

void delList(listElement *start){

    if(start->nextElem == NULL) printf("\n>> list is empty\n\n");
    else{
        int delFlag = 0;
        printf("delete list...\n");
        printf("[1] ... yes\n");
        printf("[0] ... no\n");
        scanf("%d", &delFlag);

        if(delFlag == 0){
            printf("\n>> list not deleted\n\n");
            return;
        }

        listElement * currElem = start;
        listElement * delElem;

        while(currElem->nextElem != NULL){
            delElem = currElem->nextElem;
            currElem->nextElem = currElem->nextElem->nextElem;
            free(delElem);
        }
        system("cls");
    }
}

int getLenOfList(listElement *start){ // we use this for save list fcn

    int counter = 0;
    listElement * currElem = start;
    while(currElem->nextElem != NULL) {// get last elem in list
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

    if(fPtr == NULL) {
        printf("can't open file.\n"); 
        return;
    }
    fprintf(fPtr, "%d\n", getLenOfList(start));
    
    listElement * currElem = start;
    while(currElem->nextElem != NULL){
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

    if(fPtr == NULL) {
        printf("can't open file.\n");
        return;
    }

    fscanf(fPtr,"%d", &len);
    listElement * currElem = start;
    while(currElem->nextElem != NULL) currElem = currElem->nextElem;
    
    for(int i = 0; i < len; i++){
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

    int saveFlag = 0;
    
    printf("do you want to save the current list?\n");
    printf("[1] ... yes\n");
    printf("[0] ... no\n");
    scanf("%d", &saveFlag);

    if(saveFlag == 1) saveList(start);
    system("cls");
}

void sortList(listElement *start){
	
	int i, lenOfList, userFLAGG, swapFLAGG, SWAPPING = 0; // some locals

    listElement * currElem;
    listElement * prevElem;
    
    char temp1[50];
    char temp2[50];

	printf("sort current list according to ...\n");
	printf(" [1] ... last name\n [2] ... first name\n [3] ... age\n [0] ... exit\n");
	scanf("%d",&userFLAGG);
    printf("\n\n");

    // sort useres choice and get flagg if char or int
	if (userFLAGG != 0 && userFLAGG != 1 && userFLAGG != 2 && userFLAGG != 3){
        system("cls");
        printf("invalid choice. will exit function\n\n");
        return; 
    }
    else if (userFLAGG == 0){
        system("cls");
        return;
        }
    else{ // do the sorting

        lenOfList = getLenOfList(start);

        do{

            currElem = start->nextElem;
            prevElem = start;

            SWAPPING = 0; 
            for (i = 0; i < lenOfList - 1; i++){

                    swapFLAGG = 0;
                    switch (userFLAGG){
                    case 1: // last name 
                        strcpy(temp1, currElem->lastName);
                        strcpy(temp2, currElem->nextElem->lastName);
                        
                        stringToLower(temp1);
                        stringToLower(temp2);

                        if (strcmp(temp1,temp2) > 0) swapFLAGG = 1;
                        break;
                    case 2: // first name   
                        strcpy(temp1, currElem->firstName);
                        strcpy(temp2, currElem->nextElem->firstName);

                        stringToLower(temp1);
                        stringToLower(temp2);

                        if (strcmp(temp1,temp2) > 0) swapFLAGG = 1;
                        break;
                    case 3: // age  

                        if(currElem->age > currElem->nextElem->age) swapFLAGG = 1;
                        break;    
                    
                    default:
                        break;
                    }

                if (swapFLAGG){ 

                    prevElem->nextElem = currElem->nextElem;
                    currElem->nextElem = prevElem->nextElem->nextElem;
                    prevElem->nextElem->nextElem = currElem;

                    prevElem = prevElem->nextElem;
                    
                    SWAPPING = 1;
                } else{ // increament both
                    currElem = currElem->nextElem;
                    prevElem = prevElem->nextElem;
                }

            }

            lenOfList--;
        
        }while(SWAPPING);
        
    }
	printList(start); // print sorted list.
}

void stringToLower(char *string) {
	int len = strlen(string);

	for(int i=0; i < len; i++){
		if(string[i] >= 'A' && string[i] <= 'Z'){
			string[i] += 32;
		}
	}
}
/*
JW-2020-06-05:
--------------
> well done (10/10) 
*/
#include<stdio.h>
#include"smart_delivery.h"
#include<string.h>
#include<stdlib.h>

int account_check(char* temp_mail_id,char* temp_password1,char* temp_name,char* temp_mobile)
{
    FILE* fp = fopen("src/database.csv", "r");
    if (!fp) 
    {
		printf("Can't open file\n");
	}
    char buffer[1024];
    int row = 0;
    int column = 0;
    int i=0;
    int count=0;
    int res;
    while (fgets(buffer,1024, fp)) 
        {
            column = 0;
	    char *value = malloc(2048);
    	    if (!value) {
            return 1;
    	    }
            value = strtok(buffer, ",");
  
            while (value) {
                if (column == 1) {
                    res=strcmp(temp_mail_id,value);
                    if(res==0)
                    {
                        count++;
                    }
                }
  
                if (column == 2) {
                    res=strcmp(temp_password1,value);
                    if(res==0)
                    {
                        count++;
                    }                
                }
                value = strtok(NULL, ",");
                column++;
            }
            row++;
	    free(value);
        }
    if(count>=2)
    {
        printf("\nAccount Already Existed Please Login !!\n");
        return 1;
    }
    if (count<2) 
    {
        FILE* fp = fopen("src/database.csv", "a+");
        if (!fp) {
		    printf("Can't open file\n");
	    }
	    // Saving data in file
	    fprintf(fp,"%s,%s,%s,%s\n",temp_name,temp_mail_id,temp_password1,temp_mobile);
	    printf("Account successfully created\n");
        return 0;
    }

	fclose(fp);
}

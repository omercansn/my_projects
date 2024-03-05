#include "TP02.h"
#define MAX_STRING_LENGTH 50
#define INPUT_SIZE 50
#define INT_TOKEN 50
#define ARRAY_LEN 50
 
int main()
{
    char string_to_copy[MAX_STRING_LENGTH];
    char * token;
    char input[INPUT_SIZE];
    int values[INT_TOKEN];
    int arr[ARRAY_LEN];
    int i=0;

    scanf("%s", input);
    token = strtok(input, "-");

    int case_no = atoi(token);
    size_t string_length; // i added here because i will need it
    while (token != NULL) {
        if( (case_no == 1) || (case_no == 2)  )
        {
            token = strtok(NULL, " ");
            size_t string_length = strlen(token);
        
            strncpy(string_to_copy, token, string_length);
            string_to_copy[string_length] = '\0'; // Null-terminate the copied string
            
            printf("Copied string is: %s\n", string_to_copy);
    
            break;
        }
        else{
            values[i] = atoi(token);
            token = strtok(NULL, "-");
            i++;
        }
    }

    switch(case_no) {
        
        case 1:
            printf("Under construction");
            charPermu(string_to_copy); // Under construction
            break;

        case 2:
            printf("Length of the string: %d\n", calculateLength(string_to_copy));
            break;

        case 3:
            printf("The Factorial of %d is : %d\n", values[1], findFact(values[1]));
            break;

        case 4:
            if (are_friends(values[1], values[2])!=0) 
            {
                printf("%d and %d are friends.\n", values[1], values[2]);
            } 
            else 
            {
                printf("%d and %d are not friends.\n", values[1], values[2]);
            }

            break;
        
        case 5:
            if (is_harshad(values[1])) 
            {
                printf("%d is a Harshad number.\n", values[1]);
            } 
            else 
            {
                printf("%d is not a Harshad number.\n", values[1]);
            }
            break;

        case 6:
            printf("Digital root is: %d\n", digital_root(values[1]));
            break;
        case 7: 
            ;
            int arr_len_7 = values[1];

            for (int i = 0; i<arr_len_7; i++)
            { 
                arr[i] = values[i+2];
            }

            if(isConsecutive(arr_len_7, arr))
            {
                printf("This array is consecutive\n");
            }
            else
            {
                printf("This array is not consecutive\n");
            }

            break;
        
        case 8: 
            ;
            int arr_len_8 = values[1];
            for (int i = 0; i<arr_len_8; i++)
            {
               arr[i] = values[i+2];  
            }

            printf("The smallest missing value is %d\n",findMissingSmallest(arr_len_8, arr));
            break;

        case 9:
            if (day_of_year(values[1], values[2], values[3]) == -1)
            {
                printf("Invalid");
            }
            else
            {
                printf("%dth day of the year\n", day_of_year(values[1], values[2], values[3]));
            }
            break;
        
        case 10:
            if (closest_prime(values[1]) != -1) 
            {
                printf("The largest prime number less than %d: %d\n", values[1], closest_prime(values[1]));
            } 
            else 
            {
                printf("Error: No prime number less than %d found.\n", values[1]);
            }
            break;
        
        case 11:
            
            findHardyRamanujanNumbers(values[1]);
            
            break;
        
    }
    
}

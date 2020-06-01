#define MAX_LIMIT 20000 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct Node
{
    int  length; 
    char first_four_digits[5]; 
    struct Node * next; 
};  

//struct Node node[10];
 struct Node node[10];


struct Node * createLinekdList(char str[]);
int countWords (char str[]);
void printList(struct Node* head);




int main ()
{
   int numebrOfWords = 0; 
   printf( "Enter a string: ");
   char str[MAX_LIMIT]; 
   fgets(str, MAX_LIMIT, stdin); 
   numebrOfWords = countWords (str);
   printf("Numebr of words: %d\n", numebrOfWords);

   struct Node* root = createLinekdList(str);

   printList(root);

    return 0;
}





struct Node * createLinekdList(char str[] )
{

int  numebrOfWords = 0; 
numebrOfWords = countWords (str);



 int length   = (unsigned)strlen(str); 
 int wordLength = 0 ; 
 char  word[5] = "";
 int count = 0;  
bool flag = false;  
 int number = 0; 
 
 //struct Node node[numebrOfWords];


 for (int i = 0; i  < length ; i ++ )
    {
       if (str[i] != ' ')
       {
           if (count < 4 )
           {

           word[count] = str[i];
           count ++; 

           }
           wordLength ++ ;
           
           if (str[ i+1 ] == ' ' || str[ i+1 ] ==  '\n')
           {

            node[number].length = wordLength;
            strcpy(node[number].first_four_digits, word);
            node[number].next = NULL;
            if ( number > 0)
            {
                node[number - 1 ].next = &node[number];  
            }      
            
                memset(word, 0, strlen(word));

            
            count = 0;
            wordLength = 0 ;
            number ++ ; 
           }    
       }



    }
    return node; 
}







int countWords (char str[])
{

int length   = (unsigned)strlen(str); 

int wordCount = 0 ;


 for (int i = 0; i  < length ; i ++ )
    {
       if (str[i] != ' ')
       {
           
           if (str[ i+1 ] == ' ' || str[ i+1 ] ==  '\n')
           {
              wordCount ++ ;
           }    
       }
    }

    return wordCount;
}




// Helper function to print given linked list
void printList(struct Node* head)
{
	struct Node* curr = head;
	// while (curr)
	// {
	// 	printf("%d -> ", curr->length);
	// 	curr = curr->next;
	// }


    printf( "\n\n");

    while (curr)
	{
		
        printf("%s -> ", curr->first_four_digits);
		curr = curr->next;
	}
	printf("NULL");
}

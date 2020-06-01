#define MAX_LIMIT 20000 

#define MAX_LIMIT_WORDS 20000 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> 


struct Node
{
    int  length; 
    char first_four_digits[5]; 
    struct Node * next; 
};  

//struct Node node[10];
 struct Node node[MAX_LIMIT_WORDS];


struct Node * createLinekdList(char str[]);
int countWords (char str[]);
void printList(struct Node* head);
void bubbleSort(struct Node *start);
void swap(struct Node *a, struct Node *b);



struct Node * SortLinekdList(struct Node* head);



int main ()
{
   int numebrOfWords = 0; 
   printf( "Enter a string: ");
   char str[MAX_LIMIT]; 
   fgets(str, MAX_LIMIT, stdin); 
   numebrOfWords = countWords (str);
   printf("Numebr of words: %d\n", numebrOfWords);

   struct Node* root = createLinekdList(str);

   //printList(root);
   
   bubbleSort(root);
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
		
                printf("%s %d -> ", curr->first_four_digits , curr->length);

		curr = curr->next;
	}
    printf( "\n\n");
	printf("NULL");
}



struct Node * SortLinekdList(struct Node* head )
{
    int first = 0;
    int second = 0;
    int third = 0;
    int fourth = 0; 
    int lowest = 0;

    struct Node* curr = head;

    struct Node temp;

   while (curr)
	{
		
        //printf("%s -> ", curr->first_four_digits);
        
        first = curr->first_four_digits[0];
        lowest = first;
        curr = curr->next; 
        while (curr)
        {
          curr = curr->next;
          if (lowest > curr->first_four_digits[0])
          {
            lowest = curr->first_four_digits[0];
            temp.length = curr->length;
            strcpy(temp.first_four_digits ,curr -> first_four_digits); 
          }
        }

       
    curr = curr->next;
		
	}
	printf("NULL");


}





void bubbleSort(struct Node *start) 
{ 
    int swapped, i; 
    struct Node *ptr1; 
    struct Node *lptr = NULL; 

  
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 

            if (toupper(ptr1->first_four_digits[0])  > toupper(ptr1->next->first_four_digits[0])  )
            {
                swap(ptr1, ptr1->next); 
                swapped = 1;
            }
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
  
/* function to swap data of two nodes a and b*/
void swap(struct Node *a, struct Node *b) 
{ 
    int tempLength = a->length; 
    a->length = b->length; 
    b->length = tempLength;

    char tempDigits [5];  
    strcpy(tempDigits, a->first_four_digits);
    strcpy(a->first_four_digits, b->first_four_digits);
    strcpy(b->first_four_digits, tempDigits);
 
} 

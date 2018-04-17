#include<stdio.h>
struct rec
{
    int value;
    int exponent;
    struct rec *next;
};

struct rec *insert(struct rec *head,int value,int exponent)
{ 
       struct rec *node,*tmp;
       
       // The first data
       if(head == NULL)
       { 
          head = (struct rec*)malloc(sizeof(struct rec));
          head->value = value;
          head->exponent = exponent;
          head->next = NULL;
       }
       else
       {  
          node = (struct rec*)malloc(sizeof(struct rec));
          node->value = value;
          node->exponent = exponent;
          tmp = head;
          // If the exponent over exponent first.
          if(tmp->exponent < exponent)
          {  node->next = head;
             head = node;
          }
          else
          {  
             while(tmp)
             {  //If no exponent equal Base plus the same number.      
                if(node->exponent == tmp->exponent)
                {  tmp->value += node->value;
                   break;
                } 
                //If tmp at the end.
                else if(tmp->next == NULL)
                {  node->next = NULL;
                   tmp->next = node;
                   break;
                }
                // Inserted between.
                else if(exponent > tmp->next->exponent)
                {  node->next = tmp->next;
                   tmp->next = node ;
                   break;
                }
                // tmp run to locate the appropriate
                else
                   tmp = tmp->next;
            }
         }
       }
   return head;  
}
struct rec *sum(struct rec *poly1,struct rec *poly2,struct rec *result)
{
    
    while(1)
    {
      // If the data Poly1 out.   To insert Poly2 rest completely.
      if(poly1 == NULL)
      {
          while(poly2)
          {
              result = insert(result,poly2->value,poly2->exponent);
              poly2 = poly2->next;
          }
      }
      // If the data Poly2 out.   To insert Poly1 rest completely.
      if(poly2 == NULL)      
      {
          while(poly1)
          {
              result = insert(result,poly1->value,poly1->exponent);
              poly1 = poly1->next;
          }
      }
      // If all data, both shall be completed
      if(poly1==NULL && poly2==NULL)
         break;
      // If the exponent poly1 more
      if(poly1->exponent > poly2->exponent)
      {   
          result = insert(result,poly1->value,poly1->exponent);
          poly1 = poly1->next;
      }
      // If the exponent poly2 more
      else if(poly1->exponent < poly2->exponent)  
      {   
          result = insert(result,poly2->value,poly2->exponent);
          poly2 = poly2->next;
      }
      // If the exponent equal , value1 + valu2
      else if(poly1->exponent == poly2->exponent)  
      {
          result = insert(result,poly1->value+poly2->value,poly1->exponent);
          poly1 = poly1->next;
          poly2 = poly2->next;
      }  
    }   
       return result;
}
             
print(struct rec *node)
{
    if(node != NULL)
    {   if(node->exponent == 0)
           printf("%d ",node->value);
        else if(node->exponent == 1)
           printf("%d x10 ",node->value);
        else
           printf("%d x10^%d ",node->value,node->exponent);
        
        // If not for the final, print + 
        if(node->next != NULL)
        {  printf("+ ");
           print(node->next);
        }
    }
}

int main()
{
    struct rec *poly1=NULL,*poly2=NULL,*result=NULL;
    int num1,num2;
    printf("Polynomial (1) : ");
    // Enter the polynomial 1.
    while(1)
    {
      scanf("%d",&num1);
      //Shall be completed if you enter -99.
       if(num1 == -99)
        break;
       scanf("%d",&num2);
       // Num1 num2 to send the insert.
       poly1 = insert(poly1,num1,num2);
    }
    
    
    printf("Polynomial (2) : ");
    // Enter the polynomial 2.
    while(1)
    {
      scanf("%d",&num1);
      //Shall be completed if you enter -99.
       if(num1 == -99)
        break;
       scanf("%d",&num2);
       // Num1 num2 to send the insert.
       poly2 = insert(poly2,num1,num2);
    }
   printf("\nOutput : \nPolynomial (1) : ");
   // Polynomial for the first show.
   print(poly1);
   printf("\nPolynimial (2) : ");
   // Polynomial for the second show.
   print(poly2);
   // Send to totals.
   result = sum(poly1,poly2,result);
   //Polynomial results.
   printf("\nResult : ");
   
   print(result);
   
   getch();
}

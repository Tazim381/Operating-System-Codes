

#include <stdio.h>
#include <stdlib.h>


int full = 0;
//buffer size = 5

int empty = 5, item = 0;
int  buffer[10000];
int *b =&buffer[0];
int value;
int pr=0,con=1;

void produce()
{

        printf("Enter the value \n");
        
        scanf("%d",&value);
        printf("Address is %p\n",(b+full%4)); //Circular vabe input e jabe 
        ++full;	
        *(b+full%4) = value;
	--empty;
}


void consume()
{
       printf("\nThe consumed valud is  %d",*(b+con%4));
       printf("Address is %p\n",(b+con%4)); //first theke consume hobe
       con++;
       --full;
	++empty;
}

int main()
{
	int n, i;
      
       while(1)
      {
          printf("\n1. For produce 2. For Consume 3.Exit \n");
          printf("\nEnter your choice\n");

          scanf("%d",&n);
          if(n==1)
          {
            if(empty!=0) produce();
            else printf("\nBuffer is full\n");
          }
          else if(n==2)
          {
            if(full!=0) consume();
            else printf("\nBuffer is Empty\n");
          }
         else  break;
		
	}
}



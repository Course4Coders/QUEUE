#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX 20


struct stack
{
int top;
int capacity;
int *array;	
};




struct queue
{
struct stack;	
};






struct stack* createqueue()
      {
      	struct stack*s=(struct stack*)malloc(sizeof(struct stack));
      	s->top=-1;
      	s->capacity=MAX;
      	s->array=(int*)malloc(sizeof(int));
      	
      	return s;
	  }




int isempty(struct stack*s)
   {
   		return s->top==-1;
   }
   


   
int isfull(struct stack*s)
    {
     	return s->top==s->capacity-1;     	
	}  




void push(struct stack*s,int data)
  { 
  	 if(isfull(s))
  	    {
  	     printf("isfull");
		   return;	
		}
	 s->array[++s->top]=data;	
  }
  
  


int pop(struct stack*s)
  { 
  	 if(isempty(s))
  	    {
  	     printf("isEmpty");
		   return;	
		}
	 return s->array[s->top--];	
  }





void enqueue(struct stack*s,int data)
       {
         push(s,data);   	
	   }




int dequeue(struct stack*s)
      {
      	pop(s);
	  }
  



int main() 
{
	struct stack*s=createqueue();
	
	enqueue(s,10);
	enqueue(s,20);
	printf("The deleted element is %d",dequeue(s));
	enqueue(s,30);
	printf("\nThe deleted element is %d",dequeue(s));
	enqueue(s,40);
	enqueue(s,50);
	printf("\nThe deleted element is %d",dequeue(s));
	enqueue(s,60);
	
	
	return 0;
}

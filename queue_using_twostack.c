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
struct stack *s1;
struct stack *s2;	
};






struct queue* createqueue()
      {
    
      	struct queue*q=(struct queue*)malloc(sizeof(struct queue));
      	
      	q->s1=(struct stack*)malloc(sizeof(struct stack));//DONT FORGET
      	
      	q->s1->top=-1;
      	q->s1->capacity=MAX;
      	q->s1->array=(int*)malloc(sizeof(int)*q->s1->capacity);
      	
      	q->s2=(struct stack*)malloc(sizeof(struct stack));//DONT FORGET
      	
		q->s2->top=-1;
      	q->s2->capacity=MAX;  
      	q->s2->array=(int*)malloc(sizeof(int)*q->s2->capacity);
		  
      	
      	return q;
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





void enqueue(struct queue*s,int data)
       {
         push(s->s1,data);   	
	   }




int dequeue(struct queue*s)
      {
      	if(isempty(s->s2))
      	      {
      	        push(s->s2,pop(s->s1));	
			  }
		return pop(s->s2);	  
	  }
  



int main() 
{
	struct queue*s=createqueue();
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

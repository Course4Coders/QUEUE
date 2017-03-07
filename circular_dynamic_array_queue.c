#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX 5






struct queue
{
int front,rear;
int*array;
int capacity;	
};






struct queue*createqueue()
       {
       	struct queue*q=(struct queue*)malloc(sizeof(struct queue));
       	q->front=q->rear=-1;
       	q->capacity=MAX;
       	q->array=(int*)malloc(sizeof(int)*q->capacity);
       	
       	return q;
	   }





int isfull(struct queue*q)
     {
        return   ((q->rear+1)%q->capacity==q->front);     	
	 }



int isempty(struct queue*q)
     {
     	return q->front==-1;
	 }
	 
	 
int queuesize(struct queue*q)	 
	   {
	   	return ((q->capacity-q->front+q->rear+1)%q->capacity);
	   }
	 
void againmemory(struct queue*q)
           {
           	q->capacity=q->capacity*2;
           	q->array=realloc(q->array,sizeof(int)*q->capacity);
		   }



void enqueue(struct queue*q,int data)
      {
      	if(isfull(q))
      	   {
      	   // printf("\nQueue is Full\n");
			 againmemory(q);	
		   }
		  if(q->front==-1)
		     {
		      q->front=q->rear=(q->rear+1)%q->capacity;	
			 } 
		  else
		     {
		       q->rear=(q->rear+1)%q->capacity;	 	
			 }	 
		   q->array[q->rear]=data;
	  }


int dequeue(struct queue*q)
     {
     	int data;
     	if(isempty(q))
     	   {
     	    //printf("\nQueue is Full\n");
			 return -1;	
		   }
		   
		data=q->array[q->front];
		if(q->front==q->rear)
		   {
		   	q->front=q->rear=-1;
		   }
		else
		   {
		    q->front=q->front+1%q->capacity;	
		   }   
		   
				return data;		   
	 }



     

int main()
{
	struct queue*q=createqueue();
	 int m;
	 
	     enqueue(q,10);
	     printf("\nThe Element Dequeue is => %d\n",dequeue(q));
	     enqueue(q,20);
	     enqueue(q,30);
	     m=queuesize(q);
		 m>0?printf("\n%d\n",m):printf("\n%d\n",q->capacity);
	     enqueue(q,40);
	     printf("\nThe Element Dequeue is => %d\n",dequeue(q));
	     enqueue(q,50);
	     enqueue(q,60);
	  
	     m=queuesize(q);
		 m>0?printf("\n%d\n",m):printf("\n%d\n",q->capacity);
		 
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define  MAX 5




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






int isempty(struct queue*q)
        {
        	return(q->front==-1);        	
		}
		
		
		
		
		
int isfull(struct queue*q)		
		{
        	return((q->rear+1)%q->capacity==q->front);		  	
		}
		
		
		
		
int queuesize(struct queue*q)
        {
        	printf("\n %d %d %d\n",q->capacity,q->rear,q->front);
        	return ((q->capacity-q->front+q->rear+1)%q->capacity);
		}		
		
		
		void enqueue(struct queue*q,int data)
		     {
		     	if(isfull(q))
		     	   {
		     	   	printf("\nQUEUE is FULL\n");
		     	     return;	
				   }
                    if(q->front==-1)
					   {
					   		q->front=q->rear=q->rear+1%q->capacity;	
					   }
					else
					   {   				   
				   			q->rear=q->rear+1%q->capacity;
				       }
				   			q->array[q->rear]=data;
			 }
		
		
		
		
		
		int dequeue(struct queue*q)
		      {
		       		int data;
					   if(isempty(q))
					   {
					   	printf("\nQUEUE is Empty\n");
					    return -1;	
					   } 	   
					   
					  data=q->array[q->front];
					  if(q->front==q->rear)
					     q->front=q->rear=-1;
					  else
					     q->front=q->front+1%q->capacity;
						 
						 return data;	      	
			  }
		
		
		
		
		
int main() 
{

	struct queue*q=createqueue();

    int m;

    

	enqueue(q,10);
	enqueue(q,20);
	enqueue(q,30);
	printf("\nDequeue element is as %d\n",dequeue(q));
	 m=queuesize(q);
	 if(m==0)
	      {
	      	
	      	printf("\nTotal size is %d",q->capacity);
		  }
     else 
	      {
	      	
	        printf("\nTotal size is %d",m);	
		  }		  
		  
	enqueue(q,40);
	printf("\nDequeue element is as %d\n",dequeue(q));
	enqueue(q,50);
	 m=queuesize(q);
	 if(m==0)
	      {
	      	
	      	printf("\nTotal size is %d",q->capacity);
		  }
     else 
	      {
	      	
	        printf("\nTotal size is %d",m);	
		  }		  
		  
	enqueue(q,60);

     
       m=queuesize(q);
	 if(m==0)
	      {
	      	
	      	printf("\nTotal size is %d",q->capacity);
		  }
     else 
	      {
	      	
	        printf("\nTotal size is %d",m);	
		  }		  
		  
	printf("\nDequeue element is as %d\n",dequeue(q));
	
return 0;
}

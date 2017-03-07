#include <stdio.h>
#include <stdlib.h>





struct dll
{
	int data;
	struct dll*next;
	struct dll*prev;
};





struct queue
{
struct dll*rear;
struct dll*front;	
};




struct queue*initqueue()
    {
    	struct queue*z=(struct queue*)malloc(sizeof(struct queue));
    	        z->front=NULL;
    	        z->rear=NULL;
	}


void enqueue_atfront(struct queue*z,int data)
{
	struct dll*x=(struct dll*)malloc(sizeof(struct dll));
	        x->data=data;
        	x->next=NULL;
        	x->prev=NULL;
	
     if(z->front==NULL)
        {	
        	z->rear=z->front=x;
        	return;
		}
		
		x->next=z->front;
		z->front=x;
}




void enqueue_atrear(struct queue*z,int data)
{
  struct dll*x=(struct dll*)malloc(sizeof(struct dll));
	        x->data=data;
        	x->next=NULL;
        	x->prev=NULL;
	
     if(z->front==NULL)
        {	
        	z->rear=z->front=x;
        	return;
		}
		
		x->prev=z->rear;
		z->rear=x;	
} 




int dequeue_atfront(struct queue*z)
{
	int data;
	struct dll*x;
	if(z->front==NULL)
	    {
	    	printf("QUEUEU is EMPTY\n");
	    	return -1;
		}
		data=z->front->data;
		 x=z->front;
	if(z->front==z->rear)
	    {
	      
		   z->front=z->rear=NULL;
		   free(x);  	
		}	
	else
	    {
	        z->front->next->prev=NULL;		
		   z->front=z->front->next;
		   free(x);  	
		}	
		return data;
} 




int dequeue_atrear(struct queue*z)
{
    int data;
	struct dll*x;
	if(z->front==NULL)
	    {
	    	printf("QUEUEU is EMPTY\n");
	    	return -1;
		}
		data=z->rear->data;
		 x=z->rear;
	if(z->front==z->rear)
	    {
	      
		   z->front=z->rear=NULL;
		   free(x);  	
		}	
	else
	    {
	        z->rear->prev->next=NULL;		
		   z->rear=z->rear->prev;
		   free(x);  	
		}	
		return data;
} 




int main() 
{
	struct queue*z=initqueue();
	
	enqueue_atrear(z,100);
	enqueue_atfront(z,200);
	printf("\nAT Front => %d\n",dequeue_atfront(z));
	enqueue_atrear(z,300);
	enqueue_atfront(z,500);
	printf("\nAT Front => %d\n",dequeue_atfront(z));
	enqueue_atfront(z,670);
	enqueue_atfront(z,700);
	printf("\nAt Rear => %d\n",dequeue_atrear(z));
	enqueue_atrear(z,890);
	enqueue_atfront(z,290);
	printf("\nAt Rear => %d\n",dequeue_atrear(z));
	printf("\nAT Front => %d\n",dequeue_atfront(z));
return 0;
}

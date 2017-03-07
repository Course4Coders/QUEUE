#include <stdio.h>
#include <stdlib.h>

#define MAX 20


int a[MAX];
int rear=-1;
int front=-1;
int capacity=MAX;


int isempty()
{
	return (front==-1);
} 





int isfull()
{
	return (rear==capacity-1)&&(front==0);
}



void enqueue_atfront(int data)
{
	int k;
	if(isfull())
	   {
	   	printf("queue is full\n");
	   	 return;
	   }
	   if(front==-1)
	     {
	       front=++rear;
		   a[front]=data;
		   return;	
		 }
	if(front!=0)
	   {
	     a[--front]=data;	
	   }   
	 else
	   {
	     k=rear+1;
		 while(k>front)
		      {
		      	a[k]=a[k-1];
		      	--k;
			  }
		     a[front]=data;
			 ++rear;	
	   }  
	   
}






void enqueue_atrear(int data)
{
	int k=front;
	if(isfull())
	   {
	   	printf("queue is full\n");
	   	 return;
	   }
	   
	    if(front==-1)
	     {
	       front=rear;
		   return;	
		 }	
	   
	 if(rear!=capacity-1)
	    {
	      a[++rear]=data;	
		}  
	 else
	    {
	      while(k>rear)
		     {
		      a[k-1]=a[k];
			  ++k;	
			 } 	
			 a[rear]=data;
			 --front;
		}
	  	
} 






int dequeue_atfront()
{
	int data;
	if(isempty())
	   {
	   	printf("Queue is Empty\n");
	   	return -1;
	   }
	   data=a[front];
	   if(front==rear)
	      {
	      	front=rear=-1;
		  }
		else
		  {
		    ++front;	
		  }
		  return data;  
}




int dequeue_atrear()
{
	int data;
	if(isempty())
	   {
	   	printf("queue is empty\n");
	   	 return -1;
	   }
	   data=a[rear];
	   if(front==rear)
	      front=rear=-1;
	   else
	      --rear;
		     
		     return data;
}



int main() 
{
	
	enqueue_atfront(10);
	enqueue_atfront(67);
	

	enqueue_atrear(20);
	enqueue_atrear(30);

	printf("The Dequeue element is as %d\n",dequeue_atrear());
	enqueue_atrear(40);
	enqueue_atfront(50);
	printf("\nThe Dequeue element is as %d",dequeue_atfront());
    printf("\nThe Dequeue element is as %d",dequeue_atfront());
    printf("\nThe Dequeue element is as %d\n",dequeue_atrear());
	return 0;
}

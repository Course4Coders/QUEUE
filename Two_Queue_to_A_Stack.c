#include <stdio.h>
#include <stdlib.h>
#include  <malloc.h>

#define MAX 20

    struct queue
    {
      int rear,front;
	  int capacity;
	  int *array;	
	};



      struct stack
        {
        	struct queue*q1;
        	struct queue*q2;
		};



       struct stack*createstack()
               {
               	 struct stack*s=(struct stack*)malloc(sizeof(struct stack));
               	          s->q1=(struct queue*)malloc(sizeof(struct queue));
               	          s->q2=(struct queue*)malloc(sizeof(struct queue));
               	          
               	          s->q1->rear=s->q1->front=-1;
               	          s->q1->capacity=MAX;
               	          s->q1->array=(int*)malloc(sizeof(int)*s->q1->capacity);
               	          
               	          s->q2->rear=s->q2->front=-1;
               	          s->q2->capacity=MAX;
               	          s->q2->array=(int*)malloc(sizeof(int)*s->q2->capacity);
               	          
               	          return s;
			   }



      int isfull(struct queue*q)
          {
          	return (q->rear==(q->capacity-1));
		  }
  
  
      int isempty(struct queue*q)
           {
           	return ((q->front)==-1);
		   }

        
     void enqueue(struct queue*q,int data)
	       {
	         if(isfull(q))
			    {
			     printf("\nQUEue is full\n");
				 return;	
			    }	
			  if(q->front==-1)
			    {
			      q->front=++q->rear;	
				}  
			  else
			    {
			     ++q->rear;	
				}	
			 q->array[q->rear]=data;	
		   }      
        
        
        
     int dequeue(struct queue*q)
	       {
	       	int data;
	         if(isempty(q))
			    {
			     printf("\nQUEue is emPTY\n");
				 return -1;	
			    }	
			  data=q->array[q->front];
			  
			  if(q->front==q->rear)
			     {
			       q->front=q->rear=-1;	
				 }  
			   else
			     {
			      ++q->front;	
				 }	 
				 
			    return data;
		   }   
        
        
        
        void push(struct stack*s,int data)
              {
              	if(isempty(s->q1))
              	enqueue(s->q2,data);
              	else
              	enqueue(s->q1,data);  
			  }
        
        
        int size(struct queue*s)
             {
             	return (s->rear-s->front+1);
			 }
        
        
        int pop(struct stack*s)
             {
             	int size1,i=1;
             	if(s==NULL)
             	    {
             	   	 printf("\nstack is empty\n");
             	   	 return -1;
					}
					
					if(isempty(s->q2))
					   {
					   	
					   	size1=size(s->q1);
					   	while(i<size1)
					   	      {
					   	   	    enqueue(s->q2,dequeue(s->q1));
					   	   	    ++i;
							  }
							  
							 	return dequeue(s->q1); 
					   }
					 else
					    {
					    	
						size1=size(s->q2);
					
					   	while(i<size1)
					   	      {
					   	   	    enqueue(s->q1,dequeue(s->q2));
					   	   	    ++i;
							  }
							  
							 	return dequeue(s->q2); 
					   }
					
             
			 }
        
        
	int main()
	{
		struct stack*s=createstack();
		
		push(s,10);
		push(s,20);
		push(s,30);
		printf("\n%d",pop(s));
		push(s,40);
		push(s,50);
		push(s,60);
	    printf("\n%d",pop(s));
		
		return 0;
	}

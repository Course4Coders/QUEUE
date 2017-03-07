#include <stdio.h>
#include <stdlib.h>


	struct node
	{
	   int data;
	   struct node*next;	
	};

    struct queue
    {
        struct node*front;
		struct node*rear;	
	};

      int isempty(struct queue*q)
            {
            	
            	return q->front==NULL?1:0;
            	 
			}



    void enqueue(struct queue*q,int data)
          { 
           
          	struct node*z=(struct node*)malloc(sizeof(struct node));
          	z->data=data;
          	z->next=NULL;
          	if(q->front==NULL)
          	   {
          	    q->front=q->rear=z;	
			   }
			else
			   {
			    q->rear->next=z;
				q->rear=q->rear->next;	
			   }   
		  }


         int dequeue(struct queue*q)
              {
              	
               	if(isempty(q))
              	   {
              	   
              	    printf("\nQueue is empty\n");
					  return -1;	
				   }
              	  
              	int data;
              	struct node*m;
              	data=q->front->data;
              	m=q->front;
              	q->front=q->front->next;
              	free(m);
              	return data;
			  }


     struct queue* init()
              {
              	struct queue*q=(struct queue*)malloc(sizeof(struct queue));
              	 q->front=q->rear=NULL;
              	 return q;
			  }
         

	int main()
 	{
 		struct queue*q=init();
 		   
			
 		   enqueue(q,10);
		   enqueue(q,20);
		   enqueue(q,30);
		    printf("\nDequeue element is => %d\n",dequeue(q));
		   enqueue(q,40);
		   enqueue(q,50);
		    printf("\nDequeue element is => %d\n",dequeue(q));
		   enqueue(q,60);
 		   enqueue(q,70);
 		  
		   
		   printf("\nDequeue element is => %d\n",dequeue(q));
 		
 		
		return 0;
 	}

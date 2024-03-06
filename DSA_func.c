#include "DSA_HEAD.h"

#if defined stack
int stack_array[CAPACITY];
int Top_Index = -1, Index_Size=CAPACITY;
typedef enum
{
	SUCCESS,
	OVERFLOW,
}stack_err;
uint8_t Push(int *data)
{
	if (Top_Index == Index_Size - 1)
	{
#if defined print
		printf("\nOverflow!!");
#endif
		return OVERFLOW;
	}
	else
	{
		Top_Index = Top_Index + 1;
		stack_array[Top_Index] = *data;
	}
	return SUCCESS;
}
uint8_t Pop()
{
	if (Top_Index == -1)
	{
#if defined print
		printf("\nUnderflow!!");
#endif
	}
	else
	{
		return stack_array[Top_Index--];
	}
}
void Show()
{
	if (Top_Index == -1)
	{
#if defined print
		printf("\nUnderflow!!");
#endif
	}
	else
	{
		for (int i = Top_Index; i >= 0; --i)
		{
#if defined print
			printf("%d\n", stack_array[i]);
#endif
		}
	}
}
#endif

#if defined single_linked_list

typedef enum
{
	SLL_SUCCESS,
	SLL_MALLOC_ERR,
	SLL_POS_ERR,
	SLL_EMPTY
}link_err;
struct SLL_node
{
	int data;
	struct SLL_node *next;
}__attribute__((packed));
struct SLL_node *SLL_root=NULL;

uint8_t SLL_create(int link_data)
{
	struct SLL_node *temp,*ptr;
	temp=(struct SLL_node*)malloc(sizeof(struct SLL_node));
	if(temp == NULL)
	{
		#if defined print
		printf("memory not allocated");
		#endif
		return SLL_MALLOC_ERR;
	}
	temp->data=link_data;
	temp->next=NULL;
	if(SLL_root == NULL)
	{
		SLL_root=temp;
		return SLL_SUCCESS;
	}
	else
	{
		ptr=SLL_root;
		while(ptr->next != NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
	return SLL_SUCCESS;
#if defined print
	// printf("\nptr->data : %p\n",ptr->data);
	// printf("temp->data : %p\n",temp->data);
	// printf("SLL_root->data : %p",SLL_root->data);
#endif
}
void SLL_display()
{
	struct SLL_node *temp;
	temp=SLL_root;
	if(temp == NULL)
	{
		#if defined print
		printf("list SLL_EMPTY");
		#endif
	}
	else
	{
		while(temp!= NULL)
		{
			#if defined print
			printf("\n%d\n",temp->data);
			#endif
			temp=temp->next;
		}
	}
}
uint8_t SLL_insert_begin(int begin_data)
{
	struct SLL_node *temp;
	temp=(struct SLL_node*)malloc(sizeof(struct SLL_node));
	if(temp == NULL)
	{
		#if defined print
		printf("memory full");
		#endif
		return SLL_MALLOC_ERR;
	}
	temp->data=begin_data;
	temp->next=NULL;
	if(SLL_root == NULL)
	{
		SLL_root=temp;
		return SLL_SUCCESS;
	}
	else
	{
		temp->next=SLL_root;
		SLL_root=temp;
	}
	return SLL_SUCCESS;
}
uint8_t SLL_insert_end(int end_data)
{
	struct SLL_node *temp,*ptr;
	temp=(struct SLL_node*)malloc(sizeof(struct SLL_node));
	if(temp == NULL)
	{
		#if defined print
		printf("memory full");
		#endif
		return SLL_MALLOC_ERR;
	}
	temp->data=end_data;
	temp->next=NULL;
	if(SLL_root==NULL)
	{
		SLL_root=temp;
		return SLL_SUCCESS;
	}
	else
	{
		ptr=SLL_root;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
	return SLL_SUCCESS;
}
uint8_t SLL_delete_begin()
{
	struct SLL_node *temp;
	temp=(struct SLL_node*)malloc(sizeof(struct SLL_node));
	if(temp == NULL)
	{
		#if defined print
		printf("memory full");
		#endif
		return SLL_MALLOC_ERR;
	}
	if(SLL_root == NULL)
		return SLL_SUCCESS;
	else
	{
		temp=SLL_root;
		SLL_root=temp->next;
		free(temp);
	}
	return SLL_SUCCESS;
}
uint8_t SLL_delete_end()
{
	struct SLL_node *temp,*ptr;
	if(SLL_root == NULL)
	{
		#if defined print
		printf("SLL_EMPTY");
		#endif
		return SLL_EMPTY;
	}
	ptr=SLL_root;
	while(ptr->next!=NULL)
	{
		temp=ptr;
		ptr=ptr->next;
	}
	temp->next=NULL;
	free(ptr);
	return SLL_SUCCESS;
}
uint8_t SLL_insert_pos(int posi,int posi_data)
{
	struct SLL_node *temp,*ptr;
	temp=(struct SLL_node*)malloc(sizeof(struct SLL_node));
	if(temp == NULL)
	{
		#if defined print
		printf("memory full");
		#endif
		return SLL_MALLOC_ERR;
	}
	temp->data=posi_data;
	temp->next=NULL;
    if(posi==0)
    {
        temp->next=SLL_root;
        SLL_root=temp;
    }
	else
	{
		ptr=SLL_root;
		for(int i=0;i<posi;i++)
		{
			ptr=ptr->next;
			if(ptr==NULL)
				return SLL_POS_ERR;
		}
		temp->next=ptr->next;
		ptr->next=temp;
	}
}
uint8_t SLL_delete_pos(int posi)
{
	struct SLL_node *temp,*ptr;
	if(SLL_root==NULL)
		return SLL_EMPTY;
	else
	{
		if(posi==0)
        {
            ptr=SLL_root;
            SLL_root=SLL_root->next ;
			free(ptr);
		}		
		else
		{
			ptr=SLL_root;
			for(int i=0;i<posi;i++)
			{
				temp=ptr;
				ptr=ptr->next;
				if(ptr==NULL)
					return SLL_POS_ERR;
			}
			temp->next=ptr->next;
		}
	}
	return SLL_SUCCESS;
}
uint8_t SLL_search(int posi)
{
	struct SLL_node *temp,*ptr;
	if(SLL_root==NULL)
	{
        #if defined print
		printf("Empty");
		#endif 
	}
	else
	{
		ptr=SLL_root;
		if(posi==0)
        {
            #if defined print
			printf("%d",ptr->data);
			#endif 
			return ptr->data;
		}		
		else
		{
			for(int i=0;i<posi;i++)
			{
				ptr=ptr->next;
				if(ptr==NULL)
				{
					#if defined print
					printf("wrong position");
					#endif
					return SLL_POS_ERR;
				}
			}
			return ptr->data;
		}
	}
}
#endif

#if defined double_linked_list
struct DLL_node
{
	struct DLL_node *prev;
	struct DLL_node *next;
	int data;
}__attribute__((packed));
struct DLL_node *DLL_root;

typedef enum
{
	DLL_SUCCESS,
	DLL_MALLOC_ERR,
	DLL_POS_ERR,
	DLL_EMPTY
}DLL_err;

uint8_t  DLL_insert_begin(int link_data)
{
	struct DLL_node *temp;
	temp=(struct DLL_node*)malloc(sizeof(struct DLL_node));
	if(temp == NULL)
		return DLL_MALLOC_ERR;
	if(DLL_root == NULL)
	{
		temp->data=link_data;
		temp->prev=NULL;
		temp->next=NULL;
		DLL_root=temp;
	}
	else
	{
		temp->data=link_data;
		temp->prev=NULL;
		temp->next=DLL_root;
		DLL_root->prev=temp;
		DLL_root=temp;
	}
}
uint8_t DLL_insert_end(int end_data)
{
	struct DLL_node *temp,*ptr;
	temp=(struct DLL_node*)malloc(sizeof(struct DLL_node));
	if(temp == NULL)
		return DLL_MALLOC_ERR;
	temp->data=end_data;
	temp->prev=NULL;
	temp->next=NULL;
	if(DLL_root==NULL)
	{
		DLL_root=temp;		
	}
	else
	{
		ptr=DLL_root;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
		temp->prev=ptr;
	}
}
void DLL_FwDisplay()
{
	struct DLL_node *temp;
	if(DLL_root==NULL)
	{
		#if defined print
		printf("root empty");
		#endif
	}
	else
	{
		temp=DLL_root;
		while(temp != NULL)
		{
			#if defined print
			printf("%d ",temp->data);
			#endif
			temp=temp->next;
		}
	}
}
void DLL_RwDisplay()
{
	struct DLL_node *temp;
	if(DLL_root==NULL)
	{
		#if defined print
		printf("root empty");
		#endif
	}
	else
	{
		#if defined print
		printf("\n");
		#endif		
		temp=DLL_root;
		while(temp->next != NULL)
			temp=temp->next;
		while(temp != NULL)
		{
			#if defined print
			printf("%d ",temp->data);
			#endif
			temp=temp->prev;
		}		
	}
}
uint8_t DLL_insert_pos(int posi,int posi_data)
{
	struct DLL_node *temp,*ptr;
	temp=(struct DLL_node*)malloc(sizeof(struct DLL_node));
	if(temp == NULL)
		return DLL_MALLOC_ERR;
	if(DLL_root == NULL)
	{
		temp->data=posi_data;
		temp->prev=NULL;
		temp->next=NULL;
		DLL_root=temp;
	}
	else
	{
		if(posi == 0)
		{
			DLL_insert_begin(posi_data);
		}
		else
		{
			temp->data=posi_data;
			temp->prev=NULL;
			temp->next=NULL;
			ptr=DLL_root;
			for(int i=0;i<(posi-1);i++)
			{
				ptr=ptr->next;
				if(ptr==NULL)
					return DLL_POS_ERR;
			}
			temp->next=ptr->next;
			ptr->next=temp;
			temp->prev=ptr;
		}
		return DLL_SUCCESS;
	}
}
uint8_t DLL_delete_pos(int del_pos)
{
	struct DLL_node *temp,*ptr;
	if(DLL_root == NULL)
		return DLL_EMPTY;
	if(del_pos == 0)
	{
		temp=DLL_root;
		temp=temp->next;
		temp->prev=NULL;
		DLL_root=temp;
	}
	else
	{
		ptr=DLL_root;
		for(int i=0;i<(del_pos-1);i++)
		{
			ptr=ptr->next;
			if(temp==NULL)
				return DLL_POS_ERR;
		}
		temp=ptr->next;
		ptr->next=temp->next;
		temp->prev=ptr;
		printf("temp:%d\n",temp->data);
		free(temp);
	}
}
uint8_t DLL_delete_begin()
{
	struct DLL_node *temp;
	if(DLL_root == NULL)
		return DLL_EMPTY;
	temp=DLL_root;
	temp=temp->next;
	DLL_root=temp;
	return DLL_SUCCESS;
}
uint8_t DLL_delete_end()
{
	struct DLL_node *temp;
	if(DLL_root == NULL)
		return DLL_EMPTY;
	temp=DLL_root;
	while(temp->next!=NULL)
		temp=temp->next;
	temp=temp->prev;
	temp->next=NULL;
	return DLL_SUCCESS;
}
#endif
#if defined queue
int q_rear=-1,q_front=-1;
#define Q_CAPACITY 5
int Q_arr[Q_CAPACITY];
typedef enum
{
	Q_SUCCESS,
	Q_OVERFLOW,
	Q_UNDERFLOW,
	Q_EMPTY
}q_err;
uint8_t enqueue(int q_data)
{
	if(q_rear == (Q_CAPACITY-1))
		return Q_OVERFLOW;
	else
	{
		if(q_front == -1)
			q_front=0;
		q_rear++;
		Q_arr[q_rear]=q_data;
	}
	return Q_SUCCESS;
}
int dequeue()
{
	if(q_front == -1) 
		return Q_UNDERFLOW;
	else
	{
		if(q_front>q_rear)
		{
			q_front=q_rear=-1;
			return Q_UNDERFLOW;
		}
		return Q_arr[q_front++];
	}
}
uint8_t q_show()
{
	if(q_front == -1)
		return Q_EMPTY;
	for(int i=q_front;i<=q_rear;i++)
	{
		#if defined print
		printf("%d ",Q_arr[i]);
		#endif
	}
	return Q_SUCCESS;
}
#endif
#if defined circular_queue
int cq_rear=-1,cq_front=-1;
#define CQ_CAPACITY 5
int CQ_arr[CQ_CAPACITY];
typedef enum
{
	CQ_SUCCESS,
	CQ_OVERFLOW,
	CQ_UNDERFLOW,
	CQ_EMPTY
}cq_err;
uint8_t c_enqueue(int cq_data)
{
	if((cq_rear == -1) && (cq_rear == -1))
	{
		cq_front=0;
		cq_rear=0;
		CQ_arr[cq_rear] = cq_data;
	}
	else if((cq_rear+1)%CQ_CAPACITY == cq_front)
		return CQ_OVERFLOW;
	else
	{	
		cq_rear=(cq_rear+1)%CQ_CAPACITY;
		CQ_arr[cq_rear]=cq_data;
	}
	return CQ_SUCCESS;
}
int c_dequeue()
{
	int cq_temp;
	if((cq_rear == -1) && (cq_rear == -1))
	{
		return CQ_UNDERFLOW;
	}
	else if(cq_front == cq_rear)
	{
		cq_temp=CQ_arr[cq_front];
		cq_front=-1;
		cq_rear=-1;
		return cq_temp;
	}
	else
	{
		cq_temp = CQ_arr[cq_front];
		cq_front=(cq_front+1)%CQ_CAPACITY;
		return cq_temp;
	}
}
#endif

#if defined binary_search_tree
struct BST_node
{
	int data;
	struct bst_node *right;
	struct bst_node *left;
};
struct bst_node *bst_root;

uint8_t BST_creation(int bst_data)
{
	struct BST_node *temp=(struct BST_node*)malloc(sizeof(struct BST_node));
	temp->data=bst_data;
	temp->right=NULL;
	temp->left=NULL;
	if(bst_root == NULL)
}
#endif
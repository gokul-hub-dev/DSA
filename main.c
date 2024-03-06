#include "DSA_HEAD.h"
void main()
{
    int data, show, get_option;
    while (1)    
    {
		// printf("\nselect DSA:\n0.exit\n1.stack\n2.single linked list\n3.double linked list\n4.queue\n5.circular_queue\n");
		// scanf("%d",&get_option);
		// if(get_option == 0)
			// exit(0);
		// else if(get_option==1)
		// {
		// #if defined stack
			// printf("select options: \n1.push\n2.pop\n3.show\n4.exit");
			// scanf("%d", &get_option);
			// switch (get_option)
			// {
			// case 1:
				// printf("enter data:");
				// scanf("%d",&data);
				// Push(&data);
				// break;
			// case 2:
				// show = Pop();
				// printf("\n%d\n",show);
				// break;
			// case 3:
				// Show();
				// break;
			// case 4:
				// exit(0);
				// break;
			// default:
				// break;
			// }
		// #endif
        // }
		// else if(get_option == 2)
		// {
		// #if defined single_linked_list
			// printf("select options: \n1.create\n2.display\n3.insert begin\n4.insert end\n5.delete begin\n6.delete end\n7.insert pos\n8.delete pos\n9.search\n10.exit\n");
			// int position;
			// scanf("%d", &get_option);
			// switch (get_option)
			// {
			// case 1:
				// printf("enter data:");
				// scanf("%d",&data);
				// SLL_create(data);
				// break;
			// case 2:
				// SLL_display();
				// break;
			// case 3:
				// printf("enter data:");
				// scanf("%d",&data);				
				// SLL_insert_begin(data);
				// break;
			// case 4:
				// printf("enter data:");
				// scanf("%d",&data);				
				// SLL_insert_end(data);				
				// break;
			// case 5:			
				// SLL_delete_begin();
				// break;
			// case 6:			
				// SLL_delete_end();				
				// break;
			// case 7:
				// printf("enter position:");
				// scanf("%d",&position);
				// printf("\ndata:");
				// scanf("%d",&data);
				// SLL_insert_pos(position,data);
				// break;
			// case 8:
				// printf("enter position:");
				// scanf("%d",&position);
				// SLL_delete_pos(position);
				// break;
			// case 9:
				// printf("enter position:");
				// scanf("%d",&position);
				// SLL_search(position);
				// break;				
			// case 10:
				// exit(0);
				// break;
			// default:
				// break;
			// }
		// #endif
		// }
		// else if(get_option == 3)
		// {
		// #if defined double_linked_list
			// printf("\nselect options:\n1.insert begin\n2.display\n3.insert end\n4.delete begin\n6.delete end\n7.insert pos\n8.delete pos\n9.exit\n");
			// int position;
			// scanf("%d", &get_option);
			// switch (get_option)
			// {
			// case 1:
				// printf("enter data:");
				// scanf("%d",&data);
				// DLL_insert_begin(data);
				// break;
			// case 2:
				// DLL_FwDisplay();
				// DLL_RwDisplay();
				// break;
			// case 3:
				// printf("enter data:");
				// scanf("%d",&data);
				// DLL_insert_end(data);
				// break;
			// case 4:
				// DLL_delete_begin();
				// break;
			// case 6:
				// DLL_delete_end();
				// break;
			// case 7:
				// printf("enter position:");
				// scanf("%d",&position);
				// printf("enter data:");
				// scanf("%d",&data);				
				// DLL_insert_pos(position,data);
				// break;	
			// case 8:
				// printf("enter postion:");
				// scanf("%d",&position);
				// DLL_delete_pos(position);
				// break;
			// case 9:
				// exit(0);
				// break;
			// default:
				// break;
			// }
		// #endif
		// }
		// else if(get_option == 4)
		// {
		// #if defined queue
			// printf("select options: \n1.enqueue\n2.dequeue\n3.show\n4.exit\n");
			// scanf("%d", &get_option);
			// switch (get_option)
			// {
			// case 1:
				// printf("enter data:");
				// scanf("%d",&data);
				// enqueue(data);
				// break;
			// case 2:
				// show = dequeue();
				// printf("\ndata : %d\n",show);
				// break;
			// case 3:
				// q_show();
				// break;
			// case 4:
				// exit(0);
				// break;
			// default:
				// break;
			// }
		// #endif			
		// }
		// else if(get_option == 5)
		// {
		// #if defined circular_queue
			// printf("select options: \n1.enqueue\n2.dequeue\n3.exit\n");
			// scanf("%d", &get_option);
			// switch (get_option)
			// {
			// case 1:
				// printf("enter data:");
				// scanf("%d",&data);
				// c_enqueue(data);
				// break;
			// case 2:
				// show = c_dequeue();
				// printf("\ndequeue : %d\n",show);
				// break;
			// case 3:
				// exit(0);
				// break;
			// default:
				// break;
			// }
		// #endif			
		// }
		// else if(get_option == 6)
		// {
			#if defined binary_search_tree
			printf("select options: \n1.creation\n2.insertion\n3.deletion\n4.search\n5.exit\n");
			scanf("%d", &get_option);
			switch (get_option)
			{
			case 1:
				printf("enter data:");
				scanf("%d",&data);
				BST_creation(data);
				break;
			case 2:
				// show = c_dequeue();
				printf("\ndequeue : %d\n",show);
				break;
			case 3:
				exit(0);
				break;
			default:
				break;
			}
			#endif
		// }
	}
}
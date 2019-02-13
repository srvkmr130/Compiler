#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
typedef enum
{
start,build_num,build_id,stop}
states;
 	states transition(states cur_state, char c)
 		{ 
			switch(cur_state)
 			{
	 			case start:
	 			  {
		 			  if(isdigit(c)!=0)
		 			  return build_num;
		 			  else if(isalpha(c)!=0)
		 			  return build_id;
		 			  else if(c=='.')
		 			  return stop;
		 			  else if(c==' ')
		 			  return start;
					  else printf("Error");
	 			  }
	 			 case build_id:
	 			   { 
		 			  if(isalpha(c)!=0 || isdigit(c)!=0 ||c=='_')
		 			  return build_id;
		 			  else if(c==' ')
					   {
		 			  printf("-->identifier");
		 			  return start;
		 			   }
					  else printf("Error");
	 			    }
	 			 case build_num:
	 			   {
		 			  if(isdigit(c)!=0)
		 			  return build_num;
		 			  else if(c==' ')
					  {
					   printf("-->number");
		 			   return start;
	 			          }
				  	   else printf("Error");
	 			    }
	 			 case stop:
	 			  	   return stop;
	 		   }
 			  
 		}
int main()
{
    states cur_state;
    char c;	  
    cur_state=start;
    scanf ("%c", &c);
	printf ("start");
	while (c!='\n')
	{
		cur_state = transition(cur_state, c);
		scanf ("%c",&c);
	}
	if (cur_state==stop)
		printf("\n  Accepted \n");
	else
		printf ("\n Rejected \n");
	return 0;
}

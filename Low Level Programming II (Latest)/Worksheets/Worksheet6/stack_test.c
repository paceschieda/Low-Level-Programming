#include <stdio.h> 
 
void recurse(int level) 
{ 
    char arry[1024]; 
    printf("%d\n", level); 
    recurse(level+1); 
} 

/*
SOLUTION
void recurse(int level) 
{ 
    if(level > 10000){
	return;
    }
    char *arry = malloc(1024); 
    printf("%d\n", level); 
    recurse(level+1); 
} 
*/
 
int main() 
{
    recurse(1); 
    return 0; 
} 

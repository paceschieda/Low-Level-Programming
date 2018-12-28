#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Usage: process_marks <textfile> \n");
		return -1;
	}
	else if(argc == 2)
	{
		char string[50];
		int mark;
		char grade[3];
		
		FILE *fp = fopen(argv[1], "r");
		FILE *fp_output = fopen("/home/llp2/Desktop/llp2-master/worksheets/worksheet09/outputfile.csv", "w");
		if(fp != NULL)
		{
			while(!feof(fp))
			{	
				if(fscanf(fp, "%s %d", string, &mark) == 2)
				{
					if(mark > 89)
						strncpy(grade, "A+", 2);
					else if((74 < mark) && (mark < 90))
						strncpy(grade, "A", 2);
					else if((64 < mark) && (mark < 75))
						strncpy(grade, "B", 2);
					else if((49 < mark) && (mark < 65))
						strncpy(grade, "C", 2);
					else if(mark < 50)
						strncpy(grade, "F", 2);
					
					
					fprintf(fp_output, "%s, %d, %s \n", string, mark, grade);
					
				}
				else
				{
					break;
				}
			}
			printf("Processing rows... \n");
			printf("Finished all file, results in outputfile.csv \n");

			fclose(fp);
			fclose(fp_output);
		}
		else
		{
			printf("Failed to open %s \n", argv[1]);
			return -2;
		}
	}
}
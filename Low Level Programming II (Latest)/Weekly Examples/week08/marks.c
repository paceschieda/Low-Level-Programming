#include <stdio.h>

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Usage: count_marks <textfile> \n");
		return -1;
	}
	else if(argc == 2)
	{
		int mark;
		int count = 0;
		int passes = 0;
		FILE *fp = fopen(argv[1], "r");
		if(fp != NULL)
		{
			while(!feof(fp))
			{
				if(fscanf(fp, "%d", &mark) != 1)
				{
					break;
				}
				if (mark >= 50)
				{
					passes++;
				}
				count++;
			}
			int percentage = (((double)passes)/count)*100;
			printf("Pass rate is %d of %d (%d%%)\n", passes, count, percentage);
			fclose(fp);
			return 0;
		}
		else
		{
			printf("Failed to open %s \n", argv[1]);
			return -2;
		}
	}
}


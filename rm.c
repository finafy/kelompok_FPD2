#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{



	if(argc<2)
	{
		printf(2,"Need 2 Arguments\n");
		exit();
	}
	
	else
	{
	        for(i=1;i<argc;i++)
		{

		     if(unlink(argv[i]<0)
			{
				printf(2,"rm: can't remove '%s' : No such file\n", argv[i]);

				break;
			}
		}
		exit();
	}


} 

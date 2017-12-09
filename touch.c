#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char buf[512];

int main( int argc, chr *argv[])
{
	int fd;
	fd=open(argv[1],O_CREATE);
	close(fd);

	exit();
}

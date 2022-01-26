#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp) {
	gid_t gid = getegid();
	uid_t uid = geteuid();

	setregid(gid, gid);
	setreuid(uid, uid);

	system("/bin/bash");
}


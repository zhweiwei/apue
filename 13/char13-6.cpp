#include "apue.h"

#define LOCKFILE "/var/run/deemon.pid"
#define LOCKMODE  (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)

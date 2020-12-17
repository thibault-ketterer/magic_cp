

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libproc.h>

int main (int argc, char* argv[])
{
        int ret;
        pid_t pid; 
        char pathbuf[PROC_PIDPATHINFO_MAXSIZE];
        struct proc_vnodepathinfo vpi;

        if (argc > 1) {
                pid = (pid_t) atoi(argv[1]);
                ret = proc_pidpath (pid, pathbuf, sizeof(pathbuf));
                if (ret <= 0) {
                        fprintf(stderr, "PID %d: proc_pidpath ();\n", pid);
                        fprintf(stderr, "    %s\n", strerror(errno));
                        return 1;
                }
                //printf("proc %d executable: %s\n", pid, pathbuf);
                ret = proc_pidinfo(pid, PROC_PIDVNODEPATHINFO, 0, &vpi,
                                   sizeof(vpi));
                if (ret <= 0) {
                        fprintf(stderr, "PID %d: proc_pidinfo ();\n", pid);
                        fprintf(stderr, "    %s\n", strerror(errno));
                        return 1;
                }
                printf("%s\n", vpi.pvi_cdir.vip_path);
                // printf("proc %d root: %s\n", pid, vpi.pvi_rdir.vip_path);
        }

        return 0;
}

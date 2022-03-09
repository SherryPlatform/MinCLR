/*
 * PROJECT:   MinInit
 * FILE:      MinInit.c
 * PURPOSE:   Implementation for MinInit
 *
 * LICENSE:   The MIT License
 *
 * DEVELOPER: Mouri_Naruto (Mouri_Naruto AT Outlook.com)
 */

#include <errno.h>
#include <fcntl.h>
#include <sys/mount.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <stdio.h>

void print_message(const char *message)
{
    printf("[MinInit] %s\n", message);
}

int main()
{
    {
        int confd = open("/dev/console", O_RDWR);
        if (-1 != confd)
        {
            dup2(confd, STDIN_FILENO);
            dup2(confd, STDOUT_FILENO);
            dup2(confd, STDERR_FILENO);

            if (confd > STDERR_FILENO)
            {
                close(confd);
            }
        }
    }

    if (-1 == mount(
        "udev",
        "/dev",
        "devtmpfs",
        MS_NOSUID | MS_NOEXEC | MS_RELATIME,
        "size=10240k,mode=755") && errno != EBUSY)
    {
        print_message("Failed to mount /dev.\n");
    }

    if (-1 == mount(
        "proc",
        "/proc",
        "proc",
        MS_NOSUID | MS_NOEXEC | MS_RELATIME | MS_NODEV,
        NULL) && errno != EBUSY)
    {
        print_message("Failed to mount /proc.\n");
    }

    if (-1 == mount(
        "sysfs",
        "/sys",
        "sysfs",
        MS_NOSUID | MS_NOEXEC | MS_RELATIME | MS_NODEV,
        NULL) && errno != EBUSY)
    {
        print_message("Failed to mount /sys.\n");
    }

    if (-1 == mount(
        "tmpfs",
        "/tmp",
        "tmpfs",
        0,
        NULL))
    {
        print_message("Failed to mount /tmp to tmpfs.\n");
    }

    chdir("/root");

    const char* envp[] =
    {
        "PATH=/usr/sbin:/usr/bin:/sbin:/bin",
        "TERM=xterm-256color",
        "HOME=/root",
        NULL
    };

    const char* argv[] =
    {
        "/bin/pwsh",
        "-NoLogo",
        NULL
    };

    execve(argv[0], (char* const*)argv, (char* const*)envp);

    print_message("Failed to start PowerShell.\n");

    return 0;
}

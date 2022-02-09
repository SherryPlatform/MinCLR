/*
 * PROJECT:   MinClr (.NET/Linux)
 * FILE:      main.c
 * PURPOSE:   Implementation for clrinit
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
#include <linux/major.h>
#include <linux/kdev_t.h>
#include <unistd.h>

#include <stdio.h>

int main()
{
    if (-1 == mknod(
        "/dev/console",
        S_IFCHR | S_IRUSR | S_IWUSR, 
        MKDEV(TTYAUX_MAJOR, 1)))
    {
        printf("clrinit: Failed to mknod /dev/console.\n");
    }

    int fd;
    if ((fd = open("/dev/console", O_RDWR)) != -1) {
		dup2(fd, STDIN_FILENO);
		dup2(fd, STDOUT_FILENO);
		dup2(fd, STDERR_FILENO);

		if (fd > STDERR_FILENO)
			close(fd);
	}

    if (-1 == mount(
        "udev",
        "/dev",
        "devtmpfs",
        MS_NOSUID | MS_NOEXEC | MS_RELATIME,
        "size=10240k,mode=755") && errno != EBUSY)
    {
        printf("clrinit: Failed to mount /dev.\n");
    }

    if (-1 == mount(
        "proc",
        "/proc",
        "proc",
        MS_NOSUID | MS_NOEXEC | MS_RELATIME | MS_NODEV,
        NULL) && errno != EBUSY)
    {
        printf("clrinit: Failed to mount /proc.\n");
    }

    if (-1 == mount(
        "sysfs",
        "/sys",
        "sysfs",
        MS_NOSUID | MS_NOEXEC | MS_RELATIME | MS_NODEV,
        NULL) && errno != EBUSY)
    {
        printf("clrinit: Failed to mount /sys.\n");
    }

    if (-1 == mount(
        "tmpfs",
        "/tmp",
        "tmpfs",
        0,
        NULL))
    {
        printf("clrinit: Failed to mount /tmp to tmpfs.\n");
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

    printf("clrinit: Failed to start PowerShell.\n");

    return 0;
}
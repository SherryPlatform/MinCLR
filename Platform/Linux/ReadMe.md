# Linux Platform for MinCLR Project

This is the repository contains the Linux Platform for MinCLR Project.

## Available Generic Linux Kernel Configurations

- [VMware virtualization environment, x64](kernel-config-vmware-x64)

## Userspace Native Dependencies

Based on the reference in [dotnet/dotnet-docker] project, we only need these 
Debian packages for running a standard .NET Runtime.

[dotnet/dotnet-docker]: https://github.com/dotnet/dotnet-docker/blob/main/src/runtime-deps/3.1/bullseye-slim/amd64/Dockerfile

- .NET Runtime
  - Basic
    - libc6
      - /lib64/ld-linux-x86-64.so.2
      - libc.so.6
      - libdl.so.2
      - libm.so.6
      - libnss_compat.so.2
      - libnss_dns.so.2
      - libnss_files.so.2
      - libnss_hesiod.so.2
      - libpthread.so.0
      - libresolv.so.2
      - librt.so.1
    - libcom-err2
      - libcom_err.so.2
    - libgcc-s1
      - libgcc_s.so.1
    - libgssapi-krb5-2
      - libgssapi_krb5.so.2
    - libicu67
      - libicudata.so.67
      - libicui18n.so.67
      - libicuuc.so.67
    - libk5crypto3
      - libk5crypto.so.3
    - libkeyutils1
      - libkeyutils.so.1
    - libkrb5-3
      - libkrb5.so.3
    - libkrb5support0
      - libkrb5support.so.0
    - libssl1.1
      - libcrypto.so.1.1
      - libssl.so.1.1
    - libstdc++6
      - libstdc++.so.6
    - zlib1g
      - libz.so.1
  - Extra
    - liblttng-ust0
      - liblttng-ust.so.0
      - liblttng-ust-tracepoint.so.0
    - libnuma1
      - libnuma.so.1
    - liburcu6
      - liburcu-bp.so.6
      - liburcu-cds.so.6
- PowerShell
  - Basic
    - libaudit1
      - libaudit.so.1
    - libcap-ng0
      - libcap-ng.so.0
    - libpam0g
      - libpam.so.0
  - Extra
    - busybox
      - /bin/busybox
    - ncurses-base
      - /lib/terminfo/x/xterm-256color

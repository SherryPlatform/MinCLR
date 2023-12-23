# Linux Platform for MinCLR Project (.NET/Linux)

This is the repository contains the Linux Platform for MinCLR Project.

## Optimized Linux Kernel

Source code available at https://github.com/SherryPlatform/MinLin.Kernel.

Here are available configurations for the optimized Linux Kernel.

### Hyper-V Generation 2 Virtual Machines

You can choose these configurations for Azure, Hyper-V and NanaBox.

Note: NanaBox is a third-party lightweight XAML-based out-of-box-experience 
oriented Hyper-V virtualization software based on Host Compute System API, 
Remote Desktop ActiveX control and XAML Islands, project repository available
at https://github.com/M2Team/NanaBox. NanaBox is the reference and prototype
virtualization platform for MinLin and MinCLR.

- [x64, generic, as modularized as possible](https://github.com/SherryPlatform/MinLin.Kernel/blob/main/MinLin/config-MinLin.Kernel.NanaBox)
- [x64, generic, make all modules builtin](https://github.com/SherryPlatform/MinLin.Kernel/blob/main/MinLin/config-MinLin.Kernel.NanaBox.Single)

## Minimum Native Infrastructure

Based on the reference in [dotnet-docker] and [PowerShell-Docker] project, we
only need these Alpine packages to build the root file system for running a 
standard .NET 8.0 Runtime with full i18n support and PowerShell 7.4.0.

[dotnet-docker]: https://github.com/dotnet/dotnet-docker/blob/main/src/runtime-deps/8.0/alpine3.18-extra/amd64/Dockerfile
[PowerShell-Docker]: https://github.com/PowerShell/PowerShell-Docker/blob/master/release/7-5/alpine317/docker/Dockerfile

Here are the original links for Alpine packages. You also can browse [Packages]
folder for get the backup packages.

[Packages]: Packages

- Core Packages
  - https://mirrors.tuna.tsinghua.edu.cn/alpine/v3.19/main/x86_64/musl-1.2.4_git20230717-r4.apk
  - https://mirrors.tuna.tsinghua.edu.cn/alpine/v3.19/main/x86_64/busybox-1.36.1-r15.apk
- .NET Runtime Dependencies
  - https://mirrors.tuna.tsinghua.edu.cn/alpine/v3.19/main/x86_64/libstdc%2B%2B-13.2.1_git20231014-r0.apk
  - https://mirrors.tuna.tsinghua.edu.cn/alpine/v3.19/main/x86_64/libgcc-13.2.1_git20231014-r0.apk
  - https://mirrors.tuna.tsinghua.edu.cn/alpine/v3.19/main/x86_64/libcrypto3-3.1.4-r2.apk
  - https://mirrors.tuna.tsinghua.edu.cn/alpine/v3.19/main/x86_64/libssl3-3.1.4-r2.apk
  - https://mirrors.tuna.tsinghua.edu.cn/alpine/v3.19/main/x86_64/ca-certificates-bundle-20230506-r0.apk
  - https://mirrors.tuna.tsinghua.edu.cn/alpine/v3.19/main/x86_64/zlib-1.3-r2.apk
- .NET Runtime i18n Support Dependencies
  - https://mirrors.tuna.tsinghua.edu.cn/alpine/v3.19/main/x86_64/tzdata-2023c-r1.apk
  - https://mirrors.tuna.tsinghua.edu.cn/alpine/v3.19/main/x86_64/icu-libs-74.1-r0.apk
  - https://mirrors.tuna.tsinghua.edu.cn/alpine/v3.19/main/x86_64/icu-data-full-74.1-r0.apk
- PowerShell Dependencies
  - https://mirrors.tuna.tsinghua.edu.cn/alpine/v3.19/main/x86_64/ncurses-terminfo-base-6.4_p20231125-r0.apk
- Useful utilities for bootable image
  - https://mirrors.tuna.tsinghua.edu.cn/alpine/v3.19/main/x86_64/libncursesw-6.4_p20231125-r0.apk
  - https://mirrors.tuna.tsinghua.edu.cn/alpine/v3.19/main/x86_64/htop-3.2.2-r1.apk
  - https://mirrors.tuna.tsinghua.edu.cn/alpine/v3.19/main/x86_64/dhcpcd-10.0.5-r0.apk
  - https://mirrors.tuna.tsinghua.edu.cn/alpine/v3.19/main/x86_64/nano-7.2-r1.apk

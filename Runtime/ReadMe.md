# .NET Runtime Dependencies for MinCLR Project

## Linux flavor

Based on the reference in [dotnet/dotnet-docker] project, we only need these 
Debian packages for running a standard .NET Runtime.

[dotnet/dotnet-docker]: https://github.com/dotnet/dotnet-docker/blob/main/src/runtime-deps/3.1/bullseye-slim/amd64/Dockerfile

- [x] libstdc++6
  - [x] libc6
    - [ ] libcrypt1
      (Maybe we can removed because we don't find it in [dotnet/dotnet-docker].)
    - [x] libgcc-s1
- [ ] libssl1.1
- [ ] libgssapi-krb5-2
  - [ ] libkrb5-3
    - [ ] libcom-err2
    - [ ] libk5crypto3
      - [ ] libkrb5support0
    - [ ] libkeyutils1
      (Maybe we can removed because we don't need it in the static linked
      version of libgssapi-krb5-2.)
- [ ] libicu67
- [x] zlib1g
- [x] liblttng-ust0
  - [ ] liblttng-ust-ctl4
    - [x] libnuma1
  - [x] liburcu6

### Direct dependencies for .NET Runtime native part

- [libc6] /lib64/ld-linux-x86-64.so.2
- [libc6] libc.so.6
- [libc6] libdl.so.2
- [libgcc-s1] libgcc_s.so.1
- [liblttng-ust0] liblttng-ust.so.0
- [liblttng-ust0] liblttng-ust-tracepoint.so.0
- [libc6] libm.so.6
- [libnuma1] libnuma.so.1
- [libc6] libpthread.so.0
- [libc6] librt.so.1
- [libstdc++6] libstdc++.so.6
- [liburcu6] liburcu-bp.so.6
- [liburcu6] liburcu-cds.so.6
- [zlib1g] libz.so.1

## NuttX flavor

Work In Progress.

## MinRT flavor

Work In Progress.

# .NET Runtime Dependencies for MinCLR Project

## Linux flavor

Based on the reference in [dotnet/dotnet-docker] project, we only need these 
Debian packages for running a standard .NET Runtime.

[dotnet/dotnet-docker]: https://github.com/dotnet/dotnet-docker/blob/main/src/runtime-deps/3.1/bullseye-slim/amd64/Dockerfile

- libstdc++6
  - libc6
    - libcrypt1
        Note: Maybe we can removed because we don't find it in [dotnet/dotnet-docker].
    - libgcc-s1
        - gcc-10-base
        Note: Removed because it only contains documents.
- libssl1.1
  - debconf
    Note: Removed because we don't need a standard Debian userspace.
- libgssapi-krb5-2
  - libkrb5-3
    - libcom-err2
    - libk5crypto3
      - libkrb5support0
    - libkeyutils1
      Note: Maybe we can removed because we don't need it in the static linked
      version of libgssapi-krb5-2.
- libicu67
- zlib1g

## NuttX flavor

Work In Progress.

## MinRT flavor

Work In Progress.

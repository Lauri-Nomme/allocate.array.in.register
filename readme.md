Allocation of array in reg instead of stack.

```
$ make test
g++ -v
Using built-in specs.
COLLECT_GCC=g++
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/4.9/lto-wrapper
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Debian 4.9.2-10' --with-bugurl=file:///usr/share/doc/gcc-4.9/README.Bugs --enable-languages=c,c++,java,go,d,fortran,objc,obj-c++ --prefix=/usr --program-suffix=-4.9 --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --with-gxx-include-dir=/usr/include/c++/4.9 --libdir=/usr/lib --enable-nls --with-sysroot=/ --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --enable-gnu-unique-object --disable-vtable-verify --enable-plugin --with-system-zlib --disable-browser-plugin --enable-java-awt=gtk --enable-gtk-cairo --with-java-home=/usr/lib/jvm/java-1.5.0-gcj-4.9-amd64/jre --enable-java-home --with-jvm-root-dir=/usr/lib/jvm/java-1.5.0-gcj-4.9-amd64 --with-jvm-jar-dir=/usr/lib/jvm-exports/java-1.5.0-gcj-4.9-amd64 --with-arch-directory=amd64 --with-ecj-jar=/usr/share/java/eclipse-ecj.jar --enable-objc-gc --enable-multiarch --with-arch-32=i586 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 4.9.2 (Debian 4.9.2-10)
g++ test.cpp -std=c++11 -O3
gdb -batch -ex 'disas main' a.out
Dump of assembler code for function main:
   0x00000000004006f0 <+0>:     sub    $0x8,%rsp
   0x00000000004006f4 <+4>:     mov    0x2005c5(%rip),%rax        # 0x600cc0 <_ZSt4cout@@GLIBCXX_3.4>
   0x00000000004006fb <+11>:    movslq %edi,%rdi
   0x00000000004006fe <+14>:    mov    %rdi,%rsi
   0x0000000000400701 <+17>:    shl    $0x10,%rsi
   0x0000000000400705 <+21>:    mov    -0x18(%rax),%rdx
   0x0000000000400709 <+25>:    or     %rdi,%rsi
   0x000000000040070c <+28>:    shl    $0x10,%rsi
   0x0000000000400710 <+32>:    or     %rdi,%rsi
   0x0000000000400713 <+35>:    mov    0x600cd8(%rdx),%eax
   0x0000000000400719 <+41>:    shl    $0x10,%rsi
   0x000000000040071d <+45>:    or     %rsi,%rdi
   0x0000000000400720 <+48>:    lea    0x1(%rdi),%rsi
   0x0000000000400724 <+52>:    mov    $0x600cc0,%edi
   0x0000000000400729 <+57>:    and    $0xffffffb5,%eax
   0x000000000040072c <+60>:    or     $0x8,%eax
   0x000000000040072f <+63>:    mov    %eax,0x600cd8(%rdx)
   0x0000000000400735 <+69>:    callq  0x4006d0 <_ZNSo9_M_insertImEERSoT_@plt>
   0x000000000040073a <+74>:    mov    %rax,%rdi
   0x000000000040073d <+77>:    callq  0x4006e0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@plt>
   0x0000000000400742 <+82>:    xor    %eax,%eax
   0x0000000000400744 <+84>:    add    $0x8,%rsp
   0x0000000000400748 <+88>:    retq
End of assembler dump.
```

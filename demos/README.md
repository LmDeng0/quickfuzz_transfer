# B-AFL

Binary AFL for aarch64. 

Use ```retrowrite``` to disassemble and get .s file, then use ```afl-clang-fast``` to instrument.

The binary can be compiled with ```gcc``` or ```clang```.

*Important*:
There will be unresolvable errors for ```__cxa_finalize```.

```
(retro-arm64) root@ecs:~/retrowrite-arm64/arm/tests# AFL_AS_FORCE_INSTRUMENT=1 afl-clang-fast -fPIC -pie uaf_pie_clang.s -o uaf_pie_clang_afl
afl-clang-fast 2.52b by <lszekeres@google.com>
/usr/bin/ld: /tmp/uaf_pie_clang-27835a.o(.got+0x18): unresolvable R_AARCH64_ABS64 relocation against symbol `__cxa_finalize@@GLIBC_2.17'
/usr/bin/ld: final link failed: Nonrepresentable section on output
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```

The workaround is to remove this symbol from .s file:

```sed -i 's/__cxa_finalize//g' uaf_clang.s```

## clang retrowrite afl
```
(retro-arm64) root@ecs:~/retrowrite-arm64/arm/tests# clang uaf.c -fPIC -pie -o uaf_clang
(retro-arm64) root@ecs:~/retrowrite-arm64/arm/tests# retrowrite uaf_clang uaf_clang.s
ET_DYN
.rodata 0x8f4
.init_array 0x10db8
.got 0x10fa8
.data 0x11040
.bss 0x11050
[*] Relocations for a section that's not loaded: .rela.dyn
[*] Relocations for a section that's not loaded: .rela.plt
[x] Couldn't find valid section 10dc0
[INFO] Saved 2 out of 2 global accesses (100.0% )
[INFO] Out of 0 .text pointers, 0 cannot be saved (of which 0 are non-trivial, in total 0.0%)
[INFO] Success: retrowritten assembly to uaf_clang.s
(retro-arm64) root@ecs:~/retrowrite-arm64/arm/tests# sed -i 's/__cxa_finalize//g' uaf_clang.s
(retro-arm64) root@ecs:~/retrowrite-arm64/arm/tests# AFL_AS_FORCE_INSTRUMENT=1 afl-clang-fast -fPIC -pie uaf_clang.s -o uaf_clang_afl
afl-clang-fast 2.52b by <lszekeres@google.com>
/usr/bin/ld: /usr/lib/afl/afl-llvm-rt.o(.debug_info+0x149): R_AARCH64_ABS64 used with TLS symbol __afl_prev_loc
```

## gcc retrowrite afl
```
(retro-arm64) root@ecs:~/retrowrite-arm64/arm/tests# gcc uaf.c -o uaf_gcc                                                                                          [9/1926]
(retro-arm64) root@ecs:~/retrowrite-arm64/arm/tests# retrowrite uaf_gcc uaf_gcc.s
ET_DYN
.rodata 0x8e8
.init_array 0x10d68
.got 0x10f68
.data 0x11000
.bss 0x11010
[*] Relocations for a section that's not loaded: .rela.dyn
[*] Relocations for a section that's not loaded: .rela.plt
[x] Couldn't find valid section 10d70
[INFO] Saved 2 out of 2 global accesses (100.0% )
[INFO] Out of 0 .text pointers, 0 cannot be saved (of which 0 are non-trivial, in total 0.0%)
[INFO] Success: retrowritten assembly to uaf_gcc.s
(retro-arm64) root@ecs:~/retrowrite-arm64/arm/tests# sed -i 's/__cxa_finalize//g' uaf_gcc.s
(retro-arm64) root@ecs:~/retrowrite-arm64/arm/tests# AFL_AS_FORCE_INSTRUMENT=1 afl-clang-fast -fPIC -pie uaf_gcc.s -o uaf_gcc_afl
afl-clang-fast 2.52b by <lszekeres@google.com>
/usr/bin/ld: /usr/lib/afl/afl-llvm-rt.o(.debug_info+0x149): R_AARCH64_ABS64 used with TLS symbol __afl_prev_loc
```
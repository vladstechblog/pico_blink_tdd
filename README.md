# Pico Blink TDD

This is as small example of practicing test driven development (TDD)
with the Raspberry Pi Pico C/C++ SDK.


## Building and Running Tests

Building and running tests on the host target (developer machine).

```shell
git clone https://github.com/vladstechblog/pico_blink_tdd
cd pico_blink_tdd
cmake -B build_host -DPICO_PLATFORM=host
cmake --build build_host/ -t appTestRunner
./build_host/test/appTestRunner
```


## Building Blink Binary

Building the binary uploadable to the the Pico 2W board.

```shell
git clone https://github.com/vladstechblog/pico_blink_tdd
cd pico_blink_tdd
cmake -B build_p2w -DPICO_BOARD=pico2_w -DPICO_PLATFORM=rp2350
cmake --build build_p2w
```

The "blink binary" will reside in `build_p2w/src/blink.u2f`.

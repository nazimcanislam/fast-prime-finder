# Fast Prime Finder

Prime numbers are numbers that are only divisible by 1 and itself. For example, 2, 3, 5, 7... But what about the number 132598717? It can be difficult to tell whether large numbers like this are prime or not. We may even need to check many big numbers like this (someday, who knows). That's why this program finds all prime numbers in a range given a start and end value VERY QUICKLY.

## How Does It Work?

The program makes use of practical ways to check if a number is prime.

For more information see the [details](https://byjus.com/maths/how-to-find-prime-numbers/).

## Requirements

### Install on Linux

On Linux it's easy to install compilers and build systems.

`debian`
```bash
sudo apt install build-essential
```

### Install on macOS

It also easy install on macOS with Homebrew.

`macOS with Homebrew`
```bash
brew install gcc make
```

### Install on Windows

Installing Windows is a bit harder. First, install <a href="https://sourceforge.net/projects/mingw/" target="_blank">MinGW</a>. For later, research how to install MinGW.

Then install this requirements:

- mingw32-base
- mingw32-gcc-g++
- mingw32-pthreads-w32

I assume you set system variables. You can compile the program manually, but I recommend using a build system. To install `make` run this command:

```bash
mingw-get install mingw32-make
```

## Compile & Run Program

Compile the executable in the 'bin' folder with the 'release' command in the Makefile for Linux or macOS.

```bash
make release
```

To compile for Windows, run this command.

```bash
mingw32-make release
```

To run enter the bin folder and type...
```bash
cd bin
./fastprimefinder
```

Enter the start number and end number on the screen that comes up. All prime numbers in the range you specify will be found and saved to the file.
3
## Tests

Found 664,579 primes between 1 and 10,000,000.

| Platform                 | CPU                  | Time     |
|--------------------------|----------------------|----------|
| macOS 13.3.1             | Apple M1             | ~ 0.10 s |
| Windows 11, version 23H2 | Intel Core i5-12450H | ~ 0.16 s |
| Windows 11, version 23H2 | Intel Core i7-1255U  | ~ 0.17 s |
| Ubuntu 22.10             | Intel Core i5-2400   | ~ 2.50 s |

## Also

Thanks ChatGPT 🙂

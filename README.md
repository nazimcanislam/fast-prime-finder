# Fast Prime Finder

Prime numbers are numbers that are only divisible by 1 and itself. For example, 2, 3, 5, 7... But what about the number 132598717? It can be difficult to tell whether large numbers like this are prime or not. We may even need to check many big numbers like this (someday, who knows). That's why this program finds all prime numbers in a range given a start and end value VERY QUICKLY.
## How Does It Work?

The program makes use of practical ways to check if a number is prime.

For more information see the [details](https://byjus.com/maths/how-to-find-prime-numbers/).

## Compile & Run Program

This program not optimized for Windows. It runs only `Linux` or `macOS`. Compile the executable in the 'bin' folder with the 'release' command in the Makefile.

```bash
make release
```

To run enter the bin folder and type...
```bash
cd bin
./fastprimefinder
```

Enter the start number and end number on the screen that comes up. All prime numbers in the range you specify will be found and saved to the file.

## Tests

Found 664579 primes between 1 and 10000000.

| Platform        | CPU                | Time   |
|-----------------|--------------------|--------|
| macOS 13.3.1    | Apple M1           | ~0.8 s |

## Also

Thanks ChatGPT 🙂

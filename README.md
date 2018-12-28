# Time-Parser

Time-Parser is a small C program that parses a file with pairs of times in varying formats, identifies early and later time for each line of the file, and prints out all earliest times in order of the file, followed by the latest times in reverse order.

## Build

To build and run this program :

```
git clone https://github.com/smonroe4242/Time-Parser.git
make
./timeparser logfile
```

## Dependencies

*	stdlib.h and string.h functions are used for memory management and string manipulation.

*	stdio.h is used for output (printf).

*	fcntl.h functions are used for file manipulation.

*	regex.h is used for parsing.

*	A personal library implementation of get_line from C++ makes file reading easier (get_next_line()).

*	libft.h, the abovementioned library, is included for this purpose, and will be compiled and linked on make.

## Specifications

Time-Parser can handle multiple input files.

Files are formatted as follows:

*	Two column entries per line

*	Entries are in either ISO 24h format (YYYY-MM-DD hh:mm) or 12h format (hh:mm [a|p]m)

*	Entries on the same line will have the same format

Time-Parser trusts that the input files are well formed.
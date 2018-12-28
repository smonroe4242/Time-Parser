# Time-Parser
Time-Parser is a small C program that parses a file with pairs of times in varying formats, identifies early and later time for each line of the file, and prints out all earliest times in order of the file, followed by the latest times in reverse order.

## Build
To build and run this program :

```
git clone https://github.com/smonroe4242/Time-Parser.git
make
./timeparser logfile
```

## Source

fcntl.h functions are used for file manipulation.
Parsing of lines is done with regex.h.
Information is stored and retrieved using a singly linked list.


### Specifications
Time-Parser can handle multiple input files.
Files are formatted as follows:
	Two column entries per line
	Entries are in either:
		ISO 24h format (YYYY-MM-DD hh:mm)
		12h am-pm format (hh:mm [a|p]m)
	Entries on the same line will have the same format

Time-Parser trusts that the input files are well formed.
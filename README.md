# ft_ls project - arsciand @ 42

This is my first system based project. I reproduced the ```ls``` shell command. This programm displays the names of files contained within a given directory, as well as any requested, associated information.

The following options are implemented:

```-Ralrt1@eSs```

- Colors (Directly implemented) : Display colors by file categories.
- (-R) : Process directories recursively
- (-a) : Includes directory entry whose begin with ```.```
- (-l) : List files in long format with severals informations
- (-r) : Reverse sorting
- (-1) : Output by line
- (-@) : Display extended attribute with (-l)
- (-e) : Display ACL
- (-S) : Sort files by size
- (-s) : Display files system blocks used by file

# Usage

```make```

and

```./ft_ls [-Ralrt1@eSs] [file ...]```

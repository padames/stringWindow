# stringWindow

Coding exercise from ByteCode

## Summary

Find the smalles substring within the given string such that it contains the target substring in any order.

## Arguments

The first argument os the original string while the second is the target string.
The former is searched for the smallest substring containing the letters of the second argument in any given order.

## Examples


```
$ ./stringWindow "aabeaadad" "aed"

Original string: aabeaadad
target string: aed
Found a boundary letter a in: <0, 8> continuing ...
New path found <1, 8>
Found a boundary letter a in: <1, 8> continuing ...
New path found <0, 7>
New path found <1, 7>
New path found <3, 7>
New path found <3, 8>
Found a boundary letter e in: <3, 7> continuing ...
Found a boundary letter e in: <3, 8> continuing ...
New path found <0, 6>
New path found <1, 6>
New path found <3, 6>
Found a boundary letter d in: <0, 8> continuing ...
Found a boundary letter d in: <1, 8> continuing ...
Found a boundary letter d in: <3, 8> continuing ...
---
Summary of paths found
---
<0, 6>, 7
<0, 7>, 8
<0, 8>, 9
<1, 6>, 6
<1, 7>, 7
<1, 8>, 8
<3, 6>, 4
<3, 7>, 5
<3, 8>, 6
The substring 'eaad' from 'aabeaadad' contains 'aed'
```
Abbreviated output:

```
$ ./stringWindow "aabeaadad" "aaa"
The substring 'aada' from 'aabeaadad' contains 'aaa'
```

```
$ ./stringWindow "aabeaadad" "aaaa"
The substring 'abeaad' from 'aabeaadad' contains 'aaaa'
```

# stringWindow

Coding exercise from ByteCode

## OS Builds

Platform | Build status
---------|-------------:
Ubuntu 18.04 LTS | [![Build Status](https://travis-ci.com/padames/stringWindow.svg?branch=main)](https://travis-ci.org/padames/stringWindow)

## Summary

Find the smalles substring within the given string such that it contains the target substring in any order.

## Arguments

The first argument os the original string while the second is the target string.
The former is searched for the smallest substring containing the letters of the second argument in any given order.

## Examples


```
$ ./stringWindow "aabeaadad" "aed"
The substring 'eaad' from 'aabeaadad' contains 'aed'
```

```
$ ./stringWindow "aabeaadad" "aaa"
The substring 'aada' from 'aabeaadad' contains 'aaa'
```

```
$ ./stringWindow "aaaaaa" "a"
The substring 'a' from 'aaaaaa' contains 'a'
```

```
$ ./stringWindow "aghetyqqqsaa" "aaghe"
The substring 'ghetyqqqsaa' from 'aghetyqqqsaa' contains 'aaghe'
```

# Questions

## What's `stdint.h`?

A header file that allows you to write more portable code by providing a set of typedefs that specify exact width integer types. Also includes defined minimum and maximum values for each type using macros.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

To make it clear you intend to use the data in a specific way.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1,4,4,2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes show the file is a bitmap with the letters BM or hex 0x42.

## What's the difference between `bfSize` and `biSize`?

The biSize is the size of the image including the pixels and padding and the bfSize is the size of the file including the pixels, padding and header.

## What does it mean if `biHeight` is negative?

It means it is a top-down DIB and it's origin is the upper-left corner. Top-down DIB's can't be compressed and must be either BI-RGB or BI-BITFIELDS. 

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

The biBITCOUNT specifies the number of bits per pixel so it contains the max number of colors per pixel. More bytes allocated means more color depth.

## Why might `fopen` return `NULL` in `copy.c`?

Either the file does not exist, is incorrect, or there's a permission error upon accessing the file (ie. Read-Only or Write-Protected).

## Why is the third argument to `fread` always `1` in our code?

It is the counter that holds the max number if items to be read. Since the program reads the BMP piece by piece the counter tells the max number of pieces that will be read.

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

The answer is 3 /n
Padding = (4 - (bi.biWidth * sizeof(RGBtriple)) % 4) % 4 /n
Padding = (4 - (3 * (RGBtriple is always 3)) % 4 ) % 4 /n
Padding = (4 - (9 % 4) % 4 /n
Padding = (4 -1) % 4 /n
Padding = 3 % 4 /n
Padding = 3 /n

## What does `fseek` do?

It moves a file pointer associated with a given file to a specific position.

## What is `SEEK_CUR`?

It's a file position indicator within fseek, "from", that indicates the current position in a file.

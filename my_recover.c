/* Recover
CS50 - 2019 - pset3 
Forensics

Recovers deleted JPEG images from a forensic image of 
a memory card from a camera.

Terri Brunner
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "bmp.h"

// Eliminates magic numbers
#define BLOCK 512

int main(int argc, char *argv[])
{
    // Ensure exactly 1 arg
    if (argc != 1)
    {
        fprintf(stderr, "Usage: ./recover card.raw");

        return 1;
    }

    // Remember filenames
    char card = argv[1];

    // Open image for reading (fimage for forensic image)
    FILE *fimage = fopen(card, "r");

    // If file can't be opened, inform user, return 2
    if (fimage == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", card);

        return 2;
    }
	
	// Create string array of 8 to store full filename 
	char* fname[8];
	
	// Define BYTE typedef to have 1 byte (8bits)
	typedef uint8_t  BYTE;
	
	// Create buffer to hold 512B 'block' or bblock
	BYTE bblock[BLOCK +1];
	
	// Declare newjpg that holds the current filename
	FILE* newjpg;
	
	// Define signature search = true or false
	bool sigsearch = ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
						&& (buffer[3] & 0xf0) == 0xe0);
	
    // Iterate (i) over blocks (512B) in buffer, repeat until eof
   while (fread(bblock, BLOCK, 1, fimage) == 1)
    {
        // Counter for file name numbers
	    int counter = 0;
	
        // Search for JPEG signature in 1st 3 bytes &&
		// in 4th byte
		if (sigsearch = true)
        {
            // If JPEG is already found close last jpg file and push it to the dir
            if (counter > 0);
            {
                // Close opened newjpg file
               fclose(*newjpg);  
             }
			
			// Create new jpg file + name it using counter
			sprintf(fname, "%3d.jpg", rJPEG);
			
			// Count each recovered jpeg file for filename use
			rJPEG++;
			
			// Open the new jpg file to write to
			FILE* newjpg = fopen(fname, "w");
			
			// Write first 512 found jpeg bytes to new jpg file
		    fputs(char *block, FILE *newjpg);

			// Check if contains new signature, stop writing 
			// Or rather if no new signature is found write next block
			// to same newjpg file
			if (sigsearch = false)
			{
				// Write another 512B block to new jpg file
				fputs(char *block, FILE *newjpg);
			}
			// Close newjpg file to start over
		    else
			{
				fclose(*newjpg);
			}
			}
        }
    }

    }
// Close all jpg files open
fclose(*.jpg);
            
// Close card file
fclose(card);
    
	// Success
    return 0;
}

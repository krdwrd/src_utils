#include "cv.h"
#include <stdio.h>
#include <errno.h>
#include "highgui.h"
#include <iostream>

int main (int argc, const char * argv[])
{
	if (argc != 4)
	{
		printf("Usage: %s INPUTIMAGE OUTPUTIMAGE COORDINATES\n" 
			   "Reads left top width height from COORDINATES and draws rectangles\n" 
			   "an INPUTIMAGE, writing the result to OUTPUTIMAGE\n", argv[0]);
		return 1;
	}
    FILE * f = fopen(argv[3], "r");
    char * out = (char*)malloc(10);
    int r;
    int c = 0;
    float input[4];
    CvPoint A, B;
    bool fresh = true;
    IplImage * im = cvLoadImage(argv[1]);
    CvFont f0, f1;
    cvInitFont(&f0, CV_FONT_HERSHEY_SIMPLEX, 0.5, 0.5, 0, 3, CV_AA);
    cvInitFont(&f1, CV_FONT_HERSHEY_SIMPLEX, 0.5, 0.5, 0, 1, CV_AA);

    while (1)
    {
        r = fscanf (f, "%f %f %f %f", input, input+1, input+2, input+3);
        if (r == EOF)
            break;
        else if (r == 4)
        {
			// note the typecast - cant do this in fscanf
            A.x = input[0];
            A.y = input[1];
            B.x = input[2];
            B.y = input[3];
            B.x += A.x;
            B.y += A.y;
            sprintf(out, "%d", c);
            cvRectangle(im, A, B, CV_RGB(255 - c % 3 * 128, c % 4 * 80, c % 5 * 64), 2, CV_AA);
            A.y = (A.y + B.y) /2;
            cvPutText(im, out, A, &f0,  CV_RGB(255 - c % 3 * 128, c % 4 * 80, c % 5 * 64));
            cvPutText(im, out, A, &f1,  CV_RGB(c % 3 * 128, 255 - c % 4 * 80, 255 - c % 5 * 64));
            fresh = false;
        }
        else if (r != 0)
        {
            printf("error: read only %d floats in line %d of file %s\n", r, c, argv[3]);
            return 1;
        }

        while ((r = fgetc(f)) == 10)
        {
            fresh = true;
            c++;
        }

        if (r == EOF)
            break;

        fseek(f, -1, SEEK_CUR);
    }
    cvSaveImage(argv[2], im);
	free(out);
}

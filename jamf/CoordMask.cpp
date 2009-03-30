#include "CoordMask.h"

namespace jamf
{

CoordMask::CoordMask(int ID) : BasicComponent(ID)
{
}

void CoordMask::run()
{
    PRE_INPUT_MSG(in, "No input");
    PRE_INPUT_MSG(ref, "No reference input");
    PRE_INPUT_MSG(in->cols == 4, "Expecting Nx4 input vector with coordinates");

    // output memory management
    if (out)
        cvReleaseMat(&out);
    out = cvCreateMat(ref->rows, ref->cols, CV_8UC1);
    cvZero(out);

    int c = 0;
    for (int * i = in->data.i; c<in->rows; c++)
    {
        CvPoint a, b;
        a.x = *(i++);
        a.y = *(i++);
        b.x = *(i++);
        b.y = *(i++);
        cvRectangle(out, a, b, cvScalarAll(255), -1);
    }

}

CoordMask::~CoordMask()
{
}

}


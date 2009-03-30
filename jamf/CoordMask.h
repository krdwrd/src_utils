#ifndef _COORDMASK_H
#define _COORDMASK_H

#include "BasicComponent.h"

namespace jamf
{

class CoordMask : public BasicComponent
{
public:

    CoordMask(int ID);

    ~CoordMask();

    void run();

    void input_reference(CvMat * reference)
    {
        ref = reference;
    };

private:

    CvMat * ref;

};

} // namespace
#endif /* _COORDMASK_H */

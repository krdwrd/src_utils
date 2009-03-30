#include "CoordMask.h"

using namespace jamf;

class TestCoordMask : public JamfTest
{
public:

    void setUp()
    {
    }

	void tearDown()
	{
	}

    void test_fail()
	{
		CoordMask CM(1);
		CM.run();
		TS_ASSERT_EQUALS(CM.output(), NULL);
	}

    void test_basic()
    {
		CvMat * one = cvCreateMat(3, 3, CV_8UC1);
		CvMat * v = cvCreateMat(1, 4, CV_32SC1);
		CV_MAT_ELEM(*v, int, 0, 0) = 1;
		CV_MAT_ELEM(*v, int, 0, 1) = 0;
		CV_MAT_ELEM(*v, int, 0, 2) = 2;
		CV_MAT_ELEM(*v, int, 0, 3) = 1;

		CoordMask CM(1);
		CM.input(v);
		CM.input_reference(one);
		CM.run();

		CvMat * o = CM.output();
		// note: row, col vs. x, y in input
        TS_ASSERT_EQUALS( int CV_MAT_ELEM(*o, unsigned char, 1, 1), 255 );
        TS_ASSERT_EQUALS( int CV_MAT_ELEM(*o, unsigned char, 0, 2), 255 );
        TS_ASSERT_EQUALS( int CV_MAT_ELEM(*o, unsigned char, 2, 1), 0 );
        TS_ASSERT_EQUALS( int CV_MAT_ELEM(*o, unsigned char, 0, 0), 0 );
    }


};

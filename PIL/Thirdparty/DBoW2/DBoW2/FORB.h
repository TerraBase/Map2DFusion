/**
 * File: FORB.h
 * Date: June 2012
 * Author: Dorian Galvez-Lopez
 * Description: functions for ORB descriptors
 * License: see the LICENSE.txt file
 *
 */

#ifndef __D_T_F_ORB__
#define __D_T_F_ORB__

#include <vector>
#include <string>
#include <stdint.h>

#include <opencv/cv.h>

#include "FClass.h"

namespace DBoW2 {


/// Functions to manipulate ORB descriptors
class FORB: protected FClass
{
public:

    /// Descriptor type
    //  typedef cv::Mat TDescriptor; // CV_8U
    struct TDescriptor
    {
        uint8_t data[32];

        void fromMat(const cv::Mat &desc) {
            memcpy(data,desc.data,32);
        }

        cv::Mat toMat()
        {
            cv::Mat result=cv::Mat::zeros(1, FORB::L, CV_8U);
            memcpy(result.data,data,32);
            return result.clone();
        }
    };

    /// Pointer to a single descriptor
    typedef const TDescriptor *pDescriptor;
    /// Descriptor length (in bytes)
    static const int L;

    //  /**
    //   * Calculates the mean value of a set of descriptors
    //   * @param descriptors
    //   * @param mean mean descriptor
    //   */
    static void meanValue(const std::vector<pDescriptor> &descriptors,
                          TDescriptor &mean);

    /**
   * Calculates the distance between two descriptors
   * @param a
   * @param b
   * @return distance
   */
    static int distance(const TDescriptor &a, const TDescriptor &b);

    static int distance(const cv::Mat &a, const cv::Mat &b);

    /**
   * Returns a string version of the descriptor
   * @param a descriptor
   * @return string version
   */
    static std::string toString(const TDescriptor &a);

    /**
   * Returns a descriptor from a string
   * @param a descriptor
   * @param s string version
   */
    static void fromString(TDescriptor &a, const std::string &s);

    /**
   * Returns a mat with the descriptors in float format
   * @param descriptors
   * @param mat (out) NxL 32F matrix
   */
    static void toMat32F(const std::vector<TDescriptor> &descriptors,
                         cv::Mat &mat);

    static void toMat8U(const std::vector<TDescriptor> &descriptors,
                        cv::Mat &mat);

};

} // namespace DBoW2

#endif


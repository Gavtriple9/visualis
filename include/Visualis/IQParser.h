#pragma once

#include "Core.h"

namespace Vis {

/**
 * @brief IQParser interface.
 * @date 2023-08-26
 * @file IQParser.h
 */

/**
 * @brief IQParser will store a file pointer to IQ data file
 * and provide the ability to generate a plot from the data.
 * 
 */
class IQParser {
public:
    /**
     * @brief Construct a new IQParser object
     * 
     * @param filename 
     */
    IQParser(const char* filename) : m_filename(filename) {}

    /**
     * @brief Destroy the IQParser object
     * 
     */
    ~IQParser(){}

    /**
     * @brief Generate a plot from the IQ data file.
     * 
     */
    void plot();

private:
    const char* m_filename;

};

}
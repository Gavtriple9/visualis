#pragma once

#include "Core.h"
#include "MainFrame.h"

namespace Vis {

/**
 * @brief Grapher application class
 * 
 * @details This class is the main app class 
 * for the grapher application. It is responsible
 * for creating the main frame and starting the
 * application.
 * 
 * @see wxApp
 * 
 * @note This class is a singleton
 * 
 * @return \ref GrApp
 */
class GrApp : public wxApp
{
public:
    virtual bool OnInit();
};


} // namespace Vis
#pragma once

#include "Core.h"
#include <wx/combo.h>
#include <wx/splitter.h>
#include "IQParser.h"

namespace Vis {

/**
 * @brief Frame class
 * 
 */
class MainFrame : public wxFrame
{
public:
    /**
     * @brief Construct a new \ref MainFrame object
     * @details This constructor creates a new frame with a button
     * 
     * @param title - the title of the frame
     * 
     * @return \ref MainFrame
     */
    MainFrame(const wxString& title);
    
    void OnComboSelection(wxCommandEvent& event);


    // Event handlers
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

private:
    wxComboBox* m_combo;

    wxSplitterWindow* m_splitter;
    wxPanel* m_panel1;
    wxPanel* m_panel2;

    // This class handles events
    DECLARE_EVENT_TABLE()
};

} // namespace Vis
#include <Visualis/MainFrame.h>

using namespace Visualis;

MainFrame::MainFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1200, 600))
{
    IQParser iqParser("data/alt_mim_iq_samp/lora_8-PSK_over_FS-CSS");
    iqParser.plot();

    // Create a menu bar
    wxMenu* fileMenu = new wxMenu;

    // The "About" item should be in the help menu
    wxMenu* mainMenu = new wxMenu;
    mainMenu->Append(wxID_ABOUT, wxT("&About...\tF1"), wxT("Show about dialog"));

    // The "Quit" item should be in the file menu
    fileMenu->Append(wxID_EXIT, wxT("E&xit\tAlt-X"), wxT("Quit this program"));

    // Now append the freshly created menu to the menu bar...
    wxMenuBar* menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, wxT("&File"));
    menuBar->Append(mainMenu, wxT("&Help"));

    // ... and attach this menu bar to the frame
    SetMenuBar(menuBar);

    // Create a status bar just for fun
    CreateStatusBar(2);
    SetStatusText(wxT("IQ Grapher"));

    m_splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                  wxSP_BORDER | wxSP_3DSASH);
    m_panel1 = new wxPanel(m_splitter, wxID_ANY);
    m_panel1->SetBackgroundColour(*wxBLACK);
    m_panel2 = new wxPanel(m_splitter, wxID_ANY);
    m_panel2->SetBackgroundColour(*wxBLACK);
    
    m_splitter->SplitVertically(m_panel1, m_panel2);

    // Set minimum pane sizes
    m_splitter->SetMinimumPaneSize(100);
    
    // Add combo box to the panel
    wxArrayString choices;
    choices.Add(wxT("z=z"));
    m_combo = new wxComboBox(m_panel1, wxID_ANY, wxT("z=z"), wxDefaultPosition, wxDefaultSize, choices, wxCB_DROPDOWN);
    m_combo->SetSelection(0);
    m_combo->Bind(wxEVT_COMBOBOX, &MainFrame::OnComboSelection, this);

    // Add a button to the panel
    wxButton* button = new wxButton(m_panel2, wxID_EXIT, wxT("Quit"));
    
    // Connect the button to the event handler (the button event should be received by the frame)
    button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnQuit));
        
}



void MainFrame::OnComboSelection(wxCommandEvent& event) 
{
    wxString selectedText = m_combo->GetValue();
}

void MainFrame::OnQuit(wxCommandEvent& event)
{
    // Destroy the frame
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox(wxT("This is a wxWidgets Hello World example"),
        wxT("About Hello World"), wxOK | wxICON_INFORMATION);
}
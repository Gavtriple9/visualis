#include <Visualis/GrApp.h>

using namespace Visualis;

bool GrApp::OnInit()
{
    // Create the main application window
	MainFrame *frame = new MainFrame(wxT(PROG_NAME));
	// Show it
	frame->Show(true);
	// Start the event loop
	return true;
}
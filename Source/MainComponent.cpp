#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);

    g.drawMultiLineText("\n\n---------- Clinic Counter Program ----------\nOption 1: Add new patient\nOption 2: Modify Patient's details existing in the List\nOption 3: Show all Patient Details\nOption 4: Retieve Patient's Medical Record by Patient's IC\nOption 5: Add existing Patient to queue\nOption 6: Display front of queue\nOption 7: Dequeue front patient.\nOption 8: Sort Patient List\nOption 9: Doctor's Assign Details\nOption 0: Exit Program\nPlease select an option from the menu provided: ",1,2,10000);


}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

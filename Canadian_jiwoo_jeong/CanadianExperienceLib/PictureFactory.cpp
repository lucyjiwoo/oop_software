/**
 * @file PictureFactory.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "MachineDrawable.h"


/// Directory within resources that contains the images.
const std::wstring ImagesDirectory = L"/images";


/**
 * Factory method to create a new picture.
 * @param resourcesDir Directory that contains the resources for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring resourcesDir)
{
    auto imagesDir = resourcesDir + ImagesDirectory;

    auto picture = std::make_shared<Picture>();

    // Create the background and add it
    auto background = std::make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI =
            std::make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background.jpg");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    //Create and add machine
    auto machines = std::make_shared<Actor>(L"Machines");
    //First Machine
    auto firstmachine = std::make_shared<MachineDrawable>(L"Machine1",resourcesDir);
    firstmachine->Place(wxPoint(300,500),0);
    machines->AddDrawable(firstmachine);
    firstmachine->SetStartFrame(60);
    picture->SetMachine1(firstmachine);


    // Second Machine
    auto secondmachine = std::make_shared<MachineDrawable>(L"Machine2",resourcesDir);
    secondmachine->Place(wxPoint(900,500),0);
    machines->AddDrawable(secondmachine);
    secondmachine->SetStartFrame(120);
    picture->SetMachine2(secondmachine);

    picture->AddActor(machines);

    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(300, 600));
    picture->AddActor(harold);

    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(550, 620));
    picture->AddActor(sparty);




    return picture;
}


# Purchase Manager
## Introduction
This GUI application was an assignment for an Advanced Programming Course, showcasing the use of C++ in the QtCreator IDE for managing the purchases of a bookstore. It features design patterns, Networking, XML data storage, and Threading. This is my approach at this application.

## Features
- Memento Design pattern to restore the item list.
- Converting the list into XML form.
- Networking using QUdpSocket for sending the purchase list in XML to the reciever application.
- Threading to make sure the list is sent before new data can be added to the list.

**Note:** The reciever application is in a different repository. [https://github.com/VinceMKB/PurchaseManagerReciever.git]

## Application GUI Screenshots
#### ![image](https://github.com/VinceMKB/Qt-Book-Store-Purchase-Manager/assets/155303838/04eb894d-403e-4811-93a0-9a192619b4a4)
#### ![image](https://github.com/VinceMKB/Qt-Book-Store-Purchase-Manager/assets/155303838/4dd7d554-ec1f-45b5-b707-d2a8474979e5)
#### ![image](https://github.com/VinceMKB/Qt-Book-Store-Purchase-Manager/assets/155303838/1918868e-095c-455d-9843-5a5ff28c5da3)
#### ![image](https://github.com/VinceMKB/Qt-Book-Store-Purchase-Manager/assets/155303838/48909a5c-c58f-484e-a029-33028d83fbea)
### How To USE Main Application
#### Adding Item:
To add a new item to the item list, click on the 'Item' menu and click on 'Add Item'. After filling the name and stock type click 'ADD' button which will clear the fields and add the item to the item list. Once done adding all the new items to the stocklist click 'DONE' to close the dialog.
#### Restore to previous Item List
To restore to previous item list, click ont the 'Restore' menu and click on 'Restore List'.
#### Adding Purchases:
To add a purchase, click on the 'Purchase' menu and click on 'Add Purchase'. After each data entry for each purchase click on the 'ADD PURCHASE' to add the purchase to the list. Once all purchases are added to the list click on 'CHECK OUT' to close the dialog.

### How To Use Reciever Application
When you click on 'CHECK OUT' in the new purchase dialog it will send the list to the reciever application. If the the reciever application is running it will display the list in XML format.

## Getting Started
### Dependencies

This project uses the following:
- QtCreator IDE in Qt version 6.5
- CMake
- C++

### Installation and Setup of Main Application
- **Step 1**: Download the zippped folder for this project. Navigate to the location of the zipped (compressed) folder using File Explorer.  
- **Step 2**: Right-click on the zipped folder, then select "Extract All..." from the context menu.  
- **Step 3**:In the dialog that appears, choose where you want the extracted files to be placed. By default, Windows will suggest extracting them to a folder with the same name as the zipped file, in the same location.  
- **Step 4**: Click the "Extract" button to start the extraction process. Once it's done, you can open the destination folder to access the extracted files.
- **Step 5**: Open QtCreator and click on 'Open Project'
- **Step 6**: Navigate to the extracted file named 'PurchaseManager' and locate the file called 'CMakeLists'
- **Step 7**: Click on 'CMakeLists' file and click 'Open'
- **Step 8**: The project should open up on QtCreator

### Post Installation and Setup of Main Application
- **Step 1**: After opening the project click on the Hammer button in the bottom left of the application to bulid the project.  
- **Step 2**: After clicking on the Hammer to bulid the project you can now Run the project by clicking on the play button.

## Implementation Details
### Design Patterns Used
- **Memento Design Pattern** used to restore the Item List

## License
This project is licensed under the MIT License - see the LICENSE.md file for detail

## Authors
Vincent Bossert

## Author Note
This project was done for one of my assignments for my Advance Programming Course so I am still learning. Any constructive advice is welcome!
